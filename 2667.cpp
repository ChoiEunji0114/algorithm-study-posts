#include <stdio.h>
#include <algorithm>

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
int n, k, chk[26][26], cnt[26 * 26];
char arr[26][26];

void dfs(int x, int y) {
    chk[x][y] = k;
    arr[x][y] = '0'; // 방문 표시
    cnt[k]++;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (arr[nx][ny] == '1') dfs(nx, ny);
    }
}

int main(void) {
    int i, j;
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i][j] == '1' && !chk[i][j]) {
                ++k;
                dfs(i, j);
            }
        }
    }
    
    std::sort(cnt + 1, cnt + 1 + k);
    printf("%d\n", k);
    for (i = 1; i <= k; i++) {
        printf("%d\n", cnt[i]);
    }
    
    return 0;
}

