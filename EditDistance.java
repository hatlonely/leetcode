// 72 Edit Distance
// https://leetcode.com/problems/edit-distance/
//
// Given two words word1 and word2, find the minimum number of steps
// required to convert word1 to word2. (each operation is counted as 1 step.)
//
// You have the following 3 operations permitted on a word:
//
// a) Insert a character
// b) Delete a character
// c) Replace a character

package leetcode;

public class EditDistance {
    public int minDistance(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int[][] distances = new int[len1 + 1][len2 + 1];
        for (int i = 0; i < len1 + 1; i++) {
            distances[i][0] = i;
        }
        for (int j = 0; j < len2 + 1; j++) {
            distances[0][j] = j;
        }

        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                distances[i][j] = Math.min(Math.min(distances[i - 1][j], distances[i][j - 1]) + 1,
                        distances[i - 1][j - 1]
                                + (word1.charAt(i - 1) == word2.charAt(j - 1) ? 0 : 1));
            }
        }

        return distances[len1][len2];
    }

    public static void main(String[] args) {
        EditDistance editDistance = new EditDistance();
        System.out.println(editDistance.minDistance("sissie", "hatlonely"));
    }
}
