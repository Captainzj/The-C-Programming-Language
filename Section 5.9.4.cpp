//
//  main.cpp
//  Section 5.9.4
//
//  Created by Captain on 2017/3/16.
//  Copyright © 2017年 captain. All rights reserved.
//
//Write a function that swaps(exchanges the values of)two integers.User int* as the argument type.Write another swap function using int& as the argument type.

#include <iostream>


void swap_values(int *p1,int *p2){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void swap(int &v1,int &v2){
    int tmp = v1;
    v1 = v2;
    v2 = tmp;
    
}

void swap_inadequate(int &v1,int &v2){
    v1 = v1^v2;
    v2 = v1^v2;
    v1= v1^v2;
}


int main(int argc, const char * argv[]) {
    int a1 = 10,a2 =20;
    swap_values(&a1, &a2);
    std::cout << " a1: "<< a1 << " a2: "<< a2 << "\n" ;
    
    swap(a1, a2);
    std::cout << " a1: "<< a1 << " a2: "<< a2 << "\n" ;
    
    swap_inadequate(a1, a2);
    std::cout << " a1: "<< a1 << " a2: "<< a2 << "\n" ;
    

    return 0;
}
