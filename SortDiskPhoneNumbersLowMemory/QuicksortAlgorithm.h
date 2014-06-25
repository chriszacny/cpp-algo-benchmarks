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
        string getOutputFileName(const char* pathToFile) override;
    private:
        void readDataIntoVector(vector<int> &toSort, int currentPass, const char* pathToFile);
        void quicksort(vector<int> &list, int l, int u);
        int _pushbackCount;

};

#endif /* defined(__SortDiskPhoneNumbersLowMemory__QuicksortAlgorithm__) */
