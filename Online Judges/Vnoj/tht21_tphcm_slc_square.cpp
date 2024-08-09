#include<bits/stdc++.h>
using namespace std;
const long long N=1e7;
bool p[N+1];
long long res=1;
vector<long long>v;
map<long long,long long>mp;
void sang() {
    memset(p,true,sizeof(p));
    for (int i=2;i<=N;i++) {
        v.push_back(i);
        for (int j=i*2;j<=N;j+=i) {
            p[j]=false;
        }
    }
}
int main() {
    sang();
    int a,b,c;
    cin>>a>>b>>c;
    for (int i=0;i<v.size();i++) {
        if (a==1) break;
        long long cnt=0;
        while (a%v[i]==0) {
            cnt++;
            a/=v[i];
        }
        if (mp[v[i]]<cnt)
            mp[v[i]]=cnt;
    }
    for (int i=0;i<v.size();i++) {
        if (b==1) break;
        long long cnt=0;
        while (b%v[i]==0) {
            cnt++;
            b/=v[i];
        }
        if (mp[v[i]]<cnt)
            mp[v[i]]=cnt;
    }
    for (int i=0;i<v.size();i++) {
        if (c==1) break;
        long long cnt=0;
        while (c%v[i]==0) {
            cnt++;
            c/=v[i];
        }
        if (mp[v[i]]<cnt)
            mp[v[i]]=cnt;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        if ((i->second)%2==1) (i->second)++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        long long f=i->first,s=i->second;
        for (int j=1;j<=s/2;j++) res*=f;
    }
    cout<<res;
}
