#include <bits/stdc++.h>
using namespace std;

const int dir = 4;
int dy[dir] = {0, 1, 0, -1};
int dx[dir] = {1, 0, -1, 0};

int N;
int M;

// 정답
int result;
bool visited[104][104];
int adj[104][104];

bool isValid(int y, int x){
    return (0 <= y && y < N && 0 <= x && x < M);
}

void dfs(int y, int x){
    visited[y][x] = 1;
    
    for(int k = 0; k < dir; k++){
        int ny = y + dy[k];
        int nx = x + dx[k];
        
    
        if(isValid(ny, nx)) {
            if (adj[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;
            dfs(ny, nx);
        }
    }
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> adj[i][j];
        }
    }
    
    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            if (adj[y][x] == 0) continue;
            if (visited[y][x]) continue;
            dfs(y, x);
            // 충분히 순회를 했으면, 더함
            result++;
        }
    }
    
    cout << result;
    
}