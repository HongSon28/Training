#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
bool p[N+1];
vector<int>prime;
void sang() {
    memset(p,true,sizeof(p));
    for (int i=2;i<=N;i++) {
        if (p[i]==true) {
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
    for (int i=2;i<=N;i++)
        if (p[i]==true)
            prime.push_back(i);
}
int main() {
    sang();
    int t;
    cin>>t;
    //for (auto i:prime) cout<<i<<' ';
    while (t--) {
        int d;
        cin>>d;
        int i=0;
        while (prime[i]<=d) {
            i++;
        }
        long long res=prime[i];
        while (prime[i]-res<d) i++;
        res*=prime[i];
        cout<<res<<endl;
    }
}
