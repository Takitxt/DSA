

#include <unordered_map>
#include <string>
using namespace std;


// 3713. Longest Balanced Substring I
//Solution using brute force approach

//Run on leetcode cpp editor.

class Solution {
public:

bool check(unordered_map<int,int> &mp){
    if(mp.empty()) return true;
    int x = mp.begin()->second;
    for( auto m : mp){
        if(m.second != x){
            return false;
        }
    }
    return true;

}

    int longestBalanced(string s) {
        int n = s.length();
        int result = 0;

        for(int i =0;i<n;i++){

            unordered_map<int,int> mp;  

            for(int j =i;j<n;j++){

                mp[s[j] - 'a']++;

                if(check(mp)){
                    result = max(result,j - i + 1);
                }
            }
        }

        return result;

    }
};