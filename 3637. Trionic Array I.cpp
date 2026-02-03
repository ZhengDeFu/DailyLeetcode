#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        // nhận xét: nếu 0->i mà tăng mà nums[i+1] giảm thì khả năng là đấy là p còn nếu không thì not exist
        // tương tự với q 
        // khởi tạo p, q = 0 rồi duyệt qua mảng để tìm p và q

        int p = 0, q = 0;
        int n = nums.size();
        // kiểm tra điều kiện nums[1] > nums[0]
        if(nums[0] >= nums[1]) return false;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i -1]){
                p = i - 1;
                break;
            }
            if(nums[i] == nums[i -1]) return false;
        }
        if(p == 0 ) return false;

        // tìm q

        for(int i = p + 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                q = i -1;
                break;
            }
            if(nums[i] == nums[i -1]) return false;
        }

        if(q == 0) return false;
        
        for(int i = q + 1; i < n; i++){
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
};
