#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
long long n,cnt=0,temp;
vector<long long>v;
bool c[N+5];
int main() {
    freopen("WATERING.INP","r",stdin);
    freopen("WATERING.OUT","w",stdout);
    cin>>n;
    cin>>temp;
    v.push_back(temp);
    c[0]=false;
    for (int i=1;i<n;i++) {
        cin>>temp;
        if (temp!=v[v.size()-1]) v.push_back(temp);
        c[i]=false;
    }
    if (v[0]>v[1]) {
        cnt++;
        c[0]=true;
        long long tr=v[0];
        for (int j=1;j<=n;j++) {
            if (v[j]>tr) break;
            c[j]=true;
            tr=v[j];
        }
    }
    if (v[v.size()-1]>v[v.size()-2]) {
        cnt++;
        c[v.size()-1]=true;
        long long tl=v[v.size()-1];
        for (int j=n-1;j>=0;j--) {
            if (v[j]>tl) break;
            c[j]=true;
            tl=v[j];
        }
    }
    for (int i=1;i<v.size()-1;i++) {
        if (c[i]==false) {
            if (v[i]>v[i-1]&&v[i]>v[i+1]) {
                cnt++;
                c[i]=true;
                long long tl=v[i];
                long long tr=v[i];
                for (int j=i-1;j>=1;j--) {
                    if (v[j]>tl) break;
                    c[j]=true;
                    tl=v[j];
                }
                for (int j=i+1;j<=n;j++) {
                    if (v[j]>tr) break;
                    c[j]=true;
                    tr=v[j];
                }
            }
        }
    }
    cout<<cnt;
}
