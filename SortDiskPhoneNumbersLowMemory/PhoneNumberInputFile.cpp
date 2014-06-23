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
    ISortingAlgorithm* systemSort = new SystemSortAlgorithm();
    _sortingAlgorithms[SortingAlgorithmEnum::SystemSortSort] = systemSort;
    ISortingAlgorithm* bitmapSort = new BitmapSortAlgorithm();
    _sortingAlgorithms[SortingAlgorithmEnum::BitMapStructure] = bitmapSort;
}

void PhoneNumberInputFile::sort(SortingAlgorithmEnum sortingAlgorithm)
{
    string outputFile = _sortingAlgorithms[sortingAlgorithm]->getOutputFileName(_pathToFile);
    removeExistingFileIfItExists(outputFile.c_str());
    _sortingAlgorithms[sortingAlgorithm]->sort(_pathToFile, outputFile.c_str());
}

void PhoneNumberInputFile::removeExistingFileIfItExists(const char* outputFile)
{
    remove(outputFile);
}

