//
//  Array.hpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/2/1.
//  Copyright © 2019年 dida. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>

vector<int> counting(vector<int> nums) ;
int getMedian(vector<int>& nums,int start,int end);
int findKthLargest(vector<int>& nums, int k) ;
vector<int> maxSlidingWindow(vector<int>& nums, int k);
vector<vector<int>> permute(vector<int>& nums) ;
int numIslands(vector<vector<char>>& grid);
int change(int amount, vector<int>& coins) ;
#endif /* Array_hpp */
