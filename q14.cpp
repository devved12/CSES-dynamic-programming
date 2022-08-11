#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
// same as knapsack 
void solve(){
 ll n;cin>>n;
 ll sum=n*(n+1)/2;
 if(sum&1){
     cout<<0;return;
 }
sum/=2;
vector<vector<ll>>dp(sum+1,vector<ll>(n+1,0));
dp[0][0]=1;
for(ll i=0;i<=sum;i++){
    for(ll j=1;j<=n;j++ ){
      if(i>=j){
          (dp[i][j]=dp[i][j-1]+dp[i-j][j-1])%=mod;;
      }
      else (dp[i][j]=dp[i][j-1])%=mod; 
    }
}
cout<<(dp[sum][n]*500000004)%mod;
}
int main(){
    solve();
}