//===============================================================================================================
// Name        : BMI Module
// Author      : Mohamed Osama
// Version     : V1.0
// Copyright   : Your copyright notice
// Description : Module to write a program that reads records, prints the records, and computes some statistics
//===============================================================================================================
#ifndef BMI_STATISTICS_H_
#define BMI_STATISTICS_H_
#include<vector>
//=============================================================================
// Typedefs
//==============================================================================

//=============================================================================
// Functions prototypes
//==============================================================================
int BMI_compute (int height, int weight);
void mean(int bmi_count, int  bmi_sum);
void median(std::vector<int> tmpbmis);

#endif