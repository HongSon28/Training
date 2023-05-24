#include<bits/stdc++.h>
using namespace std;
struct reward{
    long long w,v,c;
};
vector<reward>v0;
vector<reward>v1;
bool comp(reward a, reward b) {
    if (a.w==b.w) {
        return a.v<b.v;
    }
    return a.w<b.w;
}
int main() {
    long long res=0,weight=0;
    long long n,s;
    cin>>n>>s;
    vector<reward>v0;
    vector<reward>v1;
    for (int i=1;i<=n;i++) {
        reward temp;
        cin>>temp.w>>temp.v>>temp.c;
        if (temp.c==1) {
            res+=temp.v;
            weight+=temp.w;
            v1.push_back(temp);
        } else {
            v0.push_back(temp);
        }
    }
    sort(v0.begin(),v0.end(),comp);
    for (int i=0;i<v1.size();i++) {
        long long limit=s-weight+v1[i].w;
        cout<<limit<<endl;
        for (int j=0;j<v0.size();j++) {
            if (v0[j].w>limit) break;
            res=max(res,res-v1[i].v+v0[j].v);
        }
    }
    cout<<res;
}
