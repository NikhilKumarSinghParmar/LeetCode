class Solution {
public:
    vector<int> frequencyCalculator (vector<int> a) {
        unordered_map<int,int> freq;
        vector<int> ans;
        for (int i=0; i<a.size(); i++) {
            if (freq.count(a[i])) {
                freq[a[i]]++;
            }
            else freq.insert({a[i],1});
        }
        transform(freq.begin(), freq.end(), std::back_inserter(ans),
                   [](const auto& pair) { return pair.second; });
        return ans;
    }
    int minOperations(vector<int>& nums) {
        vector<int> freq;
        int count=0;
        freq=frequencyCalculator(nums);
        for (int i=0; i<freq.size();i++) {
            if (freq[i]==1) return -1;
            else if(freq[i]==2 || freq[i]==3) count++;
            else if(freq[i]%3==0) count+=freq[i]/3;
            else if(freq[i]>3) count+=(freq[i]/3)+1;
        }
        return count;
    }
};
