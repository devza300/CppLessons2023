#ifndef ABSTRACTMECHANISM_H
#define ABSTRACTMECHANISM_H

#include "Tasks/RoboTask.h"

class AbstractMechanism
{
public:
    enum MechanismType
    {
        Wheel,
        Joint,
        Leverage,
        OilPomp
    };

    AbstractMechanism(MechanismType type);
    virtual ~AbstractMechanism() = default;

    virtual RoboTask::TaskType getSkill() = 0;

private:
    MechanismType mm_type;

};

#endif // ABSTRACTMECHANISM_H
