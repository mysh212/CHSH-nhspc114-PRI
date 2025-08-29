## **B. 伴手禮** ***<font color = '#AAAAAA'> Souvenir </font>***

`time limit` 1s
`memory limit` 256MB

### ***Statement***

***ysh*** 最近出國旅遊，不小心買了太多伴手禮準備給 ***Cyana*** ......

現在 ***ysh*** 非常後悔，他不知道自己買的伴手禮是否能通過機場的檢驗標準:

 - 將所有貨物堆疊起來
 - 一層只能放一個貨物
 - 在上層的貨物之長、寬必須分別小於所有下層貨物之長、寬

也就是 **長 $15$ 公分、寬 $20$ 公分** 的貨物，可以放在 **長 $30$ 公分、寬 $50$ 公分** 的貨物上，但卻無法放在 **長 $150$ 公分、寬 $20$ 公分** 或 **長 $6$ 公分、寬 $270$ 公分** 的貨物上。

而機場老闆相當固執，對於「長」、「寬」有著相當嚴格的要求，哪邊是長邊、哪邊是短邊通通由他說了算，也就是說－－我們不可以私自旋轉貨物。

因為在購買行李時， ***ysh*** 只買了 **一疊** ，請你告訴 ***ysh*** 他最多可以帶多少行李回家。

![可愛 Baggage 迷因](img/Baggage.jpg)

<div class = 'page' />

### ***Input***

$n$
$a_1$ $b_1$
$a_2$ $b_2$
...
$a_n$ $b_n$

### ***Output***

$Ans$

### ***Sample Input 1***

```
5
1 3
2 10
9 8
2 7
3 6
```

### ***Sample Output 1***

```
3
```

### ***Sample Input 2***

```
10
1 20
17 15
2 11
3 15
3 16
14 9
14 3
16 9
4 18
6 9
```

### ***Sample Output 2***

```
3
```

<div class = 'page' />

### ***Note***

 - $0 \leq n \leq 2 \times 10 ^ 5$
 - $1 \leq a_i, b_i \leq 10 ^ 9,\ \forall\ 1 \leq i \leq n$

### ***Subtask***

 - ***subtask1***: $1\\%$ $n \leq 10,\ [\big(|\\{x|x \in < a >\\}| \leq 1\big) \vee \big(|\\{x | x \in < b >\\}| \leq 1\big)]$
 - ***subtask2***: $7\\%$ $n \leq 10$
 - ***subtask3***: $13\\%$ $a_i, b_i \leq 100,\ \forall\ 1 \leq i \leq n$
 - ***subtask4***: $37\\%$ $n \leq 2000$
 - ***subtask5***: $42\\%$ ***As statement***