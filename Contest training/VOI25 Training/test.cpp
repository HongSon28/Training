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
        ofstream inp("PER.INP");
        vector<int>v;
        int n=rand(90,100),q=rand(90,100);
        inp<<n<<' '<<q<<endl;
        for (int i=1;i<=n;i++) v.push_back(i);
        random_shuffle(v.begin(),v.end());
        for (auto x:v) inp<<x<<' ';
        inp<<'\n';
        random_shuffle(v.begin(),v.end());
        for (auto x:v) inp<<x<<' ';
        inp<<'\n';
        for (int i=1;i<=q;i++) {
            int l=rand(1,n),r=rand(l,n);
            inp<<l<<' '<<r<<' ';
            l=rand(1,n),r=rand(l,n);
            inp<<l<<' '<<r<<endl;
        }
        inp.close();
        system("PER.exe");
        system("PER1.exe");
        if (system("fc PER.OUT PER.ANS") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
