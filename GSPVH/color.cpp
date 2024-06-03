#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n1,n2;
string col[7]={"","Yellow","Green","Blue","Purple","Red","Orange"};
int main() {
	freopen("color.inp","r",stdin);
	freopen("color.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s1>>s2;
    for (int i=1;i<=6;i++) {
    	if (s1==col[i]) n1=i;
    	if (s2==col[i]) n2=i;
    }
    if (n1>n2) swap(n1,n2);
    if (n1==n2) cout<<"Same";
    else if (n1+1==n2||(n1==1&&n2==6)) cout<<"Adjacent";
    else if (n1+3==n2) cout<<"Complementary";
    else {
    	if (n1==2&&n2==6) cout<<col[1];
    	else if (n1==1&&n2==5) cout<<col[6];
    	else cout<<col[n1+1];
    }
}