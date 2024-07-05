#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,a[2*N+5],p[N+5],mx[N+5],res[N+5];
bool check[N+5];
int findroot(int u){
    if(p[u]<0) return u;
    return p[u]=findroot(p[u]);
}
void Union(int x, int y){
    int u=findroot(x), v=findroot(y);
    if(u!=v){
        if(p[u]<p[v]) swap(u,v);
        p[u]+=p[v];
        mx[u]=mx[findroot(y)];
        p[v]=u;
        //cout<<x<<' '<<y<<' '<<u<<' '<<v<<' '<<mx[u]<<endl;
    }
}
int main(){
    cin>>n;
    fill(p,p+n+1,-1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx[i]=i;
    }
    for(int i=1;i<=n;i++){
        if (!check[a[i]]) {
        	res[i]=a[i];
        	check[a[i]]=true;
        	int u=a[i]-1,v=a[i]+1;
        	if (u==0) u=n;
        	if (v>n) v-=n;
        	//cout<<i<<' '<<u<<' '<<v<<endl;
        	if (check[u]) Union(u,a[i]);
        	if (check[v]) Union(a[i],v);
        } else {
        	int u=findroot(a[i]);
        	int v=mx[u]+1;
        	if (v>n) v-=n;
        	//cout<<i<<' '<<u<<' '<<mx[u]<<endl;
        	res[i]=v;
        	check[v]=true;
        	Union(u,v);
        	int k=v+1;
        	if (k>n) k-=n;
        	if (check[k]) Union(v,k);
        }
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<' ';
}