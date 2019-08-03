//
//  main.cpp
//  LeetCode 455.Assign Cookies
//
//  Created by swae on 2019/8/3.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 LeetCode 455. Assign Cookies
 来自：https://leetcode.com/problems/assign-cookies/
 难度：easy

 分糖果
 已知一些孩子和一些糖果，每个孩子有需求因子g，每个糖果有大小s，当 某个糖果的大小s >= 某个孩子的需求因子g时，代表该糖果可以满足该孩子;求使用这 些糖果，最多能满足多少孩子?(注意，某个孩子最多只能用1个糖果满足)
 例如，需求因子数组g = [5, 10, 2, 9, 15, 9];糖果大小数组s = [6, 1, 20, 3, 8];最多可以 满足3个孩子。
 
 例如，需求因子数组 g = [5, 10, 2, 9, 15, 9];糖果大小数组 s = [6, 1, 20, 3, 8]。 为了更明显的判断某个孩子可以被某个糖果满足，对g, s进行排序后
 观察:
 g = [2, 5, 9, 9, 10, 15];s = [1, 3, 6, 8, 20]。
 1.是否可以直接暴力枚举，对每个糖果都尝试是否可以满足某个 孩子?
 2.当某个孩子可以被多个糖果满足时，是否需要优先用某个糖果满足这 个孩子?
 3.当某个糖果可以满足多个孩子时，是否需要优先满足某个孩子?
 
 贪心规律
 需求因子数组 g = [2, 5, 9, 9, 10, 15];糖果大小数组 s = [1, 3, 6, 8, 20]。 核心目标:让更多孩子得到满足，有如下规律:
 1.某个糖果如果不能满足某个孩子，则该糖果也一定不能满足需求因子更大的孩子。 如，
 糖果1(s = 1)不能满足孩子1(g = 2)，则不能满足孩子2、孩子3、...、孩子7;
 糖果2(s = 3)不能满足孩子2(g = 5)，则不能满足孩子3、孩子4、...、孩子7;
 ...
 2.某个孩子可以用更小的糖果满足，则没必要用更大糖果满足，因为可以保留更大的糖果
 满足需求因子更大的孩子。(贪心!) 如，
 孩子1(g = 2)，可以被糖果2(s = 3)满足，则没必要用糖果3、糖果4、糖果5满足; 孩子2(g = 5)，可以被糖果3(s = 6)满足，则没必要用糖果4、糖果5满足;
 ...
 3.孩子的需求因子更小则其更容易被满足，故优先从需求因子小的孩子尝试，用某个糖果 满足一个较大需求因子的孩子或满足一个较小需求因子的孩子效果是一样的(最终满足的总量 不变)。(贪心!)
 
 算法思路
 1.对需求因子数组g与糖果大小数组s进行从小到大的排序。 2.按照从小到大的顺序使用各糖果尝试是否可满足某个孩子，每个糖果只尝试1
 次;若尝试成功，则换下一个孩子尝试;直到发现没更多的孩子或者没更多的 糖果，循环结束。
 
 */

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 对孩子的需求因子g与糖果大小s 两个数组进行排序
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        // child代表满足第几个孩子
        int child = 0;
        // cookie 代表尝试了第几个糖果
        int cookie = 0;
        while (child < g.size() && cookie < s.size()) {
            // 当孩子需要的糖果满足这份糖果数量时
            if (g[child] <= s[cookie]) {
                // 准备让下一个孩子要糖果
                child++;
            }
            // 无论成功还是失败，每份糖果只尝试一次，准备下一份糖果
            cookie++;
        }
        // 最终的child为满足糖果的孩子数量
        return child;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution sovle;
    // 记录每个孩子需要的糖果数量
    std::vector<int> g;
    // 记录每份的数量
    std::vector<int> s;
    
    g.push_back(5);
    g.push_back(10);
    g.push_back(2);
    g.push_back(9);
    g.push_back(15);
    g.push_back(9);
    s.push_back(6);
    s.push_back(1);
    s.push_back(20);
    s.push_back(3);
    s.push_back(8);
    
    int count = sovle.findContentChildren(g, s);
    std::cout << s.size() <<"份糖果满足了" << count << "个孩子" << std::endl;
    
    return 0;
}
