#ifndef ENEMY_H
#define ENEMY_H

#include "Base_Stat.h"
#include <iostream>
#include "Helper.h"

struct Enemy_Stat
{
	std::string NAME;
	int AGL;
	int STR;
	int HP;
	int attackArr[4];
} Enemies[] = { { "Slime", 5, 1, 30, {3, 2, 0}}, {"Enemy 2", 20, 20, 20,{1, 0, 0}}, {"Enemy 3", 10, 20, 10,{1, 0, 0}} };



class Enemy : public Base_Stats
{
	public:
		int Current_Health;
		int Max_Health;
		Enemy() 
		{ 
			Current_Health = 0;
			Max_Health = 0;
		}
		Enemy(Enemy_Stat E)
		{
			AGL = E.AGL;
			STR = E.STR;
			HP = E.HP;
			C_Name = E.NAME;
			Max_Health = HP * 10;
			Current_Health = HP;
		}

		static Enemy Create_Enemy()
		{
			int temp = 0;//randomGen(3);
			Enemy E_temp(Enemies[temp]);
			return E_temp;
		}

};




#endif // !ENEMY_H

