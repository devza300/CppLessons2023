#include "StartupMenu.h"

#include <iostream>
#include <map>

using namespace std;

RunMode printMenu()
{
    cout << "You are welcome to RaceNote!" << endl;
    cout << endl;
    cout << "Select run mode:" << endl;
    cout << "N" << "\t" << "new race" << endl;
    cout << "H" << "\t" << "print racing history" << endl;
    cout << "C" << "\t" << "clear racing history" << endl;
    cout << "P" << "\t" << "print menu" << endl;
    cout << "Q" << "\t" << "quit the application" << endl;

    cout << endl;
    cout << "mode: ";
    string mode;
    cin >> mode;

    std::map<std::string, RunMode> modeMap = {
        {"N", NewRace},
        {"H", History},
        {"C", Clear},
        {"P", PrintMenu},
        {"Q", Quit}
    };

    if (modeMap.count(mode))
        return modeMap.at(mode);

    cout << "Selected mode <" << mode << "> is not exist!" << endl;
    cout << endl;

    return printMenu();
}
