// 60 Permutation Sequence
// https://leetcode.com/problems/permutation-sequence/
//
// The set [1,2,3,…,n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
//
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
//
// Note: Given n will be between 1 and 9 inclusive.

package leetcode;

import java.util.LinkedList;
import java.util.List;

public class PermutationSequence {
    private static int factorial(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }

        return result;
    }

    private static final int[] factorialArray = new int[] { factorial(1), factorial(2),
        factorial(3), factorial(4), factorial(5), factorial(6), factorial(7), factorial(8),
        factorial(9), };

    public String getPermutation(int n, int k) {
        k %= factorialArray[n - 1];

        StringBuffer buffer = new StringBuffer(n);
        buffer.setLength(n);
        List<Character> list = new LinkedList<Character>();
        for (int i = 1; i < n + 1; i++) {
            list.add((char) ('0' + i));
        }

        int idx = 0;
        while (idx < n + 1) {
            // 如果k == 0, 逆序
            if (k == 0) {
                while (!list.isEmpty()) {
                    buffer.setCharAt(idx++, list.get(list.size() - 1));
                    list.remove(list.size() - 1);
                }
                break;
            }
            int factorialPosition = 0; // 在阶乘数中的位置
            while (factorialArray[factorialPosition] <= k) {
                factorialPosition++;
            }
            // 将数顺序填入buffer中，只需剩下pos + 1个数
            while (list.size() > factorialPosition + 1) {
                buffer.setCharAt(idx++, list.get(0));
                list.remove(0);
            }
            // 设置当前位置为第x个数
            int currentPosition = (k - 1) / factorialArray[factorialPosition - 1];
            buffer.setCharAt(idx++, list.get(currentPosition));
            list.remove(currentPosition);

            // 更新k
            k = k % factorialArray[factorialPosition - 1];
        }

        return buffer.toString();
    }

    public static void main(String[] args) {
        PermutationSequence permutationSequence = new PermutationSequence();
        for (int i = 1; i <= factorial(4); i++) {
            System.out.println(permutationSequence.getPermutation(4, i));
        }
    }
}
