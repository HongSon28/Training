#include<bits/stdc++.h>
using namespace std;
int n,a[55];
vector<vector<int>>vt;
vector<int>temp;
void rec(int x, int n){
    int m;
    for(int i=a[x-1];i<=n;i++){
        a[x]=i;
        m=n-a[x];
        //cout<<x<<' '<<a[x]<<' '<<m<<endl;
        if(m!=0) rec(x+1,m);
        else {
        	temp.clear();
        	for(int j=1;j<=x;j++) temp.push_back(a[j]);
        	vt.push_back(temp);
        }
    }
}
int main(){
	a[0]=1;
    cin>>n;
    rec(1,n);
    for(int i=0;i<(int)vt.size();i++){
        for(int j=0;j<(int)vt[i].size();j++) cout<<vt[i][j]<<' ';
        cout<<'\n';
    }
}