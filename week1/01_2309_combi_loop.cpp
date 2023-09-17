#include <bits/stdc++.h>
using namespace std;

int arr[9];
pair<int, int> ret;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. Input
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
    }

    // 2. sort
    sort(arr, arr+9);


    // 3. arr sum
    int sum = accumulate(arr, arr+9, 0);

    // 4. combination with loop
    for(int i = 0; i < 9; i++){
        for(int j = i+1; j < 9; j++){
            int sum_tmp = sum - arr[i] - arr[j];
            if (sum_tmp == 100) {
                ret = {i, j};
                break;
            }
        }
    }

    // 5. print
    for(int i = 0; i < 9; i++){
        if(i != ret.first && i != ret.second) cout << arr[i] << '\n';
    }

}