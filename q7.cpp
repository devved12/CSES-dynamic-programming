#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
// same problem as 0-1 knapsack
int dp[1001][100001];
void solve(){
 int n,x;scanf("%d %d",&n,&x);
 int val[n],pg[n];
 for(int i=0;i<n;i++){
  cin>>val[i];
 }
  for(int i=0;i<n;i++){
  cin>>pg[i];
 }
 for(int i=1;i<=n;i++){
  for(int j=1;j<=x;j++){
    if(j>=val[i-1]){
      dp[i][j]=max(dp[i-1][j],dp[i-1][j-val[i-1]]+pg[i-1]);
    }
    else{
      dp[i][j]=dp[i-1][j];
    }
  }
 }
 cout<<dp[n][x];
}
 
int main(){
solve();
}