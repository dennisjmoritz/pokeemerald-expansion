# Mainline Story Minimization TODO

Progress tracker for minimizing story elements while preserving gym mechanics, legendaries, and facilities.

## Initial Setup
- [x] Create state.json and TODO.md tracking files
- [x] Discover maps (init state.json) - 457 maps found
- [x] Parse Key Items - 59 potential key items identified
- [x] Parse proper nouns (FLAG_VISITED constants) - 16 town/city flags
- [x] Build scoring system with story signal detection

## Processing Batches
- [x] Batch 1: process maps [0..24] - AbandonedShip through BattleColosseum (6 files modified)
- [x] Batch 2: process maps [25..49] - BattlePyramid through EverGrandeCity_Hall5 (includes DewfordTown, EverGrandeCity)
- [x] Batch 3: process maps [50..74] - EverGrandeCity_Hall4 through FortreeCity_House1 (includes FallarborTown, FortreeCity)

## Current Status (75/410 maps processed - 18.3% complete)
- Labels: 383 kept, 33 stubbed, 13 review
- National Dex hooks: 6 Pokemon Centers  
- Legendary labels preserved: 1
- Generated validation reports

## Next Steps
- [ ] Continue batch processing to completion
- [ ] Manual review of score==3 labels
- [ ] Final summary and validation