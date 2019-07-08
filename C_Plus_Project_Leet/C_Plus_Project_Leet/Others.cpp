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
#include <unordered_map>

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


// 17. Letter Combinations of a Phone Number
// 输入2-9组成的数字，返回这些数字在手机键盘上的所有可能组合
// 递归每一个字符的所有可能，每个位置出发有n种可能，n等于当前位置包含字母数量。
unordered_map<char, vector<char>> digLetterMap = {{'2',{'a','b','c'}},{'3',{'d','e','f'}},{'4',{'g','h','i'}},{'5',{'j','k','l'}},{'6',{'m','n','o'}},{'7',{'p','r','q','s'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};
// digits 输入字符串 loc：当前遍历的位置 str：到loc位置之前的字母组合 vector：结果集
void process17(string digits,int loc,string str,vector<string> &combinations){
    // 来到了字符结尾就收集当前结果
    if (loc == digits.length()) {
        combinations.push_back(str);
    }
    vector<char> letters = digLetterMap[digits[loc]];
    for (int i = 0 ; i<letters.size(); ++i) {
        process17(digits, loc+1, str+letters[i], combinations);
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.length() == 0) {
        return {};
    }
    vector<string> result;
    process17(digits, 0, "", result);
    return result;
}




