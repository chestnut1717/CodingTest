#include <bits/stdc++.h>
using namespace std;

const int max_l = 65;
int N;
char adj[max_l][max_l];

string calc(int y, int x, int size){
    if (size == 1) {
        return string(1, adj[y][x]);
    }
    else {
        string ret = "";
        char b = adj[y][x];
        for(int i = y; i < y + size; i++) {
            for(int j = x; j < x + size; j++){
                if (b != adj[i][j]) {
                    ret = "(";
                    ret += calc(y, x, size / 2);
                    ret += calc(y, x + size / 2, size / 2);
                    ret += calc(y + size / 2, x, size / 2);
                    ret += calc(y + size / 2, x + size / 2, size / 2);
                    ret += ')';

                    return ret;
                }

            }
        }
        
        return string(1, b);
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 1. Input matrix
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < N; j++){
            adj[i][j] = tmp[j];
        }
    }
    
    // 2. Divide and conquer
    string ret = calc(0, 0, N);
    cout << ret << '\n';
    return 0;
}