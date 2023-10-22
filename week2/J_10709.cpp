#include <bits/stdc++.h>
using namespace std;

const int max_l = 104;
int H, W, ny, nx;
string str;
int visited[max_l][max_l];
char adj[max_l][max_l];
int ret[max_l][max_l];

bool isValid(int y, int x){
    return (0 <= y && y < H && 0 <= x && x < W);
}

void dfs(int y, int x){
    visited[y][x] = 1;
        
    ny = y;
    nx = x + 1;
    if (isValid(ny, nx)) {

        if (adj[ny][nx] == 'c') return;
        if (visited[ny][nx]) return;
        ret[ny][nx] = ret[y][x] + 1;
        dfs(ny, nx);
    }
    
}

int main(){
    
    cin >> H >> W;
    
    for(int i = 0; i < H; i++){
        cin >> str;
        for(int j = 0; j < W; j++) {
            adj[i][j] = str[j];
        }
    }
    
    // DFS
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) {
            if(adj[i][j] == 'c') dfs(i, j);
        }
    }
    
        // fill visited 1
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) {
        // for -1
            if(visited[i][j] == 0 && adj[i][j] != 'c') ret[i][j] = -1;
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}