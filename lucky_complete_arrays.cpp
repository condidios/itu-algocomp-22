#include <iostream>
#include <vector>
#include <map>
#include <chrono>

#ifndef MAIN
#define MAIN
using namespace std;

//https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c
template<typename T>
void pretty_print(const T &c, int combo, map<int, int> &sums) {
    int total = 0;
    int n = c.size();
    for (int i = 0; i < n; ++i) {
        if ((combo >> i) & 1)
            total += c[i];
    }
    sums[total] = total;
}

template<typename T>
void combo(const T &c, int k, map<int, int> &sums) {
    int n = c.size();
    int combo = (1 << k) - 1;
    while (combo< 1 << n) {

        pretty_print(c, combo, sums);

        int x = combo & -combo;
        int y = combo + x;
        int z = (combo & ~y);
        combo = z / x;
        combo >>= 1;
        combo |= y;
    }
}

void comboAll(const vector<int> &v1, map<int, int> &sums) {
    for (int i = 1; i <= ((int) v1.size()); ++i) {
        combo(v1, i, sums);
    }
}

int findMissing(const map<int, int> &vector1) {
    int temp = 1;
    for (auto i : vector1) {
        if (i.first != temp) {
            return temp;
        }
        temp++;
    }
    return temp;
}

int main() {
    int n, temp;
    long unsigned int k;
    cin >> n >> k;
    vector<int> v1, added;
    map<int, int> v2;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        v1.push_back(temp);
    }
    int counter = 0;
    auto start2 = chrono::high_resolution_clock::now();
    auto stop2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
    while (v2.size() < k) {
        v2.clear();

        start2 = chrono::high_resolution_clock::now();

        comboAll(v1, v2);

        stop2 = chrono::high_resolution_clock::now();
        {
            duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
            cout << duration2.count() << endl;
        }

        int missing = findMissing(v2);
        added.push_back(missing);
        v1.push_back(missing);
        v2[missing] = missing;
        counter++;
    }
    duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
    cout << duration2.count() << endl;
    cout << added.size() << endl;
    return 0;
}
#endif //MAIN