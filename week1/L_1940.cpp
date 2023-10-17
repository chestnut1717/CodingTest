#include <bits/stdc++.h>
using namespace std;

int n, m;
int ret;
int arr[15004];

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 1. Input n, m
    cin >> n >> m;
    
    // 2. For each n, input number and store it
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // 3. print 0 when 0 is over 200,000
    if(m > 200000) cout << 0;
    else {
    // 4. Extract index with nC2
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int tmp = arr[i] + arr[j];
                if (tmp == m) ret++;
            }
        }
        
        cout << ret;
    }

    return 0;
}