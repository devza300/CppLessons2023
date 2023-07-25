#include "Unit.h"

#include <iostream>

using namespace std;

Unit::Unit()
{

}

void Unit::applyEffect(const std::string &effect)
{
    m_state.push_back(effect);
}

void Unit::showEffects() const
{
    cout << "Unit effects:" << endl;

    for (const auto &effect : m_state) {
        cout << effect << endl;
    }

    cout << endl;
}
