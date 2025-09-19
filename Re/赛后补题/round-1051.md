---
date: 2025-09-19
---

# [Problem - C - Codeforces](https://codeforces.com/contest/2143/problem/C)




对于每条边 $(u, v, x, y)$，我们可以使其贡献等于 $max(x, y)$。 



**证明**： 

我们为每条边指定一个方向。如果 $x \leq y$，那么在新形成的图中这条边的方向为 $u \to v$，否则方向为 $v \to u$。 

很容易看出，这个图是一个 DAG（有向无环图）。 

现在，我们可以对这个 DAG 进行拓扑排序，得到一个顶点的顺序。

假设 $order_1, order_2, \dots, order_n$ 是排序后的结果。

如果我们令 $p_{order_i} = i$，那么所有条件都将得到满足。

为什么呢？ 假设我们有一条边 $x \to y$。我们知道 $x$ 在排序中出现在 $y$ 之前，因此 $p_x \lt p_y$，这正是我们想要的结果。