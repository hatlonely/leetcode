//
//  123_best_time_to_buy_and_sell_stock_iii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/26.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Say you have an array for which the ith element is the price of a given stock on day i.
//  Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
//  Note:
//  You may not engage in multiple transactions at the same time
//  (ie, you must sell the stock before you buy again).
//

#include <iostream>
#include <cassert>
#include <vector>

namespace best_time_to_buy_and_sell_stock_iii {
    
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int size = (int)prices.size();
        std::vector<int> profits(size + 1, 0);
        
        int max_profit = 0;
        int min_price  = INT_MAX;
        for (int i = 0; i < size; i++) {
            min_price  = std::min(min_price, prices[i]);
            max_profit = std::max(max_profit, prices[i] - min_price);
            profits[i + 1] = max_profit;
        }
        
        max_profit = 0;
        int max_price  = INT_MIN;
        for (int i = size - 1; i >= 0; i--) {
            max_price  = std::max(max_price, prices[i]);
            max_profit = std::max(max_profit, max_price - prices[i]);
            profits[i] += max_profit;
        }
        
        return *std::max_element(profits.begin(), profits.end());
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> prices(li);
        int result = solution.maxProfit(prices);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({1, 2}, 1));
    assert(test({6, 1, 3, 2, 4, 7}, 7));
    
    return 0;
}
    
}
