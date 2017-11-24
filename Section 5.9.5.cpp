//
//  main.cpp
//  Section 5.9.5
//
//  Created by Captain on 2017/3/16.
//  Copyright © 2017年 captain. All rights reserved.


//What is the size of the array str in the following example:
//char str[] = "a short string";
//What is the length of the string "a short string"?


#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    char str[] = "a short string";
    
    //数组的长度包括作为结束标志的空字符所需的空间，该测试字符串共有15个字符
    std::cout << "The size of the array str: "<< sizeof(str) << "\n";
    
    
    //常用函数strlen将不考虑作为结束标志的空字符，因此strlen(str)的值是14
    std::cout << "The length of the string: "<< strlen(str) << "\n";
    
    return 0;
}
