#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAX_c = 1e7+1;
int spf[MAX_c];

void buildSPF(){
    for (int i = 1; i < MAX_c; i++){
        spf[i] = i;
    }
    for (int i = 4; i < MAX_c; i+= 2){
        spf[i] = 2;
    }

    for (int i = 3; i * i < MAX_c; i++){
        if (spf[i] == i){
            for (int j = i * i; j < MAX_c; j += i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}
// bản chất là đi đánh giấu trên mảng coi số nguyên tố bé nhất mà N chia hết cho là bao nhiêu, spf[n] = n chứng tỏ n là số nguyên tố

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);

    buildSPF();

    int n; cin >> n;
    
    //cout << n << " so nguyen to dau tien: " << '\n';
    int cnt = 0;
    int i = 2;
    while (cnt < n){
        if (spf[i] == i){
            cout << i << " ";
            cnt++;
        }
        i++;
    }
    
    return 0;
}