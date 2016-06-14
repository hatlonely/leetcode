# 2. Add Two Numbers
#
# You are given two linked lists representing two non-negative numbers.
# The digits are stored in reverse order and each of their nodes contain a single digit.
# Add the two numbers and return it as a linked list.
#
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    def __str__(self):
        result = ''
        node = self
        while node:
            result += str(node.val)
            result += ' -> '
            node = node.next
        return result


def CreateList(li):
    prev = ListNode(0)
    node = prev
    for i in li:
        node.next = ListNode(i)
        node = node.next
    return prev.next


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        node1 = l1;
        node2 = l2;
        prev = ListNode(0)
        node = prev
        carry = 0
        while node1 and node2:
            value = node1.val + node2.val + carry
            carry = int(value / 10)
            node.next = ListNode(value % 10)
            node1 = node1.next
            node2 = node2.next
            node = node.next
        while node1:
            value = node1.val + carry
            carry = int(value / 10)
            node.next = ListNode(value % 10)
            node1 = node1.next
            node = node.next
        while node2:
            value = node2.val + carry
            carry = int(value / 10)
            node.next = ListNode(value % 10)
            node2 = node2.next
            node = node.next
        if carry != 0:
            node.next = ListNode(carry)
        return prev.next



def main():
    solution = Solution()
    print(solution.addTwoNumbers(CreateList([2, 4, 3]), CreateList([5, 6, 4]))) # 7 -> 0 -> 8
    print(solution.addTwoNumbers(CreateList([5]), CreateList([5])))             # 0 -> 1


if __name__ == '__main__':
    main()
