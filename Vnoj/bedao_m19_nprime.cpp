#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
bool prime[N+5];
void seive() {
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for (int i=2;i<=N;i++){
        if (prime[i]) {
            for (int j=i*2;j<=N;j+=i) prime[j]=false;
        }
    }
}
int main() {
    seive();
    int t;
    cin>>t;
    while (t--) {
        long long n;
        cin>>n;
        long long i;
        for(i=2;i<=N;i++) {
            if (n%i==0&&prime[i]==true) {
                if (n%(i*i)==0) {
                    cout<<i<<' '<<n/(i*i)<<endl;
                    break;
                }
                else if(sqrt(n/i)*sqrt(n/i)*i==n) {
                    cout<<sqrt(n/i)<<' '<<i<<endl;
                    break;
                }
            }
        }
    }
}
