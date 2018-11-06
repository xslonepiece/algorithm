//
//  first_introduction.c
//  algorithm
//
//  Created by sili_xia on 2018/11/2.
//  Copyright © 2018 sili_xia. All rights reserved.
//

#include "first_introduction.hpp"
#include <iostream>

using namespace std;

/**
 冒泡排序
 有序序列的特征：任意两个相邻数满足a[i - 1] <= a[i];
 内部循环：一次循环查找逆序对，交换
 外部while循环：没有逆序对退出，有继续内部循环
 */
void bubblesort(int a[],int n){
//    // 我的写法：
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1 ; j <= n - i; j++) {
//            if (a[j - 1] > a[j]) {
//                // 交换
//                int tmp = a[j];
//                a[j] = a [j - 1];
//                a[j - 1] = tmp;
//            }
//        }
//        printf("第%d次排序后数组：",i);
//        printArray(a, n);
//        printf("\n");
//    }
    // 《计算机与算法》实例写法：外部不用循环n次，只要没有逆序对就退出
    bool sorted = false;
    while (!sorted) {
        printArray(a, 10);
//        cout << a;
        sorted = true;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                // 交换
                int tmp = a[i];
                a[i] = a [i - 1];
                a[i - 1] = tmp;
                sorted = false;
            }
        }
        n--;
    }
}

void printArray(int a[], int n){
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

/**
 1.2 统计任意非负整数其二进制形式中1的位数 O(log2^n)
 */
int countOnes(unsigned int n){
//    int ones = 0;
//    while (n > 0) {
//        ones += (n & 1);
//        n >>= 1;
//    }
    // O(n)
    int ones = 0;
    while (n > 0) {
        ones++;
        n &= (n - 1);
    }
    return ones;
}

#pragma mark - 递归

void reverse(int a[], int fi, int la);

/**
 数组逆序：尾递归，可等效替换成迭代版本（while循环实现）
 */
void reverse(int a[], int n){
    return reverse(a, 0, n - 1);
}

void reverse(int a[], int fi, int la){
    if (fi < la) {
        swap(a[fi],a[la]);
        reverse(a, fi + 1, la - 1);
    }
}

int square(int a);
int square(int a){return a * a;}

/**
 计算2的n次方:log(n)
 */
int power2(int n){
    if (n == 0) {
        return 1;
    }else if (n % 2 == 0){
        return square(power2(n >> 1));
    }else{
        return square(power2(n >> 1)) << 1;
    }
}

/**
 斐波那契数列 时间、空间复杂度O(n) 采用迭代方式时间O(n)，空间0(1)
 */
int fib(int n, int &prev);
void fib(int n){
    int prev = 0;
    fib(n, prev);
    cout << "\n";
}

int fib(int n, int &prev){
    if (n == 0) {
        prev = 1;
        return 0;
    }else{
        int prePrev;
        prev = fib(n - 1, prePrev);
        cout << prev << " ";
        return prePrev + prev;
    }
}

/**
 hanoi塔问题
 */
void hanoi(int n, char &a, char &b, char &c){
    if (n > 0) {
        hanoi(n - 1, a, c, b);
        cout << a << " --> " << c << "\n";
        hanoi(n - 1, b, a, c);
    }
}

/**
 缺角棋盘覆盖问题  上、右：1 左、下：-1
 */
void place(int x, int y, int dx, int dy);
void cover(int n, int x, int y, int dx, int dy){
    if (n > 0) {
        int s = 1 << (n - 1); // 子棋子边长
        place(x + dx * (s - 1), y + dy * (s - 1), dx, dy);
        if (n > 1) {
            cover(n - 1, x, y, dx, dy);
            cover(n - 1, x + (dx >> 1) * s, y + (dy >> 1) * s, dx, dy);
            cover(n - 1, x, y + dy * s, dx, -dy);
            cover(n - 1, x + dx * s, y, -dx, dy);
        }
    }
}

void place(int x, int y, int dx, int dy){
    char c1 = dx > 0 ? 'R' : 'L';
    char c2 = dy > 0 ? 'T' : 'B';
    cout << "在(" << x << "," << y << ")点放置一个缺口朝" << c1 << c2 << "的棋子\n";
}

/**
 获取最大公约数
 */
int gcd(int a, int b){
    int p = 1;
    while (!(a & 1) && !(b & 1)) {
        a = a >> 1;
        b = b >> 1;
        p <<= 1;
    }
    int t;
    while ((t = abs(a - b))) {
        if (!(t & 1)) {
            t >>= 1;
        }
        a >= b ? a = t : b = t;
    }
    return a * p;
}

/**
 将长度为n的数组A，整体左移k位
 */
int shift(int A[], int n, int k){
    k %= n;
    reverse(A, k);
    reverse(A + k, n - k);
    reverse(A, n);
    return n * 3; // 累计操作次数
}

/**
 实现下面这个递归算法
 ackermann(m,n) = n + 1 {若m = 0}
 = ackermann(m - 1, 1) {若m > 0 且n = 0}
 = ackermann(m - 1, ackermann(m, n - 1)) {若m > 0, n > 0}
 */
int ackermann(int m, int n){
    if (m > 0 & n > 0) {
        return ackermann(m - 1, ackermann(m, n - 1));
    }else if (m > 0 && n == 0){
        return ackermann(m - 1, 1);
    }else{
        return n + 1;
    }
}

/**
 非递归实现hailstone
 */
int hailstone(int n){
    int step = 0;
    while (n != 1) {
        n & 1 ? n = 3 * n + 1 : n >>= 1;
        step++;
    }
    return ++step;
}

/**
 最长子序列（长度）
 */
int LSC(char A[],int m,char B[], int n){
    /*
    // 递归实现，代码简洁，但效率低
    if (n < 1 || m < 1) {
        return 0;
    }else{
        char laA = A[n - 1];
        char laB = B[m - 1];
        if (laA == laB) {
            return LSC(A, n - 1, B, m - 1) + 1;
        }else{
            return max(LSC(A, n, B, m - 1), LSC(A, n - 1, B, m));
        }
    }
     */
    /* O(m*n) */
    int arr[100][100] = {};
    for (int i = 1 ; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            char laA = A[i - 1];
            char laB = B[j - 1];
            if (laA == laB) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }else{
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
        printArray(arr[i], n + 1);
    }
    return arr[m][n];
}
