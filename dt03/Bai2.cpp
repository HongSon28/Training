#include<bits/stdc++.h>
using namespace std;
const long long nm=1000000;
vector<int>sont;
bool checknt(unsigned long long n) {
    for (unsigned long long i=2;i*i<n;i++) {
        if (n%i==0)
            return false;
    }
    return true;
}
unsigned long long ghepso(long a,long b) {
    unsigned long long kq=a;
    unsigned long long dem=0;
    unsigned long long temp=b;
    while (temp!=0) {
        temp/=10;
        dem++;
    }
    kq*=pow(10,dem);
    kq+=b;
    return kq;
}
void sang() {
    bool nt[nm];
    memset(nt,true,sizeof(nt));
    for (unsigned long long i=2;i<nm;i++) {
        if (nt[i]==true) {
            for (long long j=i*2;j<nm;j+=i) {
                nt[j]=false;
            }
        }
    }
    for (unsigned long long i=2;i<nm;i++) {
        if (nt[i]==true) {
            sont.push_back(i);
        }
    }
}
int main() {
    ifstream inp("ngtoghep.inp");
    ofstream out("ngtoghep.out");
    sang();
    int k;
    cin>>k;
    int res=0;
    for (unsigned long long i=0;i<sont.size();i+=2) {
        int temp=ghepso(sont[i],sont[i+1]);
        if (checknt(temp)==true) {
            res++;
            cout<<res<<" "<<temp<<endl;
            if (res==k) {
                cout<<temp;
                return 0;
            }
        }
    }
}

