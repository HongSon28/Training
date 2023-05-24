#include<bits/stdc++.h>
using namespace std;
vector<string>v;
stack<int>b;
int n;
int s[100005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int x=1;
    for(int i=1;i<=n;i++){
        while(x!=s[i]&&(b.empty()||b.top()!=s[i])){
            b.push(x);
            v.push_back("A->B");
            x++;
            if (x>n) break;
        }
        if(x==s[i]){
            v.push_back("A->C");
            x++;
        }
        else if(!b.empty() && b.top()==s[i]){
            v.push_back("B->C");
            b.pop();
        } else {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<'\n';
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<'\n';
   }
}
