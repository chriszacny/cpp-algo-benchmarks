//
//  QuicksortAlgorithm.h
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#ifndef __SortDiskPhoneNumbersLowMemory__QuicksortAlgorithm__
#define __SortDiskPhoneNumbersLowMemory__QuicksortAlgorithm__

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include "ISortingAlgorithm.h"
using namespace std;

class QuicksortAlgorithm : public ISortingAlgorithm
{
    public:
        void sort(const char* pathToFile, const char* outputFile) override;
        const char* getOutputFileName(const char* pathToFile) override;
    private:
        void swap(vector<int> &list, int firstIdx, int secondIdx);
        int partition(vector<int> &list, int startIdx, int endIdx);
        void easyQuicksort(vector<int> &list, int startIdx, int endIdx);
        void readDataIntoVector(vector<int> &toSort, int currentPass, const char* pathToFile);
        void writeDataToOutputFile(vector<int> &toSort, const char* outputFile);
};

#endif /* defined(__SortDiskPhoneNumbersLowMemory__QuicksortAlgorithm__) */
