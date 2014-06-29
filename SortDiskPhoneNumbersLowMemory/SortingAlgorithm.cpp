//
//  SortingAlgorithm.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include "SortingAlgorithm.h"

void SortingAlgorithm::writeDataToOutputFile(const char* outputFile)
{
    ofstream outputfileStream;
    outputfileStream.open(outputFile, ofstream::out | ofstream::app);
    if (outputfileStream.is_open())
    {
        writeDataToOutputFileImpl(outputfileStream);
    }
    outputfileStream.close();
}