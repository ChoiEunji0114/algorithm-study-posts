/*
* 백준 1068번
* 트리
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

class Node {
	int num; // 노드 번호 
	int parent; // 부모 번호 
	int child[] = new int[50]; // 자식 리스트 
	int childCnt; // 자식 수 
	
	// 자식 추가시 처리 
	public void setChild(int childNum) {
		child[childNum]=1;
		childCnt++;
	}
}


public class Problem1068 {
	
	public static Node tree[]; // 트리
	public static int n; // 노드 갯수
	public static int delList[]; // 삭제 리스트 배열 
	
	// 리프 노드의 수 구하기 
	private static int getLeaf() {
		int i, cnt = 0;
		for(i=0 ; i<n ; i++) {
			// 노드 존재 && 루트 노드가 아님 && 자식이 0명 
			if(tree[i]!=null && tree[i].parent!=-1 && tree[i].childCnt==0)
				cnt++;
		}
		return cnt;
	}
	
	// num 번 노드 삭제 
	private static void delete(int num) {
		makeDelList(num); // 삭제 리스트 만듦 
		int i, k, pa;
		for(i=0;i<n;i++) {
			k = tree[i].num; // 현재 노드 번호 
			if(delList[k]==1) { // 현재 노드 번호가 삭제예정 리스트에 있으면 
				pa = tree[k].parent; // 현재 노드의 부모 
				tree[k] = null; // 현재 노드 삭제 
				
				// 부모가 루트 아님 && 부모가 삭제되지 않고 존재 
				if(pa!=-1 && tree[pa]!=null) {
					tree[pa].childCnt--; // 부모 노드의 자식수 -1 
					tree[pa].child[k] = 0; // 노드 자식 제거 
				}
			}
		}
	}
	
	// num 번 노드와 연결된 삭제 예정 리스트를 모두 찾기 
	private static void makeDelList(int num) {
		delList[num] = 1; // 현재 노드 num을 삭제 리스트에 추가
		for(int i=0;i<n;i++) { // num 노드와 연결된 자식 탐색 
			if(tree[num].child[i]==1)
				makeDelList(i); // 자식 노드와 연결된 또다른 노드 재귀 탐색 
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int i, pa;
		n = Integer.parseInt(in.readLine());
		
		tree = new Node[n];
		delList = new int[n];
		
		String line[] = in.readLine().split(" ");
		
		for(i=0;i<n;i++) { // 클래스 초기화 
			tree[i] = new Node();
		}
		
		for(i=0;i<n;i++) {
			pa = Integer.parseInt(line[i]); // i번 노드의 부모 번호 
			tree[i].num = i; // i번 노드의 노드 번호 = i
			tree[i].parent = pa; // i번 노드의 부모 번호 = pa
			
			// 입력 노드가 루트 노드가 아닐 경우, 부모 노드에 자식 정보 추가 
			if(pa != -1) {
				tree[pa].setChild(i);
			}
		}
		
		delete(Integer.parseInt(in.readLine()));
		out.write(String.valueOf(getLeaf()));
		
		out.close();
		in.close();
		
	}

}
