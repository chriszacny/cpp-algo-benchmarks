//
//  ISortingAlgorithm.h
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#ifndef __SortDiskPhoneNumbersLowMemory__SortingAlgorithm__
#define __SortDiskPhoneNumbersLowMemory__SortingAlgorithm__

#include <string>
#include <fstream>
using namespace std;

class SortingAlgorithm
{
    public:
        virtual void sort(const char* pathToFile, const char* outputFile) = 0;
        virtual string getOutputFileName(const char* pathToFile) = 0;
    protected:
        void writeDataToOutputFile(const char* outputFile);
        virtual void writeDataToOutputFileImpl(ofstream &outputfileStream) = 0;
};

#endif /* defined(__SortDiskPhoneNumbersLowMemory__SortingAlgorithm__) */
