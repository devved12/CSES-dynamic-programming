#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
// dp with bitmasking
void solve(){
 int n,x;cin>>n>>x;
 int arr[n];
 for(int i=0;i<n;i++){
   cin>>arr[i];
 }
 vector<pair<ll,ll>>dp(1<<n);
 dp[0]={1,0};// empty subset
 for(int i=1;i<(1<<n);i++){
   pair<ll,ll>best={INT_MAX,INT_MAX};
   for(int j=0;j<n;j++){
      if(i&(1<<j)){
          pair<ll,ll>res=dp[i^(1<<j)];
          if(res.second+arr[j]<=x){
            res.second+=arr[j];
          }
          else{
            res.first++;
            res.second=arr[j];
          }
          best=min(best,res);
        dp[i]=best;
      }
   }
 }
 cout<<dp[(1<<n)-1].first;
}
int main(){
solve();
}