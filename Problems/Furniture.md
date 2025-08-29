## **I. 家俱製造商** ***<font color = '#AAAAAA'> Furniture </font>***

`time limit` 1s
`memory limit` 256MB

### ***Statement***

作為知名家俱製造商 － ***HARC*** － 的廠長， ***Willy*** 總是需要煩惱如何才能最有效率地處理源源不絕的訂單......

而製造家俱的步驟極其繁複，需要 **設計、宣傳、砍柴、脫樹皮、削平、打蠟、組裝** 等。

這些步驟看似繁複，但其實有些可以同時進行，像是 **設計** 和 **宣傳** 、 **宣傳** 和 **砍柴** 等等。

但像是 **砍柴** $\rightarrow$ **脫樹皮** $\rightarrow$ **削平** $\rightarrow$ **打蠟** $\rightarrow$ **組裝** 這類相依的步驟，則成為了困擾 ***Willy*** 多年的難題。

幸好 ***Willy*** 在處理源源不絕訂單的同時，也有源源不絕的人力。

現在有 $n$ 項工作，編號為 $[1, n]$ ，其中共有 $m$ 組相依關係，分別是 **在完成 工作 $b_j$ 後，才能進行 工作 $c_j$ ，其中 $1 \leq j \leq m$**。

而完成 **工作 $i$** 所需的時間為 $t_i,\ 1 \leq i \leq n$。

現在 ***Willy*** 需要請你幫忙找出 **開始每項工作可能的最早時間點** 。 請你好好寫程式幫助他吧 ouob

<!-- ![圖片](https://hackmd.io/_uploads/BJNlPPKtll.png) -->
<img src = 'https://hackmd.io/_uploads/BJNlPPKtll.png' height = 500px />

<div class = 'page' />


### ***Input***

$n$ $m$
$b_1$ $c_1$
$b_2$ $c_2$
...
$b_m$ $c_m$
$t_1$ $t_2$ ... $t_n$

### ***Output***

$Ans_1$ $Ans_2$ ... $Ans_n$

其中 $Ans_i,\ 1 \leq i \leq n$ 為 **開始工作 $i$ 可能的最早時間點** ，而所有工作都需要在時間點 $0$ 後執行

### ***Sample Input***

```
5 4
1 2
2 3
4 5
4 3
1 1 1 1 1
```

### ***Sample Output***

```
0 1 2 0 1
```

輸入中描述了 $1 \rightarrow 2 \rightarrow 3$ 、 $4 \rightarrow 5$ 的關係，而因為工作可以平行進行，於是讓 **工作 $1, 4$** 在 **時間點 $0$** 開始執行，而因為每項工作所需時間皆為 $1$ ，故答案為 `0 1 2 0 1` 。

<div class = 'page' />

### ***Note***

 - $0 \leq n \leq 2 \times 10 ^ 5$
 - $\displaystyle 0 \leq m \leq min\big(\sum_{k=1}^{n - 1} k, 10 ^ 6 \big)$
 - $1 \leq b_i, c_i \leq n,\ \forall\ 1 \leq i \leq m$
 - $0 \leq t_i \leq 10 ^ 9,\ \forall\ 1 \leq i \leq n$
 - 輸入保證合理，不會有工作不可能開始。

### ***Subtask***

 - ***subtask1***: $2\\%$ $n \leq 10,\ m \leq 10$
 - ***subtask2***: $7\\%$ $n \leq 100,\ m \leq 10^3$
 - ***subtask3***: $6\\%$ $t_i = 1,\ \forall 1 \leq i \leq n$
 - ***subtask4***: $15\\%$ $n \leq 10^3,\ m \leq 10^4$
 - ***subtask5***: $12\\%$ $m \leq 100$
 - ***subtask6***: $21\\%$ $m \leq (2 \times 10 ^ 5) - 1$
 - ***subtask7***: $37\\%$ ***As statement***