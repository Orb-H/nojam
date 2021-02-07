---
title: "(반복문)"
order: 30
category: 노트
layout: note

diff: 28
basic: true

written: "2021-01-20 23:34"
edited: "2021-02-06 23:24"
---

### for문

#### 뭔가 많이 빈 for문

`for`문의 세 식을 모두 채울 필요는 없다. 루프에 사용할 변수가 없다면 `초기식` 자리를 비워도 되며, 원래 있는 변수의 값을 바꾸어 그 변수를 임시 변수로 사용할 수도 있다. 아니면 그냥 함수를 실행하기도 한다! 다른 곳도 마찬가지이다. `조건식`을 비워 무한루프로 돌아가게끔 할 수도 있고, `증감문`에 `scanf`를 넣어서 숏코딩을 하거나 루프 내에서 처리하기 위해 비우기도 한다. 그냥 실행되는 순서에 맞게만 돌아가게 아무렇게나 넣어도 된다. 그 예시로 숏코드 하나를 첨부한다. {% include boj_info.html num=1074 %} 문제 C99 1위 코드이다.

```c
r,c,x;main(n){for(scanf("%d%d%d",&n,&r,&c);n+1;)x+=(2*r&2<<n|c&1<<n)<<n--;printf("%d",x);}
```

#### foreach문

비록 `foreach`를 `for`의 하위 구문으로 정리하긴 했지만, 역사는 이 `foreach` 구문이 조금 더 길다. `for`문의 현재 형태는 C언어의 정의 때 본격적으로 사용되기 시작했고, 그 이전에는 `foreach` 형태의 반복문을 사용했다. 이 `foreach`문은 C/C++/Java/Python 중에서는 Java와 Python에서 사용할 수 있는데, 둘 모두 `foreach`라고 명시하지는 않고 `for`을 사용한다. `foreach`문의 형태는 아래와 같다.

```java
public class Main {
    public static void main(String[] args) {
        int a[] = new int[]{1, 2, 3, 4, 5};

        for (int i : a) { // a의 각 원소 i에 대하여
            System.out.println(i * i); // 제곱을 출력
        }
    }
}
```

```python
a = [1, 2, 3, 4, 5]
for i in a:
    print(i * i)
```

```python
a = [1, 2, 3, 4, 5]
print([i * i for i in a])
```

배열, 리스트와 같은 iterable한 오브젝트( 원소를 순회할 수 있는 물리적/논리적 구조를 가진 오브젝트)의 모든 원소를 순회하는 의미로 사용한다. 위의 코드는 원소가 1, 2, 3, 4, 5인 리스트의 모든 원소를 순회하여 각 원소의 제곱값을 출력하는 코드이다. `for`문과 구조를 비교해보면 초기식, 조건식, 증감문의 개념이 없고 단순히 iterable 하나만 입력하여 iterable의 원소 전체를 순회한다.

### 정리

- for문
  - 꼭 다 채울 필요는 없음
  - foreach문 (`for(변수 in iterable){ }`)