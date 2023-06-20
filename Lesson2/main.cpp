#include <iostream>

#include "StartupMenu.h"
#include "NewRace.h"
#include "StorageIface.h"

using namespace std;

int main()
{
    for(auto mode = printMenu(); mode != RunMode::Quit; mode = printMenu())
    {
        switch (mode)
        {
        case NewRace:
        {
            bool isNeedSave = false;
            string race = newRace(isNeedSave);

            if (isNeedSave)
                appendRace(race);

            break;
        }

        case History:
            printStorage();
            break;

        case Clear:

            break;

        case PrintMenu:
            // do nothing, try again (:
            break;

        default:
            // неопределенное поведение
            cout << "Selected mode <" << mode << "> crached the program!" << endl;
            return 1;
        }
    }

    return 0;
}
