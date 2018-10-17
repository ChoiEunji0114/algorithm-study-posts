#include <iostream>
using namespace std;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

int n;
int map[101][101];
int chkmap[101][101];

int makeMap() {
    cin >> n;
    int mxf = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            mxf < map[i][j] ? mxf = map[i][j] : mxf;
        }
    }
    return mxf;
}

void makeChkmap(int rainfloor) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] <= rainfloor) // 잠기는 경우
                chkmap[i][j] = 0;
            else // 잠기지 않는 경우
                chkmap[i][j] = 1;
        }
    }
}

// 깊이 탐색
void dfs(int y, int x) {
    if (chkmap[y][x] == 1)
        chkmap[y][x] = 0;
    else
        return;
    
    if (x < 0 || y < 0 || x >= n || y >= n)
        return;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        dfs(ny, nx);
    }
}

int count() {
    int safetyArea = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chkmap[i][j] == 1) {
                dfs(i, j);
                safetyArea++;
            }
        }
    }
    return safetyArea;
}

int main(void) {
    int maxFloor = makeMap();
    int maxValue = 0;
    
    for (int i = 0; i <= maxFloor; i++) {
        makeChkmap(i);
        int tmp = count();
        maxValue < tmp ? maxValue = tmp : maxValue;
    }
    
    cout << maxValue;
    return 0;
}

