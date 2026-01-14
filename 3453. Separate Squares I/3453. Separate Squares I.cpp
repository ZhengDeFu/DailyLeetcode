class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double y_min = 0;
        double y_max = squares[0][1];
        
        double are_below = 0;
        double are_above = 0;

        for(vector<int>& square:squares){
            y_max = max(y_max, (double)(square[1] + square[2]));
            are_above += (double)square[2]*square[2];
        }
        // are_below = are_above;

        double y_ave = (y_max/2 + y_min/2);
        while( abs(y_max-y_min) > 1e-5 ){
            y_ave = (y_max + y_min)/2;
            are_below = 0;

            for(auto& square:squares){
                if(square[1] < y_ave){
                    are_below += square[2] * min(y_ave  - square[1], (double)square[2]);  
                }

            }
            if(are_below < (double)are_above/2){
                y_min = y_ave;
            }
            else{
                y_max = y_ave;
            }
        }

        return y_ave;
    }
};