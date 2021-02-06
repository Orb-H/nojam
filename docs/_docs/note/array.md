---
title: "기초: 배열(자료형) 등"
order: 40
category: 노트
layout: note

diff: 27

written: "2021-01-24 14:52"
edited: "2021-02-06 23:26"
---

※ 기초 태그가 붙어있는 포스트는 까먹을 만한/더 알면 좋은 것만 정리합니다

### 배열 대신 사용할 수 있는 자료형

#### vector (C++)

배열을 대신하여 사용할 수 있는 자료형으로 C++에는 `vector`가 있다. `<vector>` 헤더에 포함되어있으며, 배열과 다른 점은 크기가 가변적이라는 것이다. `[]`를 이용하여 특정 위치에 값을 대입, 반환하는 것은 배열과 똑같으며, 추가적인 기능을 제공하여 더 유연하게 사용할 수 있도록 한 타입이다.

임의 위치의 원소 삽입과 삭제가 가능하고(`insert`, `erase`, `push_back`, `pop_back`), 길이를 늘리거나 줄이는 함수도 존재한다(`resize`). 또한 원소 순회를 위한 `iterator`(반복자)도 제공한다. 자세한 내용은 [여기](https://www.cplusplus.com/reference/vector/vector/)에서 찾아볼 수 있다. 아래는 사용 예시이다.

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v1;
    vector<int> v2(4); // 크기 4로 미리 할당
    vector<int> v3(8, 2); // 크기 8로 할당 및 모든 원소를 2로 초기화
    int m;

    v2[1] = 3; // 대입
    m = v3[5]; // 반환

    v1.push_back(3); // vector의 맨 뒤에 3을 append
    v1.insert(0, 5); // 0의 위치에 5 삽입
    v1.pop_back(); // vector의 맨 뒤의 원소를 삭제
    v1.erase(0); // 0의 위치의 원소를 삭제
    v1.resize(8); // v1을 8의 크기로 재할당

    for (vector<int>::iterator it = v3.begin(); it < v3.end(); it++) // iterator를 사용한 순회
        cout << *it << " ";

    for (int i = 0; i < v3.size(); i++) // int를 이용한 순회
        cout << v3[i] << " ";
}
```

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<int>> v1; // 2차원 vector
    vector<vector<int>> v2(10, vector<int>(6, 3)); // 10×6 크기의 2차원 vector, 값을 모두 3으로 초기화

    cout << v2[7][1]; // 2차원 배열처럼 반환
}
```

#### list (Python)

Python은 배열을 나타내는 자료형이 존재하지 않는다. 하지만 `list`라는 자료형을 사용할 수 있다. 이 `list`는 배열과는 다르게 다양한 타입의 변수를 저장할 수 있으며, 크기도 가변적이다. 또한 다양한 기능을 제공한다. 자세한 내용은 [여기](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists)에서 찾아볼 수 있다. 기본적인 사용법은 아래와 같다.

```python
a = [1, 2, 3, 4, 5] # 1, 2, 3, 4, 5로 list 초기화
b = [1, "abc", [2, 3, 4]] # 다양한 타입을 가질 수 있다

a[3] = '1' # 대입
print(b[2][0]) # 다차원 배열 비슷하게 사용

a.append(8) # list의 끝에 8을 append
a.pop() # list의 끝 원소를 삭제

c = a[0:2] # sub-list를 반환( [0, 2) 범위)
d = a[4:1:-1] # [4, 1) 범위, 거꾸로

print(len(a)) # 배열의 길이
```

#### *List* (Java)

Java에도 리스트가 존재한다. 정확히는 *`List`* 인터페이스와 그 구현체인 `ArrayList`, `LinkedList` 등의 클래스가 존재한다.[^1] 관련 내용은 <a class="invalid" href="">자료구조: 리스트</a>에서 다룬다. 그래도 필요 시 사용해야하니 사용법은 간단하게 적어놓아야할 것 같다. 사용법은 아래와 같다.

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List l1 = new ArrayList<Integer>();
        List l2 = new ArrayList<Integer>(12); // 크기 12로 할당 및 기본값으로 초기화

        l1.add(5); // 5를 뒤에 append
        l1.remove(0); // 0 위치의 원소를 삭제

        l2.set(2, 8); // 2 위치의 원소를 8로 설정
        System.out.println(l2.get(6)); // 6 위치의 원소를 출력
        System.out.println(l2.size()); // 크기 출력

        Collections.sort(l2); // 정렬
        l1.sort(new Comparator<Integer> { // 사용자가 정렬 기준을 설정 가능한 정렬
            public int compare(Integer a, Integer b) {
                return a.compareTo(b);
            }
        });
        l1.sort((a, b) -> a.compareTo(b)); // 위와 같음 (Comparator는 @FunctionalInterface라 Lambda 형식으로 작성이 가능하다)

        for (int i = 0; i < l2.size(); i++) // int로 순회
            System.out.print(l2.get(i) + " ");
        for (Integer i : l2) // foreach 구문으로 순회
            System.out.print(i + " ");
        Iterator<Integer> it = l2.iterator();
        while (it.hasNext()) // Iterator로 순회
            System.out.print(it.next() + " ");
    }
}
```

### 정리

- 배열 대체 자료형
  - `vector` (C++)
    - 일정한 타입, 가변 크기
  - `list` (Python)
    - 다양한 타입, 가변 크기
  - *`List`* (Java)
    - 일정한 타입, 가변 크기
    - `ArrayList`, `LinkedList`와 같은 구현체

<hr/>

[^1]: 리스트라는 ADT와 리스트를 배열 기반, 포인터 기반으로 구현한 DT의 관계라 보면 편하다.