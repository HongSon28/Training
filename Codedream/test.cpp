#include<bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long lo,long long hi) {
    return lo+rd()%(hi-lo+1);
}
int main() {
    ofstream inp("STBRAC.INP");
    for (int i=1;i<=1000;i++) {
        long long n=rand(1,100),m=(1,1000);
        inp<<n<<' '<<m<<'\n';
        for (int j=1;j<=n;j++) {
            int t=rand(1,2);
            if (t==1) inp<<'(';
            else inp<<')';
        }
        inp<<endl;
        while (m--) {
            int t=rand(1,2);
            t--;
            inp<<t<<' ';
            if (t==0) {
                int pos=rand(1,n);
                inp<<pos<<' ';
                int c=rand(1,2);
                if (c==1) inp<<'(';
                else inp<<')';
            } else {
                int u=rand(1,n-1);
                int v=rand(u+1,n);
                inp<<u<<' '<<v;
            }
            inp<<endl;
        }
        inp.close();
        system("stbrac.exe");
        system("stbrac_brute.exe");
        if (system("fc STBRAC.OUT STBRAC.ANS")!=0) {
            cout<<"TEST "<<i<<" WRONG";
            return 0;
        }
        cout<<"TEST "<<i<<" CORRECT"<<endl;
    }
}
