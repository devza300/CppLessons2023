#ifndef ROBOTASKMOVETO_H
#define ROBOTASKMOVETO_H

#include <math.h>
#include "RoboTask.h"

/*!
 * \brief The RoboTaskMoveTo class - задача куда-то двигаться
 */
class RoboTaskMoveTo : public RoboTask
{
public:
    /*!
     * \brief RoboTaskMoveTo - конструктор класса
     * \param coordinate - координату точки назначения
     */
    RoboTaskMoveTo(std::pair<int, int> coordinate);

    /*!
     * \brief getCoordinate - получить координату точки назначения
     * \return - ткоордината
     */
    std::pair<int, int> getCoordinate() const;

private:
    std::pair<int, int> mm_coordinate;      //!< координата точки назначения

};

#endif // ROBOTASKMOVETO_H
