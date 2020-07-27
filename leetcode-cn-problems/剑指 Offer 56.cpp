class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        vector<int> bit; bit.resize(32);
        for (auto x : nums)
            for (int i = 0; i < 32; ++ i)
                if ((x >> i) & 1)
                    bit[i] ++;
        for (int i = 0; i < 32; ++ i)
            if (bit[i] % 3)
                ans |= (1 << i);
        return ans;
    }
};
