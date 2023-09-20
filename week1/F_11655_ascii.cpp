#include <bits/stdc++.h>
using namespace std;

char arr[101];
string s;

int main(){

    // 1. input
    getline(cin, s);

    // 2. string to arr
    for(int i = 0; i < s.size(); i++){
        // 2.1 If char is not integer shape
        char tmp = s[i];
        if ( 'a' <= tmp && tmp <= 'z') arr[i] = (char) ((tmp - 'a' + 13) % 26 + 'a');
        else if ('A' <= tmp && tmp <= 'Z') arr[i] = (char) ((tmp - 'A' + 13) % 26 + 'A');
        else arr[i] = tmp;
    }

    // 3. print
    // for(char c: arr) cout << c << "";
    for(int i = 0; i < s.size(); i++) {
        cout << arr[i] << "";
    }

    return 0;
}