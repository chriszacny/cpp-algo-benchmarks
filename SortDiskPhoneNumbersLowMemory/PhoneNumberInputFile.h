//
//  FileUtils.h
//  SortDiskPhoneNumbersLowMemory
//
//  Created by Chris Zacny on 6/20/14.
//  Copyright (c) 2014 Chris Zacny. All rights reserved.
//

#ifndef __SortDiskPhoneNumbersLowMemory__PhoneNumberInputFile__
#define __SortDiskPhoneNumbersLowMemory__PhoneNumberInputFile__

#include "SortingAlgorithmEnum.h"
#include "ISortingAlgorithm.h"
#include "PhoneNumberInputFile.h"
#include "QuicksortAlgorithm.h"
#include "SystemSortAlgorithm.h"
#include "BitmapSortAlgorithm.h"
#include <map>
#include <string>

class PhoneNumberInputFile
{
    public:
        PhoneNumberInputFile(const char* pathToFile);
        void sort(SortingAlgorithmEnum sortingAlgorithm);
    private:
        void removeExistingFileIfItExists(const char* outputFile);
        const char* _pathToFile;
        int* _recordCount;
        std::map<SortingAlgorithmEnum, ISortingAlgorithm*> _sortingAlgorithms;    
};

#endif /* defined(__SortDiskPhoneNumbersLowMemory__PhoneNumberInputFile__) */
