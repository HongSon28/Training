#include <bits/stdc++.h>
using namespace std;
const int NTEST = 1;

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
        ofstream inp("EXCHANGE.INP");
        int n=0,p=rand(500,1000);
        int sum=0;
        vector<int>a;
        while (sum<p) {
        	int t=rand(1,100);
        	sum+=t;
        	a.push_back(t);
        }
        inp<<a.size()<<' '<<p<<endl;
        for (auto x:a) inp<<x<<' ';
        inp.close();
        system("EXCHANGE.exe");
        system("EXCHANGE1.exe");
        if (system("fc EXCHANGE.OUT EXCHANGE.ANS") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
