#include <bits/stdc++.h>
using namespace std;

int n;
int arr[26];
int cnt = 0;
string result;

int main(){

    // 1. Input N
    cin >> n;

    // 2. Input first name and extract first char
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        arr[s[0] - 'a']++;
    }

    // 3. count the first character above 5
    for(int i = 0; i < 26; i++){
        if(arr[i] >= 5){
            cnt++;
            result += i + 'a'; // 숫자를 문자화
        }
    }

    // 5. print result
    if (cnt == 0){
        cout << "PREDAJA";
    }
    else {
        cout << result;
    }

    return 0;
}