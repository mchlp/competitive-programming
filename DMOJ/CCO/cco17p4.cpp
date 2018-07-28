/*
 * Use tallest as left most
 * dp[i][maxV 50 * 500] = true/false
 * if dp[i-1][j] == true, dp[i][j] = true, dp[i][j + pre-cur] = true
 * loop through, adding pillars one by one
 *
 */