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
    int n=rand(1,(int)1e6);
    inp<<n<<endl;
    int div=1000;
    int m=n/div;
    vector<int>v;
    for (int i=0;i<m;i++) v.push_back(rand(1,1000));
    for (int i=1;i<m;i++) {
        for (int j=1;j<=div;j++) v.push_back(v[i]*rand(1,(int)1e9/v[i]));
    }
    while (v.size()<n) {
        v.push_back(v[0]*rand(1,(int)1e9/v[0]));
    }
    random_shuffle(v.begin(),v.end());
    for (auto x:v) inp<<x<<' ';
    int t=rand(1,(int)1e5);
    inp<<endl<<t<<endl;
    while (t--) {
        int l=rand(1,n/2),r=rand(l+1,n);
        inp<<l<<' '<<r<<endl;
    }
    inp.close();
    system("sol.exe");
    string in_name=to_string(test)+".inp";
    string out_name=to_string(test)+".out";
    rename("test.inp",in_name.c_str());
    rename("test.out",out_name.c_str());
    return 0;
}
