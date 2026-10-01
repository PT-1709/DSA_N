#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n; 
vector <int> a;
bool final = false;

void init(){
    a.assign(n,0);
}

void next_profile(){
    int i = n - 1;
    while (i >= 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if (i < 0){
        final = true;
    }
    else{
        a[i] = 1;
    }
    
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    
    cin >> n;
    init();
    while (!final){
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << '\n';
        next_profile();
    }
    
    return 0;
}