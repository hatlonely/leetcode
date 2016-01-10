// 4 Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
//
// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    var nums = nums1.concat(nums2);
    nums.sort(function(a, b) {
        return a - b;
    });

    var len = nums.length;
    if (len % 2 === 0) {
        return (nums[len / 2] + nums[len / 2 - 1]) / 2;
    } else {
        return nums[parseInt(len / 2)];
    }
};

var test = function() {
    console.log(findMedianSortedArrays([1, 2, 3], [4, 5, 6]));
    console.log(findMedianSortedArrays([], [1]));
    console.log(findMedianSortedArrays([], [2, 3]));
    console.log(findMedianSortedArrays([1], [2, 3, 4, 5, 6, 7, 8, 9, 10]));
};

test();
