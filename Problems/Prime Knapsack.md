## **E. 質數背包** ***<font color = '#AAAAAA'> Prime Knapsack </font>***

`time limit` 1s
`memory limit` 256MB

### ***Statement***

給定一個正整數 $N$，求能將其表示為質數和的最少質數個數。

若 $N$ 無法表示為任意質數的和，請輸出 "I got one million dollars."。

### ***Input***

$N$

### ***Output***

$Ans$

<div class = 'page' />

### ***Sample Input 1***

```
4
```

### ***Sample Output 1***

```
2
```

由於 2 + 2 = 4，所以最少只要 2 個質數。

### ***Sample Input 2***

```
3
```

### ***Sample Output 2***

```
1
```
由於 3 本身是質數，故只要一個就能湊出。

### ***Note***

* $2 \le N \le 10^{18}$


### ***Subtask***

- ***subtask1***: $90\\%$ $N \leq 1000$
- ***subtask2***: $9\\%$ $N \leq 10^{12}$
- ***subtask3***: $1\\%$ ***As statement***