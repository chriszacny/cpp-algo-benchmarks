//
//  main.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include <iostream>
#include <climits>
#include "Program.h"
using namespace std;

bool validate(int argc)
{
    if (argc != 3)
    {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[])
{
    cout << "Welcome to the low-memory file sorting profiler." << endl;
    bool validationSucceeded = validate(argc);
    int retVal = 0;
    if (validationSucceeded)
    {
        const char* phoneNumberInputFile = argv[1];
        int sortingAlgorithmToUse = atoi(argv[2]);
        cout << "Input file is: " << phoneNumberInputFile << endl;
        Program* p = new Program(phoneNumberInputFile, sortingAlgorithmToUse);
        retVal = p->Program::Run();
    }
    else
    {
        cout << "Please enter arguments in form of: executable {pathToInputFile} {sortingAlgorithmEnumValue}" << endl;
        retVal = 1;
    }

    return retVal;
}

