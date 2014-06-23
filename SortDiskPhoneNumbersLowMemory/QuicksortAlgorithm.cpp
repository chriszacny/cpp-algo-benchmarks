//
//  QuicksortAlgorithm.cpp
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#include "QuicksortAlgorithm.h"

const int PASSES = 40;
const int RANGE = 250000;

void QuicksortAlgorithm::swap(std::vector<int> &list, int firstIdx, int secondIdx)
{
    int temp = list[firstIdx];
    list[firstIdx] = list[secondIdx];
    list[secondIdx] = temp;
}

int QuicksortAlgorithm::partition(std::vector<int> &list, int startIdx, int endIdx)
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

void QuicksortAlgorithm::easyQuicksort(std::vector<int> &list, int startIdx, int endIdx)
{
    if (startIdx < endIdx)
    {
        int q = partition(list, startIdx, endIdx);
        easyQuicksort(list, startIdx, q - 1);
        easyQuicksort(list, q + 1, endIdx);
    }
}
 
void QuicksortAlgorithm::readDataIntoVector(std::vector<int> &toSort, int currentPass, const char* pathToFile)
{
    int lowerBound = currentPass * RANGE;
    int upperBound = ((currentPass + 1) * RANGE) - 1;
    std::cout<<"Sorting items in file: [ "<<lowerBound<<" - "<<upperBound<<" ]"<<std::endl;
    std::ifstream inputfileStream(pathToFile);
    std::string line;
    
    if (inputfileStream.is_open())
    {
        while (std::getline(inputfileStream, line))
        {
            int val = std::atoi(line.c_str());
            if (val >= lowerBound && val <= upperBound)
            {
                toSort.push_back(val);
            }
        }
        inputfileStream.close();
    }
}

void QuicksortAlgorithm::writeDataToOutputFile(std::vector<int> &toSort, const char* outputFile)
{
    std::ofstream outputfileStream;
    std::cout << "Opening: " << outputFile << std::endl;
    outputfileStream.open(outputFile, std::ofstream::out | std::ofstream::app);
    if (outputfileStream.is_open())
    {
        for (int i = 0; i < toSort.size(); i++)
        {
            std::cout << toSort[i] << std::endl;
            outputfileStream << toSort[i] << std::endl;
        }
    }
    outputfileStream.close();
}

void QuicksortAlgorithm::sort(const char* pathToFile, const char* outputFile)
{
    std::cout<<"Sorting algorithm to use is: Quicksort. Starting sort..."<<std::endl;
    // Make 40 passes over input file. Pass 1: Sort 0-249,999, Pass 2: Sort 250,000-499,000, etc. Use Quicksort.
    for (int i = 0; i < PASSES; i++)
    {
        //std::cout<<"Beginning pass "<<i+1<<std::endl;
        std::vector<int> toSort;
        readDataIntoVector(toSort, i, pathToFile);
        //std::cout<<"Read in complete. Current list size: "<<toSort.size()<<std::endl;
        easyQuicksort(toSort, 0, toSort.size() - 1);
        for (int j = 0; j < toSort.size(); j++)
        {
            std::cout<<toSort[j]<<std::endl;
        }
        //std::cout<<toSort.size()<<std::endl;
        writeDataToOutputFile(toSort, outputFile);
        //std::cout<<"Pass "<<i+1<<" complete."<<std::endl;
    }
}