#include<iostream>
#include<algorithm>
using namespace std;
struct Sum{
    int s,c,d;
    bool operator<(const Sum& t){
        if(s!=t.s) return s<t.s;
        if(c!=t.c) return c<t.c;
        return d<t.d; 
    }
};
const int maxn=5000001;
Sum sum[maxn];
int cnt=0;
int n; 
int main(){
    cin>>n;
    for(int c=0;c*c<=n;c++){
        for(int d=c;c*c+d*d<=n;d++){
            sum[cnt++]={c*c+d*d,c,d};
        }
    }
    sort(sum,sum+cnt);//要对这个数组进行二分处理，一定要先对这个数组进行排序
    for(int a=0;a*a<=n;a++){
        for(int b=a;b*b+a*a<=n;b++){
            int t=n-b*b-a*a;
            int l=0,r=cnt-1;
            while(l<r){
                int mid=l+(r-l)/2;
                if(sum[mid].s>=t) r=mid;//这块r不等于mid-1的原因是，mid可能会是最终的t，所以一定要进行保留，所以以后如果不是很确定的话，就看看这个边界点后面能否对最终的答案产生影响
                else l=mid+1; 
            }
            if(sum[l].s==t){
                cout<<a<<" "<<b<<" "<<sum[l].c<<" "<<sum[l].d<<" ";
                return 0;
            }
        }
    }
    return 0;
}