#ifndef GUARD_CONSTANTS_SECRET_BASES_H
#define GUARD_CONSTANTS_SECRET_BASES_H

#define SECRET_BASE_APARTMENT 1
#define SECRET_BASE_HOUSE 5
#define SECRET_BASE_MANSION 6

// Each secret base location is assigned an identifier value.
// The secret base's map is determined by (id / 10). The ones
// digit is used to differentiate secret bases using the same map.
// Therefore, each secret base map can be used by up to 10 different
// secret bases in the game.

// * 4 is for each byte of data per secret base group in sSecretBaseEntrancePositions
// They are the map number, the entrance warp id, and the x/y position in front of the computer
#define SECRET_BASE_GROUP(idx) ((idx) * 4)
#define SECRET_BASE_ID_TO_GROUP(baseId) SECRET_BASE_GROUP((baseId) / 10)

#define SECRET_BASE_APARTMENT1_1     1
#define SECRET_BASE_APARTMENT1_2     2
#define SECRET_BASE_APARTMENT1_3     3

#define SECRET_BASE_APARTMENT1 SECRET_BASE_GROUP(0)

#define SECRET_BASE_HOUSE1_1         11
#define SECRET_BASE_HOUSE1_2         12
#define SECRET_BASE_HOUSE1_3         13
#define SECRET_BASE_HOUSE1_4         14

#define SECRET_BASE_HOUSE1 SECRET_BASE_GROUP(1)

#define SECRET_BASE_MANSION1_1        21
#define SECRET_BASE_MANSION1_2        22
#define SECRET_BASE_MANSION1_3        23
#define SECRET_BASE_MANSION1_4        24

#define SECRET_BASE_MANSION1 SECRET_BASE_GROUP(2)

#define NUM_SECRET_BASE_GROUPS 3

#endif  // GUARD_CONSTANTS_SECRET_BASES_H
