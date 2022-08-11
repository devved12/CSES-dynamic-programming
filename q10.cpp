#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
//int dp[5005][5005];
void solve(){
 string s1,s2;cin>>s1>>s2;
 int n=s1.size(),m=s2.size();
  vector<vector<ll>>dp(n+1,vector<ll>(m+1,INT_MAX));
  for(int i=0;i<=n;i++){
    dp[i][0]=i;
  }
  for(int i=0;i<=m;i++){
    dp[0][i]=i;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(s1[i-1]==s2[j-1]){
      dp[i][j]=dp[i-1][j-1];
      }
      else{
        dp[i][j]=min({dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1});// three cases
                         // 1)when remove just increse ans+1 and recurisevly j-1 and i-1                                    
      }                   // 2)when delete just increase ans+1 and recursively i-1 and j->j
                          // 3)when insert same as 2 but i->i and j-1
    }
  }
  cout<<dp[n][m];
}
 
int main(){
solve();
}