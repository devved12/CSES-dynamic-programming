#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
//int dp[5005][5005];
void solve(){
 int a,b;cin>>a>>b;
 vector<vector<ll>>dp(a+1,vector<ll>(b+1,INT_MAX));
for(int i=0;i<=a;i++){
  for(int j=0;j<=b;j++){
  if(i==j)dp[i][j]=0;
  else{
    for(int k=1;k<i;k++){
      dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
    }
    for(int k=1;k<j;k++){
      dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
    }
  }
  }
}
cout<<dp[a][b];
}
 
int main(){
solve();
}