#include<bits/stdc++.h>
using namespace std;
int n,v,cnt;
vector<vector<int>>res;
int a[21];
int p[21];
bool used[21];
void rec(int s, int k, int mn) {
    for (int i=mn;i<=n;i++) {
        if(!used[i]) {
            used[i]=true;
            p[k]=i;
            if (s-a[i]>0) rec(s-a[i],k+1,i+1);
            else if (s-a[i]==0) {
                cnt++;
                vector<int>temp;
                for (int j=1;j<=k;j++) {
                    temp.push_back(p[j]);
                }
                res.push_back(temp);
            }
            used[i]=false;
        }
    }
}
int main() {
    cin>>n>>v;
    for (int i=1;i<=n;i++) cin>>a[i];
    rec(v,1,1);
    if (cnt==0) cout<<-1;
    else {
        cout<<cnt<<endl;
        for (auto i:res) {
            for (auto j:i) {
                cout<<j<<' ';
            }
            cout<<endl;
        }
    }
}
