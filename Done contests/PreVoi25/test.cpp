#include <bits/stdc++.h>
using namespace std;
const int NTEST = 10000;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long h) {
    assert(l <= h);
    return l + abs(rd() * 1LL * rd() % (h - l + 1));
}
int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp("CHAND.INP");
        int n=rand(100,200),q=rand(100,200);
        inp<<n<<' '<<q<<'\n';
        for (int i=1;i<=n;i++) inp<<rand(1,100000)<<' ';
        inp<<'\n';
        for (int i=2;i<=n;i++) {
            inp<<i-1<<' '<<i<<'\n';
        }
        for (int i=1;i<=q;i++) {
            int x,y;
            x=rand(1,n-1);
            y=rand(x+1,n);
            inp<<x<<' '<<y<<'\n';
        }
        inp.close();
        system("CHAND.exe");
        system("CHAND1.exe");
        if (system("fc CHAND.OUT CHAND.ANS") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
