#include <cstdio>
#include <queue>
using namespace std;

int height, width;
char map[55][55];
queue<pair<int, int> > wque;
int water[55][55];
int starty, startx;
int desty, destx;

void input(){
    scanf("%d %d", &height, &width);
    
    for (int i = 0; i < height; i++) {
        scanf("%s", &map[i]);
        
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'S') { // 고슴도치 위치 (시작) 저장
                starty = i;
                startx = j;
            }
            else if (map[i][j] == 'D') { // 비버의 굴 (도착) 저장
                desty = i;
                destx = j;
                water[i][j] = -1;
            }
            else if (map[i][j] == '*') {
                water[i][j] = 1;
                wque.push(make_pair(i, j));
            }
            else if (map[i][j] == 'X') {
                water[i][j] = 1;
            }
        }
    }
}

void solve()
{
    int visit[55][55] = { 0, };
    int dy[4] = { -1, 0, 0, 1 };
    int dx[4] = { 0, -1, 1, 0 };
    int w = 1, b = 1;
    
    queue<pair<int, int> > que;
    que.push(make_pair(starty, startx));
    visit[starty][startx] = 1;
    
    while (!que.empty()) {
        // 물 채우기
        while (!wque.empty() && w) {
            int wy = wque.front().first;
            int wx = wque.front().second;
            
            if (water[wy][wx] != w) {
                w++;
                break;
            }
            
            wque.pop();
            
            for (int i = 0; i < 4; i++) {
                int nexty = wy + dy[i];
                int nextx = wx + dx[i];
                
                if (nexty >= 0 && nexty < height && nextx >= 0 && nextx < width) {
                    if (water[nexty][nextx] == 0) {
                        water[nexty][nextx] = water[wy][wx] + 1;
                        wque.push(make_pair(nexty, nextx));
                    }
                }
            }
        }
        
        while (!que.empty()) {
            int y = que.front().first;
            int x = que.front().second;
            
            if (visit[y][x] != b) {
                b++;
                break;
            }
            
            que.pop();
            
            for (int i = 0; i < 4; i++) {
                int nexty = y + dy[i];
                int nextx = x + dx[i];
                
                if (nexty >= 0 && nexty < height && nextx >= 0 && nextx < width) {
                    if (water[nexty][nextx] <= 0 && visit[nexty][nextx] == 0) {
                        visit[nexty][nextx] = visit[y][x] + 1;
                        que.push(make_pair(nexty, nextx));
                    }
                }
            }
        }
    }
    
    if (visit[desty][destx] == 0) {
        printf("KAKTUS\n");
    }
    else printf("%d\n", visit[desty][destx] - 1);
}

int main()
{
    input();
    
    solve();
    
    return 0;
}
