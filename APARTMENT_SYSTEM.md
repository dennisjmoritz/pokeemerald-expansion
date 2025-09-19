# Apartment System (Secret Base Transformation)

This modification transforms the Pokemon Emerald secret base system from using the Secret Power move to using an Apartment Key item, making it more suitable for town-based apartments rather than wilderness secret bases.

## Key Changes

### 1. Item System
- **New Item**: `ITEM_APARTMENT_KEY` (ID 829)
- **Type**: Key Item (stored in Key Items pocket)
- **Usage**: Can be used from bag to set up apartments at secret base locations

### 2. Variable Pricing System
- **Location-Based Pricing**: Different apartment locations have different setup costs
- **Pricing Tiers**: 
  - Cave locations: ¥1300-2000 (premium)
  - Tree locations: ¥1000-1300 (mid-tier)
  - Shrub locations: ¥600-900 (budget)
- **Dynamic Display**: Price is shown when registering an apartment

### 3. Interaction Changes
- **Before**: Required Secret Power move in party + field move selection
- **After**: Simply press A near secret base spots with Apartment Key in bag, OR use Apartment Key from bag

### 4. Text Updates
- "SECRET BASE" → "APARTMENT"
- "SECRET POWER" → "APARTMENT KEY"
- Updated flavor text to be more town/apartment appropriate
- Dynamic pricing display based on location

### 5. Functionality Preserved
- All existing secret base locations still work
- Decoration system unchanged
- PC functionality unchanged
- Registry system unchanged
- Base layouts and maps unchanged

## How to Use

1. **Get the Apartment Key**: Use the test script `ApartmentKeyGiver_EventScript_GiveKey` or add it to your game through other means
2. **Find a Location**: Go to any existing secret base spot (caves, trees, shrubs)
3. **Set Up Apartment**: Either press A while facing the spot (with key in bag) or use the Apartment Key from your bag
4. **Enjoy**: The apartment functions exactly like the old secret base system

## Testing

To test this system:
1. Give player the apartment key using the provided test script
2. Go to any secret base location
3. Try both interaction methods:
   - Press A while facing the spot
   - Use Apartment Key from bag while facing the spot

## Technical Details

### Files Modified
- `include/constants/items.h` - Apartment key definition
- `src/data/items.h` - Apartment key properties  
- `include/item_use.h`, `src/item_use.c` - Field use function
- `data/scripts/secret_base.inc` - Main interaction scripts
- `data/scripts/shared_secret_base.inc` - Creation text
- `src/fldeff_misc.c` - Field interaction system
- `data/scripts/apartment_key_giver.inc` - Test script

### Key Functions
- `ItemUseOutOfBattle_ApartmentKey()` - Handles apartment key usage from bag
- `SetUpFieldMove_SecretPower()` - Modified to check for apartment key
- `SecretBase_EventScript_CheckEntrance` - Updated to use `checkitem` instead of `checkfieldmove`

## Compatibility

This system maintains full backward compatibility with existing secret base data and saves. Existing secret bases will continue to work normally, they just become "apartments" with the new terminology.