#include <stdio.h>
#include <queue>
using namespace std;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int n, m, ans, a[1001][1001];
queue<pair<int, int>> que;

int main(void) {
	int i, j;
	int k = 0;
	scanf("%d %d", &m, &n); // 가로, 세로 입력받음

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &a[i][j]); // 토마토 입력 받음
			if (a[i][j] == 1) {
				que.push({ i,j }); // 익은 토마토인 경우 queue에 push
			}
		}
	}

	while (!que.empty()) {
		auto now = que.front();
		que.pop(); // 익은 토마토를 queue에서 꺼냄
		int x = now.first; // 익은 토마토의 x좌표
		int y = now.second; // 익은 토마토의 y좌표
		ans = ans > a[x][y] ? ans : a[x][y];

		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue; // 익지 않은 토마토인 경우 생략
			if (a[nx][ny] == 0) { // 익지 않은 토마토인 경우
				que.push({ nx,ny });// queue에 push
				a[nx][ny] = a[x][y] + 1; // 익은 토마토로 처리
			}
		}
	}

	// 안 익은 토마토가 있는지 검사
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] == 0)
				ans = 0;
		}
	}

	// 날짜 출력
	printf("%d", ans - 1);
	return 0;
}
