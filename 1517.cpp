/*
백준 1517
버블 소트
*/
#include <iostream>
#include <vector>
using namespace std;

long long ans;

// merge sort
void mergeBubble(vector<int> &a, int start, int end) {
    if (start == end)
        return;
    
    int mid = (start + end) / 2; // 중간 지점
    vector<int> tmp;
    
    mergeBubble(a, start, mid); // 정렬
    mergeBubble(a, mid + 1, end); // 정렬
    
    int i = start, j = mid + 1;
    while (i <= mid && j <= end) { // 비교해서 데이터 합침
        if (a[i] <= a[j]) {
            tmp.push_back(a[i]);
            i++;
        }
        else {
            tmp.push_back(a[j]);
            ans += (mid + 1 - i);
            j++;
        }
    }
    
    // 나머지 한 쪽만 남은 경우
    while (i <= mid)
        tmp.push_back(a[i++]);
    while (j <= end)
        tmp.push_back(a[j++]);
    
    // vector a 에 복사
    for (int i = start, j = 0; i <= end; i++, j++) {
        a[i] = tmp[j];
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    // 기본값 0 으로 초기화된 n개의 원소를 가지는 vector 생성
    vector<int> a(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    mergeBubble(a, 0, a.size() - 1);
    cout << ans << endl;
    
    return 0;
}

