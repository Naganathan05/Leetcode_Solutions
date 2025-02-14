/*-----------------------
  Time Complexity: O(1)
  Space Complexity: O(n)
-------------------------*/

class ProductOfNumbers {
public:
    vector<pair<int, int>> prefixProduct;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(prefixProduct.size() == 0) prefixProduct.push_back({num, num == 0});
        else{
            pair<int, int> lastNum = prefixProduct.back();
            if(lastNum.first == 0) prefixProduct.push_back({num, (lastNum.second + (num == 0))}); 
            else prefixProduct.push_back({lastNum.first * num, (lastNum.second + (num == 0))}); 
        }
        return;
    }
    
    int getProduct(int k) {
        if(prefixProduct.size() == k) return prefixProduct.back().second ? 0 : prefixProduct.back().first;
        int ind = prefixProduct.size() - k - 1;
        int numZeroes = prefixProduct.back().second - prefixProduct[ind].second;
        if(numZeroes > 0) return 0;
        return prefixProduct[ind].first == 0 ? prefixProduct.back().first : prefixProduct.back().first / prefixProduct[ind].first;
    }
};

/*
Question Link: https://leetcode.com/problems/product-of-the-last-k-numbers/
Author: M.R.Naganathan
*/
