#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int max_l = 1004;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int R, C, ny, nx, ret;
pair<int, int> p;
char adj[max_l][max_l];
int fire[max_l][max_l];
int visited[max_l][max_l];

queue<pair<int, int>> fire_q;
queue<pair<int, int>> q;

bool isValid(int y, int x){
    return 0 <= y && y < R && 0 <= x && x < C;
}

int main(){
    cin >> R >> C;
    fill(&fire[0][0], &fire[0][0] + max_l * max_l, INF);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> adj[i][j];
            if(adj[i][j] == 'F') {
                fire[i][j] = 1; fire_q.push({i, j});
            }
            else if(adj[i][j] == 'J') {
                p.first = i; p.second = j;
            }
        }
    }
    
    // 불 이동 기록
    while(fire_q.size()) {
        int y, x;
        tie(y, x) = fire_q.front(); fire_q.pop();
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(!isValid(ny, nx)) continue;
            if(adj[ny][nx] == '#' || fire[ny][nx] != INF) continue;
            fire[ny][nx] = fire[y][x] + 1;
            fire_q.push({ny, nx});
        }
    }
    
    // 사람 이동기록 기록
    visited[p.first][p.second] = 1;
    q.push(p);
    bool flag = false;
    while(q.size()){
        int y, x;
        tie(y, x) = q.front(); q.pop();
		if(x == C-1 || y == R-1 || x == 0 || y == 0){
            ret = visited[y][x];
            flag = true;
            break;
		}
        for(int i = 0; i < 4; i++){
            ny = y + dy[i];
            nx = x + dx[i];
            if(!isValid(ny, nx)) continue;
            // 이미 방문했으면
            if(visited[ny][nx]) continue;
            // 벽이거나, 불이 사람의 움직임보다 더 빠르거나 같게 퍼졌을 때
            if(adj[ny][nx] == '#' || fire[ny][nx] <= visited[y][x] + 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    if(flag) cout << ret;
    else cout <<"IMPOSSIBLE";
    
}