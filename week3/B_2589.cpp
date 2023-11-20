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

// bfs를 통해 최단거리 탐색 가능
int bfs(int y, int x){
    int tmp_ret = 0;
    // 최단거리를 count할 배열
    int tmp_adj[max_l][max_l] = {0,};
    queue<pair<int, int>> q;
    q.push({y, x});
    
    while(q.size()){
        pair<int, int> tmp = q.front();
        y = tmp.first, x = tmp.second;
        q.pop();
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(isValid(ny, nx) &&
            adj[ny][nx] == 'L' &&
            !visited[ny][nx])
            {
                visited[ny][nx] = 1;
                q.push({ny, nx});
                tmp_adj[ny][nx] = tmp_adj[y][x] + 1;
            }
        }
    }
    tmp_ret = tmp_adj[y][x];
    return tmp_ret;
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
                int tmp_ret = bfs(i, j);
                // 가장 멀리 떨어진 보물인지 아닌지 check해야 하기 때문에
                ret = max(tmp_ret, ret);
                memset(visited, 0, sizeof(visited));
            }
        }
    }
    cout << ret;
}