#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector <int> a;
bool final = false;

void init(){
    a.resize(n);
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
    }
}

void nextPermutation(){
    int k = n - 2;
    while (k >= 0 && a[k] > a[k+1]){
        k--;
    }

    if (k < 0){
        final = true;
        return;
    }

    int i = n - 1;
    while (a[i] < a[k]){
        i--;
    }

    swap(a[i],a[k]);
    reverse(a.begin() + k + 1, a.end());


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    
    cin >> n;
    init();
    while (!final) {
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << '\n';
        nextPermutation();
    }
    
    return 0;
}