//
//  ISortingAlgorithm.h
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#ifndef __SortDiskPhoneNumbersLowMemory__ISortingAlgorithm__
#define __SortDiskPhoneNumbersLowMemory__ISortingAlgorithm__

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class ISortingAlgorithm
{
    public:
        virtual void sort(const char* pathToFile, const char* outputFile) = 0;
        virtual string getOutputFileName(const char* pathToFile) = 0;
    protected:
        void writeDataToOutputFile(vector<int> &toSort, const char* outputFile);
};

#endif /* defined(__SortDiskPhoneNumbersLowMemory__ISortingAlgorithm__) */
