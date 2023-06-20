#ifndef STORAGEIFACE_H
#define STORAGEIFACE_H

#include <iostream>

/*!
 * \brief appendRace - записать новую гонку
 * \param race - гонка
 */
void appendRace(std::string race);

/*!
 * \brief printStorage - вывод сохраненных гонок
 */
void printStorage();

/*!
 * \brief clearStorage - очистить хранилище
 */
void clearStorage();

#endif // STORAGEIFACE_H
