/*-----------------------------
  Time Complexity: O(n * logm)
  Space Complexity: O(1)
--------------------------------*/

int pow(int base, int power, int m) {
    long long ans = 1;
    for(int i = 1; i <= power; i++){
      ans *= base;
      if(ans > m) return -1;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
    long long low = 1, high = m;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        int powerValue = pow(mid, n, m);
        if (powerValue == 1) return mid;
        if (powerValue == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

/*
Question Link: https://www.naukri.com/code360/problems/nth-root-of-m_1062679
Author: M.R.Naganathan
*/
