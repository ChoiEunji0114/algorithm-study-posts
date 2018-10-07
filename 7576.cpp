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
	scanf("%d %d", &m, &n); // ����, ���� �Է¹���

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &a[i][j]); // �丶�� �Է� ����
			if (a[i][j] == 1) {
				que.push({ i,j }); // ���� �丶���� ��� queue�� push
			}
		}
	}

	while (!que.empty()) {
		auto now = que.front();
		que.pop(); // ���� �丶�並 queue���� ����
		int x = now.first; // ���� �丶���� x��ǥ
		int y = now.second; // ���� �丶���� y��ǥ
		ans = ans > a[x][y] ? ans : a[x][y];

		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue; // ���� ���� �丶���� ��� ����
			if (a[nx][ny] == 0) { // ���� ���� �丶���� ���
				que.push({ nx,ny });// queue�� push
				a[nx][ny] = a[x][y] + 1; // ���� �丶��� ó��
			}
		}
	}

	// �� ���� �丶�䰡 �ִ��� �˻�
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] == 0)
				ans = 0;
		}
	}

	// ��¥ ���
	printf("%d", ans - 1);
	return 0;
}
