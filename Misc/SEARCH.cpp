#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int m,n,p,a[N+5],b[N+5],c[N+5],da[N+5],db[N+5],dc[N+5],res,l,r;
bool check(int l,int r) {
	bool ch=true;
	for (int i=l;i<=r;i++) dc[c[i]]++;
	for (int i=1;i<=m;i++) {
		if (!dc[a[i]]) {
			ch=false;
			break;
		}
	}
	for (int i=l;i<=r;i++) dc[i]--;
	return ch;
}
int main(){
    cin>>m>>n>>p;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        da[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        db[b[i]]++;
    }
    for(int i=1;i<=p;i++){
        cin>>c[i];
        if(db[c[i]]>0) c[i]=-1;
    }
    c[0]=-1;
    c[p+1]=-1;
    for(int i=1;i<=p;i++){
       	if (c[i]==-1) continue;
       	if (c[i-1]==-1) l=i;
       	if (c[i+1]==-1) {
       		r=i; 
    		if (check(l,r)) res=max(res,r-l+1);
    	}
    }
    cout<<res;
}