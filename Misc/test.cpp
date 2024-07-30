#include <bits/stdc++.h>
using namespace std;
const int NTEST = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp("maxreg.inp");
        int n=5,m=5;
        inp<<n<<' '<<m<<'\n';
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                int t=(Rand(1,100)%2+2)%2;
                inp<<t;
            }
            inp<<'\n';
        }
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system("MAXREG.exe");
        system("MAXREG2.exe");
        // Nếu dùng linux thì thay fc bằng diff
        if (system("fc maxreg.out maxreg.ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
