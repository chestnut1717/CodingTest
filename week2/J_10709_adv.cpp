#include <bits/stdc++.h>
using namespace std;

int H, W;
int ret[104][104];
string str;

int main(){
    
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        cin >> str;
        for(int j = 0; j < W; j++){
            if(str[j] == '.') ret[i][j] = -1;
            else ret[i][j] = 0;
        }
    }
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if (ret[i][j] == 0){
                int cnt = 1;
                while(ret[i][j+1] == -1){
                    ret[i][j+1] = cnt;
                    cnt++;
                    j++;
                }
            }
        }
    }
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }
    
}