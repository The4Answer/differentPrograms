class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0;
        int ans = 0;
        int cur = 0;
        map <char, int> M;
        for (int i = 0; i < s.size(); ++i){
            while(M[s[i]] > 0){
                M[s[begin]]--;
                cur--;
                begin++;
            }
            cur++;
            M[s[i]]++;
            ans = max(ans, cur);
        }
        return ans;
    }
};
