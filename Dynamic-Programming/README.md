# Dynamic-Programming
![Image text](https://github.com/CQ-Quest/Dynamic-Programming/blob/master/12.png)

动态规划（Dynamic Programming，DP）是运筹学的一个分支，是求解决策过程最优化的过程。

动态规划算法的有效性依赖于待求解问题本身具有的两个重要性质：最优子结构性质和子问题重叠性质。

1 、最优子结构性质。如果问题的最优解所包含的子问题的解也是最优的，我们就称该问题具有最优子结构性质（即满足最优化原理）。最优子结构性质为动态规划算法解决问题提供了重要线索。

2 、子问题重叠性质。子问题重叠性质是指在用递归算法自顶向下对问题进行求解时，每次产生的子问题并不总是新问题，有些子问题会被重复计算多次。动态规划算法正是利用了这种子问题的重叠性质，对每一个子问题只计算一次，然后将其计算结果保存在一个表格中，当再次需要计算已经计算过的子问题时，只是在表格中简 单地查看一下结果，从而获得较高的解题效率。

当我们已经确定待解决的问题需要用动态规划算法求解时，通常可以按照以下步骤设计动态规划算法：

1 、分析问题的最优解，找出最优解的性质，并刻画其结构特征；

2 、递归地定义最优值；

3 、采用自底向上的方式计算问题的最优值；

4 、根据计算最优值时得到的信息，构造最优解。