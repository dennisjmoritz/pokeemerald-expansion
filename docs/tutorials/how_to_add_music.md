# How to Add Music

This tutorial will guide you through adding new background music, sound effects, and audio tracks to your pokeemerald-expansion ROM hack. Music and audio play a crucial role in creating atmosphere and enhancing the player experience.

## Content
* [Quick Summary](#quick-summary)
* [Understanding the Audio System](#understanding-the-audio-system)
* [Audio File Structure](#audio-file-structure)
* [Adding Background Music](#adding-background-music)
  * [1. Preparing Audio Files](#1-preparing-audio-files)
  * [2. Converting to MIDI](#2-converting-to-midi)
  * [3. Adding to Game](#3-adding-to-game)
* [Adding Sound Effects](#adding-sound-effects)
* [Audio Implementation](#audio-implementation)
* [Advanced Audio Features](#advanced-audio-features)
* [Troubleshooting](#troubleshooting)

## Quick Summary

If you've done this before and just need a quick reference:

1. Prepare MIDI files for background music
2. Add audio files to `sound/songs/` directory
3. Register songs in `sound/song_table.inc`
4. Add constants to `include/constants/songs.h`
5. Use new music in maps, battles, and events
6. Build and test audio playback

## Understanding the Audio System

The pokeemerald-expansion audio system supports:

- **Background Music (BGM)**: Looping tracks for maps, battles, and menus
- **Sound Effects (SE)**: Short audio clips for actions and events
- **Musical Effects (ME)**: Special musical stings and fanfares
- **Voice Samples**: Direct sound samples for cries and effects

The audio system uses the M4A (MusicPlayer4Advance) sound engine, which supports both MIDI-based music and direct sound samples.

## Audio File Structure

```
sound/
├── songs/
│   ├── midi/               # MIDI source files
│   │   ├── mus_your_song.mid
│   │   └── se_your_sound.mid
│   ├── mus_your_song.s     # Assembled audio data
│   └── se_your_sound.s
├── direct_sound_samples/   # Raw audio samples
│   ├── cries/             # Pokémon cries
│   └── effects/           # Sound effects
├── song_table.inc         # Song definitions
├── voicegroups/           # Instrument definitions
└── music_player_table.inc # Player configuration
```

## Adding Background Music

### 1. Preparing Audio Files

#### MIDI Format Requirements
- **File format**: Standard MIDI File (.mid)
- **Channels**: Maximum 16 channels
- **Instruments**: Must use General MIDI instrument set
- **Tempo**: Reasonable tempo for game context
- **Length**: Consider file size and ROM space

#### Recommended MIDI Specifications
- **Resolution**: 96-480 ticks per quarter note
- **Track length**: 1-3 minutes for looping tracks
- **Instrument count**: Limit to 8-10 simultaneous instruments
- **Complexity**: Balance quality with file size

### 2. Converting to MIDI

If you have audio in other formats, convert to MIDI:

#### Using DAW Software
1. Import your audio file into a Digital Audio Workstation
2. Transcribe or sequence the music as MIDI
3. Export as Standard MIDI File (.mid)
4. Test playback with simple MIDI player

#### Online Conversion Tools
- Use online audio-to-MIDI converters (quality may vary)
- Manual cleanup often required
- Test thoroughly before implementation

### 3. Adding to Game

#### Step 1: Add MIDI File
Place your MIDI file in `sound/songs/midi/`:

```bash
sound/songs/midi/mus_your_custom_theme.mid
```

#### Step 2: Register in Song Table
Add your song to `sound/song_table.inc`:

```assembly
	.align 2
song_mus_your_custom_theme::
	.incbin "sound/songs/mus_your_custom_theme.s"

	.align 2
```

#### Step 3: Add Constant
Define the song constant in `include/constants/songs.h`:

```c
#define MUS_YOUR_CUSTOM_THEME    400  // Use next available number

// Group related songs together
#define MUS_CUSTOM_TOWN_THEME    401
#define MUS_CUSTOM_BATTLE_THEME  402
#define MUS_CUSTOM_ROUTE_THEME   403
```

#### Step 4: Update Build System
Add your song to the build dependencies in `audio_rules.mk`:

```makefile
$(MID_SUBDIR)/mus_your_custom_theme.s: $(MID_SUBDIR)/mus_your_custom_theme.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P5
```

#### Step 5: Build Audio
Convert MIDI to game format:

```bash
make songs
```

This will create `sound/songs/mus_your_custom_theme.s` from your MIDI file.

## Adding Sound Effects

### Short Musical Effects

#### Create SE MIDI File
For musical sound effects, create short MIDI files:

```
sound/songs/midi/se_your_custom_sound.mid
```

#### Configure Sound Effect
Add to build system with appropriate parameters:

```makefile
$(MID_SUBDIR)/se_your_custom_sound.s: $(MID_SUBDIR)/se_your_custom_sound.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V127 -P1
```

#### Add SE Constant
Define in `include/constants/songs.h`:

```c
#define SE_YOUR_CUSTOM_SOUND     500  // Use available SE range
```

### Direct Sound Samples

For non-musical sound effects, use direct sound samples:

#### Prepare Audio Sample
- **Format**: WAV or AIF
- **Sample rate**: 22050 Hz or 11025 Hz
- **Bit depth**: 8-bit or 16-bit
- **Length**: Keep short (under 1 second for most effects)

#### Add Sample File
Place in `sound/direct_sound_samples/`:

```
sound/direct_sound_samples/effects/your_sound_effect.aif
```

#### Register Sample
Add to direct sound data file:

```c
const struct DirectSoundSample gYourSoundEffect = 
{
    .rate = 22050,
    .samples = your_sound_effect_data,
    .length = sizeof(your_sound_effect_data),
};
```

## Audio Implementation

### Using Music in Maps

#### Map Background Music
Set map music in the map JSON file:

```json
{
  "id": "MAP_YOUR_CUSTOM_TOWN",
  "music": "MUS_YOUR_CUSTOM_THEME",
  "weather": "WEATHER_SUNNY"
}
```

#### Dynamic Music Changes
Change music based on events:

```assembly
YourMap_EventScript_MusicChange::
	playbgm MUS_YOUR_CUSTOM_THEME, TRUE
	end

YourMap_EventScript_RestoreMusic::
	playbgm MUS_ORIGINAL_THEME, TRUE
	end
```

### Battle Music Integration

#### Trainer Battle Music
Set custom battle music for specific trainers:

```
=== TRAINER_YOUR_BOSS ===
Name: BOSS
Class: Gym Leader
Pic: Your Boss Pic
Gender: Male
Music: Your Custom Battle Theme
```

#### Wild Battle Music
Change wild Pokémon battle music:

```c
// In battle initialization code
if (IsWildBattle() && GetCurrentMapGroup() == MAP_GROUP_YOUR_AREA)
{
    PlayBGM(MUS_YOUR_WILD_BATTLE_THEME);
}
```

### Sound Effects in Scripts

#### Playing Sound Effects
Use sound effects in event scripts:

```assembly
YourScript_PlayCustomSound::
	playse SE_YOUR_CUSTOM_SOUND
	waitseplay SE_YOUR_CUSTOM_SOUND
	msgbox YourText_SoundPlayed, MSGBOX_NPC
	end
```

#### Conditional Audio
Play different sounds based on conditions:

```assembly
YourScript_ConditionalAudio::
	checkflag FLAG_YOUR_CONDITION
	goto_if_set YourScript_PlayHappySound
	playse SE_FAILURE
	goto YourScript_End

YourScript_PlayHappySound::
	playse SE_SUCCESS
	
YourScript_End::
	end
```

## Advanced Audio Features

### Looping Configuration

#### Custom Loop Points
Set specific loop points for your music:

```assembly
	.align 2
song_mus_your_looping_theme::
	.include "sound/songs/mus_your_looping_theme.s"
	.byte LOOP_START, 0x40  ; Loop from measure 64
	.byte LOOP_END
```

#### Seamless Loops
Ensure your MIDI files loop seamlessly:
- End notes should connect smoothly to beginning
- Use fade-in/fade-out if necessary
- Test loop points in-game

### Dynamic Music Layers

#### Adaptive Music System
Create music that changes based on gameplay:

```c
void UpdateDynamicMusic(void)
{
    if (IsPlayerInDanger())
    {
        if (GetCurrentBGM() != MUS_DANGER_THEME)
            PlayBGM(MUS_DANGER_THEME);
    }
    else if (IsPlayerExploring())
    {
        if (GetCurrentBGM() != MUS_EXPLORATION_THEME)
            PlayBGM(MUS_EXPLORATION_THEME);
    }
}
```

#### Layered Audio Tracks
Implement music layers that enable/disable:

```assembly
YourScript_EnableMusicLayer::
	fademusic 50, 5          ; Fade to 50% volume over 5 frames
	playbgm MUS_LAYER_2, TRUE ; Start second layer
	fademusic 100, 5         ; Fade back to full volume
	end
```

### Audio Memory Management

#### Optimizing Audio Files
- **Compress MIDI data** where possible
- **Reuse instrument samples** across songs
- **Limit simultaneous audio streams**
- **Consider ROM space constraints**

#### Preloading Audio
Preload important audio files:

```c
void PreloadCriticalAudio(void)
{
    // Preload frequently used sound effects
    LoadSoundEffect(SE_SELECT);
    LoadSoundEffect(SE_MENU_OPEN);
    
    // Preload battle music
    LoadBGM(MUS_TRAINER_BATTLE);
}
```

## Troubleshooting

### Common Issues

**MIDI not playing:**
- Check MIDI file format and compatibility
- Verify instruments use General MIDI set
- Ensure file is properly included in build
- Check for MIDI corruption or errors

**Audio quality problems:**
- Adjust MIDI parameters in build rules
- Check sample rates for direct sound
- Verify instrument mappings
- Test on actual hardware if possible

**Build errors:**
- Ensure MIDI files are valid format
- Check file paths and names match exactly
- Verify build dependencies are correct
- Look for conflicting audio constants

**Memory issues:**
- Reduce audio file sizes
- Limit simultaneous audio streams
- Optimize instrument usage
- Monitor ROM space usage

### Debug Tips

1. **Test audio incrementally** - Add one song at a time
2. **Use simple MIDI files** first to verify system works
3. **Check audio constants** for conflicts or typos
4. **Monitor build output** for audio conversion errors
5. **Test on emulator and hardware** for compatibility

### Performance Optimization

#### Audio File Size
- Keep MIDI files under 50KB when possible
- Use efficient instrument selections
- Optimize note density and complexity
- Consider compressed audio formats

#### Runtime Performance
- Limit simultaneous sound effects
- Use audio streaming for long tracks
- Preload critical audio assets
- Monitor CPU usage during audio playback

## Related Tutorials

- [How to Change the Intro](how_to_change_intro.md) - Adding custom intro music
- [How to Add Maps](how_to_add_maps.md) - Setting map background music
- [How to Add Trainers](how_to_add_trainers.md) - Custom battle music
- [Audio System Reference](audio_system_reference.md) - Technical audio details

---

*Great music can transform a good ROM hack into an unforgettable experience. Choose tracks that complement your world and enhance the player's emotional journey!*