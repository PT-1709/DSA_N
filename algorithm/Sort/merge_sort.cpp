#include <iostream>
#include <vector>
using namespace std;

// Hàm merge: trộn hai mảng con đã được sắp xếp thành một mảng con sắp xếp hoàn chỉnh
void merge(vector<int> &arr, int left, int mid, int right) {
    // Tính kích thước của hai mảng con
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo hai mảng tạm để lưu dữ liệu
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i]; // Sao chép phần tử từ mảng chính sang mảng L
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j]; // Sao chép phần tử từ mảng chính sang mảng R
    }

    // Trộn hai mảng L và R vào mảng arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; // Nếu phần tử L nhỏ hơn hoặc bằng R, lấy L
            i++;
        } else {
            arr[k] = R[j]; // Ngược lại lấy R
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L (nếu có)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R (nếu có)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm mergeSort: chia mảng thành các phần nhỏ và gọi hàm merge để trộn
void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Tìm điểm giữa
        mergeSort(arr, left, mid);           // Sắp xếp nửa trái
        mergeSort(arr, mid + 1, right);      // Sắp xếp nửa phải
        merge(arr, left, mid, right);        // Trộn hai nửa đã sắp xếp
    }
}

int main() {
    vector<int> arr;
    int n;
    cin >> n; // Nhập số lượng phần tử
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t; // Nhập từng phần tử
        arr.push_back(t);
    }

    mergeSort(arr, 0, arr.size() - 1); // Gọi hàm sắp xếp

    // In mảng sau khi sắp xếp
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}