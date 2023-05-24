#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
bool p[N+1];
int n;
vector<int>v;
void sang() {
    memset(p,true,sizeof(p));
    for (int i=2;i<=N;i++) {
        if (p[i]==true) {
            v.push_back(i);
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    freopen("NEARESTPRIME.INP","r",stdin);
    freopen("NEARESTPRIME.OUT","w",stdout);
    sang();
    while(cin>>n){
        auto it1=lower_bound(v.begin(),v.end(),n);
        auto it2=it1;
        it2--;
        int a=*it1;
        int b=*it2;
        if (abs(a-n)>abs(b-n)) cout<<b<<endl;
        else if (abs(a-n)<abs(b-n)) cout<<a<<endl;
        else cout<<b<<endl;
    }
}


