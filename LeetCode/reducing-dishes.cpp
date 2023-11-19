class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int res=0,sum=0;
        sort(satisfaction.begin(),satisfaction.end(),greater<int>());
        for (auto i:satisfaction) {
            sum+=i;
            if (sum>=0) res+=sum;
            else break;
        }
        return res;
    }
};
