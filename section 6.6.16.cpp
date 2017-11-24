//
//  main.cpp
//  section 6.6.16
//
//  Created by Captain on 2017/3/22.
//  Copyright © 2017年 captain. All rights reserved.
//

#include <iostream>
#include <string>
#include <limits>

using std:: domain_error;
using std::range_error;
using std:: string;
using namespace std;

namespace  {
    inline int digit(char c , int base){
        int value;
        switch (c) {
            case '0': value = 0; break;
            case '1': value = 1; break;
            case '2': value = 2; break;
            case '3': value = 3; break;
            case '4': value = 4; break;
            case '5': value = 5; break;
            case '6': value = 6; break;
            case '7': value = 7; break;
            case '8': value = 8; break;
            case '9': value = 9; break;
            case 'a':case 'A': value = 10 ; break;
            case 'b':case 'B': value = 11; break;
            case 'c':case 'C': value = 12; break;
            case 'd':case 'D': value = 13; break;
            case 'e':case 'E': value = 14; break;
            case 'f':case 'F': value = 15; break;
               
            default:
                throw std::domain_error(string("invalid digit"));
        }
        if (value >= base)
            throw std::domain_error(string("invalid digit"));
        return  value;
        
    }
    
    inline char next_char(char const *&p){
        if(*p!='\\') //是特殊情况 ，用‘\\'
            return *p++;
        else{       //3个八进制数字
            int char_value = digit(p[1],8)*64 + digit(p[2],8)*8 + digit(p[3],8);
            if (char_value > std::numeric_limits<char>::max() or char_value < std::numeric_limits<char>::min())
                throw std::domain_error(string("not a char"));
            p +=4; //反斜线和3个八进制数字
            return char_value;
        }
    }
    
    void load_first_digit(char const *&s,int &value,bool &is_negative , int &base){
        char c1 = next_char(s);
        is_negative = c1 == '-';
        if(c1 == '-' || c1 =='+') c1 = next_char(s);
        if (c1 =='\0') {    //"、" "-" "+" 是非法的
            throw std::domain_error(string("invalid input"));
        }else if(c1!='0'){
            base =10;
        }else{
            char const *p =s;
            char c2 = next_char(p);
            if (c2 == 'x' || c2 == 'X'){ //"0x..."
                base = 16;
                s =p;
                c1 = next_char(s);
            }else{
                base = 8 ; //0也作为八进制处理
            }
        }
        value = digit(c1,base);
    }
}//名字空间结束(协助函数)

int my_atoi(char const *s){
    int value,base;
    bool is_negative;
    load_first_digit(s, value, is_negative, base);
    while(char c = next_char(s)){
        if( value > std::numeric_limits<int>::max()/base)
            throw std::range_error(string("out-of-range"));
        value *=base;
        int d = digit(c , base);
        if( value > std::numeric_limits<int>::max()-d)
            throw std::range_error(string("out-of-range"));
        value += d;
        
    }
    return is_negative? -value:value;
}

int main(int argc, const char * argv[]) {
    int n;
    char const *str = "12345.67";
    n = my_atoi(str);
    printf("n=%d\n",n);
    std::cout << "Hello, World!\n";
    return 1;
}
