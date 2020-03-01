//dfs，每个元素都有两种选择，选或者不选
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums, result, path, 0);
        return result;
    }
private:
    void dfs(vector<int> &nums, vector<vector<int>> &result, 
    vector<int> &path, int index) {
        if (index == nums.size()) {
            result.push_back(path);
            return;
        }
        //不选
        dfs(nums, result, path, index+1);
        //选
        path.push_back(nums[index]);
        dfs(nums, result, path, index+1);
        path.pop_back();
    }
};
