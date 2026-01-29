
// ĐỀ BÀI 
/*
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 

Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.
 

Constraints:

1 <= source.length == target.length <= 105
source, target consist of lowercase English letters.
1 <= cost.length == original.length == changed.length <= 2000
original[i], changed[i] are lowercase English letters.
1 <= cost[i] <= 106
original[i] != changed[i]
*/

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Nhận xét : nếu không chuyển được thì return -1;

        // Cách đầu tiên
        // Cách Dummy nhất là cày trâu 
        // nếu source[i] != source[i] thì duyệt qua từng phần tử  0->n xem có phần tử t nào mà original[t] = source[i]
        // và target[i] = change[i] hay không, nếu có thì sẽ cộng vào Cost lưu ý sẽ duyệt qua N phần tử để xem cost nào
        // thấp nhất.
        // độ phức tạp O(n * length)

        // OK, có một vấn đề về hiểu đề bài, không nhất thiết phải chuyển từ a->b trực tiếp, mà có thể chuyển từ a->c->b
        // sao cho cost là thấp nhất
        // Vậy ý tưởng tiếp theo là xây dựng một mảng 2d để tính toán cost thấp nhất từ a->b. Nhưng mà truy vết kiểu gì?
        // => sẽ phải update 29 lần với mỗi kỹ tự :VV

        // Đầu tiền cứ cập nhật a->b, b->c trước đã
        // tiếp theo sẽ xét từng cặp, nếu có b->c thì sẽ cập nhật a->c, b->c, c->c, d->c theo b bằng cách cập nhật giá
        // trị mới bằng a->b + b->c rồi lấy min;
        // rồi sau đó cost sẽ tính giựa theo bảng 2d đó transform[i][j];
    

        long long minCost = 0;
        int n = source.size(), length = original.size();
        vector<vector<int>> transforms(29, vector<int>(29, INT_MAX/2));

        for(int i = 0; i < length; i++){
            int z = (int)'a';
            transforms[original[i] - z][changed[i] - z] = min(transforms[original[i] - z][changed[i] - z], cost[i]);
        }

        // update minCost 
        for(int update = 0; update < transforms.size(); update++){
            for(int i = 0 ; i < transforms.size(); i++){
                for(int j = 0; j < transforms[i].size(); j++){
                    for(int k = 0; k < transforms.size(); k++){
                        transforms[i][j] = min(transforms[i][j], transforms[i][k] + transforms[k][j]);

                    }
                    
                }
            }

        }


        
        for(int i = 0 ; i < n; i++){
            if(source[i] == target[i])
                continue;
            
            int a = 'a';
            if(transforms[source[i] - a][target[i] - a] == INT_MAX/2)
            {
                cout << source[i] << "->" << target[i];
                return -1;
            }
            
            minCost += transforms[source[i] - a][target[i] - a];
        }

        return minCost;
        
    }
};