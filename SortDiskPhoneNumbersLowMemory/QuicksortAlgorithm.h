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
#include "SortingAlgorithm.h"
using namespace std;

class QuicksortAlgorithm : public SortingAlgorithm
{
    public:
        void sort(const char* pathToFile, const char* outputFile) override;
        string getOutputFileName(const char* pathToFile) override;
    protected:
        void writeDataToOutputFileImpl(ofstream &outputfileStream) override;
    private:
        void readDataIntoVector(int currentPass, const char* pathToFile);
        void qsortSwap(int i, int j);
        void quicksort(int l, int u);
        vector<int> data;
};

#endif /* defined(__SortDiskPhoneNumbersLowMemory__QuicksortAlgorithm__) */
