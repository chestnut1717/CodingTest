#include<bits/stdc++.h>
using namespace std;

string s;
bool ret;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isValid(string s) {
    int flag = 0; // 0 : no vowel in string
    int v_cnt = 0;
    int a_cnt = 0;
    
    for(int i = 0; i < s.size(); i++) {
        // 1. Check if character is vowel
        if (isVowel(s[i])) v_cnt++, a_cnt = 0, flag = 1;
        else a_cnt++, v_cnt = 0;
        // 2. Three Times In a Row(Vowel or Not vowel)
        if (v_cnt == 3 || a_cnt == 3) return false;

        // 3. same character in a row
        if (i >= 1 && s[i] == s[i-1]) {
            if (s[i] == 'e' || s[i] == 'o') continue;
            else return false;
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