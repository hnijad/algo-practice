# Solutions

[Problem C](https://atcoder.jp/contests/abc211/tasks/abc211_c)

I have used dyanmic programming here. Let f(x) (x = {c, h, o, k, u, d, a, i} ) be the function that returns previos charachter for the given value in string s = "chokudai" and dp[s[i]] be "the number of strings that is equal to the first i charchter of s". Then there is the following recurrence. Note
that for the values of dp[i] where i is not in s we don't care since we don't need them.

    dp[i] = dp[i] + 1 (if i == 'c')
    dp[i] = dp[i] + dp[f(i)]

Then the answer is dp['i']

