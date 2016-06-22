// 2 Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/
//
// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8


function ListNode(val) {
    this.val = val;
    this.next = null;

    this.toString = function() {
        var node = this;
        var result = "";
        while (node != null) {
            result += node.val + " -> ";
            node = node.next;
        }

        return result;
    }
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var node1 = l1;
    var node2 = l2;
    var result = new ListNode(0);
    var node = result;

    var carry = 0;
    while (node1 && node2) {
        var value = node1.val + node2.val + carry;
        node.next = new ListNode(value % 10);
        if (value >= 10) {
            carry = 1;
        } else {
            carry = 0;
        }
        node1 = node1.next;
        node2 = node2.next;
        node = node.next;
    }

    while (node1) {
        value = node1.val + carry;
        node.next = new ListNode(value % 10);
        if (value >= 10) {
            carry = 1;
        } else {
            carry = 0;
        }
        node1 = node1.next;
        node = node.next;
    }

    while (node2) {
        value = node2.val + carry;
        node.next = new ListNode(value % 10);
        if (value >= 10) {
            carry = 1;
        } else {
            carry = 0;
        }
        node2 = node2.next;
        node = node.next;
    }

    if (carry == 1) {
        node.next = new ListNode(1);
    }

    return result.next;
};

var test = function() {
    var node1 = new ListNode(2);
    node1.next = new ListNode(4);
    node1.next.next = new ListNode(3);

    var node2 = new ListNode(5);
    node2.next = new ListNode(6);
    node2.next.next = new ListNode(4);

    var node = addTwoNumbers(node1, node2);
    console.log(node1.toString());
    console.log(node2.toString());
    console.log(node.toString());
}

test();
