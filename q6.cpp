#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
void solve(){
 int n;cin>>n;
 char arr[n][n];
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    cin>>arr[i][j];
  }
 }
 if(arr[0][0]=='*'){
  cout<<0;
  return;
 }
 int dp[n][n]={0};
  dp[0][0]=1;
  for(int i=1;i<n;i++){
   if(arr[i][0]=='.'){      // base case when there is no column
    dp[i][0]=dp[i-1][0];
   }
  }
 for(int i=1;i<n;i++){    // base case when there is no row
    if(arr[0][i]=='.'){
      dp[0][i]=dp[0][i-1];
    }
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      if(arr[i][j]=='.'){
      dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;}
    }
  }
  cout<<dp[n-1][n-1];
}
 
int main(){
solve();
}