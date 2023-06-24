#include <iostream>

#include "LowLevelDriverSimulation.h"

#define PRINT_ERR(val) std::cout << #val << std::endl;

int main()
{

    std::ifstream stream = OpenStream("driver_data.txt");

    while (!stream.fail())
    {
//        std::bitset<8> bitData(GetErrorsByte(stream));
//        std::cout << std::endl << "New state: " << bitData << std::endl;

        unsigned char result = GetErrorsByte(stream);

        unsigned char voltageErr        = 0b00000001;
        unsigned char angleLimitErr     = 0b00000010;
        unsigned char overHittErr       = 0b00000100;
        unsigned char rangeErr          = 0b00001000;
        unsigned char checkSummErr      = 0b00010000;
        unsigned char opverloadErr      = 0b00100000;
        unsigned char instructionErr    = 0b01000000;

        unsigned char UnknownErrType    = 0b10000000;

        std::bitset<8> res(result);
        std::cout << "Res code: " << res << std::endl;

//        unsigned char maskedResult = result & voltageErr;
//        if (maskedResult == voltageErr)
//            PRINT_ERR(voltageErr);

        if ((result & voltageErr) == voltageErr)
            PRINT_ERR(voltageErr);

        if ((result & angleLimitErr) == angleLimitErr)
            PRINT_ERR(angleLimitErr);

        if ((result & overHittErr) == overHittErr)
            PRINT_ERR(overHittErr);

        if ((result & rangeErr) == rangeErr)
            PRINT_ERR(rangeErr);

        if ((result & checkSummErr) == checkSummErr)
            PRINT_ERR(checkSummErr);

        if ((result & opverloadErr) == opverloadErr)
            PRINT_ERR(opverloadErr);

        if ((result & instructionErr) == instructionErr)
            PRINT_ERR(instructionErr);

        if ((result & UnknownErrType) == UnknownErrType)
            PRINT_ERR(UnknownErrType);

    }


    return 0;

}
