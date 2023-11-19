#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int a[N+5];
struct Node{
    int lazy2,lazy3,lazy5,c2,c3,c5;
};
Node st[N*4];
void down(int id) {
    st[id*2].lazy2+=st[id].lazy2;
    st[id*2].lazy3+=st[id].lazy3;
    st[id*2].lazy5+=st[id].lazy5;
    st[id*2].c2+=st[id].lazy2;
    st[id*2].c3+=st[id].lazy3;
    st[id*2].c5+=st[id].lazy5;
    st[id*2+1].lazy2+=st[id].lazy2;
    st[id*2+1].lazy3+=st[id].lazy3;
    st[id*2+1].lazy5+=st[id].lazy5;
    st[id*2+1].c2+=st[id].lazy2;
    st[id*2+1].c3+=st[id].lazy3;
    st[id*2+1].c5+=st[id].lazy5;
    st[id].lazy2=0;
    st[id].lazy3=0;
    st[id].lazy5=0;
}
void update(int id,int l,int r,int u,int v,int val) {
    if (l>=u&&r<=v) {
        if (val==0) {
            st[id].lazy2-=st[id].c2;
            st[id].lazy3-=st[id].c3;
            st[id].lazy5-=st[id].c5;
            st[id].c2=0;
            st[id].c3=0;
            st[id].c5=0;
        } else if (val==2) {
            st[id].c2++;
            st[id].lazy2++;
        }
        else if (val==3) {
            st[id].c3++;
            st[id].lazy3++;
        }
        else {
            st[id].c5++;
            st[id].lazy5++;
        }
        return;
    }
    if (l>v||r<u) return;
    down(id);
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
}
Node get(int id,int l,int r,int i) {
    if (l>i||r<i) return {0,0,0};
    if (l==r&&l==i) return st[id];
    down(id);
    int mid=(l+r)/2;
    Node get1=get(id*2,l,mid,i);
    Node get2=get(id*2+1,mid+1,r,i);
    Node temp;
    temp.c2=get1.c2+get2.c2;
    temp.c3=get1.c3+get2.c3;
    temp.c5=get1.c5+get2.c5;
    return temp;
}
int main() {
    freopen("QUERY.INP","r",stdin);
    freopen("QUERY.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    while (m--) {
        int type;
        cin>>type;
        if (type==1) {
            int l,h,p;
            cin>>l>>h>>p;
            update(1,1,n,l,h,p);
        } else {
            int i,v;
            cin>>i>>v;
            update(1,1,n,i,i,0);
            a[i]=v;
        }
    }
    for (int i=1;i<=n;i++) {
        Node temp=get(1,1,n,i);
        while (temp.c2--) {
            if (a[i]%2==0) a[i]/=2;
            else break;
        }
        while (temp.c3--) {
            if (a[i]%3==0) a[i]/=3;
            else break;
        }
        while (temp.c5--) {
            if (a[i]%5==0) a[i]/=5;
            else break;
        }
        cout<<a[i]<<' ';
    }
}
