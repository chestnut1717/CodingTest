#include<bits/stdc++.h>
using namespace std;

const int max_l = 104;
int N, ret, ny, nx;
int visited[max_l][max_l];
int adj[max_l][max_l];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int isValid(int y, int x){
    return (0 <= y && y < N && 0 <= x && x < N);
}

void dfs(int y, int x, int h){
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(isValid(ny, nx)) {
            if (adj[ny][nx] <= h) continue;
            if (visited[ny][nx]) continue;
            dfs(ny, nx, h);
        }
    }
    
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 1. Input N and matrix
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> adj[i][j];
        }
    }
    
    // 2. check every height(0 <= h <= 100)
    for(int h = 0; h <= 100; h++){
        int tmp_ret = 0;
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                // 3. DFS with specific height(h)
                if(adj[y][x] > h && !visited[y][x]) {
                    dfs(y, x, h);
                    tmp_ret++;
                }
            }
        }
        // 4. update maximum ret
        ret = max(ret, tmp_ret);
        
        // 5. Reset visited and adj array
        fill(&visited[0][0], &visited[0][0] + max_l * max_l, 0);
        // memset(visited, 0, sizeof(visited));
    }
    cout << ret << '\n';
}