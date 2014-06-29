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
    readDataIntoVector(pathToFile);
    std::sort(data.begin(), data.end());
    writeDataToOutputFile(outputFile);
}

string SystemSortAlgorithm::getOutputFileName(const char* pathToFile)
{
    string outputFileString = string(pathToFile) + ".systemsort.out";
    cout << "Calculated output file is: " << outputFileString << endl;
    return outputFileString;
}

void SystemSortAlgorithm::writeDataToOutputFileImpl(ofstream &outputfileStream)
{
    for (int i = 0; i < data.size(); i++)
    {
        outputfileStream << data[i] << endl;
    }
}

void SystemSortAlgorithm::readDataIntoVector(const char* pathToFile)
{
    ifstream inputfileStream(pathToFile);
    string line;
    if (inputfileStream.is_open())
    {
        while (getline(inputfileStream, line))
        {
            data.push_back(atoi(line.c_str()));
        }
        inputfileStream.close();
    }
}