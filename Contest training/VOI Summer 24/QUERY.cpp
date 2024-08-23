#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q,m;
int a[N+5],b[N+5];
struct query{
	int type,l,r;
} qu[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=q;i++) cin>>qu[i].type>>qu[i].l>>qu[i].r;
    for (int i=1;i<=m;i++) cin>>b[i];
    for (int i=1;i<=m;i++) {
    	for (int j=q;j>=1;j--) {
    		if (b[i]<qu[j].l||b[i]>qu[j].r) continue;
    		if (qu[j].type==1) {
    			if (b[i]==qu[j].l) b[i]=qu[j].r;
    			else b[i]--;
    		} else {
    			int p=b[i]-qu[j].l;
    			b[i]=qu[j].r-p;
    		}
    	}
    	cout<<a[b[i]]<<' ';
    }
}