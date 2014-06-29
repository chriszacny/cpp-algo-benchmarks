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
#include "SortingAlgorithm.h"
using namespace std;

class SystemSortAlgorithm : public SortingAlgorithm
{
    public:
        void sort(const char* pathToFile, const char* outputFile) override;
        string getOutputFileName(const char* pathToFile) override;
    protected:
        void writeDataToOutputFileImpl(ofstream &outputfileStream) override;
    private:
        void readDataIntoVector(const char* pathToFile);
        vector<int> data;

};
#endif /* defined(__SortDiskPhoneNumbersLowMemory__SystemSort__) */
