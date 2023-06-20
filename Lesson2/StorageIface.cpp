#include "StorageIface.h"

#include <fstream>

#define STOR_FILE "storage.txt"

void appendRace(std::string race)
{
    std::ofstream file(STOR_FILE);
    file << race;
}

void printStorage()
{
    std::ifstream file(STOR_FILE);
    std::cout << file.rdbuf();
}

void clearStorage()
{
    std::ofstream file;
    file.open(STOR_FILE, std::ofstream::out | std::ofstream::trunc);
    file.close();
}
