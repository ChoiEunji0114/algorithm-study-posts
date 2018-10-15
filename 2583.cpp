#include <iostream>
#include <algorithm>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int arr[100][100];
int chk[100][100];
int ans[100];
int m, n, k;
int cnt;

// 정사각형 입력
void makemap() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            arr[i][j] = 1;
        }
    }
}

// 깊이 우선 탐색
void dfs(int y, int x) {
    chk[y][x] = cnt;
    arr[y][x] = 1; // 방문 표시
    ans[cnt]++;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= m || nx >= n)
            continue;
        
        if (arr[ny][nx] == 0 && chk[ny][nx] == 0)
            dfs(ny, nx);
    }
    
}

int main(void) {
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        makemap();
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0 && chk[i][j] == 0) {
                ++cnt;
                dfs(i, j);
            }
        }
    }
    
    cout << cnt << endl;
    std::sort(ans + 1, ans + cnt + 1); // 오름차순 정렬
    for (int i = 1; i <= cnt; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
