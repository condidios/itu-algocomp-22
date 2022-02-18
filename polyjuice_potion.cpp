#include <iostream>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        int temp1 = 100 - a[i];
        int gcdOfThem = gcd(temp1, a[i]);
        temp1 = temp1 / gcdOfThem;
        a[i] = a[i] / gcdOfThem;
        a[i] = a[i]+temp1;
    }
    for (int i = 0; i < n; ++i) {
        std::cout<<a[i]<<std::endl;
    }
    return 0;
}