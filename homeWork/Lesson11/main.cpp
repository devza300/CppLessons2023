#include <iostream>

#include "ArgsParser.h"
#include "Config/CliConfigLoader.h"
#include "Config/FileConfigLoader.h"
#include "Emulator.h"

using namespace std;

/*!
 * \brief printHelpPage - вызов инструкции пользования утилитой
 */
void printHelpPage()
{
    cout << "Hello! You are run the Homework Lesson11 console application!" << endl;
    cout << endl;
    cout << "Usage:" << endl;
    cout << "-h, --help                     print this help page" << endl;
    cout << "-d, --dialog                   setup config from dialog" << endl;
    cout << "-f, --file     [config_file]   load config from file" << endl;
}

int main(int argc, char *argv[])
{
    FileConfigLoader loader("test.conf");
    loader.loadConfig();
    Emulator e(&loader);
    e.run();

    return 0;


    // вызвана справочная информация
    if (cmdOptionExists(argc, argv, {"-h", "--help"}))
    {
        printHelpPage();
        return 0;
    }

    // запуск инициализации через Cli
    if (cmdOptionExists(argc, argv, {"-d", "--dialog"}))
    {
        CliConfigLoader loader;
        loader.loadConfig();
        Emulator e(&loader);
        e.run();

        return 0;
    }

    // запуск инициализации через файл
    if (cmdOptionExists(argc, argv, {"-f", "--file"}))
    {
        FileConfigLoader loader(getField(argc, argv, {"-f", "--file"}));
        loader.loadConfig();
        Emulator e(&loader);
        e.run();

        return 0;
    }

    cout << "You are not select the run mode!" << endl;
    cout << endl;
    printHelpPage();
    return 1;
}
