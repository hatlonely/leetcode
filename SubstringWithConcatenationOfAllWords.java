package leetcode;

// 30 Substring with Concatenation of All Words
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//
// You are given a string, s, and a list of words, words, that are all of the same length.
// Find all starting indices of substring(s) in s that is a concatenation of each word
// in words exactly once and without any intervening characters.
//
// For example, given:
// s: "barfoothefoobarman"
// words: ["foo", "bar"]
//
// You should return the indices: [0,9].
// (order does not matter).

import java.util.Hashtable;
import java.util.List;
import java.util.LinkedList;
import java.util.Map;

public class SubstringWithConcatenationOfAllWords {
	public List<Integer> findSubstring(String s, String[] words) {
	    List<Integer> li = new LinkedList<Integer>();
	    Map<String, Integer> wordTimesMap = new Hashtable<String, Integer>();
	    for (int i = 0; i < words.length; i++) {
	    	if (wordTimesMap.containsKey(words[i])) {
	    		wordTimesMap.put(words[i], wordTimesMap.get(words[i]) + 1);
	    	} else {
	    		wordTimesMap.put(words[i], 1);
	    	}
	    }
	    int length = words[0].length();
	    int totalLength = length * words.length;
	    
	    int i = 0;
	    while (i < s.length() - totalLength + 1) {
	    	String subStr = s.substring(i, i + totalLength);
	    	if (isConcatenationOfAllWords(subStr, wordTimesMap, length)) {
	    		li.add(i);
	    	}
	    	i++;
	    }
	    
	    return li;
	}
	
	public boolean isConcatenationOfAllWords(String subStr, Map<String, Integer> wordTimesMap, int length) {
		Map<String, Integer> map = new Hashtable<String, Integer>();
		for (int i = 0; i < subStr.length(); i += length) {
			String word = subStr.substring(i, i + length);
			if (!wordTimesMap.containsKey(word)) {
				return false;
			}
			
			if (map.get(word) == wordTimesMap.get(word)) {
				return false;
			}
			
			if (map.containsKey(word)) {
				map.put(word, map.get(word) + 1);
			} else {
				map.put(word, 1);
			}
		}
		return true;
	}
	
	public static void main(String[] args) {
		SubstringWithConcatenationOfAllWords swoaw = new SubstringWithConcatenationOfAllWords();
		System.out.println(swoaw.findSubstring("barfoothefoobarman", new String[]{"foo", "bar"}));
		System.out.println(swoaw.findSubstring("a", new String[]{"a"}));
		System.out.println(swoaw.findSubstring("aaa", new String[]{"a", "b"}));
		System.out.println(swoaw.findSubstring(
				"lingmindraboofooowingdingbarrwingmonkeypoundcake",
				new String[]{"fooo","barr","wing","ding","wing"}));
	}
}
