# 奇怪的打印机
## 题解
dp[i][j] = dp[i][j-1] (s[i] == s[j])
dp[i][j] = min(dp[i][k]+dp[k+1][j]) (s[i] != s[j])
