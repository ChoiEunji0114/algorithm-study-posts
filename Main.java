package boj13325;

/*
 * 백준 13325
 * 이진 트리 
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		
		// 트리의 높이 입력받기 
		int k = Integer.parseInt(in.readLine());
		int size = 1<<(k+1);
		int left, right;
		
		int[] tree = new int[size];
		int[] path = new int[size]; // 리프까지의 최장 경로 저장 
		int[] sum = new int[size]; // 리프까지의 모든 경로를 최경로로 바꿨을 떄의 거리 합 저장 
		
		// 에지 가중치 입력 받음 
		String line[] = in.readLine().split(" ");
		
		// 입력받은 에지 가중치를 트리에 저장 
		for(int i=2;i<size;i++) {
			tree[i] = Integer.parseInt(line[i-2]);
		}
		
		// 에지 계산 
		for(int i=1<<k;--i>0;) {
			left = i<<1; // 왼쪽 자식 
			right = left+1; // 오른쪽 자식 
			path[i] = Math.max(path[left]+tree[left], path[right]+tree[right]);
			sum[i] = sum[left] + sum[right] + (path[i]-path[left]) + (path[i]-path[right]);
		}
		
		out.write(sum[1]+"");
		
		out.close();
		in.close();
	}
}
