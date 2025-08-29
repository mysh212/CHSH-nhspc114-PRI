## **J. 香蕉衝突** ***<font color = '#AAAAAA'> Banana Wars </font>***

`time limit` 2s
`memory limit` 256MB

### ***Statement***
在神秘的亞馬遜雨林深處，存在著一座形狀特殊的凸多邊形區域，這裡是飛天猴族的領地。這些猴子居住在凸多邊形上，並且對一種傳說中的稀世珍寶「黃金香蕉」，懷有難以抗拒的執念。

當黃金香蕉出現在雨林中的任意位置時，所有猴子會瞬間從自己的據點出發，沿著直線飛行路線全速衝向目標，並在另一個據點停下。然而，這些飛行路線在空中交錯縱橫，形成一張隱形的危險網絡。每當兩條飛行路線相交時，猴群就會在交點爆發激烈的空中衝突，爭奪優先通過權，這種現象被當地土著稱為「香蕉衝突」。

作為雨林和平協會的首席觀測員，你的任務是計算這些飛行路線的交點數量，以評估是否需要派出訓練有素的「飛天倉鼠」來維持秩序。

現在，給定猴子的據點（位於凸多邊形邊或頂點上）與他們規劃的飛行路線（兩點間的直線段），請你計算總共有多少對路線在空中發生了相交，也就是香蕉衝突的次數。

<!-- ![Banana_duct_taped_to_fridge_as_a_reminder_to_eat_less_meat](https://hackmd.io/_uploads/Hk4EcGWvgg.jpg) -->

<img src = 'https://hackmd.io/_uploads/Hk4EcGWvgg.jpg' alt = 'Banana_duct_taped_to_fridge_as_a_reminder_to_eat_less_meat' height = 500px />

(圖源：喜劇演員 (藝術品) - wiki)

<div class = 'page' />

### ***Input***

$n$
$x_1\ y_1$
$x_2\ y_2$
$\vdots$
$x_n\ y_n$
$m$
$S_{x_1}\ S_{y_1}\ P_{x_1}\ P_{y_1}$
$S_{x_2}\ S_{y_2}\ P_{x_2}\ P_{y_2}$
$\vdots$
$S_{x_m}\ S_{y_m}\ P_{x_m}\ P_{y_m}$

第一行包含一個整數 $n$，代表猴子的據點數。

接下來的 $n$ 行，每行包含兩個整數 $x_i$ 和 $y_i$，表示猴子據點的座標。這些點依逆時針順序給出。

接下來的一行包含一個整數 $m$，表示猴子們的飛行路線數量。

接下來的 $m$ 行，每行包含四個整數 $S_{x_i}\ S_{y_i}\ P_{x_i}\ P_{y_i}$，表示一條隱形路線的兩個端點 $(S_{x_i}, S_{y_i})$ 跟 $(P_{x_i}, P_{y_i})$，端點必在據點上。

### ***Output***

$Ans$

輸出一行整數 $Ans$ 代表香蕉衝突的次數。

<div class = 'page' />


### ***Sample Input 1***
```
5
1 1
0 0
1 -1
2 -1
3 3
3
1 1 1 -1
2 -1 3 3
0 0 3 3
```

### ***Sample Output 1***
```
2
```

### ***Sample Input 2***
```
8
3 3
2 3
1 3
1 2
1 1
2 1
3 1
3 2
4
1 3 3 1
1 2 3 2
1 1 3 3
2 1 2 3
```

### ***Sample Output 2***
```
6
```

<div class = 'page' />


### ***Note***
* $3 \leq n \leq 10^5$
* $1 \leq m \leq min(\frac{n \times (n-1)}{2}, 10^5)$
* $-10^9 \leq x_i,\ y_i \leq -10^9$
* $(S_{x_i},\ S_{y_i}),\ (P_{x_i},\ P_{y_i}) \in \\{(x_i,\ y_i)\ |\ 1 \leq i \leq n\\}$
* 保證路線不重疊
* 交點位於據點的需列入計算 (參考範例一)
* 可能有多線共點，請分別計算每組線段 (參考範例二)
* 所有輸入輸出皆為整數


### ***Subtask***

- ***subtask1***: $1\\%$ $\ \ m = 1$
- ***subtask2***: $20\\%$ $m \leq 1000$
- ***subtask3***: $31\\%$ 所有頂點皆在兩平行的垂直線上，且線段兩端點必在不同垂直線
- ***subtask4***: $48\\%$ ***As statement***