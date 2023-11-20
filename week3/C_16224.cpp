#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int N, L, R, ret;
int ny, nx;
int adj[54][54];
int visited[54][54];
vector<pair<int, int>> v;

bool isValid(int y, int x){
    return (0 <= y && y < N && 0 <= x && x < N);
}

// dfs 재귀적으로 하면서, 국경 열어야 하는 좌표 담음
void dfs(int y, int x){
    visited[y][x] = 1;

    // 국경 여는 좌표 push back
    v.push_back({y, x});
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        int cha = abs(adj[ny][nx] - adj[y][x]);
        
        if(isValid(ny, nx) &&
            !visited[ny][nx] &&
            L <= cha && cha <= R) {
            dfs(ny, nx);
        }
    }
}

// 인구이동
void movePeople(){
    int sum_p = 0;
    int cnt = 0;
    
    for(auto it : v) {
        sum_p += adj[it.first][it.second]; cnt++;
    }
    int new_p = sum_p / cnt;
    
    for(auto it : v) {
        adj[it.first][it.second] = new_p;
    }
    
}

int main(){
    // input
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> adj[i][j];
        }
    }
    
    // 완전탐색
    while(true){
        bool isMove = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if (!visited[i][j]) {
                    dfs(i, j);
                    // 인구이동 가능성이 있으면, isMove를 True로 바꾸기
                    if (v.size() >= 2) {
                        isMove = true;
                        movePeople(); 
                    }
                    // 다음 탐색 위해
                    v.clear();
                }
            }
        }
        // 인구이동이 일어나지 않았다면, while문 탈출
        if (!isMove) break;
        // 새로운 도전을 위해 초기화
        else {
            ret++;
            fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        }
    }
    cout << ret;

}