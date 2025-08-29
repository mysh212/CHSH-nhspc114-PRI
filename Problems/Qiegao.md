## **D. 切糕** ***<font color = '#AAAAAA'> Qiegao </font>***

`time limit` 1s
`memory limit` 256MB

### ***Statement***
隨著 LLM 的蓬勃發展，資深碼農 **MelonWalker** 輕易地被取代了。他決定轉型餐飲業，開始販售切糕。

他的切糕與傳統切糕不同，是一種長條形的蛋糕。由於每單位長使用的材料不同，其價格也各異。**MelonWalker** 是一位有良心的老闆，他的切糕價格是以「切下長度 $K$ 單位長，乘以該區間中位數」來計價。由於他的店家支援行動支付，所以價格可以是小數。

路過的 **hamster** 想買長度為 $K$ 的切糕，請問他至少需要支付多少錢？

具體來說，給定一個長度為 $N$ 的價格序列，你需要找到一個長度為 $K$ 的連續區間，使得該區間的中位數乘以 $K$ 的結果最小。

![videoframe_32669](https://hackmd.io/_uploads/rkNQK538eg.png)
(圖源：Youtube 呼吸菌QAQ - 小八買切糕)

### ***Input***
$N\ K$
$x_1\ x_2\ \ldots\ x_N$

輸入的第一行包含兩個整數 $N$ 和 $K$，分別代表總切糕長度與切割的長度。
第二行有 $N$ 個整數，代表該部分切糕的價格。

### ***Output***
$Ans$

輸出結果與答案誤差最大可到 $10^{-6}$

<div class = 'page' />

### ***Sample Input***
```
5 2
3 1 5 2 6
```
選擇區間 $[1, 2]$，其中位數為 $\frac{1 + 3}{2}=2$。因此，需要支付 $2 \times 2 = 4$。可以證明沒有更便宜的切法。

### ***Sample Output***
```
4.0000000000
```


### ***Note***
* $1 \leq K \leq N \leq 2\times10^5$
* $1 \leq x \leq 10^9$
* 所有輸入皆為整數

### ***Subtask***
- ***subtask1***: $3\\%$ $N = K$
- ***subtask2***: $17\\%$ $1 \leq N \leq 100$
- ***subtask3***: $40 \\%$ $K$ 是奇數
- ***subtask4***: $40 \\%$ ***As statement***