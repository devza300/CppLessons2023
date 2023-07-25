#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>

class Unit
{
public:
    Unit();

    void applyEffect(const std::string &effect);

    void showEffects() const;

private:
    std::vector<std::string> m_state {};

};

#endif // UNIT_H
