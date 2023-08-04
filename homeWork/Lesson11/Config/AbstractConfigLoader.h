#ifndef ABSTRACTCONFIGLOADER_H
#define ABSTRACTCONFIGLOADER_H

#include <vector>
#include "Tasks/RoboTask.h"

/*!
 * \brief The AbstractConfigLoader class - чтение конфигурации запуска прграммы:
 * 1. имя робота
 * 2. начальные координаты робота
 * 3. состав робота
 * 4. скорость движения
 * 5. список выполняемых задач
 */
class AbstractConfigLoader
{
public:
    AbstractConfigLoader();
    virtual ~AbstractConfigLoader() = default;

    virtual void loadConfig() = 0;

    Robot getRobot() const;

    int getSpeed() const;

    std::vector<RoboTask> getTasks() const;

private:
    Robot mm_robot;
    int mm_speed;
    std::vector<RoboTask> mm_tasks;

};

#endif // ABSTRACTCONFIGLOADER_H
