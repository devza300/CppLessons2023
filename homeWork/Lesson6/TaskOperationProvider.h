#ifndef TASKOPERATIONPROVIDER_H
#define TASKOPERATIONPROVIDER_H

#include <iostream>

template <typename Array>
/*!
 * \brief printMinimalEvenElement - поиск нименьшего четного элемента (или просто наименьшего)
 * \param arr - массив значений
 * \param length - длина массива
 */
void printMinimalEvenElement(Array *arr, int length)
{
    // переменная для хранения наименьшего значения массива
    int minimum = 0;
    // признак инициализации значением из входных данных
    bool isMinimumSet = false;

    // переменная для хранения минимального четного значения массива
    int minimumEven = 0;
    // признак инициализации значением из входных данных
    bool isMinimumEvenSet = false;

    for (int i = 0; i < length; ++i)
    {
        // получение элемента массива по указанному индексу
        int el = arr[i];

        // el is even
        if (el % 2 == 0 && (el <= minimumEven || !isMinimumEvenSet))
        {
            minimumEven = el;
            isMinimumEvenSet = true;
        }

        // хотя бы 1 четный элемент найден => нет смысла искать наименьшый элемент
        if (isMinimumEvenSet)
            continue;

        // el not even => find minimal
        if (el < minimum || !isMinimumSet)
        {
            minimum = el;
            isMinimumSet = true;
        }
    }

    // наименьший четный элемент найден
    if (isMinimumEvenSet)
    {
        std::cout << "Minimal even found: " << minimumEven << std::endl;
        return;
    }

    // вывод наименьшего элемента (нечетного)
    std::cout << "Minimal even not found, minimal odd: " << minimum << std::endl;
}

template <typename Array>
/*!
 * \brief printMinimumAndMaximumPositionSumm - вывод суммы индексов минимального и максимального элементов
 * \param arr - массив значений
 * \param length - длина массива
 */
void printMinimumAndMaximumPositionSumm(Array *arr, int length)
{
    // переменная для хранения наименьшего значения массива
    int minimum = 0;
    // индекс наименьшего элемента
    int minimumIndex = -1;

    // переменная для хранения наибольшего значения массива
    int maximum = 0;
    // индекс наибольшего элемента
    int maximumIndex = -1;

    for (int i = 0; i < length; ++i)
    {
        // получение элемента массива по указанному индексу
        int el = arr[i];

        if (el <= minimum && minimumIndex != -1)
        {
            minimum = el;
            minimumIndex = i;
        }

        if (el >= maximum && maximumIndex != -1)
        {
            maximum = el;
            maximumIndex = i;
        }
    }

    // вывод суммы индексов
    std::cout << "Minimum andm aximum position summ: " << minimumIndex + maximumIndex << std::endl;
}

template <typename Array>
/*!
 * \brief printMultiplyNotEvenPositions - вывод произведения элементов в нечетных позициях
 * \param arr - массив значений
 * \param length - длина массива
 */
void printMultiplyNotEvenPositions(Array *arr, int length)
{
    // количество нечетных позиций в массиве
    int notEvenPisitionCount = length / 2;

    // инициализация результата
    int result = 1;

    for (int i = 0; i < notEvenPisitionCount; ++i)
    {
        // плучение элемента массива по формуле 2x + 1
        int notEvenIndex = 2 * i + 1;
        int el = arr[notEvenIndex];

        // добавление элемента в произведение
        result *= el;
    }

    // вывод результата
    std::cout << "Multiply odd positions: " << result << std::endl;
}

template <typename Array>
/*!
 * \brief swapPosions - перемещение эоеменов массива
 * \param arr - массив значений
 * \param length - длина массива
 * \param indexA - первый индекс
 * \param indexB - второй индекс
 */
void swapPosions(Array *arr, int length, int indexA, int indexB)
{
    // метод проверки правильности ввода индексов
    auto checkSwapIndex = [length](int index)
    {
        if (index >= length)
        {
            std::cout << "Error, index<" << index << "> out of range!" << std::endl;
            return true;
        }
        return false;
    };

    if (!checkSwapIndex(indexA))
        return;

    if (!checkSwapIndex(indexB))
        return;

    // вывод исходных данных
    std::cout << "Value in index <" << indexA << "> is: " << arr[indexA] << std::endl;
    std::cout << "Value in index <" << indexB << "> is: " << arr[indexB] << std::endl;

    arr[indexA] = arr[indexA] + arr[indexB];
    arr[indexB] = arr[indexA] - arr[indexB];
    arr[indexA] = arr[indexA] - arr[indexB];

    // вывод результата
    std::cout << "Values are swapped!" << std::endl;
    std::cout << "Value in index <" << indexA << "> is: " << arr[indexA] << std::endl;
    std::cout << "Value in index <" << indexB << "> is: " << arr[indexB] << std::endl;
}

#endif // TASKOPERATIONPROVIDER_H
