## **A. 方差緊密度** ***<font color = '#AAAAAA'>Variance Tightness</font>***

`time limit` 2s
`memory limit` 256MB

### ***Statement***

給你一個包含 $N$ 個非負整數的序列 $A_1, \; A_2, \; \dots, \; A_N$。你需要將這個序列分成不超過 $K$ 個連續的子序列。

對於每個子序列 $[i, \; j]$，其「方差緊密度收益」定義為：

$$R(i, j) = \left(\sum\limits_{x=i}^{j} A_x \right)^2 - (j - i + 1) \sum\limits_{x=i}^j A_x^2$$

你的目標是最大化所有子序列的總方差緊密度收益。

### ***Input***

第一行包含兩個整數 $N, K$

第二行包含 $N$ 個非負整數 $A_1, A_2, \dots, A_N$

### ***Output***

一個整數，表示最大的總方差緊密度收益。

### ***Sample Input 1***

```
3 2
1 2 3
```

### ***Sample Output 1***

```
-1
```

<div class = 'page' />


### ***Sample Input 2***

```
4 2
5 5 5 5
```

### ***Sample Output 2***

```
0
```

### ***Sample Input 3***

```
5 1
10 20 30 40 50
```

### ***Sample Output 3***

```
-5000
```

### ***Note***

- $1 \leq K \leq N \leq 2000$
- $0 \leq A_i \leq 10^4$

### ***Subtask***

 - ***subtask1***: $7\\%$ $K \leq 2$
 - ***subtask2***: $13\\%$ $1 \leq K \leq N \leq 20$
 - ***subtask3***: $23\\%$ $1 \leq K \leq N \leq 500$
 - ***subtask4***: $57\\%$ ***As statement***