#include<bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long lo,long long hi) {
    return lo+rd()%(hi-lo+1);
}
int main() {
    ofstream inp("CSEQ.INP");
    for (int i=1;i<=100;i++) {
        long long n=rand(1,3e5);
        inp<<n<<endl;
        for (int j=1;j<=n;j++) inp<<rand(-1e9,1e9)<<' ';
        inp.close();
        system("cseq_nka.exe");
        system("CSEQ.exe");
        if (system("fc CSEQ.OUT cseq_nka.out")!=0) {
            cout<<"TEST "<<i<<" WRONG";
            return 0;
        }
        cout<<"TEST "<<i<<" CORRECT"<<endl;
    }
}
