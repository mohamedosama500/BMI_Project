//===============================================================================================================
// Name        : BMI Module
// Author      : Mohamed Osama
// Version     : V1.0
// Copyright   : Your copyright notice
// Description : Module to write a program that reads records, prints the records, and computes some statistics
//===============================================================================================================
/*standard libraries*/
#include<iostream>
#include<ostream>
#include<array>
#include <iomanip>
#include <algorithm>

/*local libraries*/
#include "BMI_statistics.h"
/******************************************************************************
* Function name : BMI_compute.
*
* Description   : This function is used to calculate the BMI of one person.
*
* param  		: height and weight of one person.
*
* return 		: BMI value an integer value.
*
*******************************************************************************/
int BMI_compute (int height, int weight){

    float new_height= ((float)(height * height )/10000);
    float BMI_value= (float)(weight/new_height);
    BMI_value=BMI_value+0.5;
    std::cout<< "BMI_value = "<<BMI_value<<std::endl;
    return (int)BMI_value;
    
}

/******************************************************************************
* Function name : median.
*
* Description   : This function is used to calculate the median BMI of each person.
*
* param  		: temporary  vector for BMI of one person.
*
* return 		: None.
*
*******************************************************************************/
void median(std::vector<int> tmpbmis){

// Median BMI is trickier. The easy way is to sort the
    // sort array from smaller to bigger and pick out the middle item or items.
    std::sort(tmpbmis.begin(), tmpbmis.end());
    std::cout << "Median BMI = ";
    // Index of median item.
    int i(tmpbmis.size() / 2);
    if (tmpbmis.size() % 2 == 0)
      std::cout << (tmpbmis.at(i) + tmpbmis.at(i-1)) / 2.0 << '\n';
    else
      std::cout << tmpbmis.at(i) << '\n';

   
  }

/******************************************************************************
* Function name : mean.
*
* Description   : This function is used to calculate the mean BMI of each person.
*
* param  		: Summation of BMI and number of BMI  for each person.
*
* return 		: None.
*
*******************************************************************************/

void mean(int bmi_count, int  bmi_sum){

// If the vectors are not empty, print basic statistics.
//std::setprecision(1) number of decimal places is one right after the decimal part
if (bmi_count != 0){
    std::cout << "Mean BMI = "
              << std::setprecision(1) << std::fixed << bmi_sum / bmi_count
              << '\n';
}

}
