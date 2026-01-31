#include<vector>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // trả về kỳ tự nhỏ nhất trong letters lớn hơn target thì duyệt qua từng phần tử, lấy phần tử đấy 
        // trừ đi target nếu lớn hơn 0 thì trả về, còn không thì return letters[0]

        for(auto& character:letters){
            if(character - target > 0)
                return character;
        }

        return letters[0];
    }
};