#include<bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int test=1000;
long long rand(long long l, long long h) {
    return l + rd() % (h - l + 1);
}
int main() {
    srand(time(NULL));
    for (int i=1;i<=test;i++) {
        ofstream inp("toy.inp");
        long long n=rand(1,10);
        inp<<n<<endl;
        for(int i=1;i<=n;i++) inp<<rand(1,100)<<' '<<rand(1,100)<<endl;
        inp.close();
        system("toy.exe");
        system("toy_trau.exe");
        if (system("toy.out toy.ans")!=0){
            cout<<"TEST "<<i<<" WRONG";
            break;
        }
        cout<<"TEST "<<i<<" CORRECT"<<'\n';
    }
}
