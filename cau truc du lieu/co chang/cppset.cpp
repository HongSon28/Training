#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("demo.inp","r",stdin);
    int n;
    set<int>s1;
    while (true) {
        cin>>n;
        if (n==0) {
            break;
        } else if (n==1) {
            int t;
            cin>>t;
            s1.insert(t);
        } else if (n==2) {
            int t;
            cin>>t;
            s1.erase(t);
        } else if (n==3) {
            if(s1.empty()==true){
                cout<<"empty"<<endl;
            } else {
                cout<<*s1.begin()<<endl;
            }
        } else if (n==4) {
            if(s1.empty()==true){
                cout<<"empty"<<endl;
            } else {
                auto it=s1.rbegin();
                cout<<*it<<endl;
            }
        } else if (n==5) {
            int x;
            cin>>x;
            if (s1.empty()==true) {
                cout<<"empty"<<endl;
            } else {
                auto it=s1.upper_bound(x);
                if (it==s1.end()) {
                    cout<<"no"<<endl;
                } else {
                    cout<<*it<<endl;
                }
            }
        } else if (n==6) {
            int x;
            cin>>x;
            if (s1.empty()==true) {
                cout<<"empty"<<endl;
            } else {
                auto it=s1.lower_bound(x);
                if (it==s1.end()) {
                    cout<<"no"<<endl;
                } else {
                    cout<<*it<<endl;
                }
            }
        } else if (n==7) {
            int x;
            cin>>x;
            if (s1.empty()==true) {
                cout<<"empty"<<endl;
            } else {
                auto it=s1.lower_bound(x);
                if (it==s1.begin()) {
                    cout<<"no"<<endl;
                } else {
                    it--;
                    cout<<*it<<endl;
                }
            }
        } else {
            int x;
            cin>>x;
            if (s1.empty()==true) {
                cout<<"empty"<<endl;
            } else {
                auto it=s1.lower_bound(x);
                if (it==s1.begin()) {
                    cout<<"no"<<endl;
                } else if (*it==x) {
                    cout<<x<<endl;
                } else {
                    it--;
                    cout<<*it<<endl;
                }
            }
        }
    }
}
