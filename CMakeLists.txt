cmake_minimum_required(VERSION 3.2)
project(RPGTests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

# for debugging
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${LIBRARY_OUTPUT_PATH})

add_subdirectory(googletest)

# # MAIN GAME EXECUTABLE
add_executable(mainGame

  # Runner
  src/main.cpp

  # Game Classes
  src/GameController.cpp
  src/Game.cpp

  # Item Classes
  src/Item.cpp

  src/HealthPotion.cpp

  src/weaponClassesSrc/Weapon.cpp
  src/weaponClassesSrc/Bow.cpp
  src/weaponClassesSrc/Dagger.cpp
  src/weaponClassesSrc/Sceptre.cpp
  src/weaponClassesSrc/Sword.cpp

  src/armorClassesSrc/Armor.cpp
  src/armorClassesSrc/HeavyArmor.cpp
  src/armorClassesSrc/LightArmor.cpp
  
  # Town and Npc Classes
  src/Town.cpp

  src/Npc.cpp

  src/Chemist.cpp
  src/Weaponsmith.cpp
  src/ArmorSmith.cpp

  # Character Classes

  src/Character.cpp
  src/Enemy.cpp
  src/Hero.cpp

)

# Katswato executables
add_executable(testItem
    src/Item.cpp
    tests/testItem.cpp
)

add_executable(testHealthPotion
    src/HealthPotion.cpp
    tests/testHealthPotion.cpp
    src/Item.cpp
)

add_executable(testWeapon
    src/weaponClassesSrc/Weapon.cpp
    tests/weaponClassesTests/testWeapon.cpp
    src/Item.cpp
)

add_executable(testWeaponSubclasses
    src/weaponClassesSrc/Bow.cpp
    src/weaponClassesSrc/Dagger.cpp
    src/weaponClassesSrc/Sceptre.cpp
    src/weaponClassesSrc/Sword.cpp

    src/weaponClassesSrc/Weapon.cpp
    src/Item.cpp

    tests/weaponClassesTests/testBow.cpp
    tests/weaponClassesTests/testDagger.cpp
    tests/weaponClassesTests/testSceptre.cpp
    tests/weaponClassesTests/testSword.cpp
)
    
add_executable(testArmor
    src/armorClassesSrc/Armor.cpp
    tests/armorClassesTests/testArmor.cpp
    src/Item.cpp
)

add_executable(testArmorSubclasses
    src/armorClassesSrc/Armor.cpp
    src/armorClassesSrc/HeavyArmor.cpp
    src/armorClassesSrc/LightArmor.cpp
    
    tests/armorClassesTests/testLightArmor.cpp
    tests/armorClassesTests/testHeavyArmor.cpp
    src/Item.cpp
)

add_executable(testTown
    src/Item.cpp
    src/Npc.cpp
    
    src/Weaponsmith.cpp
    src/weaponClassesSrc/Bow.cpp
    src/weaponClassesSrc/Dagger.cpp
    src/weaponClassesSrc/Sceptre.cpp
    src/weaponClassesSrc/Sword.cpp
    src/weaponClassesSrc/Weapon.cpp

    src/Chemist.cpp
    src/HealthPotion.cpp

    src/ArmorSmith.cpp
    src/armorClassesSrc/Armor.cpp
    src/armorClassesSrc/LightArmor.cpp
    src/armorClassesSrc/HeavyArmor.cpp

    src/Town.cpp

    tests/testTown.cpp
)

# # Lester executables

add_executable(testArmorsmith
  src/Item.cpp
  src/Npc.cpp
  src/armorClassesSrc/Armor.cpp
  src/armorClassesSrc/LightArmor.cpp
  src/armorClassesSrc/HeavyArmor.cpp
  src/ArmorSmith.cpp
  tests/testArmorsmith.cpp
)

add_executable(testChemist
  src/Item.cpp
  src/Npc.cpp
  src/HealthPotion.cpp
  src/Chemist.cpp
  tests/testChemist.cpp
)

# oscargzman executables
add_executable(testGame
  src/Game.cpp
  tests/testArmorsmith.cpp 

    # Game Classes
    src/GameController.cpp
    src/Game.cpp
  
    # Item Classes
    src/Item.cpp
  
    src/HealthPotion.cpp
  
    src/weaponClassesSrc/Weapon.cpp
    src/weaponClassesSrc/Bow.cpp
    src/weaponClassesSrc/Dagger.cpp
    src/weaponClassesSrc/Sceptre.cpp
    src/weaponClassesSrc/Sword.cpp
  
    src/armorClassesSrc/Armor.cpp
    src/armorClassesSrc/HeavyArmor.cpp
    src/armorClassesSrc/LightArmor.cpp
    
    # Town and Npc Classes
    src/Town.cpp
  
    src/Npc.cpp
  
    src/Chemist.cpp
    src/Weaponsmith.cpp
    src/ArmorSmith.cpp
  
    # Character Classes
  
    src/Character.cpp
    src/Enemy.cpp
    src/Hero.cpp
)

add_executable(testGameController
  src/GameController.cpp
  src/Game.cpp 
  tests/testGameController.cpp

  # Game Classes
  src/GameController.cpp
  src/Game.cpp

  # Item Classes
  src/Item.cpp

  src/HealthPotion.cpp

  src/weaponClassesSrc/Weapon.cpp
  src/weaponClassesSrc/Bow.cpp
  src/weaponClassesSrc/Dagger.cpp
  src/weaponClassesSrc/Sceptre.cpp
  src/weaponClassesSrc/Sword.cpp

  src/armorClassesSrc/Armor.cpp
  src/armorClassesSrc/HeavyArmor.cpp
  src/armorClassesSrc/LightArmor.cpp
  
  # Town and Npc Classes
  src/Town.cpp

  src/Npc.cpp

  src/Chemist.cpp
  src/Weaponsmith.cpp
  src/ArmorSmith.cpp

  # Character Classes

  src/Character.cpp
  src/Enemy.cpp
  src/Hero.cpp
)

add_executable(testHero
  src/Hero.cpp 
  src/Character.cpp
  tests/testHero.cpp
)

# Devin executables

add_executable(testNpc
  src/Item.cpp
  src/Npc.cpp
  tests/testNpc.cpp
  src/weaponClassesSrc/Bow.cpp
  src/weaponClassesSrc/Weapon.cpp
)

 add_executable(testWeaponsmith
   src/Npc.cpp
   src/Item.cpp
   src/Weaponsmith.cpp
   src/weaponClassesSrc/Bow.cpp
   src/weaponClassesSrc/Dagger.cpp
   src/weaponClassesSrc/Sceptre.cpp
   src/weaponClassesSrc/Sword.cpp
   src/weaponClassesSrc/Weapon.cpp
   tests/testWeaponsmith.cpp
)

# Tanishaa executables

add_executable(testEnemy
    src/Enemy.cpp
    src/Hero.cpp
    src/Character.cpp
    tests/testEnemy.cpp
)

# MAIN GAME LINKED
target_link_libraries(mainGame gmock gtest gtest_main)

# Katswato Linked
target_link_libraries(testItem gmock gtest gtest_main)
target_link_libraries(testHealthPotion gmock gtest gtest_main)
target_link_libraries(testWeapon gmock gtest gtest_main)
target_link_libraries(testWeaponSubclasses gmock gtest gtest_main)
target_link_libraries(testArmor gmock gtest gtest_main)
target_link_libraries(testArmorSubclasses gmock gtest gtest_main)
target_link_libraries(testTown gmock gtest gtest_main)

# Lester Linked
target_link_libraries(testArmorsmith gmock gtest gtest_main)
target_link_libraries(testChemist gmock gtest gtest_main)

# Oscar Linked
target_link_libraries(testGame gmock gtest gtest_main)
target_link_libraries(testGameController gmock gtest gtest_main)
target_link_libraries(testHero gmock gtest gtest_main)

# Devin Linked
target_link_libraries(testNpc gmock gtest gtest_main)
target_link_libraries(testWeaponsmith gmock gtest gtest_main)

# Tanishaa Linked 
target_link_libraries(testEnemy gmock gtest gtest_main)