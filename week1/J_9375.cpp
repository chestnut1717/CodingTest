#include<bits/stdc++.h>
using namespace std;

int t, n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 1. Input t
    cin >> t;
    
    // 2. Input n for each t
    while(t--){
        cin >> n;
        // 2-1 경우의 수는 무조건 long long
        long long ret = 1;
        map<string, int> mp;
        string name, type;
        for(int i = 0; i < n; i++){
            cin >> name >> type;
            mp[type]++;
        }
        
        // 2.2 경우의 수 계산
        for(auto it: mp){
            ret *= (long long) it.second + 1;
        }
        ret--;
        cout << ret << '\n';
    }
    return 0;
}