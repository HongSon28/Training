#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int k;
int x;
bool vis[N+5];
int trace[N+5];
int main() {
    freopen("ONEZERO.INP","r",stdin);
    freopen("ONEZERO.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>k;
    while (k--) {
        memset(trace,0,sizeof(trace));
        memset(vis,false,sizeof(vis));
        cin>>x;
        if (x==1) {
            cout<<1<<'\n';
            continue;
        }
        queue<int>q;
        bool flag=false;
        q.push(1);
        vis[1]=true;
        trace[1]=-1;
        while (!q.empty()) {
            int p=q.front();
            q.pop();
            if (p==0) {
                string st;
                while (true) {
                    int temp=trace[p];
                    if (temp==-1) break;
                    if ((temp*10)%x==p) {
                        st+='0';
                        p=temp;
                    } else {
                        st+='1';
                        p=temp;
                    }
                }
                reverse(st.begin(),st.end());
                cout<<"1"<<st<<'\n';
                flag=true;
                break;
            }
            if (!vis[(p*10)%x]) {
                vis[(p*10)%x]=true;
                trace[(p*10)%x]=p;
                q.push((p*10)%x);
            }
            if (!vis[(p*10+1)%x]) {
                vis[(p*10+1)%x]=true;
                trace[(p*10+1)%x]=p;
                q.push((p*10+1)%x);
            }
        }
        if (!flag) cout<<"BRAK"<<'\n';
    }
}
