#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,s,q;
long long ff[N+5];
string str;
struct Segtree{
	long long st[N*4+5];
	void update(int id,int l,int r,int pos,long long val) {
		if (l>pos||r<pos) return;
		if (l==r) {
			st[id]+=val;
			return;
		}
		int mid=(l+r)/2;
		update(id*2,l,mid,pos,val);
		update(id*2+1,mid+1,r,pos,val);
		st[id]=st[id*2]+st[id*2+1];
	}
	long long get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return 0;
		if (u<=l&&r<=v) return st[id];
		int mid=(l+r)/2;
		return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
	}
} st;
struct query{
	long long type,i,c,l,r;
} qu[N+5];
vector<int>cprs;
long long pw[11];
int g(long long x) {
	if (x%s==0) return 2;
	while (x>0) {
		if (x%10==s) return 2;
		x/=10;
	}
	return 1;
}
pair<long long,long long> dp[11][2][11][2];
pair<long long,long long> f(int i,int less,int rem,int ok) {
	if (i==(int)str.size()) {
		if (ok||rem==0) return {0,1};
		return {0,0};
	}
	if (less&&dp[i][less][rem][ok]!=(pair<long long,long long>){-1,-1}) return dp[i][less][rem][ok];
	int lim;
	if (less) lim=9;
	else lim=str[i]-'0';
	pair<long long,long long>ans={0,0};
	for (int c=0;c<=lim;c++) {
		pair<long long,long long>temp=f(i+1,less|(c<str[i]-'0'),(rem*10+c)%s,ok|(c==s));
		ans.first+=pw[str.size()-i-1]*c*temp.second+temp.first;
		ans.second+=temp.second;
	}
	return dp[i][less][rem][ok]=ans;
}
long long calc(int x) {
	str=to_string(x);
	while (str.size()<10) str='0'+str;
	return f(0,0,0,0).first;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>s>>q;
    for (int i=1;i<=q;i++) {
    	cin>>qu[i].type;
    	if (qu[i].type==1) {
    		cin>>qu[i].i>>qu[i].c;
    		cprs.push_back(qu[i].i);
    	} else cin>>qu[i].l>>qu[i].r;
    }
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    for (int i=0;i<11;i++)
    	for (int j=0;j<2;j++)
    		for (int k=0;k<11;k++)
    			for (int l=0;l<2;l++)
    				dp[i][j][k][l]={-1,-1};
    for (int i=0;i<(int)cprs.size();i++) ff[i]=g(cprs[i]);
    pw[0]=1;
    for (int i=1;i<=10;i++) pw[i]=pw[i-1]*10;
    for (int i=1;i<=q;i++) {
    	if (qu[i].type==1) {
    		int pos=lower_bound(cprs.begin(),cprs.end(),qu[i].i)-cprs.begin()+1;
    		st.update(1,1,N,pos,ff[pos-1]*(qu[i].c-cprs[pos-1])-st.get(1,1,N,pos,pos));
    		//cout<<"upd: "<<pos<<' '<<ff[pos-1]*(qu[i].c-cprs[pos-1])-st.get(1,1,N,pos,pos)<<endl;
    	} else {
    		long long l=qu[i].l,r=qu[i].r;
    		long long res=(l+r)*(r-l+1)/2+calc(r)-calc(l-1);
    		//cout<<calc(l-1)<<' '<<calc(r)<<endl;
    		int t1=lower_bound(cprs.begin(),cprs.end(),l)-cprs.begin()+1;
    		int t2=upper_bound(cprs.begin(),cprs.end(),r)-cprs.begin();
    		//cout<<t1<<' '<<t2<<' '<<st.get(1,1,N,t1,t2)<<endl;
    		res+=st.get(1,1,N,t1,t2);
    		cout<<res<<'\n';
    	}
    }
}