#include<bits/stdc++.h>
using namespace std;

const int max_l = 54;

int T, N, M, K;
int y, x, ny, nx, ret;
int visited[max_l][max_l];
int adj[max_l][max_l];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool isValid(int y, int x){
    return (0 <= y && y < N && 0 <= x && x <= M);
}

// DFS function
void dfs(int y, int x){
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(isValid(ny, nx)) {
            if(adj[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            dfs(ny, nx);
        }
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 1. Input T(test case)
    cin >> T;
    for(int t = 0; t < T; t++) {
        
        // 2 Input N, M, K for each K
        cin >> M >> N >> K;
        for(int i = 0; i < K; i++){
            cin >> x >> y;
            adj[y][x] = 1;
        }
        
        // 3. DFS for all coordinates
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(adj[i][j] == 1 && !visited[i][j]){
                    dfs(i, j);
                    ret++;
                }
            }
        }
        
        // 4. (IMPORTANT) Reset array
        // fill(&visited[0][0], &visited[0][0] + max_l * max_l, 0);
        // fill(&adj[0][0], &adj[0][0] + max_l * max_l, 0);
        memset(visited, 0, sizeof(visited));
        memset(adj, 0, sizeof(adj));

        
    // 4. print result
    cout << ret << '\n';
    ret = 0;
    }
    
    return 0;
}