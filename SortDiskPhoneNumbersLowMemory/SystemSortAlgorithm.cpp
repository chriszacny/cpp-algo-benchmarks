//
//  SystemSort.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/23/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include "SystemSortAlgorithm.h"


void SystemSortAlgorithm::sort(const char* pathToFile, const char* outputFile)
{
    cout << "Sorting algorithm to use is: system sort algorithm. Starting sort..." << endl;
    vector<int> toSort;
    readDataIntoVector(toSort, pathToFile);
    std::sort(toSort.begin(), toSort.end());
    writeDataToOutputFile(toSort, outputFile);

}

string SystemSortAlgorithm::getOutputFileName(const char* pathToFile)
{
    string outputFileString = string(pathToFile) + ".systemsort.out";
    cout << "Calculated output file is: " << outputFileString << endl;
    return outputFileString;
}

void SystemSortAlgorithm::readDataIntoVector(vector<int> &toSort, const char* pathToFile)
{
    ifstream inputfileStream(pathToFile);
    string line;
    if (inputfileStream.is_open())
    {
        while (getline(inputfileStream, line))
        {
            toSort.push_back(atoi(line.c_str()));
        }
        inputfileStream.close();
    }
}