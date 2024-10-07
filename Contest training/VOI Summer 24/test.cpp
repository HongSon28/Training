#include <bits/stdc++.h>
using namespace std;
const int NTEST = 1;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + abs(rd() * 1LL * rd() % (h - l + 1));
}
int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        vector<pair<int,int>>v;
        ofstream inp("COW.INP");
        for (int i=1;i<=30;i++) {
            for (int j=1;j*i<=30;j++) v.push_back({i,j});
        }
        inp<<v.size()<<'\n';
        for (auto [x,y]:v) inp<<x<<' '<<y<<'\n';
        inp.close();
        system("COW.exe");
        system("COW2.exe");
        if (system("fc COW.OUT COW.ANS") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
