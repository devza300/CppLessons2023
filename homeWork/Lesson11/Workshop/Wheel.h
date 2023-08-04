#ifndef WHEEL_H
#define WHEEL_H

#include "AbstractMechanism.h"

/*!
 * \brief The Wheel class - колесо, механизм робота, мозволяет перемещаться
 */
class Wheel : public AbstractMechanism
{
public:
    /*!
     * \brief Wheel - конструктор класса, инициализирует объект базового класса
     */
    Wheel();

    /*!
     * \brief getSkills - список задач, которые может выполнять механизм
     * \return - список выполняемых задач
     */
    virtual std::vector<RoboTask::TaskType> getSkills() override;

};

#endif // WHEEL_H
