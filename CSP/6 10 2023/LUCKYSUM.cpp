#include<bits/stdc++.h>
using namespace std;
vector<unsigned long long>lucky;
unsigned long long l,r,res,last;
void rec(int k,unsigned long long val) {
    if (val!=0) lucky.push_back(val);
    if (k==9) return;
    rec(k+1,val*10+4);
    rec(k+1,val*10+7);
}
void prep() {
    lucky.push_back(4444444444);
    rec(0,0);
    sort(lucky.begin(),lucky.end());
}
int main() {
    freopen("LUCKYSUM.INP","r",stdin);
    freopen("LUCKYSUM.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    prep();
    cin>>l>>r;
    last=l;
    for (auto x:lucky) {
        if (x<l) continue;
        res+=x*(min(x,r)-last+1);
        last=x+1;
        if (x>=r) break;
    }
    cout<<res;
}
