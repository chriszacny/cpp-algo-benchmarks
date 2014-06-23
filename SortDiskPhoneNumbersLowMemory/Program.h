//
//  Program.h
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#ifndef __SortDiskPhoneNumbersLowMemory__Program__
#define __SortDiskPhoneNumbersLowMemory__Program__

#include "PhoneNumberInputFile.h"

class Program
{
    public:
        Program(const char* phoneNumberInputFilePath, int sortingAlgorithmToUse);
        int Run();
    private:
        const char* _phoneNumberInputFilePath;
        int _sortingAlgorithmToUse;
};

#endif /* defined(__SortDiskPhoneNumbersLowMemory__Program__) */
