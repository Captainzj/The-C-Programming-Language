//
//  main.cpp
//  Section 4.11.3
//
//  Created by Captain on 2017/3/16.
//  Copyright © 2017年 captain. All rights reserved.
//

#include <iostream>
using namespace std;

struct Polymorph{
    virtual ~Polymorph(){}
};

enum Bit{zero,one};
enum Intensity{black = 0 ,brightest = 1000};

int main()
{
    //基本类型 the fundamental types
    cout << "Size of bool: " << sizeof(bool) << " byte" << endl;
    cout << "\n";
    
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of signed char: " << sizeof(signed char) << " byte" << endl;
    cout << "Size of unsigned char: " << sizeof(unsigned char) << " byte" << endl;
    cout << "Size of wchar_t: " << sizeof(wchar_t) << " byte" << endl;
    cout << "\n";
    
    cout << "Size of signed short: " << sizeof(signed short) << " bytes" << endl;
    cout << "Size of unsigned short: " << sizeof(unsigned short) << " bytes" << endl;
    cout << "\n";
    
    cout << "Size of signed int: " << sizeof(signed int) << " bytes" << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
    cout << "\n";
    
    cout << "Size of signed long: " << sizeof(signed long) << " bytes" << endl;
    cout << "Size of unsigned long: " << sizeof(unsigned long) << " bytes" << endl;
    
    cout << "Size of signed long long: " << sizeof(signed long long) << " bytes" << endl;
    cout << "Size of unsigned long long: " << sizeof(unsigned long long) << " bytes" << endl;
    cout << "\n";
    
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of long double: " << sizeof(long double) << " bytes" << endl;
    cout << "\n";
    
    //指针类型 a few pointer types
    cout << "Size of（int*）: " << sizeof(int*) << " bytes" << endl;
    cout << "Size of（int(*）()): " << sizeof(int(*)()) << " bytes" << endl;
    cout << "Size of（void*): " << sizeof(void *) << " bytes" << endl;
    cout << "Size of（void(Polymorph::*)()): " << sizeof(void(Polymorph::*)()) << " bytes" << endl;
    cout << "\n";
    
    //枚举类型 a few enumerations
    cout << "Size of（Bit）: " << sizeof(Bit) << " bytes" << endl;
    cout << "Size of（Intensity）: " << sizeof(Intensity) << " bytes" << endl;
    
    
    return 0;
}
