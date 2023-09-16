#include "Player.h"
#include "Dragon.h"
#include "Item.h"
#include "Inventory.h"
#include "Enemy.h"
#include <iostream>
#include <time.h>
using namespace std;

//Utility Functions
void startScreen();
string getInput();
bool confirmInput();
Player characterCreation();
Dragon dragonCreation();
vector<Item> createAllItems();
bool predefEvent(int numEvent, Player& player, Enemy& enemy, Inventory& inv, bool& alive, int nRandomEvent);
void enemyBattle(Player player, Enemy enemy, int turn);
void playerDecision(Player player, Enemy enemy);
void dialogues(int numEvent, int counter, int randomNum);
void playerCheck(Player&& player, Inventory&& inv, string c);
//Missing: Inventory, Items, Enemy
//Please do a check on getInput on Profile and Inventory commands from player (ex: if they enter profile, run player.profile)

//Lambda
auto diceRoll = [](int d) {
	//Sides stands for the number of sides on a dice
	srand(time(NULL));
	return rand() % d + 1;
};

auto setLower = [](string str) {
	const int length = str.length() + 1;
	char* char_array = new char[length];
	for (int x = 0; x < length; x++) {
		char_array[x] = tolower(str[x]);
	}
	return char_array;
};

//Main
int main()
{
	//GAME INITIALIZATION
	startScreen();
	system("CLS");
	Inventory playerInv;


	//Player creation
	Player player = characterCreation();
	Dragon dragon = dragonCreation();

	//stats
	int eAtk, eHp;
	int pAtk = player.getStat(1);
	int pHp = player.getStat(0);

	//Lore Variables
	string kingdomName = "Eldoria";
	string kingName = "King Oberon";
	string knightName = "Sir Blackheart";

	//Enemies
	Enemy guard;
	guard.setAtk(30);
	guard.setHP(300);
	Enemy witch;
	witch.setAtk(50);
	witch.setHP(400);
	Enemy rhonda;
	rhonda.setAtk(45);
	rhonda.setHP(500);
	Enemy prince;
	prince.setAtk(40);
	prince.setHP(450);
	Enemy knight;
	knight.setAtk(100);
	knight.setHP(1000);

	//Other Variables
	string opt;
	char enter;
	bool alive = true;
	int eventCounter = 1;
	int nRandomEvent = diceRoll(3);
	//use with getInput(); (like opt = getInput();)



//GAME STORY

	cout << R"("Long long time in the kingdom of )" << kingdomName <<R"(there was a beautiful and happy royal family, but destiny had a different plan for them. )" << endl;
	cout << R"(Short time after the princess )" << player.getName() << R"('s 5th birthday a very rare disease spread in the kingdom, The people who got sick died after a couple of weeks.And to the bad luck of the family, the queen became ill.However, knowing that she was going to leave her only daughter in the hands of her father, she gave him one of her most precious belongings, a dragon egg. )" << endl;
	cout << R"(Shortly after the queen's death, )" << dragon.getName() << R"((the dragon) was born and became the protector and faithful companion of )" <<player.getName() << R"(...")" << endl;
	cout << endl << "(Press “enter” to continue...)";
	cin >> enter;
	system("CLS");
	cout << "10 years later..." << endl;
	cout << endl;
	cout << "It was clear that the " << kingName << "should have been delighted with the gift from his wife, right ? " << endl << "Well...as he observed his beloved daughter growing distant from him, forming an unbreakable bond with this creature, jealousy engulfed him and his resentment spread like wildfire throughout the kingdom, casting a pall of sorrowand anguish over its inhabitants, including the princess." << endl;
	cout << endl << "(Press “enter” to continue...)";
	cin >> enter;

	system("CLS");

	cout << "This is where " << player.getName() << "'s story truly takes flight! In the grip of unfounded jealousy, " << player.getName() << "'s father now seeks " << dragon.getName() << " head, a fate you cannot abide. " << endl;
	cout << "Determined to protect her scaly companion, she makes the bold choice to flee to an abandoned castle nestled deep within the forest—a place she frequented as a child." << endl;
	cout << "But first, a daring escape from the castle must be orchestrated...";
	cout << endl << "(Press “enter” to continue...)";
	cin >> enter;

	system("CLS");

	cout << R"("We need to leave, )" << dragon.getName() << R"(. It's not safe for you to stay here.")" << endl;
	cout << endl;
	cout << "Princess " << player.getName() << " stood up, allowing for her dragon to climb up her arm and onto her shoulder. " << dragon.getName() << " settled comfortably, tail curled up across her back." << endl;
	cout << endl;
	cout << R"(")" << dragon.getName() << R"( we should grab something to eat for later....")" << endl;
	cout << "(Princess picked up a banana.)" << endl;
	cout << dragon.getName() << "'s " << dragon.getEyes() << " eyes shone." << endl;
	cout << R"("No )" << dragon.getName() << R"(I said it is for later.")" << endl;

	cout << endl << "(Press “enter” to continue...)";
	cin >> enter;
	system("CLS");


	while (alive)//Events, enemy points setting and intro to each event.
	{
		if (eventCounter == 1)//Setting enemy Hp and Ap
		{
			cout << "The princess sneaked out of her room and silently crept through the dimly lit corridors. Her heart pounded like a drum as she inched closer to the castle's exit. Freedom was within her grasp. Just a few short meters to go." << endl;
			cout << "But suddenly, as if out of nowhere, a guard appeared before her, blocking her path." << endl;
			cout << "The guard, clad in gleaming armor, towered over the princess and her dragon. He raised an eyebrow, suspicion evident in his eyes." << endl;
			cout << endl;
			cout << R"("Halt! What is the meaning of this?" he demanded, his voice stern.)" << endl;
			cout << endl;
			cout << "The princess exchanged a nervous glance with "<< dragon.getName() <<", their escape plans hanging in the balance.It was a standoff between determinationand duty, and they were about to find out who would prevail." << endl;

			predefEvent(eventCounter, player, guard, playerInv, alive, nRandomEvent);
		}
		else if (eventCounter == 2)//Setting enemy Hp and Ap
		{
			cout << "As Princess "<<player.getName()<<" and her loyal dragon companion continued on the path through the heart of the mysterious forest, the atmosphere was thick with anticipation. The dense foliage cast eerie shadows, and the distant hooting of owls added an air of mystique to their journey. The princess knew that danger lurked around every corner, but her determination to reclaim her kingdom and the memory of her mother's love spurred her forward." << endl;
			cout << endl;
			cout << "Suddenly, as if the forest itself had conjured an unexpected challenge, the duo encountered a presence that sent shivers down their spines. They couldn't quite make out the form or identity of this new adversary, but the air was charged with an undeniable tension." << endl;
			
			
				if (nRandomEvent == 1)
				{
					eHp = witch.getHP();
					eAtk = witch.getAtk();

					cout << "Seconds later an invisible barrier appeared in front of them, stopping them completely. The evil witch, "<< kingName <<"'s personal enchantress, appeared.";
					predefEvent(eventCounter, player, witch, playerInv, alive, nRandomEvent);
				}
				else if (nRandomEvent == 2)
				{
					eHp = rhonda.getHP();
					eAtk = rhonda.getAtk();
					cout << "Seconds later a beautiful female dragon appears out of nowhere and your partner falls in love at first sight, she winks her eye at him, but you notice something strange about that dragon... she emanates some weird and almost invisible magic powder..." << endl;
					cout << "Wait...Could she be... The shapeshifter witch!" << endl;
					predefEvent(eventCounter, player, rhonda, playerInv, alive, nRandomEvent);
				}
				else if (nRandomEvent == 3)
				{
					eHp = prince.getHP();
					eAtk = prince.getAtk();
					cout << "Second later a handsome prince materializes, riding a white horse, and Mary is captivated by her deep, masculine voice and striking blue eyes. He asks her to go with him, assuring her that he will take her to his kingdom and keep her safe." <<endl;
					cout << "However, in the distance you see your father's men hiding in the bushes, waiting for you to pass by to attack.";
					cout << "You try to flee but you can't anymore! You are surrounded, it's time to fight..." << endl;
					predefEvent(eventCounter, player, prince, playerInv, alive, nRandomEvent);
				}
		} 
		else if (eventCounter == 3)//Final Enemy and setting enemy Hp and Ap
		{

			eHp = knight.getHP();
			eAtk = knight.getAtk();

			cout << "In the heart of the dense forest, Princess "<< player.getName() <<" and her loyal dragon companion, "<< dragon.getName() <<", reached the towering castle. ";
			cout << "To their surprise, they found themselves face to face with "<< knightName <<", the formidable right hand of the king."<< endl;
			cout << endl;
			cout << "It was a tense standoff, as " << knightName << " revealed his true intent.";
			cout << "He sought to defeat the dragon and capture the princess, intending to deliver both their heads to the vengeful king.";
			cout << "The looming castle stood as a stark backdrop to the impending battle, with the fate of the kingdom hanging in the balance." << endl;

			predefEvent(eventCounter, player, knight, playerInv, alive, nRandomEvent);
		}
		else //The End
		{
			cout << "With determination burning in her heart, the princess stood her ground, ready to face the imposing knight, Blackheart. Her eyes met his, and for a moment, time seemed to stand still." << endl;
			cout << "The battle that ensued was fierce and unyielding. Sword clashed against sword, and the clash of steel echoed through the night. " << dragon.getName() << " circled overhead, offering support and encouragement." << endl;
			cout << endl;
			cout << "But the princess's resolve was unwavering. With each strike, she chipped away at Blackheart's defenses. Her determination and her bond with her dragon fueled her strength." << endl;
			cout << "In the end, it was her unwavering spirit and her love for her kingdom that led to her victory. Blackheart fell to his knees, defeated." << endl;
			cout << "With the knight vanquished, the princess continued her training in the forest, honing her skills and nurturing her connection with her dragon. She knew that one day, she would return to the kingdom to claim her rightful place as its protector and ruler, ensuring happiness and harmony for all." << endl;
			break;
		}
		eventCounter++;
	}
}



void startScreen()
{
	bool done = false;
	do
	{
		cout << R"( ___              __ _                   ___       _                              
|   \  _ _  __ _ / _` | ___  _ _        | _ \ _ _ (_) _ _   __  ___  ___ ___      
| |) || '_|/ _` |\__. |/ _ \| ' \       |  _/| '_|| || ' \ / _|/ -_)(_-/(_-/      
|___/ |_|  \__/_||___/ \___/|_||_|      |_|  |_|  |_||_||_|\__|\___|/__//__/      
)";
		cout << "-----------------------[ Night of The Great Escape ]-----------------------" << endl;

		cout << endl; //spacing

		//Options
		string opt;
		cout << "========= MENU ==========" << endl;
		cout << "Begin - Starts the game." << endl;
		cout << "Help - Shows how to play." << endl;
		cout << "=========================" << endl;
		cout << endl; //spacing
		cout << "> ";
		cin >> opt;

		if (opt == "Begin" || opt == "begin" || opt == "BEGIN")
		{
			system("CLS");

			cout << "Is this your first time playing? (YES/NO)" << endl;
			cout << "> ";
			cin >> opt;

			if (opt == "yes")
			{
				cout << endl << "===== IMPORTANT =====" << endl;
				cout << "To check your player profile and stats, type PROFILE" << endl;
				cout << "To check your inventory, type INVENTORY" << endl;

				cout << endl;

				cout << "If you understand this, type Understood (needs to be exactly the same): ";
				cin >> opt;
				while (opt != "Understood")
				{
					cout << "Please try again. Type Understood (needs to be exactly the same): ";
					cin >> opt;
				}

				done = true;
			}
			else if (opt == "no")
			{
				done = true;
			}
		}
		else if (opt == "Help" || opt == "help" || opt == "HELP")
		{
			system("CLS");

			cout << "===== GAME DESCRIPTION =====" << endl;
			cout << "This is a text-based adventure game, meaning you will have to type out your actions/responses in order to proceed." << endl;
			cout << "You will be provided decisions emphasized in CAPS which you can type into the input field in order to execute the decision." << endl;
			cout << "Please type in lowercase." << endl;

			cout << endl;

			cout << "===== IMPORTANT =====" << endl;
			cout << "To check your player profile and stats, type PROFILE" << endl;
			cout << "To check your inventory, type INVENTORY" << endl;

			cout << endl;

			cout << "If you understand this, type Understood (needs to be exactly the same): ";
			cin >> opt;
			while (opt != "Understood")
			{
				cout << "Please try again. Type Understood (needs to be exactly the same): ";
				cin >> opt;
			}

			system("CLS");
		}
		else
		{
			system("CLS");
			cout << "Invalid response, please try again!" << endl;
		}

	} while (!done);
}
string getInput()
{
	string i;
	cout << "> ";
	cin >> i;
	return i;
}
bool confirmInput()
{
	cout << "Confirm? (YES/NO): ";
	string temp;
	cin >> temp;
	if (temp == "yes")
	{
		return true;
	}
	else if (temp == "no")
	{
		return false;
	}
	else
	{
		cout << "Invalid input, please try again!" << endl;
		return confirmInput();
	}
}
void playerCheck(Player&& player, Inventory&& inv, string c)
{
	if (c == "profile")
	{
		player.showProfile();
		getInput();
	}
	else if (c == "inventory")
	{
		inv.PrintInventory();
		getInput();
	}
}
Player characterCreation()
{
	//Values needed to create the o class
	string pName;
	string pClass;
	bool done;

	//Name
	do
	{
		cout << "A girl sits in front of the window, moonlight shining down upon her. With a sigh, she peers down on her- No. Her father's kingdom, gathering courage for what she is about to do next. Looking towards her right, she gazes upon her reflection in the mirror. Her name is... oh, what is her name? That's odd. She can't seem to remember." << endl;
		cout << endl;
		cout << "Remind the princess of her name..." << endl;
		pName = getInput();

		//confirmation
		done = confirmInput();
		system("CLS");

	} while (!done);

	system("CLS");

	//Class Selection
	//done via entering number to avoid spelling error mistakes from player

	cout << "Oh, of course. Princess " << pName << ", that was her. What kind of princess was she?" << endl;

	do
	{
		//Display paths
		cout << "Select a path for the princess to take..." << endl;
		cout << endl;
		cout << "[1] Adventurous:" << endl;
		cout << "Health Points: 500" << endl << "Attack Points: 30" << endl;
		cout << endl;
		cout << "[2] Warrior" << endl;
		cout << "Health Points: 350" << endl << "Attack Points: 70" << endl;
		cout << endl;           
		cout << "[3] Pacifist" << endl;
		cout << "Health Points: 800" << endl << "Attack Points: 20" << endl;
		cout << endl;

		cout << "Enter the number/index of the chosen path." << endl;
		cout << "> ";
		int tempClass = 0;
		cin >> tempClass;


		if (tempClass == 1)
		{
			system("CLS");
			pClass = "Adventurer";
			cout << pName << " was a free-spirited girl, with stars in her eyes and the great seas in her blood. She was swift and graceful, often leaving the castle to gaze upon the outside world, wondering what lies beyond the horizon." << endl;

		}
		else if (tempClass == 2)
		{
			system("CLS");
			pClass = "Warrior";
			cout << pName << " was hardworking despite her royal position, her hands callused from training with wooden swords. Fire blazed in her fierce eyes, a hidden strength underneath the silken fabrics and neat appearance." << endl;

		}
		else if (tempClass == 3)
		{
			system("CLS");
			pClass = "Pacifist";
			cout << pName << "was a gentle, kind soul with a heart of gold. Her smile warmed the room and her eyes were filled with kindness for all creatures. Despite bearing power dur to her position, she refused to use it against those who did not deserve cruelty," << endl;

		}
		else
		{
			tempClass = 0;
			cout << "Invalid input, please try again." << endl;
		}

		//confirmation
		cout << endl;
		if (tempClass != 0)
			done = confirmInput();

		system("CLS");

	} while (!done);

	return Player(pName, pClass);
}
Dragon dragonCreation()
{
	//Variables
	string name;
	string scales;
	string eyes;
	bool done = false;

	do {
		cout << "Glancing away from the mirror and pausing her self-reflection, her eyes landed on her beloved companion. It had been her mother's last gift, being by her side since it first hatched on her fifth birthday." << endl;
		cout << endl;
		cout << "Curled up and sleeping soundly in a bed made just for it, was a baby dragon. Still far too young to be mighty and devour kingdoms, yet far more loyal to her than anyone else in this entire world. She saw it as more than just a fancy last gift- she saw it as family." << endl;
		cout << endl;
		cout << "That dragon's name was..." << endl;
		name = getInput();
		done = confirmInput();
		system("CLS");
	} while (!done);

	do {
		cout << name << R"(, her little dragon who had done nothing wrong. And yet, her father- the king of the country- had rather evil intentions towards the poor thing. She can't let that haappen.

With a sigh, she strode over and sat next to her companion, gently petting its head. "Wake up, silly." She gently shook it.)" << endl;
		cout << "The color of the dragon was..." << endl;
		scales = getInput();
		done = confirmInput();
		system("CLS");
	} while (!done);

	do {
		cout << "With a great yawn, the " << scales << " dragon slowly woke up, stretching as it leaned against its mistress's hand. It took a few more second to fully wake, blinking open its eyes." << endl;
		cout << "The dragon's eyes were colored..." << endl;
		eyes = getInput();
		done = confirmInput();
		system("CLS");
	} while (!done);

	return Dragon(name, scales, eyes);
}
vector<Item> createAllItems() {
	vector<Item> items;
	items.push_back(Item("Banana", "damage", 15, 1, "A classic, a lot of folks underestimate its power.", "Slip! The banana reminds it victim not to underestimate it."));
	items.push_back(Item("Health Potion", "heal", 15, 1, "A green potion, used by all folks alike, plenty are saved by its magical touch.", "Swallow. Touch of the health potion relieves your injuries."));
	items.push_back(Item("Shield", "block", 15, 2, "A sturdy shield, capable of blocking enemy attacks.", "Thud! Enemy attack blocked!"));
	items.push_back(Item("Enchanted Sword", "damage", 15, -1, "A powerful blade with magic edged into it, you can almost hear the magic hum.", "Swish! The enchanted blade strikes true and goes through armour like butter."));
	return items;
}
bool predefEvent(int numEvent, Player& player, Enemy& enemy, Inventory& inv, bool& alive, int nRandomEvent)
{
	string stemp;
	int counter = 1;
	if (numEvent == 1) //Guard Event
	{
		while (player.getStat(0) > 0 && enemy.getHP() > 0)
		{//battle phase
			counter++;//Sets the turn

			//stats print
			cout << "Player HP: " << player.getStat(0) << endl;
			cout << "Enemy HP: " << enemy.getHP() << endl;
			
			//decision
			stemp = getInput();

			enemyBattle(player, enemy, counter);	//Individual battles
			dialogues(numEvent, counter, nRandomEvent);//Individual battle dialogues
		}
		if (player.getStat(0) == 0)
		{
			cout << R"("Dumb girl, you should have known better than to challenge me! Your escape ends here!")" << endl;
		}
		else if (enemy.getHP() == 0)
		{
			cout << R"("I underestimated you... You may have won this time, but mark my words, princess, we’ll get you.”)" << endl;
		}
	}
	else if (numEvent == 2)
	{
		while (player.getStat(0) > 0 && enemy.getHP() > 0)
		{//battle phase
			counter++;//Sets the turn

			//stats print
			cout << "Player HP: " << player.getStat(0) << endl;
			cout << "Enemy HP: " << enemy.getHP() << endl;

			//decision
			stemp = getInput();

			enemyBattle(player, enemy, counter);	//Individual battles
			dialogues(numEvent, counter, nRandomEvent);//Individual battle dialogues
		}
		if (nRandomEvent == 1) //Witch
		{
			if (player.getStat(0) <= 0)//Player Loses
			{
				cout << R"("Dumb girl, you should have known better than to challenge me! Your escape ends here!")" << endl;
				return false;
			}
			else if (enemy.getHP() <= 0) //Player Wins
			{
				cout << R"("I underestimated you... You may have won this time, but mark my words, princess, we’ll get you.”)" << endl;
				cout << "The witch hands you a Health potion.";
				return true;
			}
		}
		else if (nRandomEvent == 2)//Rhonda
		{
			if (player.getStat(0) <= 0)//Player Loses
			{
				cout << R"(“Dumb nosy girl, now you'll NEVER SEE HIM AGAIN!”)" << endl;	
				return false;
			}
			else if (enemy.getHP() <= 0) //Player Wins
			{
				cout << R"("I admire your fierceness and I recognize when someone deserves a chance, so this is for you...”)" << endl;
				cout << "The witch goes back to her basic form and handles you a shield, which will help you dodge 3 attacks (use it wisely).";
				return true;
			}
		}
		else//Prince
		{
			if (player.getStat(0) <= 0)
			{
				cout << R"("Such a shame. You could have had it all, but now, you'll have nothing.")" << endl;
				return false;
			}
			else if (enemy.getHP() <= 0)
			{
				cout << R"("You may have escaped me this time, but remember, wealth and power will always find a way.")" << endl;
				cout << "he grumbles as he departs. In the end, he leaves behind the ";
				cout << R"("Enchanted Sword" as a parting gift, a tool that will serve the princess well in her quest, increasing her damage-dealing abilities by +50 attack points.)" << endl;
				return true;
			}
		}
	}
	else if (numEvent == 3 )
	{
		if (enemy.getHP() <= 0)
		{
			cout << R"(With a malevolent grin, Sir Blackheart overpowers the princess and her dragon. He declares, "The king's will prevails, and I shall bring your heads as trophies!")" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}	
}
void enemyBattle(Player player, Enemy enemy, int turn)
{
	if (turn % 2 == 0)
	{
		enemy.setHP(enemy.getHP() - player.getStat(1));
	}
	else
	{
		player.setHp(player.getStat(0) - enemy.getAtk());
	}
}
void playerDecision(Player player, Enemy enemy) {
	
}
void dialogues(int numEvent, int counter, int nRandomEvent)
{
	if (numEvent == 1) //Castle scape
	{
		if (counter % 2 == 0) //Princess turn
		{
			if (nRandomEvent == 1)
			{
				cout << R"("Don't try to stop us; we'll escape one way or another.")";
			}
			else if (nRandomEvent == 2)
			{
				cout << R"("Hold your ground, buddie. Together, we've faced worse odds than this!")";
			}
			else
			{
				cout << R"("You fool, you don't know what you're doing.")";
			}
		}
		else //Enemy turn
		{
			if (nRandomEvent == 1)
			{
				cout << R"("You think your little escape attempt can succeed, Princess? Think again!")";
			}
			else if (nRandomEvent == 2)
			{
				cout << R"("The king's orders are absolute! You'll never leave this castle!")";
			}
			else
			{
				cout << R"("You and your scaly friend won't disrupt the king's rule any longer!")";
			}
		}
	}
	else if (numEvent == 2) //Random Event
	{
		if (nRandomEvent == 1) //Witch
		{
			if (counter % 2 == 0) //Princess turn
			{
				if (nRandomEvent == 1)
				{
					cout << R"("I won't let you take my friend, no matter what!")";
				}
				else if (nRandomEvent == 2)
				{
					cout << R"("You're just a pawn in my father's wicked game!")";
				}
				else
				{
					cout << R"("I'll protect my kingdom and my dragon with all my strength!")";
				}
			}
			else //Enemy turn
			{
				if (nRandomEvent == 1)
				{
					cout << R"(“Why are you running away, sweetie, don't you know that we only want the best for you?”)";
				}
				else if (nRandomEvent == 2)
				{
					cout << R"(“Give up and give me that d*** dragon!”)";
				}
				else
				{
					cout << R"(“Your father just wants to give you a delicious dinner honey…..DRAGON SOUP *evil laugh*”)";
				}
			}
		}
		else if (nRandomEvent == 2) //Rhoda
		{
			if (counter % 2 == 0) //Princess turn
			{
				if (nRandomEvent == 1)
				{
					cout << R"("Step away from him, you enchanting trickster!")";
				}
				else if (nRandomEvent == 2)
				{
					cout << R"("You won't deceive us with your charms, witch!")";
				}
				else
				{
					cout << R"("I won't let you take him away, no matter what you do!")";
				}
			}
			else //Enemy turn
			{
				if (nRandomEvent == 1)
				{
					cout << R"(“GRRRRRR.......HE IS MINE”)";
				}
				else if (nRandomEvent == 2)
				{
					cout << R"(“What a smart girl...*laughs* You can never beat me!”)";
				}
				else
				{
					cout << R"(“He wants to be with me, DON'T YOU SEE?!”)";
				}
			}
		}
		else //Prince
		{
			if (counter % 2 == 0) //Princess turn
			{
				if (nRandomEvent == 1)
				{
					cout << R"("You're not the hero you pretend to be! I won't be your prize!")";
				}
				else if (nRandomEvent == 2)
				{
					cout << R"("I won't let you take me away from my duty and my dragon!")";
				}
				else
				{
					cout << R"("I may be captivated by your voice, but I won't be captured by your lies!")";
				}
			}
			else //Enemy turn
			{
				if (nRandomEvent == 1)
				{
					cout << R"("This is all about the treasure, my dear. Surrender it, and we can end this peacefully.")";
				}
				else if (nRandomEvent == 2)
				{
					cout << R"("I won't let some dragon and a stubborn princess stand between me and that loot!")";
				}
				else
				{
					cout << R"("It's nothing personal, just business. Hand over the treasure, and we'll all go our separate ways.")";
				}
			}
		}
	}
	else if (numEvent == 3) //Final Enemy
	{
	if (counter % 2 == 0) //Princess turn
	{
		if (nRandomEvent == 1)
		{
			cout << R"("For the safety of my faithful friend, I won't hold back!")";
		}
		else if (nRandomEvent == 2)
		{
			cout << R"("For the kingdom and my loyal buddy, I'll give it my all!")";
		}
		else
		{
			cout << R"("No harm shall befall my dragon while I still draw breath!")";
		}
	}
	else //Enemy turn
	{
		if (nRandomEvent == 1)
		{
			cout << R"("You dare to defy the king's will? You'll regret this!")";
		}
		else if (nRandomEvent == 2)
		{
			cout << R"("Your dragon's head will make a fine trophy for the king!")";
		}
		else
		{
			cout << R"("You're a fool to defend that beast. The king's orders are absolute!")";
		}
	}
	}
}

