#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
//int dp[101][100005];
void solve(){
 int n;cin>>n;
 int arr[n];
 for(int i=0;i<n;i++){
   cin>>arr[i];
 }
vector<int>seq;
seq.push_back(arr[0]);
for(int i=1;i<n;i++){
   if(arr[i]>seq.back()){
      seq.push_back(arr[i]);
   }
   else{
      int id=lower_bound(seq.begin(),seq.end(),arr[i])-seq.begin();
      seq[id]=arr[i];
   }
}
cout<<seq.size();
}
int main(){
solve();
}