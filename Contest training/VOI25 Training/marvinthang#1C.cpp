#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int t;
int a[7];
unsigned long long cnt1[N+5][2],cnt2[N+5][2],cnt3[N+5][2];
unsigned long long calc(int val,int i) {
	unsigned long long ans=0;
	for (int x=0;x<=1;x++) {
		for (int y=0;y<=1;y++) {
			for (int z=0;z<=1;z++){
				if (((x^y)^z)==val) {
					if (i==0) {
						ans+=cnt1[i][x]*cnt2[i][y]*cnt3[i][z];
					} else {
						unsigned long long c1=cnt1[i][x]-cnt1[i-1][x],c2=cnt2[i][y]-cnt2[i-1][y],c3=cnt3[i][z]-cnt3[i-1][z];
						ans+=c1*cnt2[i-1][y]*cnt3[i-1][z];
						ans+=cnt1[i-1][x]*c2*cnt3[i-1][z];
						ans+=cnt1[i-1][x]*cnt2[i-1][y]*c3;
						ans+=c1*c2*cnt3[i-1][z];
						ans+=c1*cnt2[i-1][y]*c3;
						ans+=cnt1[i-1][x]*c2*c3;
						ans+=c1*c2*c3;
					}
				}
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    for(int tt=1;tt<=t;tt++) {
    	unsigned long long res=0;
    	for (int i=1;i<=6;i++) cin>>a[i];
    	for (int i=0;i<=10;i++) {
    		memset(cnt1,0,sizeof(cnt1));
    		for (int x=0;x<=a[1];x++) {
    			for (int y=0;y<=a[4];y++) {
    				int t=(x^y);
    				cnt1[abs(x-y)][t>>i&1]++;
    			}
    		}
    		memset(cnt2,0,sizeof(cnt2));
    		for (int x=0;x<=a[2];x++) {
    			for (int y=0;y<=a[5];y++) {
    				int t=(x^y);
    				cnt2[abs(x-y)][t>>i&1]++;
    			}
    		}
    		memset(cnt3,0,sizeof(cnt3));
    		for (int x=0;x<=a[3];x++) {
    			for (int y=0;y<=a[6];y++) {
    				int t=(x^y);
    				cnt3[abs(x-y)][t>>i&1]++;
    			}
    		}
    		res+=calc(1,0)*(1ll<<i);
    		//cout<<i<<' '<<0<<' '<<1<<' '<<calc(1,0)<<endl;
    		//cout<<cnt1[0][0]<<' '<<cnt1[0][1]<<' '<<cnt2[0][0]<<' '<<cnt2[0][1]<<' '<<cnt3[0][0]<<' '<<cnt3[0][1]<<endl;
    		for (int j=1;j<=N;j++) {
    			cnt1[j][0]+=cnt1[j-1][0];
    			cnt1[j][1]+=cnt1[j-1][1];
    			cnt2[j][0]+=cnt2[j-1][0];
    			cnt2[j][1]+=cnt2[j-1][1];
    			cnt3[j][0]+=cnt3[j-1][0];
    			cnt3[j][1]+=cnt3[j-1][1];
    			if (j>>i&1) {
    				res+=calc(0,j)*(1ll<<i);
    				//cout<<i<<' '<<j<<' '<<0<<' '<<calc(0,j)<<endl;
    				//cout<<cnt1[j][0]<<' '<<cnt1[j][1]<<' '<<cnt2[j][0]<<' '<<cnt2[j][1]<<' '<<cnt3[j][0]<<' '<<cnt3[j][1]<<endl;
    			} else {
    				res+=calc(1,j)*(1ll<<i);
    				//cout<<i<<' '<<j<<' '<<1<<' '<<calc(1,j)<<endl;
    				//cout<<cnt1[j][0]<<' '<<cnt1[j][1]<<' '<<cnt2[j][0]<<' '<<cnt2[j][1]<<' '<<cnt3[j][0]<<' '<<cnt3[j][1]<<endl;
    			}
    		}
    	}
    	cout<<"Case #"<<tt<<": "<<res<<'\n';
    }
}