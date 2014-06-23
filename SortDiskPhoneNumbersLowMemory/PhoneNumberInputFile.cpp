//
//  FileUtils.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include "PhoneNumberInputFile.h"

PhoneNumberInputFile::PhoneNumberInputFile(const char* pathToFile)
{
    _pathToFile = pathToFile;
    ISortingAlgorithm* quickSort = new QuicksortAlgorithm();
    _sortingAlgorithms[SortingAlgorithmEnum::Quicksort] = quickSort;
}

void PhoneNumberInputFile::sort(SortingAlgorithmEnum sortingAlgorithm)
{
    std::string outputFileString = std::string(_pathToFile) + ".quicksort.out";
    const char* outputFile = outputFileString.c_str();
    std::cout << "Calculated output file is: " << outputFile << std::endl;
    std::cout << "test" << _pathToFile << std::endl;
    std::remove(outputFile);
    _sortingAlgorithms[sortingAlgorithm]->sort(_pathToFile, outputFile);
}

int PhoneNumberInputFile::getRecordCount()
{
    if (!_recordCount)
    {
        *_recordCount = 1;
    }
    return *_recordCount;
}
