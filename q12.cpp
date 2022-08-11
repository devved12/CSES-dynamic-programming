#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
int dp[101][100005];
void solve(){
 int n;cin>>n;
 int arr[n];
 int maxy=INT_MIN;
 for(int i=0;i<n;i++){
  cin>>arr[i];
  maxy=max(arr[i],maxy);
 }
 for(int i=0;i<=n;i++){
  dp[i][0]=1;
 }
 int maxn=maxy*n;
 for(int i=1;i<=n;i++){
  for(int j=maxn;j>=1;j--){
     dp[i][j]=dp[i-1][j]; // tranverse from last to avoid cases of repeated addition of number
   if(j>=arr[i-1] && dp[i-1][j-arr[i-1]]){   // eg.... 2,6,5 ->when 4 is reached i we transverse from start also
      dp[i][j]=1;                                      // show true
   }
                  
  }
 }
 vector<int>ans;
 for(int i=1;i<=maxn;i++){
  if(dp[n][i]){
   ans.push_back(i);
  }
 }
 cout<<ans.size()<<"\n";
 for(auto x:ans){
  cout<<x<<" ";
 }
}
 
int main(){
solve();
}