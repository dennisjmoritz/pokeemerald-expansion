# How to Change the Intro

This tutorial will guide you through customizing the game's opening sequence in your pokeemerald-expansion ROM hack. The intro sequence consists of multiple scenes that can be modified or replaced to create a unique opening experience for your game.

## Content
* [Quick Summary](#quick-summary)
* [Understanding the Intro System](#understanding-the-intro-system)
* [Intro Scene Structure](#intro-scene-structure)
* [Customizing Existing Scenes](#customizing-existing-scenes)
  * [1. Copyright Screen](#1-copyright-screen)
  * [2. Game Freak Logo Scene](#2-game-freak-logo-scene)
  * [3. Player Biking Scene](#3-player-biking-scene)
  * [4. Legendary Battle Scene](#4-legendary-battle-scene)
* [Adding New Scenes](#adding-new-scenes)
* [Graphics and Assets](#graphics-and-assets)
* [Troubleshooting](#troubleshooting)

## Quick Summary

If you've done this before and just need a quick reference:

1. Edit graphics in `graphics/intro_scene/` folder
2. Modify intro code in `src/intro.c`
3. Update expansion intro features in `src/expansion_intro.c`
4. Replace music in intro sequences
5. Test and adjust timing
6. Build and verify changes

## Understanding the Intro System

The pokeemerald-expansion intro system is built around multiple scenes that play in sequence:

- **Scene 0**: Copyright screen
- **Scene 1**: Game Freak logo with nature scene and Flygon silhouette
- **Scene 2**: Player biking with Pokémon companions
- **Scene 3**: Legendary Pokémon battle (Groudon/Kyogre/Rayquaza)

Each scene is controlled by tasks and functions in `src/intro.c` and can be customized independently.

## Intro Scene Structure

### File Organization
```
src/
├── intro.c                    # Main intro logic
├── expansion_intro.c          # Additional expansion features
└── intro_credits_graphics.c   # Graphics loading functions

graphics/intro_scene/
├── copyright_screen.png       # Copyright screen background
├── gamefreak_logo.png        # Game Freak logo graphics
├── nature_scene.png          # Background nature scene
└── legendary_battle.png      # Legendary battle graphics
```

### Scene Flow
1. **Initialization**: Set up graphics and sound systems
2. **Scene progression**: Each scene has enter, update, and exit functions
3. **Transition handling**: Smooth fades and effects between scenes
4. **Cleanup**: Prepare for title screen

## Customizing Existing Scenes

### 1. Copyright Screen

The copyright screen is the first thing players see. To customize it:

#### Changing the Background
Replace `graphics/intro_scene/copyright_screen.png` with your custom image:
- **Dimensions**: 240x160 pixels (GBA screen resolution)
- **Colors**: 16-color palette maximum
- **Format**: PNG, will be converted during build

#### Modifying Copyright Text
Edit the text strings in `src/intro.c`:

```c
// Find the copyright text definitions
static const u8 sCopyrightText[] = _("© 2023 YOUR HACK NAME");
static const u8 sGameFreakText[] = _("YOUR TEAM NAME");
```

#### Changing Display Duration
Adjust the timer in the copyright screen task:

```c
// In Task_Scene0_Copyright function
if (++data[0] > 180)  // Change 180 to adjust duration (60 = 1 second)
{
    // Proceed to next scene
}
```

### 2. Game Freak Logo Scene

This scene features the Game Freak logo with animated elements.

#### Replacing the Logo
Create your custom logo graphics:
- **Main logo**: 64x64 pixels maximum
- **Background**: 240x160 pixels
- **Animated elements**: Multiple frames if needed

Replace graphics in `graphics/intro_scene/gamefreak_logo.png`.

#### Customizing Animation
Modify the logo animation in `src/intro.c`:

```c
// Find Task_Scene1_FadeIn and related functions
static void Task_Scene1_FadeIn(u8 taskId)
{
    // Customize fade timing and effects
    s16 *data = gTasks[taskId].data;
    
    if (++data[0] > 30)  // Adjust fade in speed
    {
        // Your custom animation logic
        BlendPalettes(0xFFFFFFFF, 16 - data[1], RGB_BLACK);
    }
}
```

#### Adding Custom Elements
Add new sprites or effects:

```c
// Create custom sprites
u8 spriteId = CreateSprite(&sYourCustomSprite, x, y, priority);
gSprites[spriteId].callback = YourCustomAnimationCallback;
```

### 3. Player Biking Scene

Shows the player character biking with Pokémon companions.

#### Changing the Player Sprite
Replace the player biking graphics:
- Edit `graphics/intro_scene/player_biking.png`
- Adjust sprite frames for animation
- Update palette if needed

#### Modifying Companion Pokémon
Change which Pokémon appear with the player:

```c
// In the biking scene setup
static const u16 sBikingPokemon[] = 
{
    SPECIES_YOUR_POKEMON_1,
    SPECIES_YOUR_POKEMON_2,
    SPECIES_YOUR_POKEMON_3,
};
```

#### Background Customization
Replace the scrolling background:
- Edit `graphics/intro_scene/biking_background.png`
- Ensure it's seamless for scrolling
- Consider parallax layers for depth

### 4. Legendary Battle Scene

The climactic battle scene between legendary Pokémon.

#### Changing the Legendaries
Replace Groudon, Kyogre, and Rayquaza with your own legendary Pokémon:

```c
// In the battle scene setup
#define INTRO_LEGENDARY_1 SPECIES_YOUR_LEGENDARY_1
#define INTRO_LEGENDARY_2 SPECIES_YOUR_LEGENDARY_2  
#define INTRO_LEGENDARY_3 SPECIES_YOUR_LEGENDARY_3
```

#### Custom Battle Graphics
Replace the battle graphics:
- **Background**: Epic battle scene backdrop
- **Effect sprites**: Energy blasts, environmental effects
- **Pokémon sprites**: Use front sprites from your custom legendaries

#### Battle Animation
Customize the battle sequence:

```c
static void Task_Scene3_LegendaryBattle(u8 taskId)
{
    // Your custom battle choreography
    switch (gTasks[taskId].data[0])
    {
        case 0: // Initial setup
            LoadYourBattleGraphics();
            break;
        case 1: // First legendary appears
            CreateLegendarySprite(INTRO_LEGENDARY_1, x1, y1);
            break;
        // Add more battle phases
    }
}
```

## Adding New Scenes

To add completely new scenes to the intro:

### 1. Define New Scene Task

```c
static void Task_YourNewScene(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    switch (data[0])
    {
        case 0: // Scene initialization
            LoadYourSceneGraphics();
            PlayBGM(MUS_YOUR_SCENE_MUSIC);
            data[0]++;
            break;
            
        case 1: // Scene content
            // Your scene logic here
            if (data[1]++ > YOUR_SCENE_DURATION)
            {
                data[0]++;
            }
            break;
            
        case 2: // Scene cleanup
            FadeToNextScene();
            data[0]++;
            break;
            
        case 3: // Transition to next scene
            if (IsTransitionComplete())
            {
                DestroyTask(taskId);
                CreateTask(Task_NextScene, 0);
            }
            break;
    }
}
```

### 2. Insert Scene into Sequence

Add your scene to the intro sequence:

```c
// In the main intro progression
void StartIntroSequence(void)
{
    // Existing scenes...
    CreateTask(Task_Scene2_PlayerBiking, 0);
    CreateTask(Task_YourNewScene, 0);      // Insert here
    CreateTask(Task_Scene3_LegendaryBattle, 0);
}
```

### 3. Create Scene Graphics

Prepare your scene assets:
- Background images
- Sprite graphics
- Animation frames
- Sound effects

## Graphics and Assets

### Graphics Requirements

#### Backgrounds
- **Resolution**: 240x160 pixels
- **Color depth**: 4bpp (16 colors) or 8bpp (256 colors)
- **Format**: PNG (converted during build)

#### Sprites
- **Maximum size**: 64x64 pixels per sprite
- **Animation frames**: Multiple 64x64 frames for animation
- **Palettes**: Shared palettes to save memory

### Audio Integration

#### Background Music
Add intro-specific music tracks:

```c
// In your scene task
PlayBGM(MUS_YOUR_INTRO_THEME);
```

Define new music constants in `include/constants/songs.h`:

```c
#define MUS_YOUR_INTRO_THEME    500  // Use available number
```

#### Sound Effects
Add dramatic sound effects:

```c
// During scene events
PlaySE(SE_YOUR_DRAMATIC_SOUND);
```

### Memory Management

The intro runs in limited memory, so optimize your assets:

- **Compress graphics** where possible
- **Reuse palettes** between sprites
- **Limit simultaneous sprites** on screen
- **Free resources** when scenes end

## Troubleshooting

### Common Issues

**Graphics not appearing:**
- Check file paths and names match exactly
- Verify graphics dimensions are correct
- Ensure palettes don't exceed color limits
- Check that graphics are properly included in build

**Scene transitions broken:**
- Verify task destruction and creation sequence
- Check fade timing and completion detection
- Ensure proper cleanup of graphics resources

**Audio problems:**
- Check music file format and conversion
- Verify sound effect IDs are correct
- Ensure audio resources are loaded properly

**Performance issues:**
- Reduce sprite count on screen
- Optimize graphics compression
- Check for memory leaks in scene cleanup

### Debug Tips

1. **Use debug prints** to track scene progression:
```c
#ifdef DEBUG
    ConsolePrint("Intro Scene: %d, Phase: %d", sceneId, phase);
#endif
```

2. **Test individual scenes** by jumping directly to them

3. **Monitor memory usage** during intro playback

4. **Check timing** - intro should flow smoothly without pauses

### Performance Optimization

- **Preload critical graphics** before scenes need them
- **Use sprite pools** to avoid repeated allocation
- **Compress large backgrounds** to save ROM space
- **Optimize animation frame counts**

## Related Tutorials

- [How to Add Music](how_to_add_music.md) - Adding custom audio tracks
- [Graphics System](graphics_system.md) - Understanding game graphics
- [Animation System](animation_system.md) - Creating smooth animations
- [How to Change Character Creation](how_to_change_character_creation.md) - Customizing player setup

---

*A great intro sets the tone for your entire ROM hack. Make it memorable!*