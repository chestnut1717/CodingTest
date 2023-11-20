#include <bits/stdc++.h>
using namespace std;

int T;
bool ret;
string s;
stack<char> st;

// Check if it is VPS
bool check(string s) {
    // Always false if first char is ')'
    if(s[0] == ')') return false;
    
    // 
    for(int i = 0; i < s.size(); i++) {
        // Check size(If not => top() will raise error)
        if (st.size() && st.top() == '(' && s[i] == ')') {
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }
    
    // If stack is completely empty => s is VPS
    if(st.size() == 0) return true;
    return false;
}

int main() {
    cin >> T;
    
    for(int i = 0; i < T; i++){
        cin >> s;
        ret = check(s);
        (ret) ? cout << "YES" << '\n' : cout << "NO" << '\n';
        
        // *Clear stack
        while(st.size()) {
            st.pop();
        }
        
    }
    
}