#include<bits/stdc++.h>
using namespace std;
int a,b;
int main() {
    cin>>a>>b;
    for (int i=1;i<=a-b;i++) {
        for (int j=1;j<=a;j++) cout<<"* ";
        cout<<endl;
    }
    for (int i=1;i<=b;i++) {
        for (int j=1;j<=a-b;j++) cout<<"* ";
        cout<<endl;
    }
}
