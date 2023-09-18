#include <bits/stdc++.h>

using namespace std;

int arr[9];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. Input
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
    }
    // 2. sort for next_permutation()
    sort(arr, arr+9);

    // 3. doing permutation
    do{
        int sum = 0;
        for(int i = 0; i < 7; i++) {
            sum += arr[i];
        }
        if(sum == 100) break;
    } while(next_permutation(arr, arr+9));
    for(int i = 0; i < 7; i++) cout << arr[i] << '\n';

    return 0;
}