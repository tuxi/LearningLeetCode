//
//  main.cpp
//  LeetCode 376. Wiggle Subsequence
//
//  Created by swae on 2019/8/4.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <vector>

/*
 376. Wiggle Subsequence
 出自：https://leetcode.com/problems/wiggle-subsequence/
 难度：Medium
 
 一个整数序列，如果两个相邻元素的差恰好正负(负正)交替出现，则该序列被称为摇摆序列。一个小于2个元素的序列直接为摇摆序列。
 例如:
 序列 [1, 7, 4, 9, 2, 5]，相邻元素的差 (6, -3, 5, -7, 3)，该序列为摇摆序列。 序列 [1,4,7,2,5] (3, 3, -5, 3)、 [1,7,4,5,5] (6, -3, 1, 0)不是摇摆序列。
 给一个随机序列，求这个序列满足摇摆序列定义的最长子序列的长度。 例如: 输入[1,7,4,9,2,5]，结果为6;输入[1,17,5,10,13,15,10,5,16,8]，结果为7([1,17,10,13,10,16,8] );输入[1,2,3,4,5,6,7,8,9]，结果为2。
 
 贪心规律：
 当序列有一段连续的递增(或递减)时，为形成摇摆子序列，我们只需要 保留这段连续的递增(或递减)的首尾元素，这样更可能使得尾部的后一个元
 素成为摇摆子序列的下一个元素。
 */

using namespace std;

// 扫描摇摆序列的三种状态
typedef enum : int {
    WiggleStateBEIGIN,
    WiggleStateUP,
    WiggleStateDOWN,
} WiggleState;

class Solution {
public:
    // 求摇摆序列的最大长度
    int wiggleMaxLength(vector<int>& nums) {
       
        // 如果数组的个数小于2时，摇摆序列的个数就是数组的个数
        if (nums.size() < 2) {
            return (int)nums.size();
        }
        int maxLength = 1;
        WiggleState state = WiggleStateBEIGIN;
        
        // 遍历 扫描摇摆序列
        for (vector<int>::iterator it = nums.begin()+1; it != nums.end(); ++it) {
            switch (state) {
                case WiggleStateBEIGIN:
                    if (*(it-1) < *it) {
                        state = WiggleStateUP;
                        maxLength++;
                    }
                    else if (*(it-1) > *it) {
                        state = WiggleStateDOWN;
                        maxLength++;
                    }
                    break;
                case WiggleStateUP:
                    if (*(it-1) > *it) {
                        state = WiggleStateDOWN;
                        maxLength++;
                    }
                    break;
                case WiggleStateDOWN:
                    if (*(it-1) < *it) {
                        state = WiggleStateUP;
                        maxLength++;
                    }
                    break;
            }
        }
        return maxLength;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    [1,17,5,10,13,15,10,5,16,8]
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(17);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(13);
    nums.push_back(15);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(16);
    nums.push_back(8);
    
    Solution solve;
    int maxLength = solve.wiggleMaxLength(nums);
    cout << "摇摆序列的最大长度为："  << maxLength << endl;
    
    return 0;
}
