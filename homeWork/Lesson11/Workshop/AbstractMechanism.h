#ifndef ABSTRACTMECHANISM_H
#define ABSTRACTMECHANISM_H

#include <vector>
#include "Tasks/RoboTask.h"

/*!
 * \brief The AbstractMechanism class - абстрактный класс "управляемая деталь робота"
 */
class AbstractMechanism
{
public:
    /*!
     * \brief The MechanismType enum - поддерживаемые типы механизмов
     */
    enum MechanismType
    {
        /// колесо
        Wheel,

        /// сустав
        Joint,

        /// рычаг
        Leverage,

        /// масляный насос
        OilPomp
    };

    /*!
     * \brief AbstractMechanism - конструктор  класса
     * \param type - тип механизма
     */
    AbstractMechanism(MechanismType type);
    virtual ~AbstractMechanism() = default;

    /*!
     * \brief getSkills - список задач, которые может выполнять механизм
     * \return - список выполняемых задач
     */
    virtual std::vector<RoboTask::TaskType> getSkills() = 0;

    /*!
     * \brief getType - тип механизма
     * \return - тип
     */
    MechanismType getType() const;

private:
    MechanismType mm_type;      //!< тип механизма

};

#endif // ABSTRACTMECHANISM_H
