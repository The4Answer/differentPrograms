class Solution {
public:
    string srt (string s){
        sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> M;
        for (int i = 0; i < strs.size(); ++i)
            M[srt(strs[i])].push_back(strs[i]);
        
        vector<vector<string>> ans;
        for (auto i : M)
            ans.push_back(i.second);
        
        return ans;
    }
};
