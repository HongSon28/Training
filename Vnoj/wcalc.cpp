#include<bits/stdc++.h>
using namespace std;
long long b,n,res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>b>>n;
    for (int m=1;m<=n*2;m++) {
    	 if(((b*(m-n)*(m-n))%(n*n)==0)&&(m!=n)) res++;    
    }
    cout<<res;
}