//
//  main.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include <iostream>
#include "Program.h"

int main(int argc, const char * argv[])
{
    std::cout << "Welcome to the low-memory file sorting profiler." << std::endl;
    const char* phoneNumberInputFile = argv[1];
    int sortingAlgorithmToUse = atoi(argv[2]);
    std::cout << "Input file is: " << phoneNumberInputFile << std::endl;
    Program* p = new Program(phoneNumberInputFile, sortingAlgorithmToUse);
    int retVal = p->Program::Run();
    return retVal;
}

