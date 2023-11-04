
#include<iostream>
using namespace std;
// Top - down approach -> Recursion + memoization
int fibonacci(int n, vector<int>& dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    } // comments added
    dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
    return dp[n];
    //some new comments added
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1);
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }
    cout << fibonacci(n, dp);
    cout<<endl;
    return 0;
    
    // 2nd 
}
// Bottom - up approach -> Tabulation
/*
#include<bits/stdc++.h>
using namespace std;

int fib(int n){
        // dp array creation
        int dp[n+1];
        
        // base case
        dp[0]=0;
        dp[1]=1;
        
        // iteration
        for(int i=2; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
}

int main()
{
        int n;
        cin>>n;
        cout<<fib(n)<<endl;
}
*/

// Space optimization
/*
#include<bits/stdc++.h>
using namespace std;

int fib(int n){
       
        // base case
        if(n<=1)
            return n;
        int prev1=1;
        int prev2=0;
        // iteration
        for(int i=2; i<=n; i++){
               int curr = prev1 + prev2;
               prev2 = prev1;
               prev1 = curr; 
        }
        return prev1;
}

int main()
{
        int n;
        cin>>n;
        cout<<fib(n)<<endl;
}
*/
