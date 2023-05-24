#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
map<int,int>mp;
bool p[N+1];
vector<int>prime;
void sang() {
    memset(p,true,sizeof(p));
    for (int i=2;i<=N;i++) {
        if (p[i]==true) {
            for (int j=i*2;j<=N;j+=i) p[j]=false;
            prime.push_back(i);
        }
    }
}
int main() {
    sang();
    int s=prime.size();
    int t;
    cin>>t;
    while (t--) {
        long long x;
        cin>>x;
        if (p[x]==true) {
            cout<<x<<endl;
        } else {
            int i=0;
            while (x>1) {
                while (x%prime[i]==0) {
                    mp[prime[i]]++;
                    x/=prime[i];
                }
                i++;
                if (i==s) {
                    x=1;
                }
            }
        }
    }
}
