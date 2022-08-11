#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
int dp[100005][105];
void solve(){
 int n,m;cin>>n>>m;
 int arr[n];
 for(int i=0;i<n;i++){
   cin>>arr[i];
 }
if(arr[0]==0){              // when there is zero at initial pos then we can place any letter
  for(int i=1;i<=m;i++){    // from 1->m  
    dp[1][i]=1;
  }
}
else{
  dp[1][arr[0]]=1;
}
for(int i=2;i<=n;i++){
  for(int j=1;j<=m;j++){
    if(arr[i-1]==0){
     for(int k=j-1;k<=j+1;k++){
      dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
     }
    }
    else{
      if(arr[i-1]==j){
       for(int k=j-1;k<=j+1;k++){
      dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
     }
      }
    }
  }
}
ll ans=0;
for(int i=1;i<=m;i++){
 ans=(ans+dp[n][i])%mod;
}
cout<<ans;
}
 
int main(){
solve();
}