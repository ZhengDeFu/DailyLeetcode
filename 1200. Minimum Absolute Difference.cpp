#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int min_abs = arr[1] - arr[0];
        // find min_abs
        for(int i = 1; i < n ; i++){
            min_abs = min(min_abs, arr[i] - arr[i-1]);
        }

        // find ans vector

        for(int i = 1; i < n ;i++){
            if(min_abs == arr[i] - arr[i-1]){
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};