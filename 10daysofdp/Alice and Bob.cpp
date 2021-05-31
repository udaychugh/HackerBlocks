#include <bits/stdc++.h>
using namespace std;

long long int dp[1000000];

long long int dp_solution(long long int *a,long long int n,long long int m,map<long long int,long long int> M){
    
    dp[0]=0;
    for(long long int i=1;i<=m;i++){
        if(M.count(i)==0)
        dp[i]=dp[i-1];
        else {
        if(i>=2)
        dp[i]=max(dp[i-1],dp[i-2]+i*M[i]) ;  
        else
        dp[i]=(M.count(i))?M[i]*i:dp[i-1];
        }
    }
    return dp[m];
}

int main() {
    long long int n;
    cin>>n;
    long long int a[n];
    long long int m=INT_MIN;
    map<long long int,long long int> M;
    for(long long int i=0;i<n;i++){
        cin>>a[i];
        M[a[i]]++;
        m=max(m,a[i]);
    }
    
    fill(dp,dp+1000000,0);
    cout<<dp_solution(a,n,m,M)<<endl;
}
