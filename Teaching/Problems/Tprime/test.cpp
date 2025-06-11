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
    int t = rand(1,100000);
    inp<<t<<endl;
    while (t--) {
        if (rand(1,2)==1) inp<<rand(1,(long long)1e12)<<' ';
        else {
            long long tmp = rand(1,1000000);
            inp<<tmp*tmp<<' ';
        }
    }
    inp.close();
    system("230B.exe");
    return 0;
}
