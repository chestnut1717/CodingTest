#include <bits/stdc++.h>
using namespace std;

int N, M, j;
int ret;
int s, e;
queue<int> q;

int main(){
    cin >> N >> M;
    cin >> j;
    
    // 1. Input J
    for(int i = 0; i < j; i++){
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    
    // start, end of basket
    s = 1; e = M;
    while (q.size()){
        int apple = q.front(); q.pop();
        if (s <= apple && apple <= e) continue;

        // basket is behind the apple
        else if (apple < s) {
            int move = s - apple;
            ret += move; s -= move; e -= move;
        }
        // basket is in front of the apple
        else {
            int move = apple - e;
            ret += move; s += move; e += move;
        }
    }
    
    cout << ret;
    
}