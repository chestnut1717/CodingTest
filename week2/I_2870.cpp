#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> v;
string s, ret;

void go(){
    while(true){
        if(ret.size() && ret.front() == '0') ret.erase(ret.begin());
        else break;
    }
    
    if (ret.size() == 0) ret = "0";
    v.push_back(ret);
    ret = "";
}

// Sort string 
// 1st. When size is same -> compare each pair of ascii
// 2nd. When size is different -> string bigger size goes back
bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(){
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        ret = "";
        for(int j = 0; j < s.size(); j++){
            // 1. Check if char is number
            if(s[j] < 65) ret += s[j];
            
            // 2. When Char is not number && size > 0
            else if(ret.size()) go();
        }
        if(ret.size()) go();
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(string i : v) cout << i << '\n';
    return 0;
}