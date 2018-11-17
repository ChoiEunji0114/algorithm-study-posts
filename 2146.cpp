#include <iostream>
#include <queue>
using namespace std;

int n;
int map[100][100];
int visited[100][100];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct str {
    int y, x, cnt;
    str(int y, int x, int cnt) :y(y), x(x), cnt(cnt) { };
};

queue<str> que;

// 섬을 구분해서 que 에 push
void dfs(int y, int x, int cnt) {
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue; // 범위에 해당하지 않는 경우
        
        if (map[ny][nx] == 0 || visited[ny][nx] == 1)
            continue; // 바다인 경우, 이미 방문한 경우
        
        visited[ny][nx] = 1;
        que.push(str(ny, nx, cnt));
        dfs(ny, nx, cnt);
    }
}

int main(void) {
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    
    int cnt = 0; // 섬번호
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) { // 방문하지 않은 육지
                visited[i][j] = 1;
                que.push(str(i, j, ++cnt));
                dfs(i, j, cnt);
            }
        }
    }
    
    int ans = 1000; // 가장 짧은 다리 길이 저장
    int length = 0; // 육지 사이의 거리
    
    // 최단 거리 구하기
    while (!que.empty()) {
        int y = que.front().y;
        int x = que.front().x;
        int cnt = que.front().cnt;
        
        que.pop();
        queue<str> que2 = que;
        while (!que2.empty()) {
            int y2 = que2.front().y;
            int x2 = que2.front().x;
            int cnt2 = que2.front().cnt;
            
            que2.pop();
            
            if (cnt2 == cnt) // 같은 섬에 해당하는 경우 패스
                continue;
            
            length = abs(y2 - y) + abs(x2 - x) - 1;
            ans = min(ans, length);
        }
    }
    cout << ans << endl;
    return 0;
}
