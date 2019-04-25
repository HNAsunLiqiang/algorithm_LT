//
//  Array.cpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/2/1.
//  Copyright © 2019年 dida. All rights reserved.
//

using namespace std;

#include <vector>
#include "Array.hpp"
#include <algorithm>
#include <map>
#include <unordered_map>
#include <ext/hash_map>

void arrSwap(vector<int>& nums,int index1,int index2 ){
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}
//
//void backOneSetp(vector<int>& nums){
//    int last = nums.back();
//    for (int i ; <#condition#>; <#increment#>) {
//        <#statements#>
//    }
//}

//void rotate(vector<int>& nums, int k) {
//    for (int i = 0; i < k; i++) {
//        arrSwap(nums, i, nums.size()-1-i);
//    }
//}
// 48. Rotate Image
void rotate(vector<vector<int>>& matrix) {
    
}
// [1,2,3,4]
// 238. Product of Array Except Self
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(),1);
    for (int i = 1; i < nums.size(); i++) {
        res[i] = res[i-1] * nums[i-1];
    }
    // [1,1,1,1]
    // [1,1,2,1]
    // [1,1,2,6]
    int right = 1;
    for (int j = nums.size()-1; j >= 0; j--) {
        res[j] = right * res[j];
        right = nums[j]*right;
    }
    
    return res;
}


// 268. Missing Number
//int missingNumber(vector<int>& nums) {
//    int sub = 0;
//    int max = nums[0];
//    for (int i = 0; i<nums.size()-1; i++) {
//        sub += abs(nums[i] - nums[i+1]);
//        if (nums[i+1] > max) {
//            max = nums[i+1];
//        }
//    }
//
//}


//void rotateMap(vector<vector<int>>& matrix,){
//
//}

// 136. Single Number I
//int singleNumber(vector<int>& nums) {
//    int res = 0;
//    for (int i = 0; i<nums.size(); i++) {
//        res = res^nums[i];
//    }
//    return res;
//    int result=0;
//    vector<int> count(32,0);
//
//    for (int i=0;i < nums.size();i++)
//    {
//        for (int j=0;j<32;j++)
//        {
//            count[j] += nums[i]>>j&0x1;
//        }
//    }
//
//    for (int i=0;i<32;i++)
//    {
//        result|=(count[i]%2<<i);
//    }
//
//    return result;
//}


// 260. Single Number III
vector<int> singleNumber(vector<int>& nums) {
    vector<int> result(2,0);
    int count = 0;
    for (int i = 0; i<nums.size(); i++) {
        count ^= nums[i];
    }
    int index = 0;
    for (int j = 0; j<32; j++) {
        if ((count>>j&1) == 1) {
            index = j;
            break;
        }
    }
    for (int k = 0; k<nums.size(); k++) {
        if ((nums[k]>>index&1) == 1) {
            result[0]^=nums[k];
        } else {
            result[1]^=nums[k];
        }
    }
    return result;
    
}

// 137. Single Number II
//int singleNumber(vector<int>& nums) {
//    int result = 0;
//    vector<int>count(32,0);
//
//    for (int i = 0; i<nums.size(); i++) {
//        for (int j = 0; j < 32; j++) {
//            count[j] += (nums[i]>>j&1);
//        }
//    }
//    for (int k = 0; k<32; k++) {
//        result |= count[k]%3<<k;
//    }
//
//    return result;
//}

// counting : number for 0 to k
vector<int> counting(vector<int> nums) {
    vector<int> result(nums.size(),0);
    
    int k = nums[0];
    for (int i = 0; i<nums.size(); i++) {
        if (nums[i] > k) {
            k = nums[i];
        }
    }
    
    vector<int> counting(k+1,0);
    for (int i = 0; i<nums.size(); i++) {
        counting[nums[i]] += 1;
    }
    
    for (int i = 1; i<counting.size(); i++) {
        counting[i] = counting[i] + counting[i-1];
    }
    
    for (int i = nums.size()-1; i>=0; i--) {
        result[counting[nums[i]]-1] = nums[i];
        counting[nums[i]] -= 1;
    }
    
    return result;
}
//[1,2,4,3,3]
// 287. Find the Duplicate Number  https://www.cnblogs.com/grandyang/p/4843654.html
int findDuplicate(vector<int>& nums) {
//    int left = 0,right = nums.size();
//    while (left < right) {
//        int mid = left + (right-left)/2, cnt = 0;
//        for (int i = 0 ; i<nums.size(); i++) {
//            if (nums[i] <= mid) {
//                cnt++;
//            }
//        }
//        if (cnt > mid) {
//            right = mid;
//        }else {
//            left = mid +1;
//        }
//    }
//    return left;
    
    int result = 0;
    for (int i = 0; i<32; i++) {
        int bit = 1<<i;
        int cnt = 0;
        int bitCount = 0;
        
        for (int j = 0; j<nums.size(); j++) {
            if((j & bit) != 0) cnt++ ;
            if((nums[j] & bit) != 0) bitCount ++;
        }
        if (bitCount > cnt) {
            result += bit;
        }
    }
    
    return result;
}



// 215. Kth Largest Element in an Array
int getMedian(vector<int>& nums,int start,int end){
    if (end - start <= 5) {
        sort(nums.begin()+start, nums.begin()+end+1);
        return nums[(end - start)/2+start];
    }
    vector<int> medians;
    int len = nums.size();
    for (int i = 0; i<len; i+=5) {
        int to = (i+4 < len-1) ? i+4 : len-1;
        medians.push_back(getMedian(nums, i, to));
    }
    return getMedian(medians, 0, medians.size()-1);
}

void VSwap(vector<int>& nums,int index1,int index2){
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}

vector<int> partionRange(vector<int>& nums,int start,int end) {
    int less = start-1;
    int more = end+1;
    int L = start;
    
    int median = getMedian(nums, start, end);
    while (L < more) {
        if (nums[L] < median) {
            VSwap(nums, ++less, L++);
        } else if (nums[L] > median) {
            VSwap(nums, --more, L);
        } else {
            L++;
        }
    }
    vector<int> result;
    result.push_back(less);
    result.push_back(more);
    return result;
}

int findKthLargest(vector<int>& nums, int k) {
    
    vector<int> numsCopy;
    numsCopy.assign(nums.begin(), nums.end());
    vector<int> partitionRange = partionRange(numsCopy, 0, numsCopy.size()-1);
    int less = partitionRange[0];
    int more = partitionRange[1];
    
    if (numsCopy.size()-k < less+1) {
        vector<int> v;
        for (int i = 0; i<=less; i++) {
            v.push_back(numsCopy[i]);
        }
        return findKthLargest(v,k- (numsCopy.size()-less-1));
    } else if (numsCopy.size()-k >= more) {
        vector<int> v;
        for (int i = more; i <= numsCopy.size()-1; i++) {
            v.push_back(numsCopy[i]);
        }
        return findKthLargest(v, k);
    }
    return numsCopy[less+1];
//    if (less+1>=k) {
//        vector<int> v;
//        for (int i = 0; i<=less; i++) {
//            v.push_back(numsCopy[i]);
//        }
//        return findKthLargest(v, k);
//    } else if (more+1<=k){
//
//        vector<int> v;
//        for (int i = more; i <= numsCopy.size()-1; i++) {
//            v.push_back(numsCopy[i]);
//        }
//        return findKthLargest(v, k-more);
//    }
//    return numsCopy[less+1];
}

// 239. Sliding Window Maximum
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    vector<int> window;
    for (int i = 0; i < nums.size(); i++) {
        while (window.size() > 0 && nums[window.back()] <= nums[i]) {
            window.pop_back();
        }
        window.push_back(i);
        if (i-k == window.front()) {
            window.erase(window.begin());
        }
        if (i >= k-1) {
            
            result.push_back(nums[window.front()]);
        }
    }
    return result;
}


// 46. Permutations
vector<vector<int>> permuteRange(vector<int>& nums,int start,int end){
    vector<vector<int>> result;
    if (start > end || start > nums.size()-1) {
        return result;
    }
    if (end == start) {
        vector<int> v = {nums[start]};
        result.push_back(v);
        return  result;
    }
    
    vector<vector<int>> next = permuteRange(nums, start+1,end);
    for (int j = 0; j < next.size(); j++) {
        vector<int> permute = next[j];
        for (int k = 0; k< permute.size(); k++) {
            vector<int> tmp(permute.begin(),permute.end());
            tmp.insert(tmp.begin()+k, nums[start]);
            result.push_back(tmp);
        }
        vector<int> end(permute.begin(),permute.end());
        end.insert(end.end(), nums[start]);
        result.push_back(end);
    }
    return result;
    
}

vector<vector<int>> permute(vector<int>& nums) {
    return permuteRange(nums,0,nums.size()-1);
//    vector<vector<int>> ret;
//    Helper(ret, nums, 0);
//    return ret;
}
// 方法2 https://blog.csdn.net/summerxiachen/article/details/60579623
//vector<vector<int> > permute(vector<int> &num) {
//    vector<vector<int> > ret;
//    Helper(ret, num, 0);
//    return ret;
//}
//void Helper(vector<vector<int> >& ret, vector<int> num, int pos)
//{
//    if(pos == num.size()-1)
//        ret.push_back(num);
//    else
//    {
//        for(int i = pos; i < num.size(); i ++)
//        {//swap all the ints to the current position
//            swap(num[pos], num[i]);
//            Helper(ret, num, pos+1);
//            swap(num[pos], num[i]);
//        }
//    }
//}

// 200. Number of Islands
void isLandInfection(vector<vector<char>>& grid,int row,int col){
    if (grid[row][col] == '1') {
        grid[row][col] = '2';
        if (col <= grid.size()-2) {
            isLandInfection(grid, row, col+1);
        }
        if (row <= grid[0].size()-2) {
            isLandInfection(grid, row+1, col);
        }
        if (col > 0) {
            isLandInfection(grid, row, col-1);
        }
        if (row > 0) {
            isLandInfection(grid, row-1, col);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i< grid[0].size(); i++) {
        for (int j = 0; j< grid.size(); j++) {
            if (grid[j][i] == '1') {
                count ++;
                isLandInfection(grid, i, j);
            }
        }
    }
    return count;
}

class unionSet {
    vector<int> set;
    int num;
    unionSet(int size){
        num = size;
        for (int i = 0; i<size; i++) {
            set.push_back(0);
        }
    }
    
public:
    int find(int x){
        if (set[x] != x) {
            set[x] = find(set[x]);
        }
        return set[x];
    }
    void unionSetWith(int x,int y){
        if (find(x) == find(y)) {
            return;
        }
        num --;
        set[find(y)] = find(x);
    }
    
};
// https://blog.csdn.net/mike_learns_to_rock/article/details/87904932
int numIslandsWithUnionSet(vector<vector<char>>& grid) {
    
    int row = grid.size();
    int col = grid[0].size();
    
    
    return 0;
}

// 322. Coin Change

map<string, int> coinsmap;

int coinsFormIndex(vector<int>& coins,int index,int amount){
    
    if (index == coins.size()) {
        return amount == 0 ?1:0;
    }
    int res = 0;
    
    for (int zhang = 0; zhang*coins[index] <= amount; zhang++) {
        string key = to_string(index+1) + "_" + to_string(amount-zhang*coins[index]);
        if (coinsmap.count(key) != 0) {
            res += coinsmap[key];
        } else {
            res += coinsFormIndex(coins, index+1, amount-zhang*coins[index] );
        }
    }
    coinsmap[to_string(index) + "_" +  to_string(amount)] = res;
    return res;
}

int change(int amount, vector<int>& coins) {
    return coinsFormIndex(coins, 0, amount);
}

int dp_change(int amount, vector<int>& coins) {
    if (amount == 0 && coins.size() == 0) {
        return 1;
    }
    if (amount < 0 || coins.size() == 0) {
        return 0;
    }
    int dp[coins.size()][amount+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0 ; i < coins.size() ; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0 ; i*coins[0] <= amount ; i++) {
        dp[0][i*coins[0]] = 1;
    }
    for (int i = 1; i<coins.size(); i++) {
        for (int j = 1; j<amount+1; j++) {
            dp[i][j] = dp[i-1][j];
            dp[i][j] += j-coins[i]>=0 ? dp[i][j-coins[i]] : 0;
        }
    }
    return dp[coins.size()-1][amount];
    
}

/********/
// 560. Subarray Sum Equals K
// slo1
// 利用递归，求以每一个元素为开头的子数组的和。复杂度较高n^2，空间复杂度n。
int subArraySunRer(vector<int>& nums, int k,vector<int>& sums,int fromIndex){
    if (fromIndex == nums.size()-1) {
        sums.push_back(nums[nums.size()-1]);
        if (nums[nums.size()-1] == k) {
            return 1;
        }
        return 0;
    }
    int res = subArraySunRer(nums, k, sums,fromIndex+1);
    for (int i = 0; i<sums.size(); i++) {
        sums[i] += nums[fromIndex];
        res += sums[i] == k ? 1 : 0;
    }
    res += nums[fromIndex] == k ? 1 : 0;
    sums.push_back(nums[fromIndex]);
    return res;
}
int subarraySum(vector<int>& nums, int k) {
    vector<int> sums;
    return subArraySunRer(nums, k, sums,0);
}

// slo2
// unordered_map：相当于hash_map。插入效率高，查询效率1。
// map:平和二叉树-红黑树，有序。插入效率低，查询效率logn。
// 因为题意是求和为k的子数组个数，假设前m个数和为sum1，前n个数和为sum2，如果sum2-sum1 = k，那么以n结尾的子数组（m~n）和为k。利用这个公式，不必关系m~n范围以n结尾的每个子数组的和，只关心以m结尾子数组和，节省了遍历次数。利用unordered_map存储子数组和sum(key)出现的次数(value)。
// 因为用map存储了出现和为sum的次数，所以避免了sol1中遍历子数组和的过程。
int subarraySum2(vector<int>& nums, int k) {
    unordered_map<int, int> sumsMap = {{0,1}};
    int res = 0;
    int sum = 0;
    for (int i = 0; i<nums.size(); i++) {
        sum += nums[i];
        res += sumsMap[sum-k];
        sumsMap[sum] += 1;
    }
    return res;
}

// 15. 3Sum
// https://www.cnblogs.com/grandyang/p/4481576.html
// https://blog.csdn.net/haolexiao/article/details/70768526
// 先排序，从前往后遍历，遍历过程中m，固定一个数。找余下的两个数，查找过程和twosum相同。
// 遍历求解过程，可以理解某个数为开头的答案。因为排序过了，所以去重后，不会再遍历到这个数。
vector<vector<int>> threeSum(vector<int>& nums) {
    
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int k = 0; k < nums.size(); k++) {
        // 去重
        if (k > 0 && nums[k] == nums[k-1]) continue;
        int i = k+1;
        auto j = nums.size()-1;
        int target = -nums[k];
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                res.push_back({nums[k],nums[i],nums[j]});
                i++;
                j--;
                // 去重
                while (i<j && nums[i] == nums[i-1]) i++;
                while (i<j && nums[j] == nums[j+1]) j--;
            } else if(nums[i] + nums[j] > target){
                j--;
            }else{
                i++;
            }
        }
    }
    
    return res;

}

// 322. Coin Change

int coinChange(vector<int>& coins, int amount) {
    
}





































