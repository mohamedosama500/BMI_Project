//===============================================================================================================
// Name        : BMI Module
// Author      : Mohamed Osama
// Version     : V1.0
// Copyright   : Your copyright notice
// Description : Module to write a program that reads records, prints the records, and computes some statistics
//===============================================================================================================
#ifndef BMI_GETRECORD_H_
#define BMI_GETRECORD_H_
#include<vector>
#include <string>
//=============================================================================
// Typedefs
//==============================================================================
typedef  struct VectStruct_s{ 
    std::string name;
    int height , weight ; 
    char gender;
}VectStruct_t; 

/*Functions prototypes*/
void skip_line();

bool get_record ( std::vector< std::string > & names,
std::vector< int > & heights,
std::vector< int > & weights,
std::vector< char > & genders);


void print_table ( char gender, 
std::vector< int > const & heights, 
std::vector< int > const & weights, 
std::vector< int > const & bmis, 
std::vector< char > const & genders, 
std::vector< std::string > const & names, 
int threshold);


#endif