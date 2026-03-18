#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
long long p[maxn];
int h[maxn],w[maxn];
int main(){
    ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>h[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(h[i],w[i]);j++){
            long long count;
            count=(h[i]/j)*(w[i]/j);
            p[j]+=count;
        }
    }
    long long pre;
    for(int i=1;i<=maxn;i++){
        if(p[i]==0){
            continue;
        }
        if(p[i]>=m){
            pre=i;
        }
        if(p[i]<m){
            cout<<pre<<"  ";
            return 0;
        }
    }
    return 0;
}
//我这个代码思维是对的但是很容易超时