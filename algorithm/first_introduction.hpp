//
//  first_introduction.h
//  algorithm
//
//  Created by sili_xia on 2018/11/2.
//  Copyright © 2018 sili_xia. All rights reserved.
//

#ifndef first_introduction_h
#define first_introduction_h

#include <stdio.h>

void bubblesort(int a[], int n);

void printArray(int a[], int n);

/**
 1.2 统计任意非负整数其二进制形式中1的位数
 */
int countOnes(unsigned int n);

#pragma mark - 递归

/**
 数组逆序
 */
void reverse(int a[], int n);

/**
 计算2的n次方
 */
int power2(int n);

/**
 斐波那契数列 O(n)
 */
void fib(int n);

/**
 hanoi塔问题
 */
void hanoi(int n, char &a, char &b, char &c);
#endif /* first_introduction_h */

/**
 缺角棋盘覆盖问题
 */
void cover(int n, int x, int y, int dx, int dy);

/**
 获取最大公约数
 */
int gcd(int a, int b);

/**
 将长度为n的数组A，整体左移k位
 */
int shift(int A[], int n, int k);

/**
 实现下面这个递归算法
 ackermann(m,n) = n + 1 {若m = 0}
                = ackermann(m - 1, 1) {若m > 0 且n = 0}
                = ackermann(m - 1, = ackermann(m, n - 1)) {若m > 0, n > 0}
 */
int ackermann(int m, int n);

/**
 非递归实现hailstone
 */
int hailstone(int n);

/**
 最长子序列（长度）
 */
int LSC(char A[],int m,char B[], int n);
