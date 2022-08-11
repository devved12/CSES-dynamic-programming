#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
const int maxn=1000005;
const int minn=105;
//ll dp[minn][maxn];
void solve(){
int n,x;cin>>n>>x;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
vector<long long >dp(1000005,INT_MAX);
dp[0]=0;
for(int i=1;i<=x;i++){
    for(int j=0;j<n;j++){
       if(i>=arr[j]){
        dp[i]=min(dp[i],dp[i-arr[j]]+1);
       }
    }
}
if(dp[x]==INT_MAX){
    cout<<-1;
}
else{
    cout<<dp[x];
}
}
int main(){
solve();
}