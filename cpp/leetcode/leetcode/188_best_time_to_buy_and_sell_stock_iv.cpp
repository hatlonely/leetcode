//
//  188_best_time_to_buy_and_sell_stock_iv.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Say you have an array for which the ith element is the price of a given stock on day i.
//
//  Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
//  Note:
//  You may not engage in multiple transactions at the same time
//  (ie, you must sell the stock before you buy again).
//

#include <iostream>
#include <cassert>
#include <vector>

namespace best_time_to_buy_and_sell_stock_iv {
    
class Solution {
public:
    int maxProfit(int k, std::vector<int> &prices) {
        if (prices.empty() || k <= 0) {
            return 0;
        }
        // 如果 k 很大，可以认为没有次数限制
        if (k > prices.size()) {
            return max_profit_without_limit(prices);
        }
        
        // global[i][j] 表示 max_profit(j, prices[0 : i - 1])
        // local[i][j]  表示 max_profit(j, prices[0 : i - 1]) 并且 最后一天参与了交易
        //
        // profit = prices[i] - prices[i - 1]
        // global[i][j] = max(global[i - 1][j], local[i][j])
        //      分为最后一天参与交易，local[i][j]
        //      或者最后一天没有交易，global[i - 1][j]
        // local[i][j]  = max(local[i - 1][j] + profit, global[i - 1][j - 1] + max(profit, 0))
        //      分为最后一天参与了上一次的交易 local[i - 1][j]
        //      或者最后一天和前一天组成一次交易  global[i - 1][j - 1] + profit
        std::vector<int> global(k + 1, 0);
        std::vector<int> local(k + 1, 0);
        
        // 下面的计算重复利用上一次的结果，将二维化为了一维度
        for (int i = 1; i < (int)prices.size(); i++) {
            int profit = prices[i] - prices[i - 1];
            for (int j = k; j >= 1; j--) {  // 为了用到上一次的结果，所以这里逆序遍历
                local[j]  = std::max(local[j] + profit, global[j - 1] + std::max(profit, 0));
                global[j] = std::max(global[j], local[j]);
            }
        }
        
        return global[k];
    }
    
    int max_profit_without_limit(std::vector<int> &prices) {
        int max_profit = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        return max_profit;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int k, std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> prices(li);
        int result = solution.maxProfit(k, prices);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    (test(1, {6, 1, 3, 2, 4, 7}, 6));
    (test(2, {6, 1, 3, 2, 4, 7}, 7));
    
    return 0;
}
    
}
