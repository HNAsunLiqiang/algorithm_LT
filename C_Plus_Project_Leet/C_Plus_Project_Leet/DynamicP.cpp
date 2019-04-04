//
//  DynamicP.cpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/2/25.
//  Copyright © 2019年 dida. All rights reserved.
//

using namespace std;

#include "DynamicP.hpp"
#include <vector>
#include <algorithm>

// 279. Perfect Squares
int numSquares(int n) {
//    int res = n, square = 2;
//    while (square*square <= n) {
//        int num1 = n/(square*square) , num2 = n % (square*square);
//        res = min(res, num1 + numSquares(num2));
//        square ++;
//    }
//    return res;
    vector<int>reslut(n+1,INT_MAX);
    reslut[0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; i+j*j <= n ; j++) {
            reslut[i+j*j] = min(reslut[i+j*j], reslut[i]+1);
        }
    }
    return reslut.back();
}

// 53. Maximum Subarray
// 用MS[i]表示最大子数组的结束下标为i的情形，则对于i-1，有：
// MS[i]=max{MS[i−1]+A[i],A[i]}.
// Kadane Algorithm
int maxSubArray(vector<int>& nums) {
    vector<int> result(nums.size(),INT_MIN);
    result[0] = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i< nums.size(); i++) {
        result[i] = max(nums[i], nums[i] + result[i-1] );
        maxSum = max(result[i], maxSum);
    }
    return maxSum;
}

// 121. Best Time to Buy and Sell Stock
// MP[i] = max{MP[i-1],Prices[i]-min{Price[0]...Price[i-1]}}
// https://blog.csdn.net/the__apollo/article/details/77367534
int maxProfit1(vector<int>& prices) {
    if (!prices.size()) {
        return 0;
    }
    int minBuy = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
        maxProfit = max(maxProfit, prices[i]-minBuy);
        minBuy = min(minBuy, prices[i]);
    }
    return maxProfit;
}

// 122. Best Time to Buy and Sell Stock II
//int maxProfit2(vector<int>& prices) {
//    
//}
