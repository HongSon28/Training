#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    int a, b;
};

bool compareA(Player p1, Player p2) {
    return p1.a < p2.a;
}

bool compareB(Player p1, Player p2) {
    return p1.b > p2.b;
}

int main() {
    int n, i, score = 0;
    cin >> n;

    Player players[1000];
    for (i = 0; i < n; i++) {
        cin >> players[i].a >> players[i].b;
    }

    sort(players, players + n, compareA); // Sắp xếp theo trình độ A tăng dần
    sort(players, players + n, compareB); // Sắp xếp theo trình độ B giảm dần

    for (i = 0; i < n; i++) {
        if (players[i].b > players[i].a) {
            score += 2;
        } else if (players[i].b == players[i].a) {
            score += 1;
        } else {
            break; // Dừng lại nếu không còn kỳ thủ B phù hợp
        }
    }

    cout << score << endl;
    return 0;
}
