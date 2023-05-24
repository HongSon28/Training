#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
int type,i,j;
pair<int,int>p[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    p[1]=make_pair(0,0);
    while (m--) {
        cin>>type;
        if (type==1) { //left
            cin>>i>>j;
            p[i]=make_pair(p[j].first,j);
            int left=p[i].first;
            if (left!=0) p[left].second=i;
            p[j].first=i;
        } else if (type==2) { //right
            cin>>i>>j;
            p[i]=make_pair(j,p[j].second);
            int right=p[i].second;
            if (right!=0) p[right].first=i;
            p[j].second=i;
        } else if (type==3) { //leave
            cin>>i;
            int left=p[i].first,right=p[i].second;
            if (left!=0)
                p[left].second=right;
            if (right!=0)
                p[right].first=left;
        } else { //name
            cin>>i;
            cout<<p[i].first<<' '<<p[i].second<<endl;
        }
        //for (int k=1;k<=n;k++) cout<<p[k].first<<' '<<k<<' '<<p[k].second<<endl;
        //cout<<endl;
    }
}
