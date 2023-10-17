#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B, C;
ll tmp, ret;
ll calc(ll a, ll b, ll c){
    if (b == 1) return a % c;

    tmp = calc(a, b/2, c);
    tmp = (tmp * tmp) % c;
    // if b is odd number => only multiple a once
    if (b % 2) {
        return (tmp * a) % c;
    }
    else {
        return tmp;
    }
    
    

}

int main(){
    
    cin >> A >> B >> C;

    ret = calc(A, B, C);
    
    cout << ret << '\n';
    return 0;
}