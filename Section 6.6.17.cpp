//
//  main.cpp
//  Section 6.6.17
//
//  Created by Captain on 2017/3/22.
//  Copyright © 2017年 captain. All rights reserved.
//

#include <iostream>

using namespace std;

namespace  { char const digit[] ="0123456789"; }

char* my_itoa(int i ,char b[]){
    char *p = b;
    if (i<0) {
        *p++ = '-';
        i =-i;
    }
    int shifter = i;
    do {
        ++p;
        shifter = shifter/10;
    } while (shifter);
    *p ='\0';
    do {
        *--p = digit[i%10];
        i = i/10;
    } while (i);
    return b;
}


char* myitoa(int i ,char b[]){
    sprintf(b, "%d",i);
    return b;
}

int main(int argc, const char * argv[]) {
    char buffer[20];
    int i=3445;
    my_itoa(i,buffer);
    cout << "String of integer " << i << "(radix10):" << buffer << endl;
    
    myitoa(i,buffer);
    cout << "String of integer " << i << "(radix10):" << buffer << endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
