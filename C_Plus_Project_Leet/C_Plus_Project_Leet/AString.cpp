//
//  AString.cpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/3/6.
//  Copyright © 2019年 dida. All rights reserved.
//
using namespace std;

#include "AString.hpp"

#include <vector>
#include <unordered_map>

vector<int> getNext(string str) {
    vector<int> next;
    next.push_back(-1);
    next.push_back(0);
//    for (int i = 2; i<str.length(); i++) {
//        int index = i-1;
//        while (index>0) {
//            int length = next[index];
//            if (str[length] == str[i-1]) {
//                next.push_back(length+1);
//                break;
//            }
//            index = length;
//        }
//        if (index <= 0) {
//            next.push_back(0);
//        }
//    }
    
    int cn = 0;
    int i = 2;
    while ( i <str.length()) {
        if (str[i-1] == str[cn]) {
            next[i++] = ++cn;
        }else if (cn > 0) {
            cn = next[cn];
        } else {
            next[i++] = 0;
        }
    }
    
    return next;
}
// 28. Implement strStr()
int strStr(string haystack, string needle) {
    
    int i = 0;
    int j = 0;
    vector<int> next = getNext(needle);
    while (i < haystack.length() && j < needle.length()) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        }else if (next[j] == -1){
            j = 0;
            i++;
        } else {
            j = next[j];
        }
    }
    
    
    return j<needle.length() ? -1 : i-j ;
}

// 5. Longest Palindromic Substring

//bool isPal(string str,int center,int radius) {
//    if (charsS[i-radius] == charsS[i+radius]) {
//        return true;
//    }
//    return false;
//}

string longestPalindrome(string s) {
    
    if (s.length()<=1) {
        return s;
    }
    string charsS = "#";
    for (int i = 0; i<s.length(); i++) {
        charsS = charsS + s[i];
        charsS = charsS + "#";
    }
    int len = charsS.length();
    int i = 1;
    int maxCenter = 0;
    int maxRadius = 0;
    int maxBoundaryCenterIndex = 0;
    int maxRightPalBoundary = 0;
    vector<int> indexpalRadius(len);
    indexpalRadius[0] = 0;

    while (i < len) {
        if (i < maxRightPalBoundary) {
            int symIndex = maxBoundaryCenterIndex-(i-maxBoundaryCenterIndex);
            int symRadius = indexpalRadius[symIndex];
            int symLeftBoundary = symIndex-symRadius;
            int maxLeftPalBoundary = maxBoundaryCenterIndex - (maxRightPalBoundary-maxBoundaryCenterIndex);
            if (maxLeftPalBoundary < symLeftBoundary) {
                indexpalRadius[i] = symRadius;
            }else if (maxLeftPalBoundary > symLeftBoundary) {
                indexpalRadius[i] = maxRightPalBoundary - i;
            }else {
                int L = i -symRadius-1;
                int R = i +symRadius+1;
                while (L >= 0 && R < len && charsS[L] == charsS[R]) {
                    L--;
                    R++;
                    if (L < 0 || R >= len) {
                        break;
                    }
                }
                maxBoundaryCenterIndex = i;
                maxRightPalBoundary = R-1;
                indexpalRadius[i] = R-i-1;
            }
        } else {
            
            int L = i -1;
            int R = i +1;
            while (L >= 0 && R < len && charsS[L] == charsS[R]) {
//                ++i_maxRadius;
                L--;
                R++;
                if (L<0 || R>= len) {
                    break;
                }
            }
            maxBoundaryCenterIndex = i;
            maxRightPalBoundary = R-1;
            indexpalRadius[i] = R-i-1;
        }
        
        if (indexpalRadius[i] > maxRadius) {
            maxRadius = indexpalRadius[i];
            maxCenter = i;
        }
        
        i++;
    }
    int realCenter = maxCenter/2;
    int start = realCenter - maxRadius/2;
    string result = s.substr(start,maxRadius);

    return result;
    
//    int n = s.size();
//    if (n <= 1)
//        return s; // 添加特殊字符
//    string str;
//    for (int i = 0; i < n; i++){
//        str += "#"; str += s[i];
//
//    }
//    str += "#";
//    int len = 2 * n + 1;
//    vector<int> p(len); // p[i]为回文中心半径数组(包括以str[i])
//    int index; // 回文中心位置, pR更新时 index跟着跟新; pR不更新，index保持不变
//    int pR; // // 回文中心最右边的 下一个
//    int maxlen = 1; //最大回文长度变量
//    int pos; // 记录最大回文的中心位置
//    // i=0, i=1单独处理
//    p[0] = 1; p[1] = 2;
//    index = 1;
//    pR = 3;
//    pos = 1;
//    for (int i = 2; i < len; i++) {
//        int _i = index - (i - index);
//        int index_left = index - p[index] + 1;
//        int index_right = pR - 1;
//        int _i_left = _i - p[_i] + 1;
//        if (_i_left < index_left) //  1
//        {   int j = i + 1;
//            int _j = i - 1;
//            while (str[j] == str[_j] && _j >= 0 && j < len) {
//                _j--;
//                j++;
//                if (_j < 0 || j >= len) break;
//
//            }
//            p[i] = j - i;
//            pR = j;
//            index = i;
//
//        } else{ if (index_left < _i_left){ // 2
//            p[i] = p[_i];
//
//        } else if (index_left > _i_left){ // 3
//            p[i] = index_right - i - 1;
//
//        } else//if (_i_left == index_left) // 4
//        { // 往外扩
//            int j = pR;
//            int _j = i - (pR - i);
//            while (str[_j] == str[j] && _j >= 0 && j < len) {
//                _j--;
//                j++;
//                if (_j < 0 || j >= len) break;
//
//            }
//            p[i] = j - i;
//            pR = j; // 更新pR 和 index index = i;
//
//        }
//
//        }
//        if (p[i] - 1 > maxlen){
//            maxlen = p[i] - 1;
//            pos = i; }
//
//    }// end for // 得到子串
//    int realpos = pos / 2;
//    int startpos = realpos - maxlen / 2;
//    string ans = s.substr(startpos, maxlen);
//    return ans;
    
}

// 3. Longest Substring Without Repeating Characters
// 求最大无重复字符子串长度
// 快慢指针left、right。 用map记录是否出现过，key-字符 value-索引。若字符x在map中，移动left到上一个x出现位置的下一位m，并移除left-m范围的缓存；否则记录当前字符。
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> indexMap;
    int left = 0,right = 0;
    int res = 0;
    while (right < s.size()) {
        if (indexMap.find(s[right]) == indexMap.end()) {
            indexMap[s[right]] = right;
            right++;
            res = max(right-left, res);
        } else {
            int nextLeft = indexMap[s[right]]+1;
            while (left < nextLeft) {
                indexMap.erase(s[left++]);
            }
        }
    }
    return res;
}
// 若有重复字符最大长度出现在两个相同字符之间或首尾。
// asii码最大长度为256，用256的数组记录遍历过程中字符最后一次出现的位置。
int lengthOfLongestSubstring1(string s) {
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] > start)// 出现了重复字符，如果此字符上一个位置比start大，那么start = 这个字符出现的上一次位置，即把start向后推
            start = dict[s[i]];
        dict[s[i]] = i;// 更新字符最后一次出现的位置
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

// 131. Palindrome Partitioning
vector<vector<string>> partition(string s) {
    return NULL;
}

void partitionProcess(string s,int begin,int c,vector<vector<string>>& result){
    
}

