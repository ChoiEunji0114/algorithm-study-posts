/*
 * 백준 1149번
 * RGB 거리 
 */

package boj1149;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt(); // 집의 갯수 
		
		int[][] cost = new int[n][3]; // 집을 칠하는 비용 
		int[][] dp = new int[n][3]; // 최소합 저장 
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<3; j++) {
				cost[i][j] = scanner.nextInt();
			}
		}
		scanner.close();
		
		// 첫 번째 집의 최소 비용은 그 자체 기본값이다.
		dp[0][0] = cost[0][0];
		dp[0][1] = cost[0][1];
		dp[0][2] = cost[0][2];
		
		// 최소합 = 바로 전 집까지의 비용 최소합 + 현재 비용 최소합 
		for(int i=1; i<n; i++) {
			dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
			dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
			dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
		}
		
		int ans = Math.min(dp[n-1][0], Math.min(dp[n-1][1], dp[n-1][2]));
		System.out.println(ans);
		

	}

}
