#include<bits/stdc++.h>
using namespace std;
int t;
int q;
int p,x;
bool flag;
map<int,int>mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    for (int i=1;i<=t;i++) {
        mp.clear();
        flag=false;
        cin>>q;
        while (q--) {
            cin>>p>>x;
            if (p==1)
                mp[x]++;
            else {
                if (mp[x]>=1) mp[x]--;
                else if (mp[0]>=1) mp[0]--;
                else flag=true;
            }
        }
        if (!flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
