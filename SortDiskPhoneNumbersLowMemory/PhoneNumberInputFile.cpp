//
//  FileUtils.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include "PhoneNumberInputFile.h"
using namespace std;

PhoneNumberInputFile::PhoneNumberInputFile(const char* pathToFile)
{
    _pathToFile = pathToFile;
    ISortingAlgorithm* quickSort = new QuicksortAlgorithm();
    _sortingAlgorithms[SortingAlgorithmEnum::Quicksort] = quickSort;
}

void PhoneNumberInputFile::sort(SortingAlgorithmEnum sortingAlgorithm)
{
    const char* outputFile = _sortingAlgorithms[sortingAlgorithm]->getOutputFileName(_pathToFile);
    removeExistingFileIfItExists(outputFile);
    _sortingAlgorithms[sortingAlgorithm]->sort(_pathToFile, outputFile);
}

void PhoneNumberInputFile::removeExistingFileIfItExists(const char* outputFile)
{
    remove(outputFile);
}

