#include <bits/stdc++.h>
using namespace std;

int n, pos;
string s, pre, suf, text;
int main(){

    cin >> n;
    cin >> s;

    pos = s.find("*");
    pre = s.substr(0, pos);
    suf = s.substr(pos+1);

    for(int i = 0; i < n; i++){
        cin >> text;
        if(text.size() < pre.size() + suf.size()) {
            cout << "NE" << "\n";
        }else{
            if (text.substr(0, pre.size()) == pre && text.substr(text.size() - suf.size()) == suf) cout << "DA" << "\n";
            else cout << "NE" << "\n";
        }
    }
    return 0;

}