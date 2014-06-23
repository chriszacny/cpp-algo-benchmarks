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

void QuicksortAlgorithm::swap(vector<int> &list, int firstIdx, int secondIdx)
{
    int temp = list[firstIdx];
    list[firstIdx] = list[secondIdx];
    list[secondIdx] = temp;
}

int QuicksortAlgorithm::partition(vector<int> &list, int startIdx, int endIdx)
{
    int pivot = list[endIdx];
    int i = startIdx - 1;
    for (int j = startIdx; j < endIdx; j++)
    {
        if (list[j] <= pivot)
        {
            i = i + 1;
            swap(list, i, j);
        }
    }
    swap(list, i + 1, endIdx);
    return i + 1;
}

void QuicksortAlgorithm::easyQuicksort(vector<int> &list, int startIdx, int endIdx)
{
    if (startIdx < endIdx)
    {
        int q = partition(list, startIdx, endIdx);
        easyQuicksort(list, startIdx, q - 1);
        easyQuicksort(list, q + 1, endIdx);
    }
}
 
void QuicksortAlgorithm::readDataIntoVector(vector<int> &toSort, int currentPass, const char* pathToFile)
{
    int lowerBound = currentPass * RANGE;
    int upperBound = ((currentPass + 1) * RANGE) - 1;
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
            }
        }
        inputfileStream.close();
    }
}

void QuicksortAlgorithm::writeDataToOutputFile(vector<int> &toSort, const char* outputFile)
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

const char* QuicksortAlgorithm::getOutputFileName(const char* pathToFile)
{
    string outputFileString = string(pathToFile) + ".quicksort.out";
    const char* outputFile = outputFileString.c_str();
    cout << "Calculated output file is: " << outputFile << endl;
    return outputFile;
}

void QuicksortAlgorithm::sort(const char* pathToFile, const char* outputFile)
{
    cout << "Sorting algorithm to use is: Quicksort 40 pass algorithm. Starting sort..." << endl;
    // Make 40 passes over input file. Pass 1: Sort 0-249,999, Pass 2: Sort 250,000-499,000, etc. Use Quicksort.
    for (int i = 0; i < PASSES; i++)
    {
        vector<int> toSort;
        readDataIntoVector(toSort, i, pathToFile);
        easyQuicksort(toSort, 0, toSort.size() - 1);
        writeDataToOutputFile(toSort, outputFile);
    }
}