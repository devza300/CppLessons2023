#include "ArgsParser.h"

#include <algorithm>

char *getCmdOption(char **begin, char **end, const std::string &option)
{
    char **itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char **begin, char **end, const std::string &option)
{
    return std::find(begin, end, option) != end;
}

char *getField(int argc, char *argv[], const std::vector<std::string> &options)
{
    char *value = nullptr;

    for (const auto &option : options)
    {
        if (!cmdOptionExists(argv, argv + argc, option))
            continue;

        value = getCmdOption(argv, argv + argc, option);
        break;
    }

    return value;
}
