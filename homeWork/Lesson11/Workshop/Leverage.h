#ifndef LEVERAGE_H
#define LEVERAGE_H

#include "AbstractMechanism.h"

/*!
 * \brief The Leverage class - рычаг, механизм робота, позволяет уронить случайный предмет
 */
class Leverage : public AbstractMechanism
{
public:
    /*!
     * \brief Leverage - конструктор класса, инициализирует объект базового класса
     */
    Leverage();

    /*!
     * \brief getSkills - список задач, которые может выполнять механизм
     * \return - список выполняемых задач
     */
    virtual std::vector<RoboTask::TaskType> getSkills() override;

};

#endif // LEVERAGE_H
