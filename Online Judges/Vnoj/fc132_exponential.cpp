#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int x;
int d[N+5];
void seive() {
    for (int i=1;i<=N;i++) d[i]=i;
    for (int i=2;i*i<=N;i++) {
        if (d[i]==i)
            for (int j=i*i;j<=N;j+=i)
                if (i<d[j]) d[j]=i;
    }
}
int main() {
    seive();
    cin>>x;
    for (int i=x;i>=1;i--) {
        vector<int>v;
        int temp=i;
        while (temp>1) {
            int div=d[temp];
            int c=0;
            while (temp%div==0) {
                temp/=div;
                c++;
            }
            v.push_back(c);
        }
        if (v.size()<1) continue;
        int gcd=v[0];
        for (auto j:v) gcd=__gcd(gcd,j);
        if (gcd!=1) {
            cout<<i;
            return 0;
        }
    }
    cout<<1;
}
