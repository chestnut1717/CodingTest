#include <bits/stdc++.h>
using namespace std;

string s;
int start_idx, end_idx;
bool is_pal = 1;

int main(){
    
    // Input string
    cin >> s;
    start_idx = 0;
    end_idx = s.length() - 1;
    
    // 2. Compare the left and right 
    while (start_idx < end_idx){
        if(s[start_idx] != s[end_idx]){
            is_pal = 0;
            break;
        }
        start_idx++;
        end_idx--;
    }
    
    cout << is_pal;
    return 0;
}