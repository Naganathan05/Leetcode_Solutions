/*----------------------------------
  Time Complexity: O(n(log(logn)))
  Space Complexity: O(n)
------------------------------------*/

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isPrime(n + 1, true);

        for(int i = 2; i * i <= n; i++){
            if(!isPrime[i]) continue;
            for(int j = i * i; j <= n; j += i) isPrime[j] = false;
        }

        vector<int> primeNumbers;
        for(int i = 2; i <= n; i++){
            if(isPrime[i]) primeNumbers.push_back(i);
        }

        int i = 0, j = primeNumbers.size() - 1;
        vector<vector<int>> primePairs;
        while(i <= j){
            if(primeNumbers[i] + primeNumbers[j] > n) j -= 1;
            else if(primeNumbers[i] + primeNumbers[j] < n) i += 1;
            else {
                primePairs.push_back({primeNumbers[i], primeNumbers[j]});
                i += 1;
                j -= 1;
            }
        }
        return primePairs;
    }
};

/*
Question Link: https://leetcode.com/problems/prime-pairs-with-target-sum/
Author: M.R.Naganathan
*/
