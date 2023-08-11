#ifndef OPERATIONSVECTORSTRING_H
#define OPERATIONSVECTORSTRING_H

#include "HeavyOperationsVectorTemplate.h"
#include <iostream>

/*!
 * \brief The OperationsVectorString class - класс для работы с std::vector<std::string>
 */
class OperationsVectorString : public HeavyOperationsVectorTemplate<std::string>
{
public:
    /*!
     * \brief OperationsVectorString - конструктор класса
     * \param data - вектор строк, для инициализации объекта класса
     */
    OperationsVectorString(std::vector<std::string> data);

    /*!
     * \brief findByAngryPattern - поиск количества строк
     * \param pattern - паттерн поиска
     * \param resultVector - вектор с отфильтрованными строками
     * \return - количество совпадений
     */
    int findByAngryPattern(std::string pattern, std::vector<std::string> &resultVector);

};

#endif // OPERATIONSVECTORSTRING_H
