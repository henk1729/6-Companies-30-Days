class Solution {
public:
    void validCombinations(vector<vector<int>>&combinations, vector<int>&combo, int iter, int selected, int k, int sum, int n){
        if(sum==n && selected==k){
            combinations.push_back(combo);
            return;
        }
        if(iter>9 || selected>k) return;

        //take
        combo.push_back(iter);
        validCombinations(combinations, combo, iter+1, selected+1, k, sum+iter, n);
        //not take
        combo.pop_back();
        validCombinations(combinations, combo, iter+1, selected, k, sum, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        if(n<(k*(k+1)/2) || n>(9*k-(k*(k-1)/2))) return combinations;

        vector<int> combo;
        validCombinations(combinations, combo, 1, 0, k, 0, n);
        return combinations;
    }
};
