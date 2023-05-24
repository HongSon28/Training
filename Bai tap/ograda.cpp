#include<bits/stdc++.h>
using namespace std;
int n,res;
struct wood{
    int h,price,index;
};
bool cmp (wood a, wood b) {
    if (a.price==b.price)
        return a.h<b.h;
    return a.price>b.price;
}
set<pair<int,int>>dat;
vector<wood>ral;
int main() {
    cin>>n;
    int p[n+1]={};
    for (int i=1;i<=n;i++) {
        int t;
        cin>>t;
        dat.insert({t,i});
    }
    for (int i=1;i<=n;i++) {
        int t1,t2;
        cin>>t1>>t2;
        ral.push_back({t1,t2,i});
    }
    sort(ral.begin(),ral.end(),cmp);
    for (int i=0;i<n;i++) {
        int height=ral[i].h;
        auto it=dat.upper_bound({height,1e9});
        if (it==dat.begin()) {
            auto ed=dat.end();
            ed--;
            p[ral[i].index]=(*ed).second;
            dat.erase(ed);
        } else {
            it--;
            if ((*it).first<=height) {
                res+=ral[i].price;
                p[ral[i].index]=(*it).second;
                dat.erase(it);
            } else {
                auto ed=dat.end();
                ed--;
                p[ral[i].index]=(*ed).second;
                dat.erase(ed);
            }
        }
        //cout<<height<<' '<<ral[i].price<<' '<<ral[i].index<<' '<<(*it).first<<' '<<(*it).second<<' '<<res<<endl;
    }
    cout<<res<<endl;
    for (int i=1;i<=n;i++) cout<<p[i]<<' ';
}
