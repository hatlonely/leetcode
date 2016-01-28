//
//  134_gas_station.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/28.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  There are N gas stations along a circular route,
//  where the amount of gas at station i is gas[i].
//
//  You have a car with an unlimited gas tank and it costs cost[i] of gas
//  to travel from station i to its next station (i+1). You begin the journey
//  with an empty tank at one of the gas stations.
//
//  Return the starting gas station's index if you can travel around
//  the circuit once, otherwise return -1.
//
//  Note:
//  The solution is guaranteed to be unique.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace gas_station {
    
class Solution {
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
        int sum = 0;
        int idx = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            sum += (gas[i] - cost[i]);
            if (sum < 0) {
                idx = i + 1;
                sum = 0;
            }
        }
        
        for (int i = 0; i < idx; i++) {
            sum += (gas[i] - cost[i]);
            if (sum < 0) {
                return -1;
            }
        }
        
        return idx;
    }
};
    
int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> vi1, std::initializer_list<int> vi2, int expected) {
        Solution solution;
        std::vector<int> gas(vi1);
        std::vector<int> cost(vi2);
        int result = solution.canCompleteCircuit(gas, cost);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({1, 2, 3, 3}, {2, 1, 5, 1}, 3));
    assert(test({5}, {4}, 0));
    
    return 0;
}
    
}
