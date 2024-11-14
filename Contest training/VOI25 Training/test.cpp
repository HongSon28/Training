#include <bits/stdc++.h>
using namespace std;
const int NTEST = 100;

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
        ofstream inp("symetrictable.inp");
        int n=rand(20,30),m=rand(20,30);
        inp<<n<<' '<<m<<endl;
        for (int i=1;i<=n;i++) {
        	for (int j=1;j<=m;j++) {
        		int t=rand(0,25);
        		inp<<(char)('a'+t);
        	}
        	inp<<endl;
        }
        inp.close();
        system("symetrictable.exe");
        system("symetrictable1.exe");
        if (system("fc symetrictable.out symetrictable.ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
