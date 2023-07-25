#include "Skill.h"

#include <iostream>

using namespace std;

Skill::Skill()
{

}

void Skill::cast(Unit &unit)
{
    cout << "Skill applying..." << endl;

    privateCast(unit);

    cout << endl;
}
