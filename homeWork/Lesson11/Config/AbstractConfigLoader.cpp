#include "AbstractConfigLoader.h"

AbstractConfigLoader::AbstractConfigLoader()
{

}

std::string AbstractConfigLoader::getName() const
{
    return mm_name;
}

std::pair<int, int> AbstractConfigLoader::getCoordinate() const
{
    return mm_coordinate;
}

int AbstractConfigLoader::getSpeed() const
{
    return mm_speed;
}

std::vector<std::shared_ptr<AbstractMechanism> > AbstractConfigLoader::getMechanisms() const
{
    return mm_mechanisms;
}

std::vector<std::shared_ptr<RoboTask>> AbstractConfigLoader::getTasks() const
{
    return mm_tasks;
}
