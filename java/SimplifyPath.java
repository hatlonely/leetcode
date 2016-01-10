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

        int bufferIndex = 0;
        int pathIndex = 0;
        while (pathIndex < buffer.length()) {
            while (pathIndex < buffer.length() && buffer.charAt(pathIndex) == '/') {
                pathIndex++;
            }
            int start = pathIndex;
            while (pathIndex < buffer.length() && buffer.charAt(pathIndex) != '/') {
                pathIndex++;
            }
            if (pathIndex - start == 1 && buffer.charAt(start) == '.') {
                // nothing to do
            } else if (pathIndex - start == 2 && buffer.charAt(start) == '.'
                    && buffer.charAt(start + 1) == '.') {
                while (buffer.charAt(bufferIndex) != '/') {
                    bufferIndex--;
                }
                if (bufferIndex > 0) {
                    bufferIndex--;
                }
            } else {
                if (buffer.charAt(bufferIndex) != '/') {
                    buffer.setCharAt(++bufferIndex, '/');
                }
                for (int i = start; i < pathIndex; i++) {
                    buffer.setCharAt(++bufferIndex, buffer.charAt(i));
                }
            }
            pathIndex++;
        }

        if (buffer.charAt(bufferIndex) == '/' && bufferIndex > 0) {
            return buffer.substring(0, bufferIndex);
        }
        return buffer.substring(0, bufferIndex + 1);
    }

    public static void main(String[] args) {
        SimplifyPath simplifyPath = new SimplifyPath();
        System.out.println(simplifyPath.simplifyPath("/home/"));
        System.out.println(simplifyPath.simplifyPath("/a/./b/../../c/"));
        System.out.println(simplifyPath.simplifyPath("/home//foo/"));
        System.out.println(simplifyPath.simplifyPath("//"));
    }
}
