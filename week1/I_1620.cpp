#include <bits/stdc++.h>
using namespace std;

map<int, string> number_map;
map<string, int> string_map;

int n, m;
string tmp;

int main(){

    // 0. (IMPORTANT) preventing time limit
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. input n, m
    cin >> n >> m;

    // 2. input and numbering N poketmons
    for(int i = 1; i <= n; i++){ 
        cin >> tmp;
        number_map[i] = tmp;
        string_map[tmp] = i;
    }

    // 3. input n question and solve
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        int q_int = atoi(tmp.c_str());
        // 3.1 question is INT
        if (q_int == 0) cout << string_map[tmp] << '\n';
        else cout << number_map[q_int] << '\n';
    }
    return 0;
}