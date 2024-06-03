#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m,k;
bool p[N+5][N+5];
vector<pair<int,int>>vc;
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>m>>n>>k;
    for (int i=1;i<=k;i++) {
    	int u,v;
    	cin>>u>>v;
    	p[u][v]=true;
    	vc.push_back({u,v});
    }
    for (long long i=1;i<=min(m,n)-1;i++) res+=(long long)(m-i)*(long long)(n-i)*i;	
    for (auto [u,v]:vc) {
    	for (int r=1;r<=min(n,m)-1;r++) {
    		for (int w=0;w<r;w++) {
    			int x1=u,y1=v-w,x2=x1+r,y2=y1+r;
    			if (x1>=1&&y1>=1&&x2<=m&&y2<=n) res--;
    		}
    	}
    }
    for (auto [u,v]:vc) {
    	for (int r=1;r<=min(n,m)-1;r++) {
    		for (int w=0;w<r;w++) {
    			int x1=u-w,x2=x1+r,y2=v,y1=y2-r;
    			int xa=x1,ya=y1+w;
    			if (x1>=1&&y1>=1&&x2<=m&&y2<=n&&!p[xa][ya]) res--;
    		}
    	}
    }
    for (auto [u,v]:vc) {
    	for (int r=1;r<=min(n,m)-1;r++) {
    		for (int w=0;w<r;w++) {
    			int x2=u,y2=v+w,x1=x2-r,y1=y2-r;
    			int xa=x1,ya=y1+w,xb=x1+w,yb=y2;
    			if (x1>=1&&y1>=1&&x2<=m&&y2<=n&&!p[xa][ya]&&!p[xb][yb]) res--;
    		}
    	}
    }
    for (auto [u,v]:vc) {
    	for (int r=1;r<=min(n,m)-1;r++) {
    		for (int w=0;w<r;w++) {
    			int x2=u+w,x1=x2-r,y1=v,y2=y1+r;
    			int xa=x1,ya=y1+w,xb=x1+w,yb=y2,xc=x2,yc=y2-w;
    			if (x1>=1&&y1>=1&&x2<=m&&y2<=n&&!p[xa][ya]&&!p[xb][yb]&&!p[xc][yc]) res--;
    		}
    	}
    }
    cout<<res;
}