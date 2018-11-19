/*
 백준 9205
 맥주 마시면서 걸어가기 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100 + 2;

int N; // 편의점 갯수
vector<int> graph[MAX]; // 양방향 그래프
bool visited[MAX]; // 방문 표시

// 맨해튼 거리 계산
int distance(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

// 깊이 우선 탐색
void DFS(int node) {
    visited[node] = true; // 방문 표시
    
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (visited[next] == false) {
            DFS(next);
        }
    }
}

int main(void) {
    
    ios_base::sync_with_stdio(0); // cin,cout scanf,printf 혼용 가능
    cin.tie(0); // cin 속도 향상
    
    int test_case;
    cin >> test_case;
    
    while (test_case--) {
        
        for (int i = 0; i < MAX; i++) {
            graph[i].clear();
        }
        
        memset(visited, false, sizeof(visited));
        
        cin >> N;
        vector<pair<int, int>> coord;
        
        // 출발점(0), 도착점(N+2) -> 출발,편의점,도착 좌표 입력
        for (int i = 0; i < N + 2; i++) {
            int y, x;
            cin >> y >> x;
            
            coord.push_back(make_pair(y, x));
        }
        
        // 맥주 20병으로 갈 수 있는 거리내에 있으면 그래프 추가
        for (int i = 0; i < N + 2; i++) {
            for (int j = i + 1; j < N + 2; j++) {
                if (distance(coord[i], coord[j]) <= 50*20) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        DFS(0);
        
        if (visited[N + 1])
            cout << "happy" << endl;
        else
            cout << "sad" << endl;
        
    }
    
    return 0;
}
