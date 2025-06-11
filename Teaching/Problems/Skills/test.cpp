#include <bits/stdc++.h>
using namespace std;
const int NTEST = 1000;
int test = 1;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long h) {
    assert(l <= h);
    return l + abs(rd() * 1LL * rd() % (h - l + 1));
}
int main()
{
    srand(time(NULL));
    ofstream inp("test.inp");
    int n=rand(1,500000), m=rand(3,64);
    inp<<n<<' '<<m<<endl;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) inp<<rand(0,1);
        inp<<endl;
    }
    inp.close();
    system("Skills.exe");
    string in_name=to_string(test)+".inp";
    string out_name=to_string(test)+".out";
    rename("test.inp",in_name.c_str());
    rename("test.out",out_name.c_str());
    return 0;
}
