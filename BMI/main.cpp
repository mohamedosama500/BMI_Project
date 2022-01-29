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
//#include<vector>

/*local libraries*/
#include "BMI_statistics.h"
#include "BMI_getrecord.h"




int main (){

  std::vector<std::string> names;
  std::vector<int>         heights;
  std::vector<int>         weights;
  std::vector<char>        genders;
  std::vector<int>         bmis;
  int threshold;
  char decision='y'; 
  std::cout << "Enter threshold BMI: ";
  if (! (std::cin >> threshold))
    return EXIT_FAILURE;
  skip_line();

  std::cout << "Enter name, height (in cm),"
               " and weight (in kg) for each person:\n";
  while (decision=='y' && get_record(names, heights, weights, genders))
  {
     
    int bmi(BMI_compute(heights.back(), weights.back()));
    bmis.push_back(bmi);
    std::cout << "BMI = " << bmi << '\n';
    std::cout << "DO you want to add another person (y or n)?"<< '\n';
    std::cin >> decision;
    skip_line();
  }

  // Print the data.
  std::cout << "\n\nMale data\n";
  print_table('M', heights, weights, bmis, genders, names, threshold);
  std::cout << "\nFemale data\n";
  print_table('F', heights, weights, bmis, genders, names, threshold);


}