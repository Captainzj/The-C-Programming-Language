//
//  main.cpp
//  Section 5.9.7
//
//  Created by Captain on 2017/3/16.
//  Copyright © 2017年 captain. All rights reserved.
//

//Define a table

#include <iostream>

int const n_months = 12 ;

char const *month[n_months]
    ={"January","February","March","April","May","June","July","August","September","October","November","December"};

int const month_length[n_months]
    ={31,28,31,30,31,30,31,31,30,31,30,31};

struct Month {
    char const *name_;
    int length_;
};

Month const month_[n_months]
={{"January",31},{"February",28},{"March",31},{"April",30},{"May",31},{"June",30},{"July",31},{"August",31},{"September",30},{"October",31},{"November",30},{"December",31}};



int main(int argc, const char * argv[]) {
    for (int k = 0; k!= n_months; ++k) {
        std::cout << month[k] << ":\t" <<month_length[k] << std::endl;
        
    }
    
    std::cout<<"\n\n";
    
    for (int k = 0; k!= n_months; ++k) {
        std::cout << month_[k].name_ << ":\t" <<month_[k].length_ << std::endl;
        
    }
    
    return 0;
}
