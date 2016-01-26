//
//  121_best_time_to_buy_and_sell_stock.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/26.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Say you have an array for which the ith element is the price of a given stock on day i.
//
//  If you were only permitted to complete at most one transaction
//  (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace best_time_to_buy_and_sell_stock {

namespace best_time_to_buy_and_sell_stock_1 {
    
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int size = (int)prices.size();
        int idx1 = 0;
        int idx2 = 1;
        int max = 0;
        while (idx2 < size) {
            while (idx2 < size && prices[idx2 - 1] < prices[idx2]) {
                idx2++;
            }
            if (max < prices[idx2 - 1] - prices[idx1]) {
                max = prices[idx2 - 1] - prices[idx1];
            }
            while (idx2 < size && prices[idx2 - 1] >= prices[idx2]) {
                idx2++;
            }
            if (prices[idx2 - 1] < prices[idx1]) {
                idx1 = idx2 - 1;
            }
        }
        
        return max;
    }
};
    
}
    
namespace best_time_to_buy_and_sell_stock_2 {

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int max_profit = 0;
        int min_price  = INT_MAX;
        
        for (int i = 0; i < (int)prices.size(); i++) {
            min_price  = std::min(min_price, prices[i]);
            max_profit = std::max(max_profit, prices[i] - min_price);
        }
        
        return max_profit;
    }
};

}

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        best_time_to_buy_and_sell_stock_2::Solution solution;
        std::vector<int> prices(li);
        int result = solution.maxProfit(prices);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({4, 3, 2, 5, 6, 8}, 6));
    assert(test({6, 1, 3, 2, 4, 7}, 6));
    assert(test({}, 0));
    
    return 0;
}
    
}
