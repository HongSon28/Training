#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int trace[N],x;
bool vis[N];
void bfs(){
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int n=q.front();
        q.pop();
        for(int i=0;i<=1;i++){
            if(i==0){
                int a=n*10;
                if(!vis[a%x]){
                    vis[a%x]=true;
                    trace[a%x]=n;
                    q.push(a%x);
                }
            }
            else{
                int a=n*10+1;
                if(!vis[a%x]){
                    vis[a%x]=true;
                    trace[a%x]=n;
                    q.push(a%x);
                }
            }
        }
    }
}
int main(){
    freopen("ONEZERO.INP","r",stdin);
    freopen("ONEZERO.OUT","w",stdout);
    int k; cin>>k;
    while(k--){
        memset(trace,0,sizeof(trace));
        memset(vis,false,sizeof(vis));
        cin>>x;
        if (x==1) {
            cout<<1<<'\n';
            continue;
        }
        bfs();
        vector<int>res;
        int u=0;
        if(trace[0]==0) cout<<"BRAK"<<'\n';
        else{
            trace[1]=-1;
            while(u!=-1){
                if(trace[u]==-1) break;
                if(trace[u]*10%x==u) res.push_back(0);
                else res.push_back(1);
                u=trace[u];
            }
            cout<<1;
            for(int i=res.size()-1;i>=0;i--){
                cout<<res[i];
            }
            cout<<'\n';
        }
    }
}
