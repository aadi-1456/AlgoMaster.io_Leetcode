#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Prefix - Sufix Pattern

    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n), suffix(n), result(n);

        prefix[0]=1;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];        
        }

        suffix[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            result[i]=prefix[i]*suffix[i];
        }
        return result;
    }

    // Optimized Approach with O(1) space

    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);

        int left=1;
        for(int i=0;i<n;i++){
            result[i]=left;
            left*=nums[i];
        }
        
        int right=1;
        for(int i=n-1;i>=0;i--){
            result[i]=right;
            right*=nums[i];
        }

        return result;
    }

};

