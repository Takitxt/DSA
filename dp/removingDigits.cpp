#include <iostream>
#include <vector>
#include <climits>


using namespace std;

int helper(int n, vector<int> &dp) {

    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    int ans = INT_MAX;

    for(int i = 1; i <= n; i *= 10) {
        int digit = (n / i) % 10;
        if(digit != 0) {
            ans = min(ans, helper(n - digit, dp));
        }
    }

    return dp[n] = ans + 1;

}

int removingDigits(int n) {

    vector<int> dp(n + 1, -1);
    return helper(n,dp);  

}


int main() {

    int n;

    cin >> n;

    cout << removingDigits(n) << endl;

    return 0;


    
}