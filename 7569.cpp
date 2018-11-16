#include <iostream>
#include <queue>
using namespace std;

int m, n, h;
int map[100][100][100]; // 토마토 배열
int visited[100][100][100]; // 방문 표시

struct Point { // 3차원 배열 저장하는 구조체
    int z, y, x;
    Point(int a, int b, int c) {
        z = a;
        y = b;
        x = c;
    }
    Point() {        }
};

queue<Point> que;
int dz[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dx[6] = { 0,0,0,0,-1,1 };

int main(void) {
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 1) { // 익은 토마토 que에 push
                    que.push(Point(i, j, k));
                    visited[i][j][k] = 1;
                }
            }
        }
    }
    
    while (!que.empty()) { // BFS 탐색 시작
        auto cur = que.front();
        que.pop();
        int z = cur.z;
        int y = cur.y;
        int x = cur.x;
        
        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m)
                continue; // 범위에 해당하지 않는 경우
            
            if (map[nz][ny][nx] == -1)
                continue; // 토마토가 들어있지 않은 경우
            
            if (visited[nz][ny][nx] != 0)
                continue; // 이미 방문한 경우
            
            if (visited[nz][ny][nx] == 0 && map[nz][ny][nx] == 0) { // 익지 않은 토마토
                visited[nz][ny][nx] = visited[z][y][x] + 1; // 방문표시
                map[nz][ny][nx] = 1; // 익은 토마토로 처리
                que.push(Point(nz, ny, nx));
            }
        }
    }
    
    int fl = 1;
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (visited[i][j][k] >= ans)
                    ans = visited[i][j][k];
                if (map[i][j][k] == 0) // 익지 않은 토마토가 존재하는 경우
                    fl = 0;
            }
        }
    }
    
    if (fl == 0)
        cout << -1 << endl;
    else
        cout << ans - 1 << endl;
    return 0;
}
