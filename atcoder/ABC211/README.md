# Solutions

[Problem C](https://atcoder.jp/contests/abc211/tasks/abc211_c)

I have used dynamic programming here. Let **f(x)** (x = {c, h, o, k, u, d, a, i} ) be the function that returns previous charachter for the given value in string **s** = "chokudai" and **dp[s[i]]** be "the number of strings that is equal to the first i charchter of **s**". Then there is the following recurrence. Note
that for the values of **dp[i]** where **i** is not in **s** we don't care since we don't need them.

    dp[i] = dp[i] + 1 (if i == 'c')
    dp[i] = dp[i] + dp[f(i)]

Then the answer is **dp['i']**

[Problem D](https://atcoder.jp/contests/abc211/tasks/abc211_d)

Since weight of all the edges is 1, we can solve this problem using basic dynamic programming and BFS(Breadth First Search). Let **dp[i]** be "number of the shortest paths" from node **1** to node **i** and **level[i]** be "the level of the node **i** in bfs". For each **v** we iterate its **childs**. If we haven't visited it yet, we add it to the queue **q** and do following

    dp[child] += dp[v] 
    level[child] = level[v] + 1
    q.push(child)

If we have visited it, we still can go from this level to the next one. So if **level[child] == level[v] + 1**, then do following
   
    dp[child] += dp[v]

And the answer is **dp[n]**. Note that all the operations are done under module.

