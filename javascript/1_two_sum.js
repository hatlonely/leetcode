// 1 Two Sum
// https://leetcode.com/problems/two-sum/
//
// Given an array of integers, return indices of the two numbers
// such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution.
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//
// UPDATE (2016/2/13):
// The return format had been changed to zero-based indices.
// Please read the above updated description carefully.
//

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var num_idx_map = {};
    for (var i = 0; i < nums.length; i++) {
        num_idx_map[nums[i]] = i;
    }

    for (var i = 0; i < nums.length; i++) {
        var idx = num_idx_map[target - nums[i]];
        if (idx == undefined || idx == i) {
            continue;
        }
        if (i > idx) {
            return [idx, i];
        } else {
            return [i, idx];
        }
    }
    return [];
};

var test = function() {
    console.log(twoSum([2, 7, 11, 15], 9))
};

test();
