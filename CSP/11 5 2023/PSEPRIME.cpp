#include<bits/stdc++.h>
using namespace std;
unsigned long long m;
const int N=1e6;
bool flag=false;
bool prime[N+5];
void sang() {
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for (int i=2;i<=N;i++) {
        if (prime[i]==true) {
            for (int j=i*2;j<=N;j+=i) prime[j]=false;
        }
    }
}
unsigned long long power(unsigned long long x, unsigned long long n) {
    long long temp;
    if (n==0) return 1;
    temp=power(x,n/2)%m;
    if (n%2==0) {
        unsigned long long res=temp*temp;
        res%=m;
        return res;
    } else {
        unsigned long long res=(x%m)*temp*temp;
        res%=m;
        return res;
    }
}
int main() {
    freopen("PSEPRIME.INP","r",stdin);
    freopen("PSEPRIME.OUT","w",stdout);
    sang();
    unsigned long long n;
    cin>>n;
    for (m=1;m<=n;m++) {
        if (prime[m]==false) {
            if (power(2,m)==2) {
                cout<<m<<' ';
                flag=true;
            }
        }
    }
    if (!flag) cout<<0;
}
