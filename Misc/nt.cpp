#include<bits/stdc++.h>
using namespace std;
long long n=1000000,res=0;
vector<long long> prime;
void sang() {
    bool isprime[n+1];
    for (int i=0;i<=n;i++) isprime[i]=true;
    for (int i=2;i<=n;i++) {
        if (isprime[i]==true) {
            prime.push_back(i);
            for (int j=i*2;j<=n;j+=i) {
                isprime[j]=false;
            }
        }
    }
}
int main() {
    sang();
    for (int i=0;i<prime.size()-1;i++) {
        for (int j=i+1;j<prime.size();j++) {
            res++;
        }
    }
    cout<<res;
}
