#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
int n;
string s;
bool check(int  k){
    unordered_set<string> m;
    for(int i=0;i<=n-k;i++){//这一块的的等于号一定要加上
        string str=s.substr(i,k);//代表字符串s从i位置出发，长度为k的子串
        if(m.count(str)) return false;
        m.insert(str);
    }
    return true;
}
int main(){
    cin>>n;
    cin>>s;
    int ans;
    int l=1,r=n;//这一块儿l一定要等于1，因为我是二分答案法，所以这个人不能看到0个信箱，至少能看见一个，
    while(l<=r){
        int mid=l+(r-l)/2;//这块是一个防止溢出的小技巧
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
