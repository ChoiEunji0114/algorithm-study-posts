/*
 * 백준 2193번
 * [DP] 이친수 
 */

package boj2193;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		
		long dp[] = new long[n+1]; // int 범위 초과 -> 큰 자료형 사용 
		
		dp[0] = 0;
		dp[1] = 1; // 첫 번째 숫자는 1로 시작 
		
		for(int i=2; i<=n; i++) {
			dp[i] = dp[i-2] + dp[i-1];
		}
		System.out.println(dp[n]);
	}

}
