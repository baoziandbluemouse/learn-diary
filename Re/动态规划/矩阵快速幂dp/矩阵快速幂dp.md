---
date: 2025-05-13
tags:
  - 动态规划
---


# [3335. 字符串转换后的长度 I - 力扣（LeetCode）](https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/solutions/2967041/zhuang-tai-ji-dp-ju-zhen-kuai-su-mi-you-6rmqh/?envType=daily-question&envId=2025-05-13)

[3337. 字符串转换后的长度 II - 力扣（LeetCode）](https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/solutions/2967037/ju-zhen-kuai-su-mi-you-hua-dppythonjavac-cd2j/)



本题是一个动态规划题，我们先考虑dfs。

观察字符串，不难发现，每个字母是互不影响的，我们其实可以直接算出**每个字母在t次操作下最终会变成什么字母**。之后再遍历一遍给定的字符串来求解具体长度即可

就比如例题中，字母a在t次操作中变为c，b在t次操作中变为d。而特殊的字母就是z，他会在一次操作后分裂为a和b。

我们考虑dfs的话，定义一个dfs(i,j)代表操作到第i次时，字母j（我们用0-25来表示a-z）最后有多长。

那么0-24的字母都是dfs(i,j)=dfs(i-1,j+1),而**字母z是dfs(i,25)=dfs(i-1,0)+dfs(i-1,1)**。

并且dfs(0,j)=1

接下来使用dp，定义

f[i,0]=f[i-1,1],f[i,1]=f[i-1,2]

f[i,25]=f[i-1,1]+f[i-1,0]

这样的时间复杂度是$O(t \times 26)$


但是这样的做法只能过第一题，过不了第二题，第二题t的数据量是$10^9$,我们需要更快的做法，这里我们就要考虑用矩阵快速幂

由之前得出的递推式，我们可得


![[Pasted image 20250513204449.png]]


所以如此化简就能得到$F[i]=M \times F[i-1]$，而又有$F[i-1] = M \times F[i-2]$

矩阵的运算满足结合律，最终我们可以得到

$$F[i] = M^{i} \times F[0]$$

F[0]是一个全为1的列向量，即初始值,M的i次方可以用快速幂计算

另外，第二题给出了一个数组nums来初始化M矩阵，所以和第一题会有一些不一样



