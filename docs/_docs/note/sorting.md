---
title: "알고리즘: 정렬 1"
order: 110
category: 노트
layout: note

diff: 26

written: "2021-02-20 22:54"
edited: 
---

<style>
.red {
    color: red;
}

.blue {
    color: blue;
}

.green {
    color: green;
}

@media (prefers-color-scheme: dark) {
    .red {
        color: #ff8080;
    }

    .blue {
        color: #8080ff;
    }

    .green {
        color: #80ff80;
    }
}
</style>

이것의 전 포스트인 브루트 포스는 문제 해결의 하나의 방법론으로써 제시한 것이기 때문에 구체적으로 무엇을 어떻게 해야 하는지에 대해서는 다루지 않았습니다. 하지만 여기부터는 구체적으로 다룰 예정입니다! ~~정작 작성자가 구체적인 설명을 못합니다~~

### 정렬

좁은 의미로는 수를 크기 순서대로, 넓은 의미로는 자료를 정해진 조건에 따라 순서대로 배열하는 것입니다.[^1] '정렬'이라는 것이 기초적인 알고리즘이면서 중간 과정에 대한 설명이 없고 입력과 출력만 제시한 연산이기 때문에 이를 구현한 방법이 매우 다양합니다. 그 중에서 복잡한 자료 구조를 사용하거나 그 구현 방식 자체가 복잡하여 이해에 시간이 걸리는 것들은 조금 나중에 다루어보도록 하고 여기서는 간단한, 직관적인 정렬 알고리즘 위주로 작성할 예정입니다.

먼저 결론부터 말하자면 시간 복잡도가 $O(n^2)$인 정렬 세 가지(버블 정렬, 삽입 정렬, 선택 정렬)에 대해 다룹니다. 여기서는 각 정렬 방법마다 어떻게 작동하는지 보고, 시간 복잡도는 조금 나중에 다루겠습니다!

#### 버블 정렬 (Bubble Sort)

버블 정렬의 알고리즘을 글로 설명하자면 아래와 같습니다.

- 수열이 모두 정렬될 때까지
  - 수열의 각 원소에 대해
    - 현재 원소와 다음 원소가 순서에 맞지 않으면
      - 두 원소의 위치를 바꿈

의사 코드로 나타내면 주석의 내용과 같습니다.[^2] 실제로 구현에는 아래의 것을 많이 사용합니다. 아래의 것은 일정하게 적당한 성능을 내기 위해 조금 개량된 버전입니다.[^3]

```python
n = len(A)
for i in range(n - 1, 0, -1): # (n-1), (n-2), (n-3), ... , 1
    for j in range(0, i): # 0, 1, 2, ... , (i-1)
        if A[j] > A[j + 1]:
            swap(A[j], A[j + 1])
```

간단하게 원소 6개짜리 예시를 들어보겠습니다. `2 5 3 6 4 1`의 배열을 가지고 해보겠습니다.

<pre>
i / j:  5 / 0
Array:  2 5 3 6 4 1
Compare ^ ^

i / j:  5 / 1
Array:  2 5 3 6 4 1
Compare   ^ ^         --> Swap

i / j:  5 / 2
Array:  2 <b class="red">3 5</b> 6 4 1
Compare     ^ ^

i / j:  5 / 3
Array:  2 3 5 6 4 1
Compare       ^ ^     --> Swap

i / j:  5 / 4
Array:  2 3 5 <b class="red">4 6</b> 1
Compare         ^ ^   --> Swap

i / j:  5 / <b class="blue">5</b>         --> Next
Array:  2 3 5 4 <b class="red">1 6</b>
</pre>

결과를 보면 가장 큰 원소가 오른쪽 끝에 위치하게 되었습니다. 그러면 가장 오른쪽의 원소를 더 이상 건드릴 필요가 없으므로 `i`의 값을 1만큼 빼도 될 것 같습니다. 같은 동작을 반복할 때마다 오른쪽에 정렬된 부분이 1씩 늘어나므로 그만큼 탐색할 길이를 줄여도 되겠습니다. 그래서 매 반복마다 `i`를 1씩 빼주는 것입니다.

<p><details>
<summary><b>전 과정 보기</b></summary>
<pre>
i / j:  4 / 0
Array:  2 3 5 4 1 <b class="blue">6</b>
Compare ^ ^

i / j:  4 / 1
Array:  2 3 5 4 1 <b class="blue">6</b>
Compare   ^ ^

i / j:  4 / 2
Array:  2 3 5 4 1 <b class="blue">6</b>
Compare     ^ ^       --> Swap

i / j:  4 / 3
Array:  2 3 <b class="red">4 5</b> 1 <b class="blue">6</b>
Compare       ^ ^     --> Swap

i / j:  4 / <b class="blue">4</b>         --> Next
Array:  2 3 4 <b class="red">1 5</b> <b class="blue">6</b>
</pre>

<pre>
i / j:  3 / 0
Array:  2 3 4 1 <b class="blue">5 6</b>
Compare ^ ^

i / j:  3 / 1
Array:  2 3 4 1 <b class="blue">5 6</b>
Compare   ^ ^

i / j:  3 / 2
Array:  2 3 4 1 <b class="blue">5 6</b>
Compare     ^ ^       --> Swap

i / j:  3 / <b class="blue">3</b>         --> Next
Array:  2 3 <b class="red">1 4</b> <b class="blue">5 6</b>
</pre>

<pre>
i / j:  2 / 0
Array:  2 3 1 <b class="blue">4 5 6</b>
Compare ^ ^

i / j:  2 / 1
Array:  2 3 1 <b class="blue">4 5 6</b>
Compare   ^ ^         --> Swap

i / j:  2 / <b class="blue">2</b>         --> Next
Array:  2 <b class="red">1 3</b> <b class="blue">4 5 6</b>
</pre>

<pre>
i / j:  1 / 0
Array:  2 1 <b class="blue">3 4 5 6</b>
Compare ^ ^           --> Swap

i / j:  1 / <b class="blue">1</b>         --> Next
Array:  <b class="red">1 2</b> <b class="blue">3 4 5 6</b>
</pre>

<pre>
Array:  <b class="blue">1 2 3 4 5 6</b>
</pre>

이로써 수열이 모두 정렬되었습니다.
</details></p>

#### 삽입 정렬 (Insertion Sort)

삽입 정렬의 알고리즘을 글로 나타내면 아래와 같습니다.

- 수열이 모두 정렬될 때까지
  - 정렬되지 않은 부분의 가장 왼쪽 원소를 선택
  - 이 원소가 정렬된 부분의 알맞은 위치에 들어갈 때까지 왼쪽 원소와 swap

이를 의사 코드로 나타내면 아래와 같습니다.[^4]

```python
n = len(A)
for i in range(1, n):
    j = i
    while j > 0 and A[j - 1] > A[j]:
        swap(A[j], A[j - 1])
        j -= 1
```

버블 정렬과 같은 예시인 `2 5 3 6 4 1`를 가지고 정렬을 진행해보겠습니다.

<pre>
i / j:  1 / 1
Array:  <b class="blue">2</b> 5 3 6 4 1
Compare ^ ^           --> Next
</pre>

<pre>
i / j:  2 / 2
Array:  <b class="blue">2 5</b> 3 6 4 1
Compare   ^ ^         --> Swap

i / j:  2 / 1
Array:  <b class="blue">2</b> <b class="red">3 5</b> 6 4 1
Compare ^ ^           --> Next
</pre>

<pre>
i / j:  3 / 3
Array:  <b class="blue">2 3 5</b> 6 4 1
Compare     ^ ^       --> Next
</pre>

`i`의 값이 커질 때마다 수열의 왼쪽부터 일정 길이만큼 정렬된 상태를 유지하는 것이 보입니다. 정확히는 왼쪽의 `i`개의 원소만 정렬한 결과가 남는 것입니다. 의사 코드에 따르면 `i`의 값이 늘어나므로 정렬된 부분의 길이가 점점 길어져 결국 수열 전체가 정렬될 것입니다.

<p><details>
<summary><b>전 과정 보기</b></summary>
<pre>
i / j:  4 / 4
Array:  <b class="blue">2 3 5 6</b> 4 1
Compare       ^ ^     --> Swap

i / j:  4 / 3
Array:  <b class="blue">2 3 5</b> <b class="red">4 6</b> 1
Compare     ^ ^       --> Swap

i / j:  4 / 2
Array:  <b class="blue">2 3</b> <b class="red">4 5</b> <b class="blue">6</b> 1
Compare   ^ ^         --> Next
</pre>

<pre>
i / j:  5 / 5
Array:  <b class="blue">2 3 4 5 6</b> 1
Compare         ^ ^   --> Swap

i / j:  5 / 4
Array:  <b class="blue">2 3 4 5</b> <b class="red">1 6</b>
Compare       ^ ^     --> Swap

i / j:  5 / 3
Array:  <b class="blue">2 3 4</b> <b class="red">1 5</b> <b class="blue">6</b>
Compare     ^ ^       --> Swap

i / j:  5 / 2
Array:  <b class="blue">2 3</b> <b class="red">1 4</b> <b class="blue">5 6</b>
Compare   ^ ^         --> Swap

i / j:  5 / 1
Array:  <b class="blue">2</b> <b class="red">1 3</b> <b class="blue">4 5 6</b>
Compare ^ ^           --> Swap

i / j:  5 / <b class="blue">0</b>         --> Next
Array:  <b class="red">1 2</b> <b class="blue">3 4 5 6</b>
</pre>

<pre>
Array:  <b class="blue">1 2 3 4 5 6</b>
</pre>

이로써 수열이 모두 정렬되었습니다.
</details></p>

#### 선택 정렬 (Selection Sort)

선택 정렬의 알고리즘을 글로 나타내면 아래와 같습니다.

- 수열이 모두 정렬될 때까지
  - 수열의 정렬되지 않은 부분을 순회하면서
    - 가장 작은 원소를 탐색
  - 탐색한 원소를 정렬된 부분의 바로 오른쪽 원소와 swap

의사 코드로 나타내면 아래와 같습니다.

```python
n = len(A)
for i in range(n - 1):
    x = i
    for j in range(i + 1, n):
        if A[x] > A[j]:
            x = j
    if j != i:
        swap(A[i], A[x])
```

마찬가지로 `2 5 3 6 4 1`을 가지고 정렬해보겠습니다.

<pre>
i / j:  0 / 1
Array:  <b class="green">2</b> 5 3 6 4 1
Compare ^ ^

i / j:  0 / 2
Array:  <b class="green">2</b> 5 3 6 4 1
Compare ^   ^

i / j:  0 / 3
Array:  <b class="green">2</b> 5 3 6 4 1
Compare ^     ^

i / j:  0 / 4
Array:  <b class="green">2</b> 5 3 6 4 1
Compare ^       ^

i / j:  0 / 5
Array:  2 5 3 6 4 <b class="green">1</b>
Compare ^         ^

Swap -->
Array:  <b class="red">1</b> 5 3 6 4 <b class="red">2</b>
</pre>

`i`가 0일 때를 보니, 가장 작은 원소인 1이 가장 앞으로 이동했습니다. 다음 연산 때에는 정렬되지 않은 부분의 가장 작은 원소, 즉, 전체 수열에서는 두 번째로 작은 원소가 선택되어 인덱스 1의 위치의 원소와 swap이 될 것입니다. 이를 계속 반복하다보면 수열의 모든 부분이 정렬이 완료됩니다.

<p><details>
<summary><b>전 과정 보기</b></summary>
<pre>
i / j:  1 / 2
Array:  <b class="blue">1</b> 5 <b class="green">3</b> 6 4 2
Compare   ^ ^

i / j:  1 / 3
Array:  <b class="blue">1</b> 5 <b class="green">3</b> 6 4 2
Compare     ^ ^

i / j:  1 / 4
Array:  <b class="blue">1</b> 5 <b class="green">3</b> 6 4 2
Compare     ^   ^

i / j:  1 / 5
Array:  <b class="blue">1</b> 5 3 6 4 <b class="green">2</b>
Compare     ^     ^

Swap -->
Array:  <b class="blue">1</b> <b class="red">2</b> 3 6 4 <b class="red">5</b>
</pre>

<pre>
i / j:  2 / 3
Array:  <b class="blue">1 2</b> <b class="green">3</b> 6 4 5
Compare     ^ ^

i / j:  2 / 4
Array:  <b class="blue">1 2</b> <b class="green">3</b> 6 4 5
Compare     ^   ^

i / j:  2 / 5
Array:  <b class="blue">1 2</b> <b class="green">3</b> 6 4 5
Compare     ^     ^

Swap -->
Array:  <b class="blue">1 2 3</b> 6 4 5
</pre>

<pre>
i / j:  3 / 4
Array:  <b class="blue">1 2 3</b> 6 <b class="green">4</b> 5
Compare       ^ ^

i / j:  3 / 5
Array:  <b class="blue">1 2 3</b> 6 <b class="green">4</b> 5
Compare         ^ ^

Swap -->
Array:  <b class="blue">1 2 3</b> <b class="red">4 6</b> 5
</pre>

<pre>
i / j:  4 / 5
Array:  <b class="blue">1 2 3 4</b> 6 <b class="green">5</b>
Compare         ^ ^

Swap -->
Array:  <b class="blue">1 2 3 4</b> <b class="red">5 6</b>
</pre>

<pre>
Array:  <b class="blue">1 2 3 4 5 6</b>
</pre>

이로써 수열이 모두 정렬되었습니다.
</details></p>

<hr/>

[^1]: 물리적인 데이터 공간에서 연속적이게 존재할 필요는 없고 논리적으로만 순서대로 나열하면 됩니다. 배열의 경우는 연속적인 메모리를 할당받은 상태고, 배열 상에서 정렬을 진행하면 물리적으로도 순서대로 배치됩니다.~~가상 메모리라 물리적으로 연속이 아니라고요? 쉿!~~ 하지만 그렇지 않을 수 있는데,  그 예시로 `LinkedList`의 형태로 저장된 수열이 있습니다. `LinkedList`는 동적 할당을 사용해서 구현하는데, `next` 포인터를 사용해서 `List`를 iterate하면 원소를 순서대로 순회할 수 있습니다. 여기서의 정렬은 원소의 메모리 위치는 바뀌지 않지만 `next` 포인터가 바뀌면서 원소 자체가 아닌 순회의 순서를 바꿉니다. 즉, 원소는 물리적으로는 섞여있지만 정렬된 순서로 탐색을 할 수 있는 상태가 되어있기 때문에 정렬이 되었다고 할 수 있습니다.
[^2]: 영문 위키피디아를 찾아보니 원래의 버블 정렬은 다음과 같다고 합니다. 본문의 것보다는 시간 상으로 조금 더 빠른 방법입니다.

    ```python
    n = len(A)
    swapped = false
    while not swapped:
        swapped = false
        for i in range(1, n): # 1, 2, 3, ... , (n-1)
            if A[i-1] > A[i]:
                swap(A[i-1], A[i])
                swapped = true
    ```
[^3]: swap의 순서는 개인차가 있으며, 위의 코드는 오른쪽 끝(가장 큰 수)부터 정렬이 되는데, `for i in range(0, n)`과 `for j in range(n - 1, i, -1)`와 적절한 인덱스 변형을 통해서 수열의 왼쪽부터 정렬되게 구현하기도 합니다.
[^4]: swap을 사용하지 않을 수도 있는데, 이 경우의 의사코드는 아래와 같습니다.

    ```python
    n = len(A)
    for i in range(n):
        x = A[i]
        j = i - 1
        while j >= 0 and A[j] > x:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = x
    ```
