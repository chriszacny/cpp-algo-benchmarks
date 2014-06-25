//
//  QuicksortAlgorithm.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include "QuicksortAlgorithm.h"
using namespace std;

const int PASSES = 40;
const int RANGE = 250000;

void QuicksortAlgorithm::quicksort(vector<int> &list, int l, int u)
{
    if (l >= u)
    {
        return;
    }
    int t = list[l];
    int i = l;
    int j = u + 1;
    while(1 == 1)
    {
        do
        {
            i = i + 1;
        } while (i <= u && list[i] < t);
        
        do
        {
            j = j - 1;
        } while (list[j] > t);
        
        if (i > j)
        {
            break;
        }
        swap(list[i] , list[j]);
    }
    swap(list[l], list[j]);
    quicksort(list, l, j - 1);
    quicksort(list, j + 1, u);
}

void QuicksortAlgorithm::readDataIntoVector(vector<int> &toSort, int currentPass, const char* pathToFile)
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
                toSort.push_back(val);
                _pushbackCount++;
            }
        }
        inputfileStream.close();
    }
    cout << "Pushed back " << _pushbackCount << " times." << endl;
}

string QuicksortAlgorithm::getOutputFileName(const char* pathToFile)
{
    string outputFileString = string(pathToFile) + ".quicksort.out";
    cout << "Calculated output file is: " << outputFileString << endl;
    return outputFileString;
}

void QuicksortAlgorithm::sort(const char* pathToFile, const char* outputFile)
{
    cout << "Sorting algorithm to use is: Quicksort multi-pass algorithm. Starting sort..." << endl;
    // Make several passes over input file. Use Quicksort.
    _pushbackCount = 0;
    for (int i = 0; i < PASSES; i++)
    {
        vector<int> toSort;
        readDataIntoVector(toSort, i, pathToFile);
        quicksort(toSort, 0, toSort.size() - 1);
        writeDataToOutputFile(toSort, outputFile);
    }
}