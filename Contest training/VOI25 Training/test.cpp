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
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp("SQUARE.INP");
        int n=rand(2,4),m=rand(2,min(20/n,8)),t=rand(0,min(5,n*m));
        inp<<n<<' '<<m<<' '<<t<<endl;
        for (int i=1;i<=t;i++) {
            inp<<rand(1,n)<<' '<<rand(1,m)<<' '<<rand(0,1)<<endl;
        }
        inp.close();
        system("SQUARE.exe");
        system("SQUARE1.exe");
        if (system("fc SQUARE.OUT SQUARE.ANS") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
