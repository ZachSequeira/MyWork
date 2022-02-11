#ifndef GAME_JOURNEY_H
#define GAME_JOURNEY_H

#include <iostream>
#include "Enemy.h"
#include "Player_Character.h"
#include "Helper.h"
#include "Attacks.h"

void Enemy_Fight(Enemy* EPtr, Player_Character* PPtr)
{
	*EPtr = Enemy::Create_Enemy();
	std::cout << "You have encountered a " << EPtr->C_Name << std::endl;
	while (EPtr->HP > 0 && PPtr->HP > 0)
	{
		//Agility Check
		if (PPtr->AGL > EPtr->AGL)
		{//Player Plays First

		}
		else
		{//Enemy Plays First

		}
	}
}

void find_chest(Player_Character* PPtr)
{
	int chance = randomGen(10);
	int lockpick;
	char cUInput;
	std::cout << "You have found a chest. Do you wish to open it? (y / n): " << std::endl;
	std::cin >> cUInput;

	if (cUInput == 'Y' || cUInput == 'y')
	{
		if (chance < 5)
		{
			lockpick = randomGen(10);
			if (PPtr->DEX > lockpick)
			{
				std::cout << "You open the Chest and Gained XP!!" << std::endl;
				PPtr->DEX += 15;
			}
			else
			{
				std::cout << "Your DEX is too low to open the Chest!" << std::endl;
			}
			return;
		}
		else if (chance >= 5 && chance < 8)
		{
			lockpick = randomGen(10);
			if (PPtr->DEX > lockpick)
			{
				std::cout << "You open the Chest and found an XP Potion!!" << std::endl;
				if (PPtr->Current_Potion_Reserve < PPtr->Max_Potion_Reserve)
				{
					++PPtr->Current_Potion_Reserve;
				}
				else
				{
					std::cout << "You cannot carry any more potions!" << std::endl;
				}
			}
			else
			{
				std::cout << "Your DEX is too low to open the Chest!" << std::endl;
			}
			return;
		}
		else
		{
			lockpick = randomGen(10);
			if (PPtr->DEX > lockpick)
			{
				std::cout << "You open the Chest and Found a Key!!" << std::endl;
				PPtr->Player_keys;
			}
			else
			{
				std::cout << "Your DEX is too low to open the Chest!" << std::endl;
			}
			return;
		}
	}
	return;
	 
}

#endif // !GAME_JOURNEY_H

