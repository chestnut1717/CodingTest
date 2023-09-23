#include <bits/stdc++.h>
using namespace std;

string s, ret;
// 0. character => use array!
int cnt[200], flag;
char mid;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 1. Input string and str to map(char type)
    cin >> s;
    for(char c : s) cnt[c]++;

    // 2. Traverse array if there is odd number
    for(int i = 'Z'; i >= 'A'; i--) {
        if(cnt[i]) {
            if(cnt[i] & 1){
                mid = char(i);
                flag++;
                cnt[i]--;
            }
            // 2.1 if flag 2 => impossible case
            if(flag == 2) break;
            // 2.2 after checking, characters in array are added to ret
            for(int j = 0; j < cnt[i]; j += 2){
                ret = char(i) + ret;
                ret += char(i);
            }
        } 
    }
    
    // 3. mid to ret
    if(mid) ret.insert(ret.begin() + ret.size() / 2, mid);
    if(flag == 2) cout << "I'm Sorry Hansoo\n";
    else cout << ret << "\n";
}