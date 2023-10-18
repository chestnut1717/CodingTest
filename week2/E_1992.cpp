#include <bits/stdc++.h>
using namespace std;

const int max_l = 65;
int N;
int adj[max_l][max_l];

string calc(int s_y, int s_x, int e_y, int e_x, int sz){
    if (sz == 1) {
        return to_string(adj[s_y][s_x]);
    }
    else {
        string ret = "";
        int cnt_w = 0;
        int cnt_b = 0;
        for(int i = s_y; i < e_y; i++) {
            for(int j = s_x; j < e_x; j++){
                if (adj[i][j] == 0) cnt_w++;
                else if (adj[i][j] == 1) cnt_b++;
            }
        }
       // cout << s_y << " " << s_x << " " << e_y << " " << e_x << '\n';
    //cout << cnt_w << ", " << cnt_b << " : "<< sz << '\n';
        if (cnt_w == sz) {ret += '0';}
        else if (cnt_b == sz) {ret += '1';}
        else{
            sz /= 4;
            int m_y = (s_y + e_y) / 2;
            int m_x = (s_x + e_x) / 2;
            ret = "(";
            ret += calc(s_y, s_x, m_y, m_x, sz);
            ret += calc(s_y, m_x, m_y, e_x, sz);
            ret += calc(m_y, s_x, e_y, m_x, sz);
            ret += calc(m_y, m_x, e_y, e_x, sz);
            ret += ')';
        }
        
        
        return ret;
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
            adj[i][j] = tmp[j] - '0';
        }
    }
    
    // 2. Divide and conquer
    string ret = calc(0, 0, N, N, N*N);
    cout << ret << '\n';
    return 0;
}