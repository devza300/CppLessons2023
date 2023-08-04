#include "Emulator.h"

#include <iostream>

#define MSG(string) std::cout << "[Emulator]: " << string << std::endl

Emulator::Emulator(AbstractConfigLoader *config) :
    ptr_config(config)
{

}

void Emulator::run()
{
    MSG("Create new robot...");

    ptr_robot = std::make_shared<Robot>(ptr_config->getName(),
                                        ptr_config->getCoordinate(),
                                        ptr_config->getSpeed(),
                                        ptr_config->getMechanisms());

    for (const auto &task : ptr_config->getTasks())
        ptr_robot->execute(task);
}
