#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h>
#include <time.h>




static int randomGen(int range)
{
	srand(time(0));
	return (rand() % range);
}


#endif // !HELPER_H

