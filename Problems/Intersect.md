## **G. 神秘交叉** ***<font color = '#AAAAAA'> Intersect </font>***

`time limit` 2s
`memory limit` 256MB

### ***Statement***

給定一個長度為 $n$ 的數列 $< a >$ ，試求 $\displaystyle\max(\big\\{f(l, r)\big|1 \leq l \leq r \leq n \wedge l, r \in \mathbb{N}\big\\})$, 其中 $f(l, r) \equiv a_l \oplus a_{l + 1} \oplus ... \oplus a_{r - 1} \oplus a_r$

![Cargo 迷因](img/Cargo.jpg)

<div class = 'page' />

### ***Input***

$n$
$a_1$ $a_2$ ... $a_n$

### ***Output***

$Ans$

### ***Sample Input 1***

```
3
4 1 9
```

### ***Sample Output 1***

```
12
```

### ***Sample Input 2***

```
7
412401279450576652 580784719358114359 357424042474072598 638120460316099882 402905540305957455 557218558427174880 762984001351336261
```

### ***Sample Output 2***

```
1009394896808872595
```

### ***Note***

 - $1 \leq n \leq 10 ^ 5$
 - $1 \leq a_i \leq 10 ^ {18},\ \forall\ 1 \leq i \leq n$

### ***Subtask***

 - ***subtask1***: $37\\%$ $n \leq 1000$
 - ***subtask2***: $63\\%$ ***As statement***