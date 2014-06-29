//
//  QuicksortAlgorithm.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include "QuicksortAlgorithm.h"
using namespace std;

const int PASSES = 80;
const int RANGE = 125000;

void QuicksortAlgorithm::quicksort(int l, int u)
{
    if (l >= u)
    {
        return;
    }
    int t = data[l];
    int i = l;
    int j = u + 1;
    while(1 == 1)
    {
        do
        {
            i = i + 1;
        } while (i <= u && data[i] < t);
        
        do
        {
            j = j - 1;
        } while (data[j] > t);
        
        if (i > j)
        {
            break;
        }
        swap(data[i], data[j]);
    }
    swap(data[l], data[j]);
    quicksort(l, j - 1);
    quicksort(j + 1, u);
}

void QuicksortAlgorithm::readDataIntoVector(int currentPass, const char* pathToFile)
{
    long lowerBound = currentPass * RANGE;
    long upperBound = ((currentPass + 1) * RANGE) - 1;
    ifstream inputfileStream(pathToFile);
    string line;
    
    if (inputfileStream.is_open())
    {
        while (getline(inputfileStream, line))
        {
            int val = atoi(line.c_str());
            if (val >= lowerBound && val <= upperBound)
            {
                data.push_back(val);
            }
        }
        inputfileStream.close();
    }
}

string QuicksortAlgorithm::getOutputFileName(const char* pathToFile)
{
    string outputFileString = string(pathToFile) + ".quicksort.out";
    cout << "Calculated output file is: " << outputFileString << endl;
    return outputFileString;
}

void QuicksortAlgorithm::writeDataToOutputFileImpl(ofstream &outputfileStream)
{
    for (int i = 0; i < data.size(); i++)
    {
        outputfileStream << data[i] << endl;
    }
}

void QuicksortAlgorithm::sort(const char* pathToFile, const char* outputFile)
{
    cout << "Sorting algorithm to use is: Quicksort multi-pass algorithm. Starting sort..." << endl;
    // Make several passes over input file. Use Quicksort.
    for (int i = 0; i < PASSES; i++)
    {
        data.clear();
        readDataIntoVector(i, pathToFile);
        quicksort(0, data.size() - 1);
        writeDataToOutputFile(outputFile);
    }
}