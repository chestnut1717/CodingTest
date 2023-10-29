#include <bits/stdc++.h>
using namespace std;

int t, n;
int num, cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    // 1. Input case
    for(int i = 0; i < t; i++){
        cin >> n;
        num = 5;
        cnt = 0;
        
        // 2. For each case, count how much 5 appears with powered by 5
        while(num <= n){
            cnt += n / num;
            num *= 5;
        }
        cout << cnt << '\n';
    }
    
}