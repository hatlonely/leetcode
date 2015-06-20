package leetcode;

import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
	}
	
	ListNode(List<Integer> li) {
		if (li.isEmpty()) {
			return;
		}
		Iterator<Integer> it = li.iterator();
		val = it.next();
		ListNode node = this;
		while (it.hasNext()) {
			node.next = new ListNode(it.next());
			node = node.next;
		}
	}
	
	@Override
	public String toString() {
		String string = "[";
		ListNode node = this;
		while (node.next != null) {
			string += node.val;
			string += ", ";
			node = node.next;
		}
		string += node.val;
		string += "]";
		return string;
	}
	
	public static void main(String[] args) {
		ListNode ln = new ListNode(new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4)));
		System.out.println(ln);
	}
}