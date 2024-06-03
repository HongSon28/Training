#include<bits/stdc++.h>
using namespace std;
int q,x,y,a,b;
int main() {
	freopen("knight.inp","r",stdin);
	freopen("knight.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>q;
    while (q--) {	
    	cin>>a>>b>>x>>y;
    	x=abs(x-a),y=abs(y-b);
    	if ((x==1&&y==0)||(x==0&&y==1)) {
    		cout<<3<<' ';
    		continue;
    	}
    	if (x==2&&y==2)  {
    		cout<<4<<' ';
    		continue;
    	}
    	if (x==1&&y==1)  {
    		cout<<2<<' ';
    		continue;
    	}
    	int k=max({(x+1)/2,(y+1)/2,(x+y+2)/3});
    	int t1=(x+y)%2,t2=k%2;
    	if (t1!=t2) cout<<k+1<<' ';
    	else cout<<k<<' ';
    }
}