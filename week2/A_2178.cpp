#include <bits/stdc++.h>
using namespace std;

const int max_l = 104;
int N, M, ny, nx;
int result;

int visited[max_l][max_l];
int adj[max_l][max_l];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

// Check Overflow
bool isValid(int y, int x) {
    return (0 <= y && y < N && 0 <= x && x < M);
}

void bfs(int y, int x){
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    
    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (isValid(ny, nx)) {
                if (adj[ny][nx] == 0) continue;
                if (visited[ny][nx]) continue;

                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // Input N, M
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++){
            // for 1 digit number
            adj[i][j] = tmp[j] - '0';
        }
    }

    bfs(0, 0);
    cout << visited[N-1][M-1] << '\n';
    
}