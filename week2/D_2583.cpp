#include <bits/stdc++.h>
#define y1 aaaa
using namespace std;

const int max_l = 104;

int M, N, K;
int cnt, ny, nx;
vector<int> area_v;

int visited[max_l][max_l];
int adj[max_l][max_l];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool isValid(int y, int x){
    return (0 <= y && y < M && 0 <= x && x < N);
}

int dfs(int y, int x){
    visited[y][x] = 1;
    
    int area = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(isValid(ny, nx)) {
            if(visited[ny][nx]) continue;
            if(adj[ny][nx] >= 1) continue;
            // Count area not filled
            area += dfs(ny, nx);
        }
    }
    return area;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++){
        int y1, y2, x1, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1 = M - y1 - 1;
        y2 = M - y2;
        
        // Fill area with two coordinates
        for(int y = y1; y >= y2; y--){
            for(int x = x1; x <= x2 - 1; x++){
                adj[y][x]++;
            }
        }
    }
    
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            // Not visited and adj is zero(count case not filled)
            if (!visited[i][j] && adj[i][j] == 0){
                cnt++;
                area_v.push_back(dfs(i, j));
            }
        }
    }
    
    // vector sort for ascending order
    sort(area_v.begin(), area_v.end());
    
    cout << cnt << '\n';
    for(int a : area_v) cout << a << ' ';
    
    return 0;
}