#include <bits/stdc++.h>
using namespace std;
const int NTEST = 1000;
int test = 9;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long h) {
    assert(l <= h);
    return l + abs(rd() * 1LL * rd() % (h - l + 1));
}
int main()
{
    srand(time(NULL));
    ofstream inp("test.inp");
    int n=rand(1,(int)1e5), m=rand(0,10);
    inp<<n<<' '<<m<<endl;
    vector<int>v;
    for (int i=1;i<=n;i++) v.push_back(i);
    random_shuffle(v.begin(),v.end());
    for (auto x:v) inp<<x<<' ';
    inp.close();
    system("597C.exe");
    string in_name=to_string(test)+".inp";
    string out_name=to_string(test)+".out";
    rename("test.inp",in_name.c_str());
    rename("test.out",out_name.c_str());
    return 0;
}
