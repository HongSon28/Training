#include <bits/stdc++.h>
using namespace std;
const int NTEST = 1000;
int test = 10;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long h) {
    assert(l <= h);
    return l + abs(rd() * 1LL * rd() % (h - l + 1));
}
int main()
{
    srand(time(NULL));
    ofstream inp("test.inp");
    int n=rand(1,(int)1e5), m=rand(1,(int)5e4);
    inp<<n<<endl;
    for (int i=1;i<=n;i++) {
        inp<<rand(1,(int)1e6)<<' ';
    }
    inp<<endl<<m<<endl;
    while (m--) {
        int type=rand(1,2);
        int l=rand(1,n/2),r=rand(l+1,n);
        inp<<type<<' '<<l<<' '<<r;
        if (type==2) inp<<' '<<rand(1,(int)1e6);
        inp<<endl;
    }
    inp.close();
    system("sol.exe");
    string in_name=to_string(test)+".inp";
    string out_name=to_string(test)+".out";
    rename("test.inp",in_name.c_str());
    rename("test.out",out_name.c_str());
    return 0;
}
