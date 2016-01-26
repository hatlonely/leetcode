//
//  122_best_time_to_buy_and_sell_stock_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/26.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Say you have an array for which the ith element is the price of a given stock on day i.
//
//  Design an algorithm to find the maximum profit. You may complete as many transactions
//  as you like (ie, buy one and sell one share of the stock multiple times).
//  However, you may not engage in multiple transactions at the same time
//  (ie, you must sell the stock before you buy again).
//

#include <iostream>
#include <cassert>
#include <vector>

namespace best_time_to_buy_and_sell_stock_ii {
    
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int max_prices = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                max_prices += prices[i] - prices[i - 1];
            }
        }
        return max_prices;
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
    
    assert(test({4, 3, 2, 5, 6, 8}, 6));
    
    return 0;
}
    
}
