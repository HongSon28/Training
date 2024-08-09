#include <bits/stdc++.h>
using namespace std;
const int NTEST = 100;

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
        ofstream inp("FNCS.inp");
        int n=150;
        inp<<n<<'\n';
        for (int i=1;i<=n;i++) inp<<Rand(1,1e9)<<' ';
        inp<<'\n';
        for (int i=1;i<=n;i++) {
            int l=Rand(1,n-1),r=Rand(l+1,n);
            inp<<l<<' '<<r<<'\n';
        }
        int q=Rand(3,7);
        inp<<q<<'\n';
        for (int i=1;i<=q;i++) {
            int t=Rand(1,2);
            if (t==1) inp<<t<<' '<<Rand(1,n)<<' '<<Rand(1,1e9)<<'\n';
            else {
                int u=Rand(1,n),v=Rand(u,n);
                inp<<t<<' '<<u<<' '<<v<<'\n';
            }
        }
        inp.close();
        system("FNCS.exe");
        system("FNCS_brute.exe");
        if (system("fc FNCS.out FNCS.ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
