#include <iostream>

#include "Unit.h"
#include "DartPoison.h"
#include "Fireball.h"

using namespace std;

int main()
{
    Unit unit;
    unit.showEffects();

    DartPoison skill1;    
    skill1.cast(unit);
    unit.showEffects();

    Fireball skill2;
    skill2.cast(unit);
    unit.showEffects();

    return 0;
}
