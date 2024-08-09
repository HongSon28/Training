#include<bits/stdc++.h>
using namespace std;
#define ll long long
int s;
char c[6][11];
ll a[11][11][11][11][11];
ll dp1[11][11][11][11][11][11],dp2[11][11][11][11][11][11];;
ll h[6],hh[6],res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    for (int i=1;i<=5;i++)
        for (int j=1;j<=10;j++)
            cin>>c[i][j];
    for (h[1]=0;h[1]<=10;h[1]++) {
        for (h[2]=0;h[2]<=10;h[2]++) {
            for (h[3]=0;h[3]<=10;h[3]++) {
                for (h[4]=0;h[4]<=10;h[4]++) {
                    for (h[5]=0;h[5]<=10;h[5]++) {
                        for(int i=1;i<=5;i++) {
                            ll cur=0;
                            for (int j=1;j<=5;j++) {
                                if (h[j]>=h[i]) cur+=h[i];
                                else cur=0;
                                a[h[1]][h[2]][h[3]][h[4]][h[5]]=max(a[h[1]][h[2]][h[3]][h[4]][h[5]],cur);
                            }
                            a[h[1]][h[2]][h[3]][h[4]][h[5]]=max(a[h[1]][h[2]][h[3]][h[4]][h[5]],cur);
                        }
                    }
                }
            }
        }
    }
    dp1[0][0][0][0][0][0]=dp2[0][0][0][0][0][0]=1;
    for (int j=0;j<10;j++) {
        for (h[1]=0;h[1]<=j;h[1]++) {
            for (h[2]=0;h[2]<=j;h[2]++) {
                for (h[3]=0;h[3]<=j;h[3]++) {
                    for (h[4]=0;h[4]<=j;h[4]++) {
                        for (h[5]=0;h[5]<=j;h[5]++) {
                            for (int mask=0;mask<32;mask++) {
                                bool valid=true;
                                for (int bit=0;bit<5;bit++) {
                                    if ((mask>>bit)&1) {
                                        if (c[bit+1][j+1]=='1') {
                                            valid=false;
                                            break;
                                        }
                                        hh[bit+1]=h[bit+1]+1;
                                    } else hh[bit+1]=0;
                                }
                                if (valid) {
                                    if (a[hh[1]][hh[2]][hh[3]][hh[4]][hh[5]]<=s) dp1[j+1][hh[1]][hh[2]][hh[3]][hh[4]][hh[5]]+=dp1[j][h[1]][h[2]][h[3]][h[4]][h[5]];
                                    if (a[hh[1]][hh[2]][hh[3]][hh[4]][hh[5]]<=s-1) dp2[j+1][hh[1]][hh[2]][hh[3]][hh[4]][hh[5]]+=dp2[j][h[1]][h[2]][h[3]][h[4]][h[5]];
                                    //if (dp1[j][h[1]][h[2]][h[3]][h[4]][h[5]]>0) cout<<j<<' '<<h[1]<<' '<<h[2]<<' '<<h[3]<<' '<<h[4]<<' '<<h[5]<<' '<<hh[1]<<' '<<dp1[j][h[1]][h[2]][h[3]][h[4]][h[5]]<<endl;
                                    //if (j==8&&hh[1]==1) cout<<j<<' '<<h[1]<<' '<<h[2]<<' '<<h[3]<<' '<<h[4]<<' '<<h[5]<<' '<<hh[1]<<' '<<c[1][j+1]<<' '<<dp1[j][h[1]][h[2]][h[3]][h[4]][h[5]]<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (h[1]=0;h[1]<=10;h[1]++) {
        for (h[2]=0;h[2]<=10;h[2]++) {
            for (h[3]=0;h[3]<=10;h[3]++) {
                for (h[4]=0;h[4]<=10;h[4]++) {
                    for (h[5]=0;h[5]<=10;h[5]++) {
                        res+=dp1[10][h[1]][h[2]][h[3]][h[4]][h[5]]-dp2[10][h[1]][h[2]][h[3]][h[4]][h[5]];
                    }
                }
            }
        }
    }
    cout<<res;
}
