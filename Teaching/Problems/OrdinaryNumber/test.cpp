#include <bits/stdc++.h>
using namespace std;
const int NTEST = 1000;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long h) {
    assert(l <= h);
    return l + abs(rd() * 1LL * rd() % (h - l + 1));
}
int main()
{
    srand(time(NULL));
    ofstream inp("test.inp");
    int t = rand(1,10000);
    inp<<t<<endl;
    while (t--) inp<<rand(1,1000000000)<<endl;
    inp.close();
    system("1520B.exe");
    return 0;
}
