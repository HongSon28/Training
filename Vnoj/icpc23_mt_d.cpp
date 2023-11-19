#include<bits/stdc++.h>
using namespace std;
int n,m,k,res=-1;
vector<vector<int>>v;
vector<int>cur;
char t;
int lo=0,hi=1e5;
bool check(int rad) {
    int cnt=0;
    for (auto vc:v) {
        int last=-1;
        for (auto temp:vc) {
            if (temp>last){
                cnt++;
                last=temp+2*rad;
            }
        }
    }
    return cnt<=k;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>t;
            if (t=='x') cur.push_back(j);
            else if (t=='#') {
                if (!cur.empty()) v.push_back(cur);
                cur.clear();
            }
        }
        if (!cur.empty()) v.push_back(cur);
        cur.clear();
    }
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    cout<<res;
}
