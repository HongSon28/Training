#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
string s;
int cur,id;
int a[N+5],c[N+5],nl[N+5],vl[N+5],nr[N+5],vr[N+5],pre[N+5],suf[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    for (auto x:s) {
    	if (x>='0'&&x<='9') cur=cur*10+x-'0';
    	else {
    		id++;
    		a[id]=cur;
    		if (x=='+') c[id]=0;
    		else c[id]=1;
    		cur=0;
    	} 
    }
    if (cur!=0) a[++id]=cur;
    for (int i=1;i<=id;i++) {
    	int pos=i-1,add=a[i];
    	while (c[pos]) {
    		add*=a[pos];
    		pos--;
    	}
    	nl[i]=pos;
    	vl[i]=add/a[i];
    	pre[i]=pre[pos]+add;
    }
    suf[id]=a[id];
    for (int i=id;i>=1;i--) {
    	int pos=i+1,add=a[i];
    	while (c[pos-1]) {
    		add*=a[pos];
    		pos++;
    	}
    	nr[i]=pos;
    	vr[i]=add/a[i];
    	suf[i]=suf[pos]+add;
    }
    int ans=pre[id];
    for (int i=1;i<=id;i++) {
    	int val=0,temp=a[i];
    	for (int j=i-1;j>=1;j--) {
    		if (c[j]) temp*=a[j];
    		else {
    			val+=temp;
    			temp=a[j];
    		}
    		int sum=val+temp;
    		ans=max(ans,pre[nl[j]]+suf[nr[i]]+sum*vl[j]*vr[i]);
    	}
    }
    cout<<ans;
}