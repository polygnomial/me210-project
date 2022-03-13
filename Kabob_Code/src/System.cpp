#include "System.h"

void System::activity(void)
{
    chassis.left.activity();
    chassis.right.activity();
}

System shephard;