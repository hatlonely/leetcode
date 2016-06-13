# 1. two sum
#
# Given an array of integers, return indices of the two numbers such that they add up to a specific target.
#
# You may assume that each input would have exactly one solution.
#
# Example:
# Given nums = [2, 7, 11, 15], target = 9,
#
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].
#
# UPDATE (2016/2/13):
# The return format had been changed to zero-based indices. Please read the above updated description carefully.
#

class Solution(object):
    def twoSum(self, nums, target):
        numsIndexMap = {}
        if target % 2 == 0:
            half = target / 2
            indexs = []
            for i in range(0, len(nums)):
                if nums[i] == half:
                    indexs.append(i)
            if len(indexs) >= 2:
                return [indexs[0], indexs[1]]
        for i in range(0, len(nums)):
            numsIndexMap[nums[i]] = i
        for num in numsIndexMap:
            if target - num in numsIndexMap:
                return [numsIndexMap[num], numsIndexMap[target - num]]


def main():
    solution = Solution()
    print(solution.twoSum([2, 7, 11, 15], 9))
    print(solution.twoSum([0, 4, 3, 0], 0))


if __name__ == '__main__':
    main()
