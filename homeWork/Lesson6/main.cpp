#include <iostream>

#include "ArgsParser.h"
#include "MassiveMode.h"
#include "VectorMode.h"

using namespace std;

/*!
 * \brief printHelpPage - вызов инструкции пользования утилитой
 */
void printHelpPage()
{
    cout << "Hello! You are run the Homework Lesson6 console application!" << endl;
    cout << endl;
    cout << "Usage:" << endl;
    cout << "-h, --help                     print this help page" << endl;
    cout << "-m, --massive                  run with massive storage" << endl;
    cout << "-v, --vector                   run with vector storage" << endl;
}

int main(int argc, char *argv[])
{
    // вызвана справочная информация
    if (cmdOptionExists(argv, argv + argc, "-h") || cmdOptionExists(argv, argv + argc, "--help"))
    {
        printHelpPage();
        return 0;
    }

    // сохранение данных в массив
    bool massive_mode = cmdOptionExists(argv, argv + argc, "-m") || cmdOptionExists(argv, argv + argc, "--massive");
    if (massive_mode)
        return taskMassive();

    // сохранение данных в вектор
    bool vector_mode = cmdOptionExists(argv, argv + argc, "-v") || cmdOptionExists(argv, argv + argc, "--vector");
    if (vector_mode)
        return taskVector();

    cout << "Run mode not set!" << std::endl;
    cout << std::endl;
    printHelpPage();
    return 1;
}
