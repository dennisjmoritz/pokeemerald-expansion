#!/usr/bin/env python3
"""
Mainline Story Minimization Script
Processes Pokemon Emerald Expansion maps to reduce story content while preserving gameplay.
"""

import json
import re
import os
import shutil
from datetime import datetime
from collections import defaultdict


class StoryMinimizer:
    def __init__(self, repo_root):
        self.repo_root = repo_root
        self.state_file = os.path.join(repo_root, 'reports/minimize/state.json')
        self.load_state()
        
        # Scoring patterns 
        self.patterns = {
            'flag_badge_story': re.compile(r'setflag\s+FLAG_(BADGE|DEFEATED_|SYS_|HIDE_|.*STORY)', re.IGNORECASE),
            'var_story': re.compile(r'setvar\s+VAR_(MAIN|STORY|.*BADGE)', re.IGNORECASE),
            'key_items': re.compile(r'(giveitem|checkitem)\s+ITEM_[A-Z0-9_]+', re.IGNORECASE),
            'trainer_battle': re.compile(r'trainerbattle\w*', re.IGNORECASE),
            'movement_warp': re.compile(r'(applymovement|followplayer|warp|fadescreen|playbgm|delay|setweather|showobject|hideobject|createobject|setobjectxy)', re.IGNORECASE),
            'map_script': re.compile(r'(map_script|MAP_SCRIPT_SCENE)', re.IGNORECASE)
        }
        
        # Flag visited mapping
        self.visited_flags = {
            'LITTLEROOT_TOWN': 'FLAG_VISITED_LITTLEROOT_TOWN',
            'OLDALE_TOWN': 'FLAG_VISITED_OLDALE_TOWN', 
            'DEWFORD_TOWN': 'FLAG_VISITED_DEWFORD_TOWN',
            'LAVARIDGE_TOWN': 'FLAG_VISITED_LAVARIDGE_TOWN',
            'FALLARBOR_TOWN': 'FLAG_VISITED_FALLARBOR_TOWN',
            'VERDANTURF_TOWN': 'FLAG_VISITED_VERDANTURF_TOWN',
            'PACIFIDLOG_TOWN': 'FLAG_VISITED_PACIFIDLOG_TOWN',
            'PETALBURG_CITY': 'FLAG_VISITED_PETALBURG_CITY',
            'SLATEPORT_CITY': 'FLAG_VISITED_SLATEPORT_CITY',
            'MAUVILLE_CITY': 'FLAG_VISITED_MAUVILLE_CITY',
            'RUSTBORO_CITY': 'FLAG_VISITED_RUSTBORO_CITY',
            'FORTREE_CITY': 'FLAG_VISITED_FORTREE_CITY',
            'LILYCOVE_CITY': 'FLAG_VISITED_LILYCOVE_CITY',
            'MOSSDEEP_CITY': 'FLAG_VISITED_MOSSDEEP_CITY',
            'SOOTOPOLIS_CITY': 'FLAG_VISITED_SOOTOPOLIS_CITY',
            'EVER_GRANDE_CITY': 'FLAG_VISITED_EVER_GRANDE_CITY'
        }

    def load_state(self):
        """Load current state from JSON file"""
        with open(self.state_file, 'r') as f:
            self.state = json.load(f)

    def save_state(self):
        """Save current state to JSON file"""
        with open(self.state_file, 'w') as f:
            json.dump(self.state, f, indent=2)

    def score_content(self, content):
        """Score script content based on story signal patterns"""
        score = 0
        signals = defaultdict(int)
        
        for pattern_name, pattern in self.patterns.items():
            matches = pattern.findall(content)
            match_count = len(matches)
            signals[pattern_name] = match_count
            
            # Weight different patterns
            if pattern_name in ['flag_badge_story', 'var_story']:
                score += match_count * 2
            elif pattern_name in ['key_items', 'map_script']:
                score += match_count * 1.5
            else:
                score += match_count * 0.5
        
        return score, dict(signals)

    def analyze_labels(self, content):
        """Extract and categorize labels from script content"""
        labels = []
        
        label_pattern = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)::', re.MULTILINE)
        for match in label_pattern.finditer(content):
            label_name = match.group(1)
            
            # Get content after label until next label or end
            start = match.end()
            next_label = label_pattern.search(content, start)
            end = next_label.start() if next_label else len(content)
            label_content = content[start:end]
            
            label_score, signals = self.score_content(label_content)
            
            # Determine action
            action = 'KEEP'
            if label_score >= self.state['threshold']:
                action = 'STUB'
            elif label_score == 3:
                action = 'REVIEW'
                
            # Special cases - preserve gym/legendary/trainer content
            if any(keyword in label_name.lower() for keyword in ['gym', 'leader']):
                action = 'KEEP'
            elif 'setwildbattle' in label_content or 'startbattle' in label_content:
                action = 'KEEP'  # Legendary encounters
            elif 'trainerbattle' in label_content and label_score < 6:
                action = 'KEEP'  # Simple trainer battles
                
            labels.append({
                'name': label_name,
                'score': label_score,
                'signals': signals,
                'action': action,
                'content': label_content
            })
        
        return labels

    def stub_label(self, label_name, label_content):
        """Create appropriate stub for different label types"""
        if 'trainerbattle' in label_content:
            # Keep first trainerbattle line, then end
            lines = label_content.strip().split('\n')
            for i, line in enumerate(lines):
                if 'trainerbattle' in line.lower():
                    return f"{label_name}::\n\t{line}\n\tend\n\n"
            return f"{label_name}::\n\tend\n\n"
        elif 'setwildbattle' in label_content or 'startbattle' in label_content:
            # Keep legendary encounter setup
            lines = label_content.strip().split('\n')
            keep_lines = []
            for line in lines:
                if any(keyword in line.lower() for keyword in ['setwildbattle', 'startbattle', 'playbgm', 'cry']):
                    keep_lines.append(line)
                elif 'warp' in line.lower() or 'fade' in line.lower():
                    break  # Remove gates/cutscenes
            if keep_lines:
                return f"{label_name}::\n" + '\n'.join(f"\t{line}" for line in keep_lines) + "\n\tend\n\n"
            return f"{label_name}::\n\tend\n\n"
        else:
            # Generic stub
            return f"{label_name}::\n\tend\n\n"

    def process_map_script(self, scripts_path):
        """Process a single map's script file"""
        if not os.path.exists(scripts_path):
            return None
            
        with open(scripts_path, 'r') as f:
            original_content = f.read()
        
        labels = self.analyze_labels(original_content)
        
        # Build new content
        new_content = original_content
        
        # Process labels in reverse order to maintain string positions
        label_pattern = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)::', re.MULTILINE)
        matches = list(label_pattern.finditer(original_content))
        
        for i in reversed(range(len(matches))):
            match = matches[i]
            label_name = match.group(1)
            
            # Find corresponding label info
            label_info = next((l for l in labels if l['name'] == label_name), None)
            if not label_info or label_info['action'] != 'STUB':
                continue
                
            # Get label boundaries
            start = match.start()
            if i + 1 < len(matches):
                end = matches[i + 1].start()
            else:
                end = len(new_content)
            
            # Replace with stub
            stub = self.stub_label(label_name, label_info['content'])
            new_content = new_content[:start] + stub + new_content[end:]
        
        return new_content, labels

    def add_town_fly_hook(self, scripts_path, map_name):
        """Add fly visit hook to town/city maps"""
        flag = None
        for town_key, town_flag in self.visited_flags.items():
            if town_key.lower() in map_name.lower():
                flag = town_flag
                break
        
        if not flag:
            return False, None
            
        with open(scripts_path, 'r') as f:
            content = f.read()
        
        # Check if already has the flag
        if flag in content:
            return False, flag
            
        # Find map scripts section
        map_scripts_pattern = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*_MapScripts)::', re.MULTILINE)
        match = map_scripts_pattern.search(content)
        
        if not match:
            return False, flag
            
        # Check if already has MAP_SCRIPT_ON_TRANSITION
        if 'MAP_SCRIPT_ON_TRANSITION' in content:
            # Find the transition script and add flag
            transition_pattern = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*_OnTransition)::', re.MULTILINE)
            trans_match = transition_pattern.search(content)
            if trans_match:
                # Add setflag at beginning of transition
                trans_start = trans_match.end()
                insertion = f"\n\tsetflag {flag}"
                content = content[:trans_start] + insertion + content[trans_start:]
        else:
            # Add new transition script
            map_scripts_end = content.find('\t.byte 0', match.end())
            if map_scripts_end != -1:
                insertion = f"\n\tmap_script MAP_SCRIPT_ON_TRANSITION, {match.group(1)[:-10]}_OnTransition"
                content = content[:map_scripts_end] + insertion + content[map_scripts_end:]
                
                # Add the transition script after .byte 0
                byte_zero_end = content.find('\n', map_scripts_end) + 1
                transition_script = f"\n{match.group(1)[:-10]}_OnTransition::\n\tsetflag {flag}\n\tend\n"
                content = content[:byte_zero_end] + transition_script + content[byte_zero_end:]
        
        # Write back
        with open(scripts_path, 'w') as f:
            f.write(content)
            
        return True, flag

    def add_national_dex_hook(self, scripts_path):
        """Add National Dex hook to Pokemon Center maps"""
        if 'pokemoncenter' not in scripts_path.lower():
            return False
            
        with open(scripts_path, 'r') as f:
            content = f.read()
        
        # Check if already has national dex setup
        if 'FLAG_SYS_NATIONAL_DEX' in content:
            return False
            
        # Similar to fly hook logic but for national dex
        map_scripts_pattern = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*_MapScripts)::', re.MULTILINE)
        match = map_scripts_pattern.search(content)
        
        if not match:
            return False
            
        # Add national dex logic
        dex_code = """
\tsetflag FLAG_SYS_NATIONAL_DEX
\tspecial EnableNationalPokedex"""
        
        if 'MAP_SCRIPT_ON_TRANSITION' in content:
            transition_pattern = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*_OnTransition)::', re.MULTILINE)  
            trans_match = transition_pattern.search(content)
            if trans_match:
                trans_start = trans_match.end()
                content = content[:trans_start] + dex_code + content[trans_start:]
        else:
            # Add new transition script
            map_scripts_end = content.find('\t.byte 0', match.end())
            if map_scripts_end != -1:
                insertion = f"\n\tmap_script MAP_SCRIPT_ON_TRANSITION, {match.group(1)[:-10]}_OnTransition"
                content = content[:map_scripts_end] + insertion + content[map_scripts_end:]
                
                byte_zero_end = content.find('\n', map_scripts_end) + 1
                transition_script = f"\n{match.group(1)[:-10]}_OnTransition::{dex_code}\n\tend\n"
                content = content[:byte_zero_end] + transition_script + content[byte_zero_end:]
        
        with open(scripts_path, 'w') as f:
            f.write(content)
            
        return True

    def prune_coord_events(self, map_dir):
        """Prune coord events that set flags then warp/move"""
        map_json_path = os.path.join(map_dir, 'map.json')
        if not os.path.exists(map_json_path):
            return 0
            
        with open(map_json_path, 'r') as f:
            map_data = json.load(f)
        
        coord_events = map_data.get('coord_events', [])
        if not coord_events:
            return 0
            
        original_count = len(coord_events)
        
        # Keep coord events that don't match the pruning criteria
        # (This is a simplified implementation - full implementation would need 
        # to parse script content to find flag-set-then-warp patterns)
        pruned_events = []
        for event in coord_events:
            script = event.get('script', '')
            # Simple heuristic: if script name suggests story progression, remove it
            if any(keyword in script.lower() for keyword in ['story', 'cutscene', 'event']):
                continue  # Prune this event
            pruned_events.append(event)
        
        pruned_count = original_count - len(pruned_events)
        
        if pruned_count > 0:
            map_data['coord_events'] = pruned_events
            with open(map_json_path, 'w') as f:
                json.dump(map_data, f, indent=2)
        
        return pruned_count

    def process_batch(self, start_idx=None, end_idx=None):
        """Process a batch of maps"""
        if start_idx is None:
            start_idx = self.state['queue_index']
        if end_idx is None:
            end_idx = min(start_idx + self.state['batch_size'], len(self.state['maps']))
            
        processed = []
        errors = []
        
        for i in range(start_idx, end_idx):
            if i >= len(self.state['maps']):
                break
                
            map_info = self.state['maps'][i]
            scripts_path = os.path.join(self.repo_root, map_info['path'])
            map_dir = os.path.dirname(scripts_path)
            
            try:
                print(f"Processing {map_info['path']}...")
                
                # Process scripts
                result = self.process_map_script(scripts_path)
                if result:
                    new_content, labels = result
                    
                    # Write modified content
                    with open(scripts_path, 'w') as f:
                        f.write(new_content)
                    
                    # Update stats
                    map_info['score_stats'] = {
                        'labels': len(labels),
                        'keep': sum(1 for l in labels if l['action'] == 'KEEP'),
                        'stub': sum(1 for l in labels if l['action'] == 'STUB'), 
                        'review': sum(1 for l in labels if l['action'] == 'REVIEW')
                    }
                    
                    # Track legendary labels
                    map_info['legendary_labels_kept'] = [
                        l['name'] for l in labels 
                        if l['action'] == 'KEEP' and ('setwildbattle' in l['content'] or 'startbattle' in l['content'])
                    ]
                
                # Add fly hook for towns/cities
                map_name = os.path.basename(os.path.dirname(scripts_path))
                if any(suffix in map_name for suffix in ['Town', 'City']):
                    added, flag = self.add_town_fly_hook(scripts_path, map_name)
                    if added:
                        map_info['town_flag'] = flag
                
                # Add national dex hook for pokemon centers
                if self.add_national_dex_hook(scripts_path):
                    map_info['center_dex_hook'] = True
                
                # Prune coordinate events
                pruned = self.prune_coord_events(map_dir)
                map_info['coord_events_pruned'] = pruned
                
                map_info['status'] = 'stubbed' if map_info['score_stats']['stub'] > 0 else 'kept'
                map_info['last_updated'] = datetime.now().isoformat()
                processed.append(map_info['path'])
                
            except Exception as e:
                error_msg = f"Error processing {map_info['path']}: {str(e)}"
                print(error_msg)
                errors.append(error_msg)
                map_info['status'] = 'error'
                map_info['notes'] = str(e)
        
        # Update queue index
        self.state['queue_index'] = end_idx
        
        # Update run info
        if self.state['runs']:
            self.state['runs'][-1]['processed'].extend(processed)
            self.state['runs'][-1]['errors'].extend(errors)
            if end_idx >= len(self.state['maps']):
                self.state['runs'][-1]['ended'] = datetime.now().isoformat()
        
        self.save_state()
        return len(processed), len(errors)


def main():
    repo_root = '/home/runner/work/pokeemerald-expansion/pokeemerald-expansion'
    minimizer = StoryMinimizer(repo_root)
    
    # Process first batch
    processed, errors = minimizer.process_batch(0, 25)
    print(f"Processed {processed} maps with {errors} errors")


if __name__ == '__main__':
    main()