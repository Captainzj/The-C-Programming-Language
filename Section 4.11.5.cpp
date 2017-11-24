//
//  main.cpp
//  Section 4.11.5
//
//  Created by Captain on 2017/3/16.
//  Copyright © 2017年 captain. All rights reserved.
//
//What,on your system,are the largest and the smallest values of the following types:char,short,int,long,float,double,long double,and unsigned.

#include <iostream>
#include <limits>
#include <typeinfo>

template<typename T>
struct Type{
    static void print(){
        std::cout << typeid(T).name() << " : range is (" << std::numeric_limits<T>::min() << " , " << std::numeric_limits<T>::max() << ")\n";
    }
};

int main(int argc, const char * argv[]) {
    Type<char>::print();
    Type<short>::print();
    Type<int>::print();
    Type<long>::print();
    Type<float>::print();
    Type<double>::print();
    Type<long double>::print();
    Type<unsigned>::print();
    
//    std::cout << "Hello, World!\n";
    
    return 0;
}
