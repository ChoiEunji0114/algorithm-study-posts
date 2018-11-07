#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, a, b;
int arr[101][101];
int visit[101];
int depth[101];
int ans[101];

void bfs(int num) {
    visit[num] = 1;
    
    queue<int> que;
    que.push(num);
    
    while (!que.empty()) {
        int tmp = que.front();
        que.pop();
        
        for (int i = 1; i <= n; i++) {
            if (visit[i] == 0 && arr[tmp][i] == 1) {
                visit[i] = 1;
                que.push(i);
                depth[i] = depth[tmp] + 1;
            }
        }
    }
}

int main(void) {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        bfs(i);
        memset(visit, 0, sizeof(visit)); // visit 초기화
        for (int j = 1; j <= n; j++) {
            ans[i] += depth[j]; // 케빈 베이컨의 수 저장
        }
        memset(depth, 0, sizeof(depth)); //depth 초기화
    }
    
    int min = ans[1];
    int minstu = 1;
    
    for (int i = 2; i <= n; i++) { // 최소값 구하기
        if (min > ans[i]) {
            min = ans[i];
            minstu = i;
        }
    }
    cout << minstu << endl;
    return 0;
}
