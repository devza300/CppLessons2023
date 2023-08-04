#ifndef OILPOMP_H
#define OILPOMP_H

#include "AbstractMechanism.h"

/*!
 * \brief The OilPomp class - масляный насос, механизм робота, мозволяет подать масло
 */
class OilPomp : public AbstractMechanism
{
public:
    /*!
     * \brief OilPomp - конструктор класса, инициализирует объект базового класса
     */
    OilPomp();

    /*!
     * \brief getSkills - список задач, которые может выполнять механизм
     * \return - список выполняемых задач
     */
    virtual std::vector<RoboTask::TaskType> getSkills() override;

};

#endif // OILPOMP_H
