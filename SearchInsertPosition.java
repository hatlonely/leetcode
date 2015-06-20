package leetcode;

// 35 Search Insert Position
// https://leetcode.com/problems/search-insert-position/
// Given a sorted array and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.
//
// You may assume no duplicates in the array.
//
// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

public class SearchInsertPosition {
    public int searchInsert(int[] nums, int target) {
        int idx1 = 0;
        int idx2 = nums.length  - 1;
        
        while (idx1 < idx2) {
            int mid = (idx1 + idx2) / 2;
            if (nums[mid] > target) {
                idx2 = mid - 1;
            } else if (nums[mid] < target) {
                idx1 = mid + 1;
            } else {
                return mid;
            }
        }
        
        if (idx1 == idx2 && nums[idx1] < target) {
            return idx1 + 1;
        } else {
            return idx1;
        }
    }
    
    public static void main(String[] args) {
        SearchInsertPosition searchInsertPosition = new SearchInsertPosition();
        System.out.println(searchInsertPosition.searchInsert(new int[]{1,3,5,6}, 5) == 2);
        System.out.println(searchInsertPosition.searchInsert(new int[]{1,3,5,6}, 2) == 1);
        System.out.println(searchInsertPosition.searchInsert(new int[]{1,3,5,6}, 7) == 4);
        System.out.println(searchInsertPosition.searchInsert(new int[]{1,3,5,6}, 0) == 0);
        System.out.println(searchInsertPosition.searchInsert(new int[]{1}, 0) == 0);
        System.out.println(searchInsertPosition.searchInsert(new int[]{1, 3}, 0) == 0);
    }
}
