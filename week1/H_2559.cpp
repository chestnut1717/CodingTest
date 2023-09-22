#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100004];
int presum, ret;

int main(){

    // 1. Input n, k and each temperature for n
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 2. sum for arr[0] ~ arr[k-1]
    for(int i = 0; i <= k-1; i++){
        presum += arr[i];
    }

    ret = presum;

    // 3. sum
    for(int i = k; i < n; i++){
        presum = presum - arr[i-k] + arr[i];
        if(presum > ret) ret = presum;
    }

    cout << ret;
    return 0;
}