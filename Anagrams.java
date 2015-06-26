// 49 Anagrams
// https://leetcode.com/problems/anagrams/
//
// Given an array of strings, return all groups of strings that are anagrams.
// Note: All inputs will be in lower-case.

package leetcode;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class Anagrams {
    public List<String> anagrams(String[] strs) {
        List<String> result = new LinkedList<String>();
        long[] hashcodes = new long[strs.length];
        boolean[] flags = new boolean[strs.length];
        Arrays.fill(flags, false);

        for (int i = 0; i < hashcodes.length; i++) {
            hashcodes[i] = hashString(strs[i]);
        }

        for (int i = 0; i < hashcodes.length; i++) {
            if (flags[i]) {
                continue;
            }
            for (int j = i + 1; j < hashcodes.length; j++) {
                if (flags[j]) {
                    continue;
                }
                if (hashcodes[i] == hashcodes[j]) {
                    flags[i] = true;
                    flags[j] = true;
                }
            }
        }

        for (int i = 0; i < flags.length; i++) {
            if (flags[i]) {
                result.add(strs[i]);
            }
        }

        return result;
    }

    public long hashString(String str) {
        long[] times = new long[26];
        Arrays.fill(times, 0);
        long hash = 0;

        for (int i = 0; i < str.length(); i++) {
            times[str.charAt(i) - 'a']++;
        }

        for (long time : times) {
            hash += (hash << 2 | hash >> 62) + time;
        }

        return hash;
    }

    public static void main(String[] args) {
        Anagrams anagrams = new Anagrams();
        System.out.println(anagrams.anagrams(new String[] { "abc", "cba", "sissie" }));
        System.out.println(anagrams.anagrams(new String[] { "cab", "tin", "pew", "duh", "may",
                "ill", "buy", "bar", "max", "doc" }));
    }
}
