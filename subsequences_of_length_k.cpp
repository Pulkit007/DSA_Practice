vector<vector<int>> ans;

void recur(vector<int> &nums, int k, int n, int idx, vector<int> &v)
{
    if ((int)v.size() == k)
    {
        ans.push_back(v);
        return;
    }

    if (idx == n)
        return;

    for (int i = idx; i < n; i++)
    {
        v.push_back(nums[i]);
        print(v);
        recur(nums, k, n, i + 1, v);
        v.pop_back();
    }
    return;
}