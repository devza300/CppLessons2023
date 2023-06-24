#include <iostream>
#include <sstream>
#include <climits>
#include <limits>

#include "LowLevelDriverSimulation.h"


std::ifstream OpenStream(const std::string& name)
{
	std::ifstream stream(name);

	if (!stream)
	{
		std::cerr << "file doesn't exists";

        // NOTE если на этом месте возникают ошибки сборки, то доавить аргументом строку: throw std::exception("");
        throw std::exception();
	}
	else
	{
		return stream;
	}
}

unsigned char GetErrorsByte(std::ifstream& stream)
{
	std::string stringData;
	std::getline(stream, stringData);
	std::stringstream localStream;

	localStream << stringData;

    unsigned char result = 0;

	for (size_t i = 0; i < 8; i++)
	{
		int value;
		localStream >> value;

		if (localStream.fail())
		{
			return result;
		}

        value = value << i;
        result |= value;
	}

	return result;
}
