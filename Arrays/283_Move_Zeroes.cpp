#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Two-Pointers: One-Pass

    void moveZeroes(vector<int>& nums) {
        int writePos = 0; 
        for (int readPos = 0; readPos < (int)nums.size(); readPos++) {
            if (nums[readPos] != 0) {
                if (readPos != writePos) {
                    int tmp = nums[readPos];
                    nums[readPos] = nums[writePos];
                    nums[writePos] = tmp;
                }
                writePos++;
            }
        }
    }

    // Two-Pointers: Two Pass

    void moveZeroes(vector<int>& nums) {
        int writePos = 0; // next position for a non-zero

        // Pass 1: compact non-zeros
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != 0) {
                nums[writePos++] = nums[i];
            }
        }

        // Pass 2: fill remaining with zeros
        while (writePos < (int)nums.size()) {
            nums[writePos++] = 0;
        }
    }

};

