//
//  main.cpp
//  algorithm
//
//  Created by sili_xia on 2018/11/3.
//  Copyright © 2018 sili_xia. All rights reserved.
//

#include <iostream>
#include "first_introduction.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    cout << "题目：冒泡排序\n";
    int A[] = {10,9,8,7,6,5,4,3,2,1};
    bubblesort(A, 10);
    
//    cout << "题目：统计任意非负整数其二进制形式中1的位数\n" << "请输入任意非负整数：";
//    int input;
//    cin >> input;
//    int ones = countOnes(input);
//    cout << ones << "\n";
    cout << "===================================\n";
    cout << "递归部分\n";
    cout << "题目：数组逆序\n";
    reverse(A, 10);
    printArray(A, 10);
    
    cout << "题目：2的n次方\n";
    cout << power2(10) << "\n";
    
    cout << "题目：斐波那契数列\n";
    fib(10);
    
    cout << "题目：hanoi塔问题\n";
    char a = 'A';
    char b = 'B';
    char c = 'C';
    hanoi(3, a, b, c);
    
    cout << "题目：缺角棋盘放置方案问题\n";
    cover(2, 0, 0, 1, 1);
    
    cout << "题目：求取最大公因数\n";
    cout << gcd(12, 18) << "\n";
    
    cout << "题目：将长度为n的数组A，整体左移k位\n";
    int count = shift(A, 10, 3);
    printArray(A, 10);
    cout << "计算次数：" << count << "\n";
    
    cout << "ackermann = " << ackermann(3,3) << "\n";
    cout << "hailstone = " << hailstone(7) << "\n";
    
    cout << "题目：计算最小子序列长度" << "\n";
    char str1[] = "program";
    char str2[] = "algorithm";
    cout << LSC(str1, 7, str2, 9) << "\n";
    return 0;
}
