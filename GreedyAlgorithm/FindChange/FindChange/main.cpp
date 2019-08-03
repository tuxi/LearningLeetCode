//
//  main.cpp
//  FindChange
//
//  Created by swae on 2019/8/3.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include <iostream>

/*
 找零钱问题:
 以人民币1元,2元，5元，10元，20元，50元，100元为例,要求所找的张数最少.
 贪心解法:
 要找N分钱,先拿N除最大零钱面值,取整就是所找的最大面值零钱的个数,取模得
 出余数重新赋给N.重复操作直到除最小面值结束.
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    
    const int parValue[7] = {100,50,20,10,5,2,1};//面值从大到小排列
    // 记录每一个面额需要的数量
    int anNumber[7];
    std::cout << "请输入钱数：" << std::endl;
    int money = 0;
    std::cin>>money;
    int n = money;
    while(n) {
        memset(anNumber, 0, 7*sizeof(int));
        
        int i = 0, cnt = 0;
        while (n > 0) {
            anNumber[i] = n/parValue[i];
            n = n%parValue[i];
            cnt += anNumber[i];
            ++i;
        }
        
        std::cout<<"rmb的面值:100 50 20 10 5 2 1"<<std::endl;
        std::cout<<money<<"元钱的钞票明细:";
        for (i = 0; i < 7; ++i) {
            if (anNumber[i] > 0) {
                std::cout << parValue[i] << "元钞票：" << anNumber[i] << "张； ";
            }
        }
        
        std::cout<<std::endl;
        std::cout<<"需要的钞票张数:"<<cnt<<std::endl;
    }
    return 0;
}
