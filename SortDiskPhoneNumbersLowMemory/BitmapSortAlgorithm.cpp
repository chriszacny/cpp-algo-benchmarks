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

/*
 def bit_map_test():
 bit_map = []
 for i in range(START_VAL, RECORD_COUNT + 1):
 bit_map.append(False)
 with open(sys.argv[1], 'r') as r_hdl:
 for line in r_hdl:
 number = int(line)
 bit_map[number - START_VAL] = True
 with open('%s.bitmapsort' % sys.argv[2], 'w') as w_hdl:
 for i in range(START_VAL, RECORD_COUNT + 1):
 if bit_map[i - START_VAL] is True:
 w_hdl.write(str(i))
 w_hdl.write(os.linesep)
*/


void BitmapSortAlgorithm::sort(const char* pathToFile, const char* outputFile)
{
    cout << "Sorting algorithm to use is: bitmap sort algorithm. Starting sort..." << endl;
    vector<bool> toSort;
    initializeVectorToFalse(toSort);
    readDataIntoVector(toSort, pathToFile);
    writeDataToOutputFile(toSort, outputFile);
}

void BitmapSortAlgorithm::initializeVectorToFalse(vector<bool> &bitmap)
{
    for (int i = LOWER_NUMBER_BOUND; i <= UPPER_NUMBER_BOUND; i++)
    {
        bitmap.push_back(false);
    }
}

string BitmapSortAlgorithm::getOutputFileName(const char* pathToFile)
{
    string outputFileString = string(pathToFile) + ".bitmapsort.out";
    cout << "Calculated output file is: " << outputFileString << endl;
    return outputFileString;
}

void BitmapSortAlgorithm::readDataIntoVector(vector<bool> &bitmap, const char* pathToFile)
{
    ifstream inputfileStream(pathToFile);
    string line;
    if (inputfileStream.is_open())
    {
        while (getline(inputfileStream, line))
        {
            int index = atoi(line.c_str());
            bitmap[index - LOWER_NUMBER_BOUND] = true;
        }
        inputfileStream.close();
    }
}
void BitmapSortAlgorithm::writeDataToOutputFile(vector<bool> &bitmap, const char* outputFile)
{
    ofstream outputfileStream;
    outputfileStream.open(outputFile, ofstream::out | ofstream::app);
    if (outputfileStream.is_open())
    {
        for (int i = LOWER_NUMBER_BOUND; i <= UPPER_NUMBER_BOUND; i++)
        {
            if (bitmap[i - LOWER_NUMBER_BOUND] == true)
            {
                outputfileStream << i << endl;
            }
        }
    }
    outputfileStream.close();
}