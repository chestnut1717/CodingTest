#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string s;

int main(){

    // 1. Input n and s for each n
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        stack<char> st;
    // 2. Push each character of string to stack;
        for(char c : s) {
            if (st.size() && st.top() == c) st.pop();
            else st.push(c);
        }
        if (st.size() == 0) cnt++;

    }

    cout << cnt;

    return 0;
}