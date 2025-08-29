## **C. 希格瑪** ***<font color = '#AAAAAA'> Sigma </font>***

`time limit` 1s
`memory limit` 128MB

### ***Statement***
給定 $N$，試求：
$$\left(\sum_{K=1}^{N^2}{\lfloor \sqrt{K} \rfloor} \right) \pmod{10^9 + 7}$$

### ***Input***
$N$

### ***Output***
$Ans$


### ***Sample Input***
```
3
```

### ***Sample Output***
```
16
```
$\sum_{K=1}^{3^2}{\lfloor \sqrt{K} \rfloor} = \lfloor\sqrt{1}\rfloor + \lfloor\sqrt{2}\rfloor + \ldots + \lfloor\sqrt{9}\rfloor = 16$

### ***Note***
* $1 \leq N \leq 10^{18}$
* $10^9 + 7$ 是質數
* 所有輸入輸出皆為整數


### ***Subtask***
- ***subtask1***: $8\\%$ $N \leq 10^3$
- ***subtask2***: $23\\%$ $N \leq 10^6$
- ***subtask3***: $69\\%$ ***As statement***