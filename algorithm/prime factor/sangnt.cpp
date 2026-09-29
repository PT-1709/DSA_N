#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_C = 1e7 + 5;
vector <bool> snt(MAX_C, true);

void sangnt(){
    snt[0] = snt[1] = false;
    for (int i = 2; 1LL * i * i < MAX_C; i++){
        if (snt[i]){
            for (int j = i * i; j < MAX_C; j += i){
                snt[j]= false;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    sangnt();

    int n= 2, cnt = 0;
    while (cnt < 100){
        if (snt[n]){
            cout << n << " ";
            cnt++;
        }
        n++;
    }
    
    return 0;
}