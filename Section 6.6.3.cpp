//
//  main.cpp
//  Section 6.6.3
//
//  Created by Captain on 2017/3/22.
//  Copyright © 2017年 captain. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Stat {
    //确定默认构造函数做了正确的事情
    //（内部使用，用了map数据结构）
    Stat(): sum_(0.0), count_(0){}
    double sum_;
    int count_;
};

using std::string;
typedef std:: map<string,Stat> Data;

void collect_data(Data &stats){
    string name;
    while (cin >> name) {
        double datum;
        cin>>datum;
        stats[name].sum_+=datum;
        ++stats[name].count_;
    }
}

void print_stats(Data const &stats){
    double global_sum = 0.0;
    int global_count = 0;
    for (Data::iterator p = stats.begin(); p!=stats.end(); ++p) {
          cout << (*p).first
             << ":sum =" << (*p).second.sum_
            <<",mean = "
            <<(*p).second.sum_/(*p).second.count_
            <<'\n';
        global_sum += (*p).second.sum_;
        global_count += (*p).second.count_;
    }
    std::cout<<"Global sum:" << global_sum
    <<",Global mean :" << global_sum/global_count
    << std::  endl;
}


int main(int argc, const char * argv[]) {
    Data  stats;
    collect_data(stats);
    print_stats(stats);
    
    return 0;
}
