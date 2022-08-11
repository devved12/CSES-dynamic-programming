#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
// case of restricted knapsack
void solve(){
 int n;cin>>n;
 vector<tuple<int,int,int>>p(n);
for(int i=0;i<n;i++){
   int x,y,z;cin>>x>>y>>z;
   p.push_back({y,x,z});
}
sort(p.begin(),p.end());// sort the project in terms of ending
map<ll,ll>dp;// stores max val at each project end
ll best=0;
dp[0]=0;
for(auto x:p){
   ll start,end,price;
   tie(end,start,price)=x;
  auto it=dp.lower_bound(start);// binary search to find perfect pos for this project
  it--;
  best=max(best,price+it->second);
  dp[end]=best;
}
cout<<best;
}
int main(){
solve();
}