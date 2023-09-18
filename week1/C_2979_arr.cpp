#include <bits/stdc++.h>
using namespace std;

int arr[101];

int a, b, c;
int start_t, end_t;
int sum = 0;

// count cars
void countCars(int start_t, int end_t){
    for(int i = start_t; i < end_t; i++) {
        arr[i]++;
    } 
    return;
}
    
int main(){

	// 1. input cost
    cin >> a >> b >> c;
    
    // 2. input 3 cars time and count
    for(int i = 0; i < 3; i++){
        cin >> start_t >> end_t;
        countCars(start_t, end_t);
    }
    
    // 3. sum of cost
    for(int i = 1; i < 100; i++){
        if(arr[i] == 1) sum += a;
        else if(arr[i] == 2) sum += 2 * b;
        else if(arr[i] == 3) sum += 3 * c;
    }

    cout << sum;

}