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
#include<limits>
#include <iomanip>
/*local libraries*/
#include "BMI_getrecord.h"
#include "BMI_statistics.h"


/******************************************************************************
 * Module Variable Definitions
 *******************************************************************************/
static VectStruct_t person_info;
/******************************************************************************
* Function name : skip_line.
*
* Description   : This function is used to clear buffer before taking new line.
*
* param  		: None.
*
* return 		: None.
*
*******************************************************************************/
void skip_line()
{
  std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}
/******************************************************************************
* Function name : get_record.
*
* Description   : This function is used to get info of each person.
*
* param  		: name, gender, height and weight of one person.
*
* return 		: boolean true or false according to the value exist or not.
*
*******************************************************************************/

bool get_record ( std::vector< std::string> & names,
std::vector< int > & heights,
std::vector< int > & weights,
std::vector< char > & genders)

{   person_info.name;
    person_info.height=0;
    person_info.weight=0;
    person_info.gender='?';//initialize gender char with question mark
   
    std::cout << "Name " << names.size()+1 << ": ";
    if (! std::getline(std::cin, person_info.name))
        return false;
    
    std::cout << "Height (cm): ";
    if (! (std::cin >> person_info.height)){
        std::cout << "Invalid height. Aborting.\n";
        return false;
    }
        skip_line();

    std::cout << "Weight (kg): ";
    if (! (std::cin >> person_info.weight)){
        std::cout << "Invalid weight. Aborting.\n";
        return false;
    }   
        skip_line();

    std::cout << "gender (M or F): ";
    if (!(std::cin >> person_info.gender))
       return false;
    person_info.gender = (char)std::toupper(person_info.gender);   

    if (person_info.gender != 'M' && person_info.gender != 'F')
    {
        std::cout << "Invalid gender. Aborting.\n";
        return false;
    }

    
    names.push_back(person_info.name);
    heights.push_back(person_info.height);
    weights.push_back(person_info.weight);
    genders.push_back(person_info.gender);

    return true;

}


/******************************************************************************
* Function name : print_table.
*
* Description   : This function is used to print all info and  BMI of each person.
*
* param  		: all of the names, genders, heights and weights .
*
* return 		: None.
*
*******************************************************************************/
void print_table ( char gender, 
std::vector< int > const & heights, 
std::vector< int > const & weights, 
std::vector< int > const & bmis, 
std::vector< char > const & genders, 
std::vector< std::string > const & names, 
int threshold)

{
std::cout << "Ht(cm)  Wt(kg)  gender  BMI      Name\n";

  float bmi_sum(0);
  long int bmi_count(0);
  std::vector<int> tmpbmis; // store only the BMIs that are printed
     // to compute the median
  for (std::vector<int>::size_type i(0); i != heights.size(); ++i)
    if (genders.at(i) == gender)
    {
      bmi_sum = bmi_sum + bmis.at(i);
      ++bmi_count;
      tmpbmis.push_back(bmis.at(i));

      //spaces to make a table
      std::cout << std::setw(5) << heights.at(i)
                << std::setw(5) << weights.at(i)
                << std::setw(8) << genders.at(i)
                << std::setw(9) << bmis.at(i);
      if (bmis.at(i) >= threshold)
        std::cout << '*';
      else
        std::cout << ' ';
      std::cout << std::setw(10) << names.at(i) << '\n';
    }
    mean(bmi_count,  bmi_sum);
    median(tmpbmis);
}