// 28 Implement strStr()
// https://leetcode.com/problems/implement-strstr/
// Implement strStr().
//
// Returns the index of the first occurrence of needle in haystack,
// or -1 if needle is not part of haystack

package leetcode;

public class ImplementStrStr {
    // 字符串匹配sunday算法
    public int strStr(String haystack, String needle) {
        for (int i = 0; i < haystack.length();) {
            boolean isMatch = true;
            // 匹配字符串与源字符串是否匹配
            for (int j = 0; j < needle.length(); j++) {
                if (i + j > haystack.length() - 1) {
                    return -1;
                }
                if (haystack.charAt(i + j) != needle.charAt(j)) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                return i;
            }

            int k = i + needle.length(); // 获取下一个字符
            if (k > haystack.length() - 1) {
                return -1;
            }
            for (int j = needle.length() - 1; j >= 0; j--) {
                // 下一个字符于匹配字符串中匹配，按照这个字符串对齐
                if (haystack.charAt(k) == needle.charAt(j)) {
                    i += needle.length() - j;
                    isMatch = true;
                    break;
                }
            }
            // 下一个字符于匹配字符串完全不匹配（匹配字符串中不包含该字符）
            // 直接跳过匹配字符串的长度 + 1
            if (!isMatch) {
                i += needle.length() + 1;
            }
        }

        // 匹配字符串为空串，返回0
        if (needle.length() == 0) {
            return 0;
        }
        return -1;
    }

    public static void main(String[] args) {
        ImplementStrStr implementStrStr = new ImplementStrStr();
        System.out.println(implementStrStr.strStr("abcdefghijklmn", "def") == 3);
        System.out.println(implementStrStr.strStr("abcdddeedefghijklmn", "def") == 8);
        System.out.println(implementStrStr.strStr("aaa", "aaaa") == -1);
        System.out.println(implementStrStr.strStr("mississippi", "a") == -1);
        System.out.println(implementStrStr.strStr("", "") == 0);
        System.out.println(implementStrStr.strStr("a", "a") == 0);
    }
}
