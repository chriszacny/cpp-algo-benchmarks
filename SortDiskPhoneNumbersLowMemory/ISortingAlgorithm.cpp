//
//  ISortingAlgorithm.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include "ISortingAlgorithm.h"

void ISortingAlgorithm::writeDataToOutputFile(vector<int> &toSort, const char* outputFile)
{
    ofstream outputfileStream;
    outputfileStream.open(outputFile, ofstream::out | ofstream::app);
    if (outputfileStream.is_open())
    {
        for (int i = 0; i < toSort.size(); i++)
        {
            outputfileStream << toSort[i] << endl;
        }
    }
    outputfileStream.close();
}