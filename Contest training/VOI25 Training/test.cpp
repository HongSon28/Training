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
        ofstream inp("BOX.INP");
        int n=100;
        inp<<n<<'\n';
        for (int i=1;i<=n;i++) {
        	int a=rand(2,1000000),b=rand(1,a-1);
        	inp<<a<<' '<<b<<endl;
        }
        inp.close();
        system("boxd4.exe");
        system("boxd5.exe");
        if (system("fc BOX.OUT BOX.ANS") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
