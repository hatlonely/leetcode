// 71 Simplify Path
// https://leetcode.com/problems/simplify-path/
//
// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

package leetcode;

public class SimplifyPath {
    public String simplifyPath(String path) {
        StringBuffer buffer = new StringBuffer(path);

        int idx1 = 0;
        int idx2 = 0;
        while (idx2 < buffer.length()) {
            while (idx2 < buffer.length() && buffer.charAt(idx2) == '/') {
                idx2++;
            }
            int pos = idx2;
            while (idx2 < buffer.length() && buffer.charAt(idx2) != '/') {
                idx2++;
            }
            if (idx2 - pos == 1 && buffer.charAt(pos) == '.') {
                // nothing to do
            } else if (idx2 - pos == 2 && buffer.charAt(pos) == '.'
                    && buffer.charAt(pos + 1) == '.') {
                while (buffer.charAt(idx1) != '/') {
                    idx1--;
                }
                if (idx1 > 0) {
                    idx1--;
                }
            } else {
                if (buffer.charAt(idx1) != '/') {
                    buffer.setCharAt(++idx1, '/');
                }
                for (int i = pos; i < idx2; i++) {
                    buffer.setCharAt(++idx1, buffer.charAt(i));
                }
            }
            idx2++;
        }

        if (buffer.charAt(idx1) == '/' && idx1 > 0) {
            return buffer.substring(0, idx1);
        }
        return buffer.substring(0, idx1 + 1);
    }

    public static void main(String[] args) {
        SimplifyPath simplifyPath = new SimplifyPath();
        System.out.println(simplifyPath.simplifyPath("/home/"));
        System.out.println(simplifyPath.simplifyPath("/a/./b/../../c/"));
        System.out.println(simplifyPath.simplifyPath("/home//foo/"));
        System.out.println(simplifyPath.simplifyPath("//"));
    }
}
