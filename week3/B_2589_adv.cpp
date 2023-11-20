#include <bits/stdc++.h>
using namespace std;

const int max_l = 54;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int N, M, nx, ny;
int ret;
char adj[max_l][max_l];
int visited[max_l][max_l];

bool isValid(int y, int x){
    return (0 <= y && y < N && 0 <= x && x < M);
}

// 최단거리 + 가장 먼 보물 거리 갱신하는 BFS
void bfs(int y, int x){
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(isValid(ny, nx) &&
            adj[ny][nx] == 'L' &&
            !visited[ny][nx])
            {
                q.push({ny, nx});
                // 여기서 visited는 0, 1 방문 유무가 아닌 최단거리 기록용
                visited[ny][nx] = visited[y][x] + 1;
                // 기존 보물 거리보다 크면 갱신
                ret = max(ret, visited[ny][nx]);
            }
        }
    }
}

int main(){
    
    // INPUT
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> adj[i][j];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(adj[i][j] == 'L' && !visited[i][j]) {
                visited[i][j] = 1;
                bfs(i, j);
                memset(visited, 0, sizeof(visited));

            }
        }
    }
    // 출발을 1부터 시작하니, -1 해주기
    cout << ret - 1;
}