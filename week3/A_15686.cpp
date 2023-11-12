#include <bits/stdc++.h>
using namespace std;

int N, M, tmp;
int ret = 1e6;

vector<pair<int, int>> chicken;
vector<pair<int, int>> tmp_chicken;
vector<pair<int, int>> house;

int calc_distance(pair<int, int>h, pair<int, int> c) {
    return abs(h.first - c.first) + abs(h.second - c.second);
}

void go(){
    vector<int> tmp_house_dist;
    
    for(auto it_h: house){
        int min_dist = 1e6;
        for(auto it_c: tmp_chicken) {
            min_dist = min(min_dist, calc_distance(it_h, it_c));
        }
        // 각 집마다 가장 거리가 짧은 치킨집의 거리를 더함
        tmp_house_dist.push_back(min_dist);
    }
    // 도시의 치킨 거리 계산
    int sum = accumulate(tmp_house_dist.begin(), tmp_house_dist.end(), 0);
    
    ret = min(ret, sum);
}

void chooseChicken(int idx, int cnt){
    if(cnt == M) {
        go();
        return;
    }
    for(int i = idx; i < chicken.size(); i++){
        tmp_chicken.push_back(chicken[i]);
        chooseChicken(i+1, cnt+1);    
        tmp_chicken.pop_back();
    }
    
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> tmp;
            if(tmp == 1) house.push_back({i, j});
            if(tmp == 2) chicken.push_back({i, j});
        }
    }
    
    chooseChicken(0, 0);
    cout << ret;
}