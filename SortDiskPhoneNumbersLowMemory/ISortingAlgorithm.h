//
//  ISortingAlgorithm.h
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#ifndef __SortDiskPhoneNumbersLowMemory__ISortingAlgorithm__
#define __SortDiskPhoneNumbersLowMemory__ISortingAlgorithm__

class ISortingAlgorithm
{
    public:
        virtual void sort(const char* pathToFile, const char* outputFile) = 0;
        virtual const char* getOutputFileName(const char* pathToFile) = 0;
};

#endif /* defined(__SortDiskPhoneNumbersLowMemory__ISortingAlgorithm__) */
