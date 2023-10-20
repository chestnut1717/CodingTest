#include<bits/stdc++.h>
using namespace std;

string s;
bool ret;
vector<char> v{'a', 'e', 'i', 'o', 'u'};
stack<char> st;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isValid(string s) {
    int flag = 0; // 0 : no vowel in string
    int v_cnt = 1;
    int a_cnt = 1;
    
    for(int i = 0; i < s.size(); i++) {
         if (isVowel(s[i])) flag = 1;
        
        // same character in a row
        if (i >= 1 && s[i] == s[i-1]) {
            if (s[i] == 'e' || s[i] == 'o') continue;
            else return false;
        }
        
        if (i >= 1 && isVowel(s[i]) == isVowel(s[i-1])) {
            if (isVowel(s[i])) v_cnt++;
            else a_cnt++;
        } else {
            v_cnt = 1, a_cnt = 1;
        }
        
        if (v_cnt == 3 || a_cnt == 3) {
            return false;
        }       
    }
    
    if (flag == 0) return false;
    
    return true;
    
}

int main(){
    
    while (true) {
        cin >> s;
        if (s == "end") break;
        ret = isValid(s);
        
        if (ret) printf("<%s> is acceptable.\n", s.c_str());
        else printf("<%s> is not acceptable.\n", s.c_str());
        
    }
    return 0;
}