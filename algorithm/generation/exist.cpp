// next_permutation exist
#include <bits/stdc++.h>
using namespace std;
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 3;
    vector<int> a(n);

    // Tạo cấu hình đầu tiên: 1, 2, 3
    iota(a.begin(), a.end(), 1);

    // Vòng lặp do-while tự động sinh toàn bộ N! hoán vị
    do {
        for (int x : a) {
            cout << x << " ";
        }
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}