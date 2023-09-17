#include <bits/stdc++.h>
using namespace std;

int n = 9, r = 7;
int arr[9];

// Vector for combination
vector<int> v;

// for print array element
void print(){
    for(int i: v){
        cout << arr[i] << '\n';
    }
}

// for summation
int summation() {
    int sum = 0;
    for(int i : v) sum += arr[i];
    return sum;
}

void combi(int n, int r, int start){
    if(v.size() == r) {
        int sum = summation();
        if(sum == 100) {
            print();
            exit(0);
        }
        return;
    }
    for(int i = start; i < n; i++){
        v.push_back(i);
        combi(n, r, i+1);
        v.pop_back();
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. Input
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
    }

    // 2. sort()
    sort(arr, arr+9);

    // 3. combination with recursion
    combi(n, r, 0);

}