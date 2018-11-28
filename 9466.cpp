/*
 백준 9466번
 [DFS/cycle] 텀 프로젝트
 */

#include <iostream>
#include <cstring>
using namespace std;

int t, n, ans;
int arr[100001], visit[100001], cycle[100001];

int dfs(int start, int cur, int dep) { // 시작점, 현재 방문 지점, 지금까지 거쳐온 정보
    visit[cur] = dep; // 방문 표시
    cycle[cur] = start; // 출발 좌표 기록
    
    int next = arr[cur]; // 다음 방문 좌표
    
    if (visit[next] == 0) { // 방문한 적이 없는 경우 -> 간선 따라 이동
        dfs(start, next, dep + 1);
    }
    else if (visit[next] != 0 && start == cycle[next])
        return dep - visit[next] + 1; // 사이클을 돌아 다시 자기 자신에 돌아옴
    else if (visit[next] != 0 && start != cycle[next])
        return 0; // 끝난 사이클 (쓰레기)
}

int main(void) {
    cin >> t; // test case
    
    while (t--) {
        cin >> n; // 학생 수
        memset(visit, 0, sizeof(visit)); // visit 배열 초기화
        ans = 0; // ans 초기화
        
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        
        for (int i = 1; i <= n; i++) {
            if (visit[i] != 0) // 이미 방문한 경우 - 탐색 하지 않음
                continue;
            if (visit[arr[i]] == 0)
                ans += dfs(i, i, 1); // 팀에 속하는 학생 수
        }
        cout << n - ans << endl;
    }
    return 0;
}
