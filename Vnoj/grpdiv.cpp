#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int k,n,a[12],sum,x,b[12];
pair<int,int>p[12];
bool dau[12];
void rec(int j){
    for(int i=1;i<=n;i++){
        if(!dau[i]){
            p[j].fi=a[i];
            p[j].se=i;
            dau[i]=true;
            if(j==n){
                int s=0,cnt=0;
                for(int q=1;q<=n;q++){
                    s+=p[q].fi;
                    if(s==x){
                        cnt++;
                        s=0;
                    }
                }
                if(cnt==k&&s==0){
                	int stt=1;
                    for(int q=1;q<=n;q++){
                        s+=p[q].fi;
                        b[p[q].se]=stt;
                        if(s==x){
                            stt++;
                            s=0;
                        }
                    }
                    for(int q=1;q<=n;q++){
                        cout<<b[q]<<' ';
                    }
                    exit(0);
                }
            } else rec(j+1);
            dau[i]=false;
        }
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%k!=0) cout<<"ze";
    else{
        x=sum/k;
        rec(1);
        cout<<"ze";
    }
}