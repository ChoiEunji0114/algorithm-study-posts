#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main(void) {
    char map[50][50] = { 0, };
    int dist[50][50] = { 0, };
    
    int h, w;
    cin >> h >> w;
    
    queue<pair<int, int>> landQ;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map [i][j];
            if (map[i][j] == 'L')
                landQ.push(make_pair(i, j));
        }
    }
    
    int ans = 0;
    while (!landQ.empty()) {
        int land_y = landQ.front().first;
        int land_x = landQ.front().second;
        landQ.pop();
        
        memset(dist, 0, sizeof(dist));
        
        queue<pair<int, int>> q;
        q.push(make_pair(land_y, land_x));
        
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if (ny < 0 || nx < 0 || ny >= h || nx >= w)
                    continue;
                
                if (map[ny][nx] == 'W' || (land_y == ny && land_x == nx))
                    continue;
                
                if (!dist[ny][nx] || dist[ny][nx] > dist[y][x] + 1) {
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (dist[i][j])
                    ans = max(ans, dist[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
