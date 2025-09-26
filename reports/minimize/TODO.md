# Mainline Story Minimization TODO

Progress tracker for minimizing story elements while preserving gym mechanics, legendaries, and facilities.

## Initial Setup
- [x] Create state.json and TODO.md tracking files
- [x] Discover maps (init state.json) - 457 maps found
- [x] Parse Key Items - 59 potential key items identified
- [x] Parse proper nouns (FLAG_VISITED constants) - 16 town/city flags
- [x] Build scoring system with story signal detection

## Processing Batches
- [x] Batch 1: process maps [0..24] - AbandonedShip through BattleColosseum
    - [x] Apply stubs based on story signal scoring
    - [x] Add Fly visit hook (towns) - none in this batch
    - [x] Add National Dex hook (centers) - none in this batch
    - [ ] Prune coord events (qualified)
    - [ ] Update reports
    - [x] Commit batch 1 changes

## Final Tasks  
- [ ] REVIEW items (score==3) list prepared
- [ ] Final reports and summary