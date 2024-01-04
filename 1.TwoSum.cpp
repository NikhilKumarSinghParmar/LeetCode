class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        unordered_set<int> s;
        int n = nums.size();
        s.insert(nums[0]);
        int rem=0;
        for (int i=1; i<n; i++) {
            rem = target-nums[i];
            if (s.count(rem)) {
                ans.push_back(i);
                break;
            }
            else s.insert(nums[i]);
        }
        for (int i=0; i<n; i++) {
            if (nums[i]==rem) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }   
};
