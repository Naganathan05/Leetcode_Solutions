 // --------------------------------------
 //  Time Complexity: O(m.n(m + n))
//   Space Complexity: O(1)

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        for(int i = 0; i <= mat.size() - 1; i++){
            for(int j = 0; j <= mat[0].size() - 1; j++){
                bool status = true;
                if(mat[i][j] == 1){
                    for(int k = 0; k <= mat[0].size() - 1; k++){
                        if(mat[i][k] == 1 && k != j){
                            status = false;
                        }
                    }

                    for(int k = 0; k <= mat.size() - 1; k++){
                        if(mat[k][j] == 1 && k != i){
                            status = false;
                        }
                    }

                    if(status){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

// Question Link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/?envType=daily-question&envId=2023-12-13
