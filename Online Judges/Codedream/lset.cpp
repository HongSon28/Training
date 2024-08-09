#include<bits/stdc++.h>
using namespace std;
int n,a[22];
vector<vector<int>>vt;
vector<int>temp;
void rec(int x){
    for(int i=a[x-1]+1;i<=n;i++){
        a[x]=i;
        temp.clear();
        for(int j=1;j<=x;j++) temp.push_back(a[j]);
        vt.push_back(temp);
        if(x<n) rec(x+1);
    }
}
int main(){
    cin>>n;
    rec(1);
    for(int i=0;i<(int)vt.size();i++){
        for(int j=0;j<(int)vt[i].size();j++) cout<<vt[i][j]<<' ';
        cout<<'\n';
    }
}