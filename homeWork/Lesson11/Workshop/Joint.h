#ifndef JOINT_H
#define JOINT_H

#include "AbstractMechanism.h"

/*!
 * \brief The Wheel class - сустав, механизм робота, позоляет подбирать и класть
 */
class Joint : public AbstractMechanism
{
public:
    /*!
     * \brief Joint - конструктор класса, инициализирует объект базового класса
     */
    Joint();

    /*!
     * \brief getSkills - список задач, которые может выполнять механизм
     * \return - список выполняемых задач
     */
    virtual std::vector<RoboTask::TaskType> getSkills() override;

};

#endif // JOINT_H
