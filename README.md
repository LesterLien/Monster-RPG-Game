# Text-Based RPG

 > Authors: [Oscar Guzman](https://github.com/oscargzman), [Raffe Manzanilla](https://github.com/Katswato), [Lester Lien](https://github.com/LesterLien), [Devin Felix](https://github.com/DvnFx), [Tanishaa Singh](https://github.com/tanishaasingh)

## Project Description

 > NOTE: Project Description was worked on by all group members in a google doc.
 >
 > Our group thinks it is interesting to make a video game because we are all gamers :). Text-based RPGs have intriguing aspects to them such as the storyline, battle systems, and item management. Additionally, RPGS allows the players to fully immerse themselves into the game which allows for creativity and teamwork. 
 >
 > The language we are going to use is C++; this is the language we’re familiar with. Tools we plan to use are vscode and the existing extensions we’ve downloaded for vscode. We also plan to use external resources from educational documents, websites, and media; we will not plagiarize. If we find ourselves in deep struggle with the construction of our project, we’ll consult each other and look for TA’s and professors for assistance.
 >
 > Being a text-based RPG, our project will be using text-based input through the use of letters. There will be a prompt that shows the available options the player has. For example:
 >
 >      Type “a” to attack. Type “b” to use an item.
 >
 > The output of these actions will be prompts describing what happened in the battle and details listing the events that occurred to each player and monster. For example:
 >
 >      Player1 has used “health potion.” Player1 gained 50 health.
 >
 >      Or
 >
 >      MonsterA took 50 damage. MonsterB took 40 damage.
 >      Monster B has died.
 >
 > If the user enters anything that doesn’t fit within the game’s protocols, the user will simply be asked to reinput.
 >
 > The project will feature a storyline: the player will have the ability to select and replay missions, have the ability to make decisions with who you encounter, and exchange dialogue with those npcs. Throughout the story, the player will face a diverse amount of enemies including one unique boss monster and will earn different drops/experience depending on the enemy faced.. The project will also support a home area: a town where the player has the ability to buy/sell items with the various merchants located there. In regards to who the player is, they can choose between 4 different classes: Brawler, Mage, Assassin, or Hunter. They will have the ability to customize their weapon and armor types.
 >
 > Here's a more in-depth list detailing the features:
 >
 > Storyline
 > * Mission Select 
 > * Dialogue
 > * Ability to replay missions 
 >
 > Town (Home Area) : like you can go to different places here and talk to different npcs 
 > * Ability to buy/sell/use items 
 > * Currency
 > * Different types of npc (Blacksmith, quests, food, merchant, etc..)
 >
 > Character 
 > * 4 amount of classes to choose from: Knight, Mage, Assassin, Hunter
 > * Different types of weapons:
 > * Gear Types: Light Armor, Heavy Armor, Enchanted Armor
 > * Different kinds of stats like: HP, ATK DMG, REGEN, CRIT, ATTSPD, MVMT SPEED, DEF
 > * Earn exp in battle to upgrade different stats
 >
 > Enemies
 > * 5 types of monsters (bosses/regular monsters) that the character fights
 > * Different kinds of stats with weaknesses and strengths
 > * Drops gear/weapons/gold when slain
 > * Gives exp to the character when slain
 
## Class Diagram
 > UML Class Diagram:
 > ![CS100-UML (1)](https://user-images.githubusercontent.com/114470310/204682133-238e5da9-1703-4bd6-be05-f075ca5e75f6.png)

 > Diagram description:
 >
 > The Text-Based RPG UML diagram depicts four major classes: Game Controller, Character, Item, Scene, and NPC. 
 > 
 > The GameController class is responsible for the logical flow of the RPG. It initializes and outputs the various states of the game, including the character creation, main menu, town menu, level-up menu, and exit menu. It has a private Game member variable which is the object that performs functions for the game to progress through a series of inputs by the player.
 >
 > The Game class is responsible for using the objects of the Character, Town, and NPC to execute the gameplay within various menus in the game. The Game object allows for the creation of these classes.
 >
 > The Character class allows the creation of a character that has a name, a multitude of various stats, and equipment. This Character class contains two variants: Hero or Enemy. The Character class accesses the various stats of a character object, as well as the character’s name.
 >
 > The Hero and Enemy classes are inherited from the Character class. The Hero class is responsible for the player’s side of the game, while the Enemy class is responsible for the AI side, specifically after a battle is initiated. The Hero can choose to attack the enemy, use an item, attempt a block, and attempt a flee. For the Enemy class, the enemy has a rewardDeath function which awards the hero after it has been defeated. The Hero class is used in the creation of the player’s main character and dives into four class variants: Knight, Hunter, Mage, and Assassin. The Enemy class also contains four class variants: Minotaur, Wandering Wolf, Shrieker, and Undead Knight.
 >
 > The Item class is used to create the different kinds of equipment the character can use in order to boost their stats. The item class contains three types: Health Potion, Weapon, and Armor. The Health Potion class allows the creation of items that have the ability to heal the player: meaning that the player’s current health is increased. The Weapon class allows the creation of four sub weapon types: Bow, Dagger, Sceptre, and Sword. These weapons affect the Hero’s ability to do damage and dodge enemy attacks. The Armor class allows the creation of four sub armor types: Light Armor and Heavy Armor. These armor types affect the Hero’s maximum health.
 > 
 > The NPC class is responsible for buying/selling items to the player. The NPC class contains three types: Chemist, Blacksmith, and Armorsmith. The Chemist class allows the player to buy potions. The Blacksmith class allows the character to buy weapons. The Armorsmith allows the character to buy armor. How these items worked is explained in the paragraph above.
 >
 >
 ## Screenshots
 >
 > This is the first scene that appears to the player when you run the game. This is the intro scene.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674629-fe33ebee-beb3-4896-801f-536014efe03c.jpg" width=50% height=50%>
 > 
 > After hitting enter at the intro scene, the player now enters the scene where they get to name thier character.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674634-db93de70-d664-4b13-b669-ffbaa3701016.jpg" width=50% height=50%>
 >
 > After naming their hero, the player now enters the main menu scene where they can make a variety of choices.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674644-e6f0871d-57d8-46c3-9cc0-f188191d521a.jpg" width=50% height=50%>
 >
 > If the player types in 1 and hits enter, they will enter the town where they can choose to visit the various Npcs.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674656-71ab7b80-c1e9-4122-b427-7167b67fbea2.jpg" width=50% height=50%>
 >
 > If the player types 1 and hits enter, they will visit the chemist where they can choose to leave, buy, or sell. This type of menu is available for all Npcs; this includs the Weaponsmith and Armorsmith Npcs.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674663-13f216c8-f970-4c07-ae8d-b8e89d3b56e5.jpg" width=50% height=50%>
 >
 > If the player types 1 and hits enter, they will enter the chemist's shop where they can choose what kind of items they want to buy.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674667-b9506950-0b0c-4533-b11d-3c7df477ae9c.jpg" width=50% height=50%>
 >
 > If the player tries to buy an item without having enough gold, a message will pop up explaining why the player couldn't buy that item.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674670-bc50360c-c782-46d3-9eab-e9bfccf4fb29.jpg" width=50% height=50%>
 >
 > If the player goes for the option where they try to sell an item to the chemist without having any items in their inventory, a message will pop up saying that their inventory is empty.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674680-074551ef-e5dc-4e6a-981f-ca03fb3fd3a9.jpg" width=50% height=50%>
 >
 > If the player chooses to visit the Weaponsmith, this will be shop displayed.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674697-90b4fc7e-c995-44e1-b5f1-0e6c7883e27e.jpg" width=50% height=50%>
 >
 > If the player chooses to visit the Armorsmith, this will be the shop displayed.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674705-de4ce891-e4aa-4ad5-b7d5-1cdad54f4eda.jpg" width=50% height=50%>
 >
 > Going back to the main menu, if the player types 6 and hits enter. They will be able to view their current character's stats.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674713-f3bdd57b-499c-40b9-adc5-b6db7e4eb64b.jpg" width=50% height=50%>
 >
 > Going back to the main menu, if the player types 7 and hits enter,they will be able to view their character's current gear.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204680283-0130a23f-e1c7-431e-86b0-1e2b89bea18d.jpg" width=50% height=50%>
 >
 > Going back to the main menu, if the player types 3 and hits enter, they will be able to attempt to level up. This means that if they have enough experience, they can level up their characters stats.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674739-cd045deb-6dd5-4a80-bd2d-08868a46d247.jpg" width=50% height=50%>
 >
 > Going back to the main menu, if the player types 2 and hits enter, they will be able to enter a battle where they encounter one of the four enemy types in the game.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674749-bd0d5dfb-a4c9-44fc-80ea-f8e99d32e857.jpg" width=50% height=50%>
 >
 > If the player types 0 and chooses to flee, they speed of the player is compared to the speed of the monster. If the speed of the player is equal or greater to the speed of the monster, they will be able to successfuly flee battle.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674756-e43b9e2e-9536-4d05-8c82-4d1931be21ed.jpg" width=50% height=50%>
 >
 > If the player types 1 and chooses to attack, the player and the monster will both deal damage to each other.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674764-427f863f-0634-44ce-868b-3dd4b20cd769.jpg" width=50% height=50%>
 >
 > If the player types 2 and chooses to block, the player will have a 50% chance to block the monster's damage. There is an additional 50% to counter-attack while blocking. In this case the player successfully blocks.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674775-45cec79e-ab14-4be8-97a3-4f3ecb5ef205.jpg" width=50% height=50%>
 >
 > In this case, the player types 2 again and managed to block and counter attack.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674784-a7fa7d54-4c7e-4951-8354-b0990d36d4a6.jpg" width=50% height=50%>
 >
 > In this case, the player types 2 again and failed to block the monster's attack.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674793-a647a6ac-3f9d-4952-a014-cd0931fda103.jpg" width=50% height=50%>
 >
 > If the player doesn't manage to kill the monster and dies. This failed battle scene appears. However, not all is lost. The player will simply regain max health and go back to the main menu will all thier items.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674799-f7f7db6d-48df-4457-acf2-47dc5acd2c3c.jpg" width=50% height=50%>
 >
 > In each battle phase, there is battle text that explains what happed during the game. Here's one example with some "funny" battle text.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674807-de206096-d439-4263-bded-8b56027471b7.jpg" width=50% height=50%>
 >
 > If the player does manage to kill the monster, this successful battle scene appears.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674811-850dff40-3aac-4e13-a14d-66be99e15cb7.jpg" width=50% height=50%>
 >
 > After battling some monsters, the player decides to buy some weapons from the Weaponsmith. The player successfully manages to buy the item. A message pops up explaing that the player has bought the item and shows them their updated inventory.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674826-23a0d2ab-1188-4aae-b5fa-3c3552913eac.jpg" width=50% height=50%>
 >
 > Going back to the main menu, we want to equip the new item we have just bought. If the player inputs 5, types the item slot number the item he wants to equip exists on, he will be able to successfully equip the iten.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674832-f9c8affc-851f-4bf2-9bd1-1acf66b6664f.jpg" width=50% height=50%>
 >
 > To check their new stats, the player goes back to the main menu, enters 6, and hits enter. Here are the player's updated stats after equipping the item.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674845-46451555-d4f5-4791-abd3-ec0adc67cdd5.jpg" width=50% height=50%>
 >
 > Going back to the main menu, the player wants to view their current gear. The player types 7 and hits enter.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674857-acb2e64d-c8f4-4f1e-8bac-9e7d1159fc1b.jpg" width=50% height=50%>
 >
 > Going back to the main menu, the player wants to view their current inventory. The player types 4 and hits enter. We can see that their old weapon equipped is now located in their inventory. They have the option to reequip that item by going back to the menu and using the eqiup item.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674868-cbcba197-eadf-46b7-8b50-9d29d8f5d40d.jpg" width=50% height=50%>
 >
 > After successfully battling enough enemies, the player can choose to level up. This is located in the main menu as option 3. If the player has enough expereince, they will be able to level up with boosted stats.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674881-8c16d777-b7d4-4ba1-a3bc-b51aeb008cb5.jpg" width=50% height=50%>
 >
 > The player decides to enter more battles. When in battle, the player can choose to use items. In this case, the player has taken damage and decides to use the health potion. Upon using the health potion, a message pops up to confirm the player has used the health potion.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674888-bb1dc27a-6d60-47aa-a5d7-38e068840c21.jpg" width=50% height=50%>
 >
 > Besides potions, the player can also choose to equip other items; de-equiping their current weapon/armor depending on the item chosen. In this case, the player chooses to equip their hand.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674912-f93fc793-9cb9-4dbd-9587-c5d5c7445831.jpg" width=50% height=50%>
 >
 > After having a long day playing the game, they player goes back to the main menu. The player then types 0 to enter the exit menu. The player then types 1 to confirm their leaving of the game.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204674928-9dd1226a-5a12-4cb7-b291-6b17c446e135.jpg" width=50% height=50%>
 >
 > Here is our group's valgrind report after running the program.
 >
 > <img src="https://user-images.githubusercontent.com/114470310/204681579-af838089-d9ca-4d3e-afff-2d015faf0ee0.png" width=50% height=50%>
 >
 ## Installation/Usage
 > To download our group’s game, you need to download vscode and set it up to the school’s standards. Afterwards, our group’s repository needs to be cloned into your local repo. You can do this by running the following command:
 >
  > $ git clone --recursive https://github.com/cs100/final-project-oguzm008-rmanz008-llien007-dfeli020.git
 > 
 > Afterwards, enter this cloned repository using the cd command. If you don’t know the directory this repository is in, then run “ls” beforehand while making sure you are in the base repositories, run the following commands.
 >
  > cmake .
  >
  > make 
  >
  > ./bin/mainGame
 >
 > You are now able to run the game.
 >

 ## Testing
 > The source code editor used by all project members is Visual Studio Code. In this IDE application, we used the extensions: C/C++, C/C++ Extension Pack, CMake, CMake Tools, and YAML. These extensions allowed us to have the ability to run a CMake file. This file allowed us to compile and run a large amount of compiled executables. In our program, this file was named “CMakeLists.txt.”
 >
 > Googletest is a unit testing library that allows programmers to write tests that easily compare inputs and outputs. In order to use googletest, our group needed to add the googletest submodule to our repositories. This was done by running the following command:
 >
 > $ git submodule add https://github.com/google/googletest.git
 > 
 > After the installation of the googletest submodule, the CMakeLists.txt file was modified to link the executables files to the gmock, gtest, and gtest_main libraries; this was necessary for the googletest functions to run correctly. 
 > 
 > For each of the classes we created for our program, we constructed groups of tests that would make sure our classes functions ran as expected. The first group of tests would test the classes’ constructors. The second group of tests would test the classes’ accessors. The third group of tests would test the classes’ modifiers. All other tests would come after these three main groups of tests. This would include testing: derived functions, complicated tests, etc.
 >
 > In order for our tests to run properly, the correct library and header files needed to be included. The CMake file had to be tended to frequently in order to make sure we wouldn’t run into a wall of errors.
 >
 > Every time a file was modified, tests were run within our local repositories to ensure that the modification of the file didn’t affect the expected results.

