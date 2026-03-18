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
#include<iostream>

using namespace std;
const int N=100010;

int H[N],W[N];
int n,k;
int main() {
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>H[i]>>W[i];

    int l=1,r=100000;
    while (l<r) {
        int mid=(l+r+1)/2;
        int cnt=0;
        for (int i=0;i<n;i++) {
            cnt+=(H[i]/mid)*(W[i]/mid);
        }
        if (cnt<k)r=mid-1;
        else l=mid;
    }
    cout<<l<<endl;
    return 0;
}
//下面我想说说关于二分的见解：
//1.就是关于l<=r和l<r的区别，前者需要有一个ans来时刻记录者答案，直接闭着眼睛写mid+1和mid-1，而后者则需要考虑保留mid还是剔除mid，且如果是l=mid，那么mid的计算必须写成(l+r+1)/2
//第一种的核心思维：核心思维： 每次遇到一个合法的 mid，我不管三七二十一，先把它存进一个小本本（变量 ans）里。既然我已经把它记下来了，这个 mid 的历史使命就结束了，接下来的搜索区间就可以大胆地把它踢出去。

//循环条件： while (l <= r)。意思是只要区间里还有哪怕 1 个数（l == r），我也要把它揪出来查一下。当 l > r（两个指针错开）时，搜索彻底结束。
//第二种的核心思维：核心思维： 我不弄小本本记答案，我要用左指针 l 和右指针 r 不断把正确答案挤在中间。最后当 l 和 r 撞到一起（l == r）的时候，它们指着的那唯一一个数，就是最终答案。

//循环条件： while (l < r)。当 l == r 时循环结束，此时直接输出 l 即可。
