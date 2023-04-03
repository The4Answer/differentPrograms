class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, pair<int, int>> M;
        vector <int> ans;
        for (int i = 0; i < nums.size(); ++i){
            if (M[target - nums[i]].first > 0){
                ans.push_back(M[target - nums[i]].second);
                ans.push_back(i);
                break;
            }
            M[nums[i]].first = 1;
            M[nums[i]].second = i;
        }
        return ans;
    }
};
