#include "MassiveMode.h"

#include <iostream>
#include <sstream>
#include <memory>

#include "TaskOperationProvider.h"

using namespace std;

/*!
 * \brief getMassiveSize - получение размера массива
 * \return - размер
 */
int getMassiveSize()
{
    cout << "Put count of array elements: ";

    string input;
    std::getline(cin, input);

    stringstream localStream;
    localStream << input;

    int value = 0;
    localStream >> value;

    if (localStream.fail())
    {
        localStream.clear();
        localStream.ignore(10000, '\n');
        cout << "Error, input is not number!" << endl;

        return getMassiveSize();
    }

    if (value <= 0)
    {
        cout << "Error, the massive size must be greater than 0!" << endl;
        return getMassiveSize();
    }

    return value;
}

/*!
 * \brief getInput - метод получения данных
 * \param index - индекс ввода
 * \return - введенное значение
 */
int getInput(int index)
{
    cout << "Put the value of index <" << index << ">: ";

    string input;
    std::getline(cin, input);

    stringstream localStream;
    localStream << input;

    int value = 0;
    localStream >> value;

    if (localStream.fail())
    {
        localStream.clear();
        localStream.ignore(10000, '\n');
        cout << "Error, input is not number!" << endl;

        return getInput(index);
    }

    return value;
}

int taskMassive()
{
    // создание массива заданного пользователем размера
    int size = getMassiveSize();
    auto massArray = new int[size];

    // инициализация массива
    for (int index = 0; index < size; ++index)
        massArray[index] = getInput(index);

    cout << endl;

    // поиск нименьшего четного элемента
    printMinimalEvenElement(massArray, size);
    cout << endl;

    // вывод суммы индексов минимального и максимального элементов
    printMinimumAndMaximumPositionSumm(massArray, size);
    cout << endl;

    // вывод произведения элементов в нечетных позициях
    printMultiplyNotEvenPositions(massArray, size);
    cout << endl;

    // вывод произведения элементов в нечетных позициях
    swapPosions(massArray, size);

    delete []massArray;
    return 0;
}
