//
//  BitmapSort.h
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/23/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#ifndef __SortDiskPhoneNumbersLowMemory__BitmapSort__
#define __SortDiskPhoneNumbersLowMemory__BitmapSort__

#include <iostream>
#include <vector>
#include <fstream>
#include "SortingAlgorithm.h"
using namespace std;

class BitmapSortAlgorithm : public SortingAlgorithm
{
    public:
        void sort(const char* pathToFile, const char* outputFile) override;
        string getOutputFileName(const char* pathToFile) override;
    protected:
        void writeDataToOutputFileImpl(ofstream &outputfileStream) override;
    private:
        void initializeVectorToFalse();
        void readDataIntoVector(const char* pathToFile);
        vector<bool> bitmapData;
};

#endif /* defined(__SortDiskPhoneNumbersLowMemory__BitmapSort__) */
