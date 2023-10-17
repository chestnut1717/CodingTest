#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(cin >> n){
        int cnt = 1, ret = 1;

        while(cnt % n){
            cnt = (cnt * 10) + 1;
            cnt %= n;
            ret++;
        }
        
        cout << ret << '\n';
    }
    return 0;
}