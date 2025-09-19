# Variable Apartment Pricing System

This document describes the implementation of variable pricing for apartment locations in the Pokemon Emerald Expansion apartment system.

## Overview

The apartment system (formerly secret base system) now uses location-based pricing instead of a fixed cost of ¥1000. Different apartment locations have different prices based on their type and desirability.

## Pricing Structure

### Cave Locations (Premium Tier)
These are the most expensive locations, representing premium underground apartments:

**Red Caves** (¥1700-2000):
- Red Cave 1: ¥2000
- Red Cave 2: ¥1800  
- Red Cave 3: ¥1900
- Red Cave 4: ¥1700

**Blue Caves** (¥1600-1900):
- Blue Cave 1: ¥1800
- Blue Cave 2: ¥1600
- Blue Cave 3: ¥1900
- Blue Cave 4: ¥1750

**Brown Caves** (¥1400-1700):
- Brown Cave 1: ¥1600
- Brown Cave 2: ¥1500
- Brown Cave 3: ¥1700
- Brown Cave 4: ¥1400

**Yellow Caves** (¥1300-1600):
- Yellow Cave 1: ¥1500
- Yellow Cave 2: ¥1300
- Yellow Cave 3: ¥1600
- Yellow Cave 4: ¥1400

### Tree Locations (Mid-Tier)
These represent tree-house style apartments (¥1000-1300):
- Tree 1: ¥1200
- Tree 2: ¥1100
- Tree 3: ¥1300
- Tree 4: ¥1000

### Shrub Locations (Budget Tier)
These are the most affordable apartment locations (¥600-900):
- Shrub 1: ¥800
- Shrub 2: ¥700
- Shrub 3: ¥900
- Shrub 4: ¥600

## Technical Implementation

### Core Functions

1. **`GetApartmentPrice(u8 secretBaseId)`** in `src/secret_base.c`
   - Takes a secret base ID and returns the appropriate price
   - Uses the base group to determine pricing tier
   - Returns 1000 as fallback for unknown locations

2. **`GetCurrentApartmentPrice()`** in `src/field_specials.c`
   - Script special function that gets the current apartment price
   - Uses `VAR_CURRENT_SECRET_BASE` to determine the location
   - Sets `gSpecialVar_Result` to the calculated price

### Script Integration

The registration script in `data/scripts/shared_secret_base.inc` has been updated to:
1. Call `GetCurrentApartmentPrice` to get the location-specific price
2. Store the price in `VAR_0x8005` for money operations
3. Format the price in `STR_VAR_2` for display in text

### Text Updates

All registration-related text strings now use `{STR_VAR_2}` to display the dynamic price:
- Registration confirmation dialog
- Cost warning message  
- Insufficient funds message

## Usage

When a player tries to set up an apartment at a location:
1. The system determines the location type and specific ID
2. Calculates the appropriate price based on the pricing table
3. Displays the location-specific price to the player
4. Processes payment using the calculated amount

## Benefits

- **Gameplay Balance**: Different price tiers create meaningful choices
- **Location Value**: Premium locations feel more exclusive  
- **Progression System**: Players can start with budget locations and upgrade
- **Immersion**: Pricing reflects location desirability realistically