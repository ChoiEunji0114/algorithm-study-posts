/*
 * 백준 2579번 
 * [DP] 계단 오르기 (Climbing Stairs)
 */

package boj2579;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		
		int cost[] = new int[n+1]; // 계단 점수 
		int dp[] = new int[n+1]; // 계단 오르며 얻는 최대 점수 
		
		for(int i=1; i<=n; i++) {
			cost[i] = scanner.nextInt();
		}
		
		dp[1] = cost[1];
		if(n >= 2) dp[2] = dp[1] + cost[2];

		// 1. 마지막 계단 전의 계단을 밟지 않은 경우 
		// 2. 마지막 계단 전의 계단을 밟은 경우 -> max 값을 저장 
		for(int i=3; i<=n; i++) {
			dp[i] = Math.max(dp[i-2]+cost[i], dp[i-3]+cost[i-1]+cost[i]);
		}
		
		System.out.println(dp[n]);
	}

}
