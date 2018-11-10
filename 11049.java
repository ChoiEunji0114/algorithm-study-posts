package boj11049;

import java.util.Scanner;

// 주어진 행렬을 곱하는데 필요한 곱셈 연산의 최솟값 출력 
public class Main {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(); // 행렬의 개수 
		int[][] m = new int[501][501];
		int[] d= new int[1001];
		
		// 각 행렬의 크기 입력 받음 
		for(int i=0; i<n; i++) {
			d[i]=sc.nextInt();
			d[i+1]=sc.nextInt();
		}

		// len : chain의 길이를 추적해주는 변수 
		for(int len=2; len<=n; len++) {
			for(int i=1; i<=n-len+1; i++) {
				int j = i+len-1;
				m[i][j] = Integer.MAX_VALUE;
				for(int k=i; k<j; k++) {
					int cost = m[i][k] + m[k+1][j] + d[i-1]*d[k]*d[j];
					m[i][j] = Math.min(m[i][j], cost);
				}
			}
		}
		System.out.println(m[1][n]);
	}

}
