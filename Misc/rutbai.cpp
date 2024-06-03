#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n, i, j, min1, min2;
    long long cost = 0;
    ifstream input("RUTBAI.INP");
    ofstream output("RUTBAI.OUT");

    cin >> n;
    int cards[n];

    for (i = 0; i < n; i++) {
        cin >> cards[i];
    }

    for (i = 0; i < n - 2; i++) {
        // Tìm hai lá bài có giá trị nhỏ nhất
        if (cards[i] <= cards[i+1]) {
            min1 = i;
            min2 = i + 1;
        } else {
            min1 = i + 1;
            min2 = i;
        }

        for (j = i + 2; j < n; j++) {
            if (cards[j] < cards[min1]) {
                min2 = min1;
                min1 = j;
            } else if (cards[j] < cards[min2]) {
                min2 = j;
            }
        }

        // Rút hai lá bài có giá trị nhỏ nhất
        cost += (long long)cards[min1] * cards[min2] * cards[min1+1];
        for (j = min1; j < n - 2; j++) {
            cards[j] = cards[j+1];
        }
        for (j = min2 - 1; j < n - 3; j++) {
            cards[j] = cards[j+1];
        }
        n -= 2;
        i--;
    }

    cout << cost << endl;
    return 0;
}
