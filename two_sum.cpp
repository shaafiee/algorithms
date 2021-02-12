class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {

                for (int j = 0; j < temp.size(); j++) {
                    if (nums[temp[j]] + nums[i] == target) {
                        result.push_back(temp[j]);
                        result.push_back(i);
                        return result;
                    }
                }
                temp.push_back(i);

        }
        return result;
    }
};
