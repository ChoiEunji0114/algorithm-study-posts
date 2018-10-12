package bojAlgorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;

// 트리의 기초 - 노드 클래스
class Node {
	char data;
	Node left;
	Node right;
	
	public Node (char data) {
		this.data = data;
	}
}

// 트리 클래스 
class Tree {
	Node root; // 루트 노드 (처음엔 null) 
	
	public void add (char data, char left, char right) {
		if(root==null) { // 최초의 상태인 경우 루트에 데이터 삽입 
			if(data != '.')
				root = new Node(data);
			if(left != '.')
				root.left = new Node(left);
			if(right != '.')
				root.right = new Node(right);
		} else { // 최초의 상태가 아닌 경우 삽입해야 할 위치를 찾음 
			search(root, data, left, right);
		}
	}
	
	private void search(Node root, char data, char left, char right) {
		if(root==null) {
			// 삽입 위치를 찾지 못한 경우 종료 
			return;
		} else if (root.data == data) {
			// 위치를 찾은 경우 데이터 삽입 
			if(left != '.')
				root.left = new Node(left);
			if(right != '.')
				root.right = new Node(right);
		} else {
			// 재귀 탐색 
			search(root.left, data, left, right);
			search(root.right, data, left, right);
		}
	}
	
	// 전위 탐색 : 루트 -> 왼쪽 자식 -> 오른쪽 자식 
	public void preorder(Node root) {
		System.out.print(root.data);
		if(root.left != null)
			preorder(root.left);
		if(root.right != null)
			preorder(root.right);
	}
	
	// 중위 탐색 : 왼쪽 자식 -> 루트 -> 오른쪽 자식 
	public void inorder(Node root) {
		if(root.left != null)
			inorder(root.left);
		System.out.print(root.data);
		if(root.right != null)
			inorder(root.right);
	}
	
	// 후위 탐색 : 왼쪽 자식 -> 오른쪽 자식 -> 루트 
	public void postorder(Node root) {
		if(root.left != null)
			postorder(root.left);
		if(root.right != null)
			postorder(root.right);
		System.out.print(root.data);
	}
}


public class Problem1991 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int i, n = Integer.parseInt(in.readLine());
		Tree t = new Tree();
		
		char data[];
		for(i=0;i<n;i++) {
			data = in.readLine().replaceAll(" ", "").toCharArray();
			t.add(data[0], data[1], data[2]);
		}
		
		t.preorder(t.root);
		System.out.println();
		t.inorder(t.root);
		System.out.println();
		t.postorder(t.root);
		in.close();
		
	}
}
