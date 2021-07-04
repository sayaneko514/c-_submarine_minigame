/*
// Course: INFO1112
// Last Name: Tang
// First Name: Rui (Terry)
// Student ID: 100352332
// File: customizerFunction_TangT.cpp
// Summary: Incorporating a user input to customize the shape of original product shape.
//
// Reference: battleship & submarin http://chris.com/ascii/index.php?art=transportation/nautical
*/

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

	void customization(string sub);
	void build_Sub();
	void background_gen();
	string fish = "><(((o>";
	string fish_2 = "<o(((><";
	string sub;
	string sub_customed;
	string sub_with_bg1;
	string sub_with_bg2;
	string monocular =		"                                  ?                                               \n";
	string pole1 =			"                                  |^\"                                            \n";
	string pole2 =			"                                  |                                               \n";
	string pole3 =			"                                  |                                               \n";
	string pole4 =			"                                  |                                               \n";
	string pole5 =			"                                __|__                                             \n";
	string conning_t =		"                               |     \\                                           \n";
	string conning_b =		"                               |      \\                                          \n";
	string conning_b2 =		"   ____________________________|_______\\________________                         \n";
	string torpedo_tube =	" <    O                                                  \\_________________     _\n";
	string sub_name =		"  \\                                                               U511      \\  (_)\n";
	string viewing_dock =	"   \\     O     O     O                                                       >= )\n";
	string base =			"    \\______________________________________________________________________/   (_)\n";
//                           012345678901234567890123456789012345678901234567890123456789012345678901234567890123456

int main()
{
	build_Sub();
	cout << "Welcome to submarine simulator 1.0.1\n\n\n";
	string cos;
	customization(sub);
	background_gen();
	cout << sub_customed;
	cout << "\nYour submarine is ready to lunch!\n";
	cout << "Are you ready to advance? (Yes/No)\n";
	string adv;
	cin >> adv;
	// keep playing
	while (true){
		int ranNum;
		bool  encounter = false;
		if (adv == "Yes") {
			// advance to encounter enemy
			if (encounter == false) {
				bool combat;
				ranNum = rand() % 6;
				if (ranNum > 4) {
					encounter = true;
					int subHP = 5;
					int shipHP = 10;
					cout << sub_with_bg1;
					cout << "You've enouther an enemy destroyer! Choose one of the following action.\n";
					
					combat = true;
					while (combat) {
						cout << "1. Launch torpedo.\n";
						cout << "2. Try to escape.\n";
						int action;
						cin >> action;
						switch (action) {
							case 1:
								int ranTorp;
								ranTorp = rand() % 10;
								shipHP = shipHP - ranTorp;
								cout << "You've dealt " << ranTorp << " amount of damages to the enemy." << endl;
								if (shipHP <= 0) {
									cout << "You've successfully sunk an enemy destroyer." << endl;
									combat = false;
									encounter == false;
								}
								else {
									cout << "Enemy ship still has " << shipHP << " amount of hit-points left." << endl;
									cout << "The enemy dropped a mine." << endl;
								int ranMine;
								ranMine = rand() % 2;
								subHP = subHP - ranMine;
								cout << "The enemy destroyer dealt " << ranMine << " amount of damages to you." << endl;
								if (subHP <= 0) {
									cout << "You've been sunk by an enemy destroyer." << endl;
									cout << "Game Over.\n";
									combat = false;
									encounter == false;
								}
								else {
									cout << "You still have " << subHP << " amount of hit-points left." << endl;
								
								}
							}
								break;
							case 2:
								int ranEsc;
								ranEsc = rand() % 2;
								if (ranEsc > 0) {
									cout << "You have escaped." << endl;
									combat = false;
									encounter == false;
									break;
								}
								else{
									cout << "Escaped failed. Battle continue." << endl;
									int ranMine = rand() % 2;
									subHP = subHP - ranMine;
									cout << "The enemy destroyer dealt " << ranMine << " amount of damages to you." << endl;
									if (subHP <= 0) {
										cout << "You've been sunk by an enemy destroyer." << endl;
										cout << "Game Over.\n";
										combat = false;
										encounter == false;
									}
									else {
										cout << "You still have " << subHP << " amount of hit-points left." << endl;
									}
								}
								break;
						}
					}
				}
				else {
					encounter = false;
					cout << sub_with_bg2;
					cout << "No enemy insight, do you want to keep going? (Yes/No)\n";
					cin >> adv;
				}
				if (combat = false) {
					break;
				}
			}
		}
		else if (adv == "No") {
			cout << "Sailing back to operation base.\n";
			cout << "Thank you for playing!\n";
			break;
		}
		else {
			cout << "You entered a wrong input, do you want to keep going? (Yes/No)\n";
			cin >> adv;
		}
	}
	return 0;
}

void build_Sub() {
	sub = monocular + pole1 + pole2 + pole3 + pole4 + pole5 + conning_t + conning_b + conning_b2 + torpedo_tube + sub_name + viewing_dock + base;
}

void customization(string c_sub){
	cout << c_sub;
	cout << "Redesign monocular (1 character)" << endl;
	getline(cin, monocular);
	cout << "Redesign conning tower (7 characters)" << endl;
	getline(cin, conning_t);
	cout << "Redesign torpedo tube (3 characters)" << endl;
	getline(cin, torpedo_tube);
	cout << "Name your submarin (4 characters)" << endl;
	getline(cin, sub_name);

	monocular = "                                  " + monocular +"\n";
	torpedo_tube = " <    "+ torpedo_tube +"                                                \\_________________     _\n";
	sub_name = "  \\                                                               " + sub_name + "      \\  (_)\n";
	conning_t = "                               "+ conning_t +"\n";


	build_Sub();
	sub_customed = sub;
	return;
}

void background_gen(){
	pole3.replace(10, 7, fish);
	conning_b.replace(6, 7, fish);
	pole4.replace(67, 7, fish_2);
	build_Sub();
	string burgee = "                                       .____\n";
	string burgee_2 = "                                       |___<     \n";
	string mast = "                                       |__\n                                       |\\/\n                                       ---\n";
	string m_light = "                                       / | [\n";
	string engine_roof = "                                !      | |||\n                              _/|     _/|-++'\n";
	string bridge = "                          +  +--|    |--|--|_ | -     \n";
	string engine_room = "                       { /|__|  |/\\__|  |--- |||__ / \n";
	string anti_air = "                      +--------------___[}--_===_.'____\n";
	string turrent_s = "                  ____`-' ||___-{]_| _[}-  |     |_[___\\==--                 _\n";
	string turrent_m = "   __..._____--==/___]_ | __ | __________________________[___\\==--__, ------' .7\n";
	string stern = "  |                                                                  DD      /\n";
	string turbine = "   \\________________________________________________________________________|     \n";
	string water = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	string space = "                                                                                   \n";
	string ship = burgee + burgee_2 + mast + m_light + engine_roof + bridge + engine_room + anti_air + turrent_s + turrent_m + stern + turbine + water + space + space;
	sub_with_bg1 = ship + sub;
	pole1 = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|^\"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	build_Sub();
	sub_with_bg2 = space + space + space + space + space + space + space + space + space + space + space + space + space + sub;

	return;
}