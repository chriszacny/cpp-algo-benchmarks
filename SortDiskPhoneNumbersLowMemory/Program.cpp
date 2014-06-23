//
//  Program.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include "Program.h"

Program::Program(const char* phoneNumberInputFilePath, int sortingAlgorithmToUse)
{
    _phoneNumberInputFilePath = phoneNumberInputFilePath;
    _sortingAlgorithmToUse = sortingAlgorithmToUse;
}

int Program::Run()
{
    PhoneNumberInputFile* phoneNumberInputFile = new PhoneNumberInputFile(_phoneNumberInputFilePath);
    phoneNumberInputFile->sort((SortingAlgorithmEnum)_sortingAlgorithmToUse);
    return 0;
}