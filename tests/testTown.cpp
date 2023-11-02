#include "../header/Town.h"
#include "../header/Npc.h"
#include "../header/Weaponsmith.h"
#include "../header/Chemist.h"
#include "../header/ArmorSmith.h"

#include "gtest/gtest.h"

using ::NPC;
using ::Weaponsmith;
using ::Chemist;
using ::Armorsmith;

//Constructors
TEST(TownConstructors, testTownBasicConstructor)
{
    Town *town = new Town();
    EXPECT_EQ(town -> getTownName(), "");
}

TEST(TownConstructors, testTownParameterConstructor)
{
    Town *town = new Town("Among Us");
    EXPECT_EQ(town -> getTownName(), "Among Us");
}

//Accessors
TEST(TownAccessors, testTownGetTownName)
{
    Town *town = new Town("Among Us");
    EXPECT_EQ(town -> getTownName(), "Among Us");
}

TEST(TownAccessors, testTownGetTownName2)
{
    Town *town = new Town("Imposter");
    EXPECT_EQ(town -> getTownName(), "Imposter");
}

TEST(TownAccessors, testTownGetTownMembers)
{
    Town *town = new Town("Wait what?");

    NPC* member1 = new Chemist("Chemist");
    NPC* member2 = new Weaponsmith("Weaponsmith");
    NPC* member3 = new Armorsmith("Armorsmith");

    EXPECT_EQ(town -> getTownMember(0) -> getnonplayableName(), member1 -> getnonplayableName());
    EXPECT_EQ(town -> getTownMember(1) -> getnonplayableName(), member2 -> getnonplayableName());
    EXPECT_EQ(town -> getTownMember(2) -> getnonplayableName(), member3 -> getnonplayableName());
}