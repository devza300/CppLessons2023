#ifndef ROBOTASKMOVETO_H
#define ROBOTASKMOVETO_H

#include "Config/Coordinate.h"
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
    RoboTaskMoveTo(Coordinate coordinate);

    /*!
     * \brief getCoordinate - получить координату точки назначения
     * \return - ткоордината
     */
    Coordinate getCoordinate() const;

private:
    Coordinate mm_coordinate;   //!< координата точки назначения

};

#endif // ROBOTASKMOVETO_H
