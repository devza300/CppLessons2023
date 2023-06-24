#pragma once
#include <fstream>
#include <string>
#include <bitset>

std::ifstream OpenStream(const std::string& name);

unsigned char GetErrorsByte(std::ifstream& stream);
