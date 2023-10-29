#include <bits/stdc++.h>
using namespace std;

int n, c;
int arr[1004];
map<int, int> mp, mp_first;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return mp_first[a.second] < mp_first[b.second];
    }
    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        // count
        mp[arr[i]]++; 
        // check if it is first input => if yes, save order
        if(mp_first[arr[i]] == 0) mp_first[arr[i]] = i + 1;
    }
    
    for(auto it : mp) {
        // it.second = freq, it.first = value
        v.push_back({it.second, it.first});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(auto it: v) {
        for(int i = 0; i < it.first; i++) {
            cout << it.second << " ";
        }
    }
    
}