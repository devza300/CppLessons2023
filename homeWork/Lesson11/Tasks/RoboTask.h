#ifndef ROBOTASK_H
#define ROBOTASK_H

/*!
 * \brief The RoboTask class - тип задачи для робота
 */
class RoboTask
{
public:
    /*!
     * \brief The TaskType enum - тип задачи для робота
     */
    enum TaskType
    {
        /// куда-то двигаться
        MoveTo,

        /// что-то подобрать
        GetSmth,

        /// что-то положить
        PutSmth,

        /// подать масло
        OilShower
    };

    /*!
     * \brief RoboTask - конструктор класса
     * \param type - тип задачи
     */
    RoboTask(TaskType type);

    /*!
     * \brief getType - возвращает заданный тип задачи
     * \return  - тип
     */
    TaskType getType() const;

private:
    TaskType mm_type;       //!< тип задачи

};

#endif // ROBOTASK_H
