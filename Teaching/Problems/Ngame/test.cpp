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
    int n=rand((int)1e8,(int)1e9), k=rand(12,15);
    inp<<n<<' '<<k<<endl;
    for (int i=1;i<=k;i++) inp<<rand(1,100)<<' ';
    inp.close();
    system("NGM2.exe");
    string in_name=to_string(test)+".inp";
    string out_name=to_string(test)+".out";
    rename("test.inp",in_name.c_str());
    rename("test.out",out_name.c_str());
    return 0;
}
