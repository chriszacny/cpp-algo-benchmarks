//
//  BitmapSort.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/23/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include "BitmapSortAlgorithm.h"

const int LOWER_NUMBER_BOUND = 1000000;
const int UPPER_NUMBER_BOUND = 9999999;

void BitmapSortAlgorithm::sort(const char* pathToFile, const char* outputFile)
{
    cout << "Sorting algorithm to use is: bitmap sort algorithm. Starting sort..." << endl;
    initializeVectorToFalse();
    readDataIntoVector(pathToFile);
    writeDataToOutputFile(outputFile);
}

void BitmapSortAlgorithm::initializeVectorToFalse()
{
    for (int i = LOWER_NUMBER_BOUND; i <= UPPER_NUMBER_BOUND; i++)
    {
        bitmapData.push_back(false);
    }
}

string BitmapSortAlgorithm::getOutputFileName(const char* pathToFile)
{
    string outputFileString = string(pathToFile) + ".bitmapsort.out";
    cout << "Calculated output file is: " << outputFileString << endl;
    return outputFileString;
}

void BitmapSortAlgorithm::readDataIntoVector(const char* pathToFile)
{
    ifstream inputfileStream(pathToFile);
    string line;
    if (inputfileStream.is_open())
    {
        while (getline(inputfileStream, line))
        {
            int index = atoi(line.c_str());
            bitmapData[index - LOWER_NUMBER_BOUND] = true;
        }
        inputfileStream.close();
    }
}

void BitmapSortAlgorithm::writeDataToOutputFileImpl(ofstream &outputfileStream)
{
    for (int i = LOWER_NUMBER_BOUND; i <= UPPER_NUMBER_BOUND; i++)
    {
        if (bitmapData[i - LOWER_NUMBER_BOUND] == true)
        {
            outputfileStream << i << endl;
        }
    }
}
