#include <iostream>
#include "Player_Character.h"
#include "Game_Journey.h"
#include "Enemy.h"
#include "Attacks.h"

void Create_Character(Player_Character* P1);

bool flee(Enemy* EPtr, Player_Character* PPtr, int initiator)
{
	if (initiator == 0)
	{
		std::cout << EPtr->C_Name << " has decided to flee" << std::endl;
		return true;
	}
	else
	{
		std::cout << "You have chosen to flee! You do not gain any XP! " << std::endl;
		return true;
	}
}

//Debug
//typedef bool (Attacks::* movePtr)(Enemy*, Player_Character*, int);

int main()
{
	
	
	//movePtr MPtr;
	bool (* movePtr)(Enemy*, Player_Character*, int);
	tableInit();
	int contInput;
	Player_Character P;
	Enemy E;
	Create_Character(&P);
	E = Enemy::Create_Enemy();
	
	

	movePtr = table[3];
	std::cout << movePtr(&E, &P, 0) << std::endl;
	//Enemy_Fight(&E, &P);
	find_chest(&P);
	P.Stats_Display();
	return 0;
}

void Create_Character(Player_Character* P1)
{
	P1->Choose_Class();
	P1->Stats_Display();
}