#include <bits/stdc++.h>
#define prev asdf
using namespace std;

int n;
int score;
string s;
int asum, bsum;
int A, B;
string prev;


int changeToSec(string s) {
    return stoi(s.substr(0, 2).c_str()) * 60 + stoi(s.substr(3, 2).c_str());
}

void calc(int &sum, string s){
    sum += changeToSec(s) - changeToSec(prev);
}

// print the specifit format
void print(int sum) {
    string min = "00" + to_string(sum / 60);
    string sec = "00" + to_string(sum % 60);
    
    cout << min.substr(min.size() - 2, 2) << ":" << sec.substr(sec.size() - 2, 2) << '\n';
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> score >> s;
        
        if (A > B) calc(asum, s);
        else if (A < B) calc(bsum, s);
        (score == 1) ? A++ : B++;
        prev = s;        
    }
    // need to calculate last input
    if (A > B) calc(asum, "48:00");
    else if (A < B) calc(bsum, "48:00"); 
    
    print(asum);
    print(bsum);
    
}