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
#include <iostream>
#include <iomanip>
#include <set>
#include <queue>

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
// 固定一个位置，全排列排列它之后的位置
// 排列中应该得到0位置的字母a，在0~n每个位置的各种排列情况
// 用for循环来找出各种组合
// 打印子序列是每个位置有包含和不包含两种情况，此题类似，每个位置的字母会被放到它之后的n个位置
// 为什么只往后面for循环？因为index之前的交换情况由前面的数负责。
// 第一层递归可以看成固定第一个数，第二d次递归看成固定第二个数，...。
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
                // 跳过重复数字
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

// 递归解法
// 数组先排序，从大-小取
// 用minZhang记录当前取得的最小张数，递归过程如果>=minZhang，放弃本路径
// 用递归查找每一条路径并记录需要的张数，当金额==0时，此路径成立，记录张数。
void coinChangeHelper(vector<int>& coins, int amount , int curIndex,int* minZhang,int curZhang) {
    
    if (amount == 0) {
        *minZhang = min(*minZhang, curZhang);
        return;
    } else if(curIndex == -1){
        return;
    }
    if (curZhang >= *minZhang) {
        return;
    }
    for (int zhang = 0; zhang* coins[curIndex] <= amount; zhang++) {
        
        coinChangeHelper(coins, amount-zhang* coins[curIndex], curIndex-1, minZhang, curZhang+zhang);
    }
    
}

int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());
    int res = INT_MAX;
    
    coinChangeHelper(coins, amount, coins.size()-1, &res, 0);
    
    return res > amount ? -1 :res;
}
// 动态规划1
// 思路类似找钱有多少种方案322. Coin Change
// 第一行表示职用数组中第一个数去找钱，每个金额（列）需要的最小张数，那么第一行数据可求；第二行等于用数组中前两个数去找钱，那么第二行每个列的最小值=取第二张各种张数的情况下，所需的最小张数。
int coinChange_dp1(vector<int>& coins, int amount) {
    
    int dp[coins.size()][amount+1];
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i*coins[0] <= amount; i++) {
        dp[0][i*coins[0]] = i;
    }
    for (int i = 1; i < coins.size(); i++) {
        for (int j = 0; j < amount+1; j++) {
            int minZhang = INT_MAX;
            bool valid = false;
            for (int zhang = 0; zhang* coins[i] <= j; zhang++) {
                int preZhang = dp[i-1][j-zhang* coins[i]];
                if (preZhang == -1) {
                    continue;
                }
                valid = true;
                minZhang = min(zhang + preZhang, minZhang);
            }
            dp[i][j] = valid ? minZhang : -1 ;
        }
    }
    return dp[coins.size()-1][amount];
}
// 动归2
// 是1的改进版，不必遍历下面一行的所有位置，h因为当前行的dp[i][j-coins[i]]已经计算过了除dp[i-1][j]的所有位置。
int coinChange_dp2(vector<int>& coins, int amount) {
    
    int dp[coins.size()][amount+1];
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i*coins[0] <= amount; i++) {
        dp[0][i*coins[0]] = i;
    }
    for (int i = 0; i < coins.size(); i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i < coins.size(); i++) {
        for (int j = 1; j < amount+1; j++) {
            // j-coins[i] 即当前总金额减去当前票面额，就是少一张面值时候，所需的最小张数a。当前需张数=a+1
            // 保证取得的结果为-1（无结果）或者正数(有结果)
            dp[i][j] = j-coins[i] >=0 ? (dp[i][j-coins[i]] == -1 ? -1 :dp[i][j-coins[i]]+1) : -1;
            // 因为 负数*正数 = 负数，此时需要保留正数，则取最大值； 否则保留负数（-1）；
            dp[i][j] = dp[i-1][j]*dp[i][j] < 0 ? max(dp[i-1][j], dp[i][j]):min(dp[i-1][j], dp[i][j]);
            
        }
    }
//    for (int i = 0; i<coins.size(); i++) {
//        cout << "\n";
//        cout << "换行 ";
//        for (int j = 0; j < amount+1; j++) {
//
//            cout << dp[i][j];
//            cout << "  ";
//        }
//    }
    
    return dp[coins.size()-1][amount];
}

// 350. Intersection of Two Arrays II
// 利用归并的merge过程，merge前提是排序数组，所以先sort
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    int i = 0,j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            res.push_back(nums1[i]);
            i++;
            j++;
        } else {
            nums1[i] < nums2[j] ? i++ : j++;
        }
    }
    return res;
}
// 另一种 用map存储nums1中数字出现的次数，再遍历nums2，如果数字记录在map中，那么这个数字是重合z数字，此时需要把此数字计数-1。
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int>hashmap;
    if (nums1.size() < nums2.size()) swap(nums1, nums2);
    
    for (int i=0; i<nums1.size(); i++) {
        if (hashmap.count(nums1[i]) <= 0)
            hashmap.insert(make_pair(nums1[i], 1));
        else
            hashmap[nums1[i]] ++;
    }
    
    for (int i=0; i<nums2.size(); i++) {
        if (hashmap.count(nums2[i]) > 0 && hashmap[nums2[i]] > 0) {
            ans.push_back(nums2[i]);
            hashmap[nums2[i]] --;
        }
    }
    
    
    return ans;
}

// 55. Jump Game
// 从数组中每个位置出发能最多走的步数是arr[i]，问能否到达最后。
// 遍历数组，设置一个最大到达数，如果之前位置的最大到达不能到达当前位置，那么更不能到达终点，返回false。再检查从这个位置出发能到达位置是否大于=最后索引。复杂度n
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i<nums.size(); i++) {
        if (maxReach < i) {
            return false;
        }
        maxReach = max(maxReach, i+nums[i]);
        if (maxReach >= nums.size()-1) {
            return true;
        }
    }
    return false;
}

// 45. Jump Game II
// 从数组中每个位置出发能最多走的步数是arr[i]，问到达最后所需的最小步数。
// 假设到i位置所需最小步数为n，a那么从i位置出发能能到的最大位置是i+arr[i]，到这些位置的可能步数是n+1步。怎么求到某位置的最小步数？第一次从左边某个位置x能到达当前位置，那么当前位置的最小步数就是到左边位置的最小步数+1。因为到x的步数肯定<=到i+1...的步数，所以x出发到这个位置就是这个位置的最小路径。
// 用一个数组记录到每个位置所需的最小步数，便利过程更新能到达的最大位置，如果最大位置右扩，那么更填充右扩位置的步数，也就是当前位置最小步数+1步。
int jump(vector<int>& nums) {
    
    vector<int> setups;
    setups.push_back(0);
    for (int i = 0; i<nums.size(); i++) {
        int nextReach = nums[i]+i;
        int curReach = setups.size()-1;
        if (curReach >= nums.size()-1) {
            return setups[i];
        }
        if (nextReach >= nums.size()-1) {
            return setups[i]+1;
        }
        
        if (curReach < nextReach) {
            int j = 0;
            while (j < nextReach - curReach) {
                setups.push_back(setups[i]+1);
            }
        }
        
    }
    return setups.back();
}

// 11. Container With Most Water
// 水池的最大储水量
// 利用双指针夹逼：移动较短的索引。为什么移动短的？因为水池高度由短木板决定，所以如果移动高的因为i~j减小，并且木板水池高度不可能高于未移动的矮的木板，所以此时，总储量只能减小，所以移动高的没有意义。
// 为什么这样一定能取到最大值？先分析什么情况会错过最大值，假设i1,j1时存储量最大，为maxArea。也就是一个过了最大值位置，一个还未到时候，肯定会错过最大值。证明L：i和j肯定有一个先到i1或j1，假设i先到i1，因为此时是存储量最大值，如果i会向右移动，那么此时肯定是j位置高度大于i1位置，此种情况底边更长，所以面积大于此前假设maxArea，与假设不符，所以这时候只能是j左移一直移动到j1。综上，此过程肯定能取得最大值。
int maxArea(vector<int>& height) {
    int i = 0,j = height.size()-1;
    int maxAr = 0;
    while (i < j) {
        maxAr = max(maxAr, min(height[i], height[j])*(j-i));
        height[i] < height[j] ? i++ : j--;
    }
    return maxAr;
}

// 42. Trapping Rain Water https://leetcode.com/problems/trapping-rain-water/submissions/
// 给定n个非负整数表示每个柱的宽度为1的高程图，计算下雨后能够捕获的水量。
// 每个位置能存储的水平 = min(当前位置左边的最大高度,当前位置右边的最大高度) - 当前位置高。
// 利用动态规划，当前位置i左边最大高度 maxLeft(i) = max(maxLeft(i-1), height[i])；右边同理
// 复杂度n
int trap(vector<int>& height) {
    if (height.size() < 3) {
        return 0;
    }
    int trapSize = 0;
    vector<int> leftMaxIndex(height.size(),0);
    vector<int> rightMaxIndex(height.size(),0);
    int i = 1;
    while (i < height.size()) {
        leftMaxIndex[i] = height[leftMaxIndex[i-1]] > height[i] ? leftMaxIndex[i-1] : i;
        i++;
    }
    rightMaxIndex[height.size()-1] = height.size()-1;
    i = height.size()-2;
    while (i > -1) {
        rightMaxIndex[i] = height[rightMaxIndex[i+1]] > height[i] ? rightMaxIndex[i+1] : i;
        i--;
    }
    i = 1;
    while (i < height.size() - 1) {
        trapSize += abs(min(height[leftMaxIndex[i]], height[rightMaxIndex[i]])) - height[i] ;
        i++;
    }
    return trapSize;
}
int trap1(vector<int>& height)
{
    if(!height.size()) return 0;
    
    int l = 0, r = height.size()-1;
    int secHighest = 0;
    int area = 0;
    
    while(l < r)
    {
        if(height[l] < height[r])
        {
            secHighest = std::max(secHighest, height[l]);
            area += secHighest - height[l];
            l++;
        }
        else
        {
            secHighest = std::max(secHighest, height[r]);
            area += secHighest - height[r];
            r--;
        }
    }
    
    return area;
}

// 78. Subsets
// 每个位置有两个路径：1、加上当前数；2、不加。当到最后时候，加入结果集合。
void subsetProcess(vector<vector<int>> &res,vector<int>& nums,int from,vector<int>& cur){
    if (from == nums.size()) {
        res.push_back(cur);
        return;
    }
    vector<int> v(cur);
    subsetProcess(res, nums, from+1,v);
    cur.push_back(nums[from]);
    subsetProcess(res, nums, from+1,cur);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    subsetProcess(res,nums, 0,cur);
    return res;
}

// 75. Sort Colors
// 数组中有三种数，0、1、2，个数不固定，按0、1、2的顺序排序，要求只遍历一次。
// 利用快排的partation过程，把1当成分割数，0方左边，2放右边。
// 三个指针一个h是遍历用的i，一个是left-左边界-指向小于1的最后一个数，一个是right-右边界-指向大于1的第一个数。
void swap75(vector<int>& nums,int index1,int index2);
void sortColors(vector<int>& nums) {
    int i = 0,left =-1,right = nums.size();
    while (i < right) {
        if (nums[i] == 1) {
            i += 1;
        }else if (nums[i] == 0){
            swap75(nums, ++left, i++);
        }else {
            // 交换到较大区的时候，当前索引i不增加，因为此时从较大区被交换过来的数没有验证过大小
            swap75(nums, --right, i);
        }
    }
}

void swap75(vector<int>& nums,int index1,int index2){
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}



// 347. Top K Frequent Elements
// 求数组中出行最频繁的前k个数
// 两种做法：1、桶+map 2、优先级队列+map

// 遍历一次存到map中：key-数，value-次数
// 再遍历map，将次数和数字组成pair放入priority_queue，组成大根堆
// 当priority_queue中元素大于n-k个时候，开始收集数据
vector<int> topKFrequent1(vector<int>& nums, int k) {
    unordered_map<int,int> map;
    for(int num : nums){
        map[num]++;
    }
    
    vector<int> res;
    // pair<first, second>: first is frequency,  second is number
    priority_queue<pair<int,int>> pq;
    for(auto it = map.begin(); it != map.end(); it++){
        // make_pair 第一个参数在排序中有更高的优先级
        pq.push(make_pair(it->second, it->first));
        // 当队列中的元素个数大于n-k个时候，pq.top数据为肯定是前k个中的，开始收集结果
        if(pq.size() > (int)map.size() - k){
            res.push_back(pq.top().second);
            pq.pop();
        }
    }
    return res;
}
// 生成n个桶
// 遍历一次存到map中：key-数，value-次数
// 再遍历map，以alue为索引把数字放入响应的桶中,再逆序遍历桶，取出k个数
vector<int> topKFrequent2(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int num : nums)
        ++m[num];
    // 不必显式插入初始化的数组
    vector<vector<int>> buckets(nums.size() + 1);
    for (auto p : m)
        buckets[p.second].push_back(p.first);
    
    vector<int> ans;
    for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
        for (int num : buckets[i]) {
            ans.push_back(num);
            if (ans.size() == k)
                break;
        }
    }
    return ans;
}

// 128. Longest Consecutive Sequence
// 求数组内最长连续子数列
// 并查集：把连续串的最小数当成串的标记节点。利用两个map ，一个存储当前数所在的集合，以连续串的最小数来标识一个结合。  另一个存储当前数为集合标记的size
class unionConseSet{
    // 存储以某个数为头的连续串长度
    unordered_map<int, int> start_length_map;
    // 存储某个节点以哪个节点为头，当节点以它本身为头时，他自己是当前串的起始节点
    unordered_map<int, int> node_root_map;

public:
    bool hasLeft(int key){
        return node_root_map.count(key-1) != 0;
    }
    bool hasRight(int key){
        return node_root_map.count(key+1) != 0;
    }
    bool hasCurrent(int key){
        return node_root_map.count(key) != 0;
    }
//    int conseLength(int key){
//        if (hasCurrent(key) == false) {
//            return 0;
//        }
//        return start_length_map[findRoot(key)];
//    }
    
    // 插入某个数到集合中，并返回次数所在的连续串长度
    int insetKey(int key){
        // 当前数在结合中，说明已经统计过，不重复统计
        if (hasCurrent(key)) {
            return 0;
        }
        bool left = hasLeft(key);
        bool right = hasRight(key);
        int rootLeft = findRoot(key-1);
        int rootRigt = findRoot(key+1);
        // 当前数小一和大一的数都在结合中，需要合并左右串并把当前数字加入到合并的串中
        if (left && right) {
            unionConse(rootLeft, rootRigt);
            start_length_map[rootLeft] += 1;
            node_root_map[key] = rootLeft;
            return start_length_map[rootLeft];
        }else if (left){// 当前数小一的数都在结合中，把当前数加入到小一所在的串中
            start_length_map[rootLeft] += 1;
            node_root_map[key] = rootLeft;
            return start_length_map[rootLeft];
        }else if(right){// 当前数大一的数都在结合中，把当前数加入到大一所在的串中,并把这个串的头设为当前数
            node_root_map[rootRigt] = key;
            node_root_map[key] = key;
            start_length_map[key] = 1 + start_length_map[rootRigt];
            return start_length_map[key];
        }else {// 左右都不在集合中，直接插入当前数
            start_length_map[key] = 1;
            node_root_map[key] = key;
            return 1;
        }
    }

    int findRoot(int key){
        if (node_root_map.count(key) == 0) {
            return 0;
        }
        if (node_root_map[key] != key) {
            node_root_map[key] = findRoot(node_root_map[key]);
        }
        return node_root_map[key];
    }

    void unionConse(int a, int b){
        int rootA = findRoot(a);
        int rootB = findRoot(b);
        if (rootA == rootB) {
            return;
        }
        start_length_map[rootA] += start_length_map[rootB];
        node_root_map[rootB] = rootA;
    }
};


int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> start_length_map;
    unordered_map<int, int> node_root_map;
    int result = 0;
    unionConseSet set = unionConseSet();
    for (int value : nums) {
        result = max(set.insetKey(value), result);
    }
    return result;
}
// 虽然看起来有多个for，实际上每个数只会访问2n次，所以复杂度为n
// 将所有数装到map中，再次遍历数组，当遍历一个数a的时候，向下连续查找map中比a小的数有几个，并从map中删除。同理检查大的数。如果map中没有当前的数a，说明a在前面已经被删除了，不需要再统计。
int longestConsecutive1(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    
    unordered_map<int, bool> m;
    for (auto num : nums) {
        m[num] = true;
    }
    
    int res = INT_MIN;
    for (auto num : nums) {
        if (m.find(num) != m.end()) {
            int cnt = 1;
            m.erase(num);
            
            int left = num - 1;
            int right = num + 1;
            while (m.find(left) != m.end()) {
                cnt++;
                m.erase(left);
                left--;
            }
            
            while (m.find(right) != m.end()) {
                cnt++;
                m.erase(right);
                right++;
            }
            
            res = max(res, cnt);
        }
    }
    
    return res;
    
}

// 300. Longest Increasing Subsequence
// 求数组中最长的升序序列长度。
// dp思想，f(i) = max(1,max(f(0),f(1)……f(i)))，复杂度为n^2
// 以i位置为结尾的升序串长度等于 0~i-1 范围所有比i位置的数小的数的结尾的序列长度+1。
int lengthOfLIS(vector<int>& nums) {
    int result = 0;
    vector<int> lengths(nums.size(),1);// 数据集合，用来存储以每个位置为结尾的最长升序序列长度
    for (int i = 0; i < nums.size(); i++) {// 遍历数组
        int maxi = 1;
        for (int j = 0; j < i; j++) {// 遍历i以下的所有已收集的数据
            if (nums[i] > nums[j]) {
                maxi = max(maxi, lengths[j]+1);
            }
        }
        lengths[i] = maxi;
        result = max(result, lengths[i]);
    }
    return result;
}

// 162. Find Peak Element
// 找出序列里的局部峰值，即比相邻数大的数,题设nums[i] ≠ nums[i+1]，nums[-1] = nums[n] = -∞。要求时间复杂度logn
// 二分查找法：if nums[mid] < nums[mid+1] 那么mid右侧肯定出现至少一个升序序列，又因为nums[n] = -∞，所以右侧肯定出现局部峰值，所以left = mid+1。左侧同理。

int findPeakElement(vector<int>& nums) {
    int left = 0,right = nums.size()-1;
    while (left < right) {
        int mid = left +(right-left)/2;
        if (nums[mid] < nums[mid+1]) {
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return right;
}



























