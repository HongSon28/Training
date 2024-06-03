#include<bits/stdc++.h>
#define int long long
using namespace std;
int q,t,x,a,y;
map<int,int>m;
set<int>s;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>q;
    while(q--){
        cin>>t;
        if(t==1){
            cin>>x>>a;
            m[x]+=a;
            s.insert(x);
        }else if(t==2){
            cin>>x>>a;
            if(a>m[x]) m[x]=0;
            else m[x]-=a;
            if(!m[x]) s.erase(x);
        }else if(t==3){
            auto it=s.begin();
            cout<<*it<<'\n';
        }
        else if(t==4){
            auto it=s.end();
            cout<<*(--it)<<'\n';
        }else{
            cin>>y;
            int res=y*m[y];
            auto z=s.upper_bound(y);
            auto t=s.lower_bound(y);
            if(z!=s.end()) res+=(*z)*m[(*z)];
            if(t!=s.begin()) {
            	t--;
            	res+=(*t)*m[(*t)];
            }
            cout<<res<<'\n';
        }
    }
}
//1 2 2 3 3 3 3