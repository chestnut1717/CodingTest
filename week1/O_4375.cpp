#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(cin >> n){
        int i = 1;
        long long ret = 1 % n;
        int mem = 1 % n;
        while(ret){
            mem = ( (10 % n) * mem ) % n;
            ret = (mem + ret) % n;
            i++;
        }
        
        cout << i << '\n';
    }
    return 0;
}