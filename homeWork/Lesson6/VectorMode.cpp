#include "VectorMode.h"

#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

#include "TaskOperationProvider.h"

using namespace std;

/*!
 * \brief getInput - метод получения данных
 * \param index - индекс ввода
 * \param isNeedContinue - признак продолжения ввода
 * \return - введенное значение
 */
int getInput(int index, int &isNeedContinue)
{
    cout << "Put the value of index <" << index << "> or 'D' to done: ";

    string input;
    std::getline(cin, input);

    stringstream localStream;
    localStream << input;

    if (input == "D")
    {
        isNeedContinue = false;
        return 0;
    }

    int value = 0;
    localStream >> value;

    if (localStream.fail())
    {
        localStream.clear();
        localStream.ignore(10000, '\n');
        cout << "Error, input is not number!" << endl;

        return getInput(index, isNeedContinue);
    }

    return value;
}

int taskVector()
{
    // инициализация вектора
    auto vectorArray = make_unique<vector<int>>();
    for (int index = 0, isNeedContinue = true; isNeedContinue; ++index)
    {
        int value = getInput(index, isNeedContinue);

        if (isNeedContinue)
            vectorArray->push_back(value);
    }

    if (vectorArray->size() == 0)
    {
        cout << "Error, the vector size must be greater than 0!" << endl;
        return 1;
    }

    cout << endl;

    // поиск нименьшего четного элемента
    printMinimalEvenElement(*vectorArray.get(), vectorArray->size());
    cout << endl;

    // вывод суммы индексов минимального и максимального элементов
    printMinimumAndMaximumPositionSumm(*vectorArray.get(), vectorArray->size());
    cout << endl;

    // вывод произведения элементов в нечетных позициях
    printMultiplyNotEvenPositions(*vectorArray.get(), vectorArray->size());
    cout << endl;

    // вывод произведения элементов в нечетных позициях
    swapPosions(*vectorArray.get(), vectorArray->size());

    return 0;
}
