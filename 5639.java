package bojAlgorithm;

/*
 * 백준 5639 문제 
 * 이진 검색 트리 
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	int key;
	Main left;
	Main right;
	Main rootNode;
	
	StringBuilder sb = new StringBuilder();
	
	// 후위 순회 (왼쪽 자식 -> 오른쪽 자식 -> 루트) 
	public void postOrder(Main root) {
		if(root!=null) {
			postOrder(root.left);
			postOrder(root.right);
			System.out.println(root.key);
		}
	}
	
	public Main insertKey(Main T, int x){
		if(T==null) {
			Main newNode = new Main();
			newNode.key = x;
			return newNode;
		} else if (x<T.key) { // 왼쪽 탐색 -> 추가 
			T.left = insertKey(T.left, x);
			return T;
		} else if (x>T.key) { // 오른쪽 탐색 -> 추가 
			T.right = insertKey(T.right, x);
			return T;
		} else {
			return T;
		}
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		// 트리 입력받기 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Main main = new Main();
		Scanner scanner = new Scanner(System.in);

		while(scanner.hasNext()) {
			try {
				main.rootNode = main.insertKey(main.rootNode, scanner.nextInt());
			} catch(Exception e) {
				System.out.println("입력 종료");
				break;
			}
		}
		main.postOrder(main.rootNode);
	}
}
