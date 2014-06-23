//
//  SystemSort.h
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/23/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#ifndef __SortDiskPhoneNumbersLowMemory__SystemSort__
#define __SortDiskPhoneNumbersLowMemory__SystemSort__

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "ISortingAlgorithm.h"
using namespace std;

class SystemSortAlgorithm : public ISortingAlgorithm
{
    public:
        void sort(const char* pathToFile, const char* outputFile) override;
        string getOutputFileName(const char* pathToFile) override;
    private:
        void readDataIntoVector(vector<int> &toSort, const char* pathToFile);

};
#endif /* defined(__SortDiskPhoneNumbersLowMemory__SystemSort__) */
