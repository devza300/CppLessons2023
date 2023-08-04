#include "ArgsParser.h"

#include <algorithm>

char *getCmdOption(int argc, char *argv[], const std::string &option)
{
    char **itr = std::find(argv, argv + argc, option);
    if (itr != (argv + argc) && ++itr != (argv + argc))
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(int argc, char *argv[], const std::vector<std::string> &options)
{    
    for (const auto &option : options)
    {
        bool exist = std::find(argv, argv + argc, option) != (argv + argc);
        if (exist)
            return true;
    }
    return false;
}

char *getField(int argc, char *argv[], const std::vector<std::string> &options)
{
    char *value = nullptr;

    for (const auto &option : options)
    {
        if (!cmdOptionExists(argc, argv, {option}))
            continue;

        value = getCmdOption(argc, argv, option);
        break;
    }

    return value;
}
