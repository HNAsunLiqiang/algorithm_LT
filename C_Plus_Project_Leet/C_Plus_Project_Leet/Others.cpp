//
//  Others.cpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/3/22.
//  Copyright © 2019年 dida. All rights reserved.
//



#include "Others.hpp"
#include <string>
#include <vector>
using namespace std;

// 69. Sqrt(x)
int mySqrt(int x) {
    if (x == 1) {
        return 1;
    }
//    int left = 1;
//    int right = x;
//    int number = 1;
//    while (left < right) {
//        number = left + (right-left)/2;
//
//        if (number <= x/number) {
//            break;
//        }
//        right = number-1;
//    }
    
    if (x <= 1) {
        return x;
    }
    int l = 1, h = x;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        int sqrt = x / mid;
        if (sqrt == mid) {
            return mid;
        } else if (sqrt < mid) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return h;
    
    
//    if (x <= 1) return x;
//    int left = 0, right = x;
//    while (left < right) {
//        int mid = left + (right - left) / 2;
//        if (x / mid >= mid) left = mid + 1;
//        else right = mid;
//    }
//    return right - 1;
}

// 22. Generate Parentheses
/// 1
void generateHelper(vector<string>* result,string cur,int leftCount,int rightCount) {
    if (leftCount > rightCount ) {
        return;
    }
    if (leftCount == 0 && rightCount == 0) {
        result->push_back(cur);
    } else if (leftCount == rightCount) {
        generateHelper(result, cur + '(', leftCount-1, rightCount);
    } else {
        if (leftCount != 0) {
            generateHelper(result, cur + '(' , leftCount-1, rightCount);
            generateHelper(result, cur + ')' , leftCount, rightCount-1);
        } else {
            generateHelper(result, cur + ')' , leftCount, rightCount-1);
        }
    }
}
/// 2
void foo(vector<string>* result,string cur,int leftCount,int rightCount) {
    if (leftCount > rightCount || leftCount < 0 || rightCount < 0) return;
    if (leftCount + rightCount == 0) result->push_back(cur);
    foo(result, cur + '(', leftCount-1, rightCount);
    foo(result, cur + ')', leftCount, rightCount-1);
}

vector<string> generateParenthesis(int n) {
    vector<string> result ;
    generateHelper(&result, "", n, n);
    return result;
}



