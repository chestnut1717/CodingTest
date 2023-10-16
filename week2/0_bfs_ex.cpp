#include <bits/stdc++.h>
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int visited[104][104];
int adj[104][104];

int N, M;

// 시작지점고 목적지
int c_y, c_x;
int e_y, e_x;

// 처음에 1 소모하고 시작하므로
int result = 1;

bool isValid(int y, int x){
    return (0 <= y && y < N && 0 <= x && x < M);
}

void bfs(int y, int x){
    queue<pair<int, int>> q;
    visited[y][x] = 1;

    // 그냥 만들지 않고 다음과 같이 넣어도 된다pair<int, int> p = make_pair(y, x);
    q.push({y, x});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();

        for(int k = 0; k < 4; k++){
            int ny = y + dy[k];
            int nx = x + dx[k];
            
            // 유효하고, 방문도 안했고 가능한 곳이라면 push해준다.
            if(isValid(ny, nx)){
                if(adj[ny][nx] == 1 && visited[ny][nx] == 0) {
                    visited[ny][nx] = visited[y][x] + 1;
                    // pair<int, int> p = make_pair(ny, nx);
                    q.push({ny, nx});
                }
            }
        }
    }

}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> c_y >> c_x;
    cin >> e_y >> e_x;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> adj[i][j];
        }
    }

    bfs(c_y, c_x);

    cout << visited[e_y][e_x] << '\n';

}