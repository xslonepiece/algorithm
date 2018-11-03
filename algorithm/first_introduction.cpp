//
//  first_introduction.c
//  algorithm
//
//  Created by sili_xia on 2018/11/2.
//  Copyright © 2018 sili_xia. All rights reserved.
//

#include "first_introduction.hpp"
#include <stdbool.h>
void printArray(int a[], int n);

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
        printf("\n");
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
        printf("%d ",a[i]);
    }
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
 数组逆序
 */
void reverse(int a[], int n){
    return reverse(a, 0, n - 1);
}

void reverse(int a[], int fi, int la){
    if (fi < la) {
        reverse(a, fi + 1, la - 1);
    }else{
        
    }
}
