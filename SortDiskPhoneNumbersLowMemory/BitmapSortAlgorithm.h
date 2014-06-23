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
#include "ISortingAlgorithm.h"
using namespace std;

class BitmapSortAlgorithm : public ISortingAlgorithm
{
    public:
        void sort(const char* pathToFile, const char* outputFile) override;
        string getOutputFileName(const char* pathToFile) override;
    private:
        void initializeVectorToFalse(vector<bool> &bitmap);
        void readDataIntoVector(vector<bool> &bitmap, const char* pathToFile);
        void writeDataToOutputFile(vector<bool> &bitmap, const char* outputFile);
};

#endif /* defined(__SortDiskPhoneNumbersLowMemory__BitmapSort__) */
