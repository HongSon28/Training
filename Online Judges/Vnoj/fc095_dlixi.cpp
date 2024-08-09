#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a>>b>>c;
    int fi=(a+c-1)/c*c;
    int se=(b/c*c);
    cout<<(se-fi)/c+1;	
}