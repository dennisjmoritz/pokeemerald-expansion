#include "global.h"
#include "test_runner.h"
#include "secret_base.h"
#include "constants/secret_bases.h"

// Test the apartment pricing functionality
SINGLE_BATTLE_TEST("Apartment pricing varies by location type")
{
    GIVEN {
        // Test cave locations (premium pricing)
        u32 redCave1Price = GetApartmentPrice(SECRET_BASE_RED_CAVE1_1);
        u32 blueCave1Price = GetApartmentPrice(SECRET_BASE_BLUE_CAVE1_1);
        u32 brownCave1Price = GetApartmentPrice(SECRET_BASE_BROWN_CAVE1_1);
        u32 yellowCave1Price = GetApartmentPrice(SECRET_BASE_YELLOW_CAVE1_1);
        
        // Test tree locations (mid-tier pricing)
        u32 tree1Price = GetApartmentPrice(SECRET_BASE_TREE1_1);
        u32 tree2Price = GetApartmentPrice(SECRET_BASE_TREE2_1);
        
        // Test shrub locations (budget pricing)
        u32 shrub1Price = GetApartmentPrice(SECRET_BASE_SHRUB1_1);
        u32 shrub2Price = GetApartmentPrice(SECRET_BASE_SHRUB2_1);
        
        // Verify pricing tiers are correct
        EXPECT_EQ(redCave1Price, APARTMENT_PRICE_RED_CAVE1);
        EXPECT_EQ(blueCave1Price, APARTMENT_PRICE_BLUE_CAVE1);
        EXPECT_EQ(brownCave1Price, APARTMENT_PRICE_BROWN_CAVE1);
        EXPECT_EQ(yellowCave1Price, APARTMENT_PRICE_YELLOW_CAVE1);
        
        EXPECT_EQ(tree1Price, APARTMENT_PRICE_TREE1);
        EXPECT_EQ(tree2Price, APARTMENT_PRICE_TREE2);
        
        EXPECT_EQ(shrub1Price, APARTMENT_PRICE_SHRUB1);
        EXPECT_EQ(shrub2Price, APARTMENT_PRICE_SHRUB2);
        
        // Verify pricing hierarchy: caves > trees > shrubs
        EXPECT_GT(redCave1Price, tree1Price);
        EXPECT_GT(tree1Price, shrub1Price);
        EXPECT_GT(blueCave1Price, tree2Price);
        EXPECT_GT(tree2Price, shrub2Price);
        
        // Verify all prices are reasonable (between 500-2500)
        EXPECT_GE(redCave1Price, 500);
        EXPECT_LE(redCave1Price, 2500);
        EXPECT_GE(shrub1Price, 500);
        EXPECT_LE(shrub1Price, 2500);
    }
}

SINGLE_BATTLE_TEST("Apartment pricing fallback for invalid location")
{
    GIVEN {
        // Test with invalid location ID (should return default 1000)
        u32 invalidPrice = GetApartmentPrice(999);
        EXPECT_EQ(invalidPrice, 1000);
    }
}