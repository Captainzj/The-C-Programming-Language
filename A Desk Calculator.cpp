//
//  main.cpp
//  A Desk Calculator
//
//  Created by Captain on 2017/3/22.
//  Copyright © 2017年 captain. All rights reserved.
//

#include <iostream>
#include<map>
#include<string>

using namespace std;

enum Token_value {
    NAME, NUMBER, END,
    PLUS = '+' ,  MINUS = '-',  MUL = '*', DIV ='/',
    PRINT = ';',  ASSGIN = '=',  LP = '(', RP = ')'
};

Token_value curr_tok = PRINT ;
double number_value;
std::string string_value;
map<string,double> table;
int no_of_errors;

double error(const string& s){
    no_of_errors++;
    cerr << "error:" << s << "\n";
    return 1;
}

Token_value get_token(){
    char ch = 0;
     cout << "hhhhh_请输入：\n";
    cin>>ch;
     cout << "hhhhh_已输入\t";
    switch (ch) {
        case 0:
            cout << "hhhhh_end\n";
            return curr_tok = END;
            
        case ';': case '*': case '/': case '+':
        case '-': case '(': case ')': case '=':
            cout << "hhhhh_token\n";
            return curr_tok = Token_value(ch);
            
        case '0': case '1': case '2': case '3':
        case '4': case '5': case '6': case '7':
        case '8': case '9': case '.':
            cout << "hhhhh_number \n";
            cin.putback(ch); cin>>number_value;
            return curr_tok = NUMBER;
            
        default:
            if (isalpha(ch)) {
                cout << "hhhhh_isalpha_NAME\n";
                cin.putback(ch);cin>> string_value;
                return curr_tok = NAME;
            }
            error("bad token");
            return curr_tok =PRINT;
    }
}


double prim(bool get){
    double expr(bool get);
    
    if (get) get_token(); //由调用者决定是否读取下一个token

    switch (curr_tok) {
        case NUMBER: //prim: NUMBER
        { double v = number_value;
            get_token();
            return v;
        }
        case NAME:  //prim: NAME, NAME=expr
        { double& v = table[string_value];
            if (get_token() == ASSGIN) v = expr(true);
                return v;
        }
        case MINUS:  //prim: -prim 相反数
            return -prim(true);
        case LP:  // ‘(‘
        { double e = expr(true);
          if (curr_tok != RP) return error(" ) expected");
            get_token();  // eat ”)”
            return e;
        }
        default:  //Token_value 、 PRINT 、 END
            return error ("primary expected");
        }//switch
    }


double term(bool get){
    double left = prim(get);
    for (;;)          // “forever∫”
        switch (curr_tok) {
            case MUL:
                left *= prim(true);
                break;
            case DIV:
                if (double d = prim(true)) {
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
}


double expr(bool get) //process the 'expression'
{
    double left = term(get);
    for (; ; ) {     // “forever”
        switch (curr_tok) {
            case PLUS:
                left += term(true); //expr:expr + term
                break;
            case MINUS: left -= term(true); //expr:expr - term
                break;
                
            default:  //expr: term
                return left;  //the ONLY return
                
        }
    }
}

int main(int argc, const char * argv[]) {
    table["pi"] = 3.14;
    table["e"] = 2.71;
    while (cin) {
        cout << "hhhhh_循环一次main函数while\n";
        get_token();
        if (curr_tok == END ) break;
        if(curr_tok ==PRINT) continue;
        cout << expr(false)<< '\n';
    }
    return no_of_errors;
}
