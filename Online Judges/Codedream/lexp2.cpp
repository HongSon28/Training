#include<bits/stdc++.h>
using namespace std;
stack<double>st;
int n,d[15];
double a[15],m,b[15],mx;
void dd(int k){
    for(int t=1;t<=4;t++){
        d[k]=t;
        if(k<n-1) dd(k+1);
        else{
            double res=0;
            st.push(a[1]);
            for(int i=1;i<n;i++){
                if(d[i]==1) st.push(a[i+1]);
                else if(d[i]==2) st.push(-a[i+1]);
                else if(d[i]==3){
                    double x=st.top();
                    st.pop();
                    double y=x*a[i+1];
                    st.push(y);
                }
                else{
                    double x=st.top();
                    st.pop();
                    double y=x/a[i+1];
                    st.push(y);
                }
            }
            while(!st.empty()){
                res+=st.top();
                st.pop();
            }
            if(res<=m) mx=max(res,mx);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dd(1);
    cout<<setprecision(3)<<fixed<<mx;
}