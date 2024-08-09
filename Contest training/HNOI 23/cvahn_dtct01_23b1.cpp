#include<bits/stdc++.h>
using namespace std;
long long n;
vector<long long>fib;
bool check(long long x) {
    for (long long i=2;i*i<=x;i++)
        if (x%i==0) return false;
    return true;
}
int main() {
    freopen("NGTOFIB.INP","r",stdin);
    freopen("NGTOFIB.OUT","w",stdout);
    cin>>n;
    long long x=1,y=1;
    while (true) {
        long long z=x+y;
        if (z>n) break;
        if (z>=10) fib.push_back(z);
        x=y;
        y=z;
    }
    for (auto i:fib) {
        if (!check(i)) continue;
        string s=to_string(i);
        while(next_permutation(s.begin(),s.end())) {
            long long temp=stoi(s);
            if (check(temp)) {
                cout<<i<<endl;
                break;
            }
        }
    }
}
