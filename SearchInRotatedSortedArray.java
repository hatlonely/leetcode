// 33 Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
//
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// You are given a target value to search. If found in the array return its index,
// otherwise return -1.
// You may assume no duplicate exists in the array.

package leetcode;

public class SearchInRotatedSortedArray {
    public int search(int[] nums, int target) {
        int search_point = 0;
        // 如果第一个值小于最后一个值，说明序列是有序的，否则是经过rotate的
        if (nums[0] > nums[nums.length - 1]) {
            search_point = binary_search_point(nums, 0, nums.length - 1);
        } else {
            return binary_search(nums, 0, nums.length - 1, target);
        }

        // 要查找的值大于第一个值，在左边段，否则在右边段
        if (target >= nums[0]) {
            return binary_search(nums, 0, search_point, target);
        } else {
            return binary_search(nums, search_point + 1, nums.length - 1, target);
        }
    }

    // 二分查找轴值
    public int binary_search_point(int[] nums, int beginIndex, int endIndex) {
        while (beginIndex < endIndex) {
            // 数组中之后两个数时，如果第一个数大于第二个数时，则第一个数为轴值
            // 否则不存在轴值
            if (endIndex - beginIndex == 1) {
                if (nums[beginIndex] > nums[endIndex]) {
                    return beginIndex;
                } else {
                    return -1;
                }
            }
            int middleIndex = (beginIndex + endIndex) / 2;
            if (nums[beginIndex] > nums[middleIndex]) {
                endIndex = middleIndex;
            } else if (nums[middleIndex + 1] > nums[endIndex]) {
                beginIndex = middleIndex + 1;
            } else {
                return middleIndex;
            }
        }

        return -1;
    }

    // 二分查找
    public int binary_search(int[] nums, int beginIndex, int endIndex, int target) {
        while (beginIndex <= endIndex) {
            int middleIndex = (beginIndex + endIndex) / 2;
            if (nums[middleIndex] < target) {
                beginIndex = middleIndex + 1;
            } else if (nums[middleIndex] > target) {
                endIndex = middleIndex - 1;
            } else {
                return middleIndex;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        SearchInRotatedSortedArray searchInRotatedSortedArray = new SearchInRotatedSortedArray();
        System.out.println(searchInRotatedSortedArray.search(new int[] { 3 }, 3) == 0);
        System.out.println(searchInRotatedSortedArray.search(new int[] { 1, 2, 5 }, 5) == 2);
        System.out.println(searchInRotatedSortedArray.search(new int[] { 2, 3, 4, 1 }, 3) == 1);
    }
}
