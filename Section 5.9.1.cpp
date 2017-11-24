//
//  main.cpp
//  Section 5.9.1
//
//  Created by Captain on 2017/3/16.
//  Copyright © 2017年 captain. All rights reserved.
//
// Write declarations for the following: a pointer to a character, an array of 10 integers,a reference to an array of 10 integers,a pointer to an array of character strings, a pointer to a pointer to a character,a constant integer,a pointer to a constant integer,and a constant pointer to an integer.Initialize each one.

#include <iostream>

int main(int argc, const char * argv[]) {
    
    char *pc = 0;    //a pointer to a character
    int ai[10] = {1,1,2,3,5,8,13,21,34,55};     //an array of 10 integers
    int(&rai)[10] = ai;     //a reference to an array of 10 integers
    std::string(*pas)[5] = 0;   //a pointer to an array of character strings
    char **ppc = &pc;       //a pointer to a pointer to a character
    int const ci = 42;  //a constant integer 
    int const *pci = &ci; //a pointer to a constant integer
    int *const pai = ai+3;  //a constant pointer to an integer
    
    //a constant integer : int const ci or const int ci
    
    return 0;
}
