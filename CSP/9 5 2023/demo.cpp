#include <iostream>
using namespace std;

// Tính x^n mod m bằng phương pháp tính mũ nhanh
int power(int x, long long n, int m) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * x) % m;
        }
        x = (x * x) % m;
        n /= 2;
    }
    return result;
}

// Tính tổng tất cả các phần tử trong cấp số nhân
int geometric_sequence_sum(int x, long long n, int m) {
    int numerator = power(x, n+1, m) - 1;
    int denominator = x - 1;
    int s = (1LL * numerator * power(denominator, m-2, m)) % m;
    return s;
}

int main() {
    // Đọc dữ liệu từ file input
    int x, m;
    long long n;
    cin >> x >> n >> m;

    // Tính tổng các phần tử trong cấp số nhân và in ra kết quả
    int s = geometric_sequence_sum(x, n, m);
    cout << s << endl;

    return 0;
}
