---
title: "기초: 함수 선언 및 정의"
order: 50
category: 노트
layout: note

diff: 0

written: "2021-01-24 19:12"
edited:
---

※ 이 내용은 문제 해결의 난이도에 직접적으로 영향을 주는 내용이 아니라 난이도는 책정되지 않았지만 이후에 나오는 내용과 관련있는 내용임

### `main` 함수

대부분의 프로그램은 `main` 함수를 시작으로 돌아간다. 그래서 PS의 답안이 될 코드를 작성할 때 `main` 함수 (또는 그와 동등한 언어별 구조)을 쓰는 것으로 시작한다. 아래와 같이 말이다.

```c
int main() { // 사실 int main(int argc, char** argv)가 정석이다
    ...
}
```

```java
public class Program {
    public static void main(String[] args) {
        ...
    }
}
```

```python
... # Python은 main 함수가 없고 첫 줄부터 시작한다

# main 함수 비슷한 것을 만들려면 아래와 같이 하면 된다.
if __name__ == "__main__":
    ...
```

간단한 문제는 main 함수 안에 필요한 코드만 작성하면 정답을 맞출 수 있다. 하지만 문제가 복잡해지면 비슷한 코드를 여러 번 작성하거나 조건은 다르지만 같은 코드를 돌리는 등 하나의 코드 덩어리로 분리할 필요가 생긴다. 이 때 `main`이 아닌 다른 함수를 선언하여 `main` 함수에서 이를 호출하여 사용하는 방식으로 활용할 수 있다.

### 새로운 함수 정의

#### C/C++

함수를 **정의**할 때에는 `[타입] [이름]([타입] [이름], [타입] [이름] ...){}`의 형식으로 정의한다. 가장 앞의 `[타입]`은 이 함수가 반환하는 값의 타입, 그 바로 뒤의 `[이름]`은 함수의 이름이다. 소괄호(`(`, `)`) 안의 타입과 이름은 **매개 변수**로 들어오는 변수의 타입과 사용할 이름을 결정하는데, 매개 변수를 사용할 필요가 없다면 비우면 된다. 예시는 아래와 같다.

```cpp
int add(int a, int b) { // 매개 변수가 2개인 반환형이 int인 함수
    return a + b;
}

int five() { // 매개 변수가 없는 반환형이 int인 함수
    return 5;
}
```

C/C++에서 함수를 **선언**할 때에는 해당 함수를 사용하는 구문보다 먼저 선언해야 한다. 예를 들어, 위의 `add` 함수를 `main` 함수에서 사용하려면 `add` 함수의 선언은 `main`보다 위에서 해야 한다. 다만 `main`보다 위의 부분에서 **정의**를 할 필요는 없다. 아래의 코드를 보면 `main` 전에 이 함수가 있다는 것만 알려주고 그 내용은 `main`보다 뒤에서 정의했다.

```cpp
int add(int a, int b); // 선언만 함

int main() {
    printf("%d", add(3, 5));
}

int add(int a, int b) { // 정의는 아래에서 함
    return a + b;
}
```

즉, 선언과 정의를 따로 할 수 있다. 이를 조금 더 활용해보면 아래와 같은 구문도 가능하다.

```cpp
int add(int a);
int five();

int main() {
    printf("%d", add(3));
}

int add(int a) {
    return a + five();
}

int five() {
    return 5;
}
```

선언이 없었더라면 에러가 마구 튀어나왔을 코드이다. `main`에서 `add`가 정의되어있지 않고, `add`에서는 `five`가 정의되어있지 않다는 오류 메시지를 출력했을 것이다.

새로운 함수를 선언하는 것은 단순히 `[타입] [이름](...){}`의 형식만 있는 것이 아니다. `extern`이나 `static`과 같은 키워드가 붙을 수도 있고, C++에서는 클래스를 사용하기 때문에 더 다양한 키워드가 붙는다. 하지만 PS할 때에는 거의 쓰지 않을 것 같아서 관련 내용은 작성하지 않는다. 만약 필요할 때가 생기면 그 때 더 추가될 것이다.

#### Java

사용 방식은 C/C++과 비슷하다. 하지만 `[타입]` 앞에 `static` 키워드가 붙게 되는데, 그 이유는 `main` 함수가 static 메서드이기 때문에 `main`에서 호출하려면 `static` 키워드가 붙어야 한다. 또한 C/C++과는 다른 점이 있는데, 굳이 `main` 앞에 선언할 필요가 없고, 선언과 정의를 분리할 수 없다. 사용 예시는 아래와 같다.

```java
public class Program {
    public static void main(String[] args) {
        System.out.println(add(3, five()));
    }

    static int add(int a, int b) {
        return a + b;
    }

    static int five() {
        return 5;
    }
}
```

마찬가지로 메서드의 성질을 결정하는 여러 키워드가 있지만, PS에서는 `main`에서 직접 호출하는 `static` 메서드와 따로 클래스를 만들어서 사용할 때 호출하는 일반 메서드 외에는 잘 사용할 일이 없을 것이다.

#### Python

Python은 위의 C/C++/Java와는 조금 다른 형태를 가진다. `def` 키워드를 이용하여 함수를 정의하고, 반환 타입을 명시하지 않는다. 매개 변수의 타입 또한 적지 않는다. 또한 정의한 함수를 사용하기 위해서는 함수를 정의한 위치보다 아래에서 호출해야 한다. 예시는 아래와 같다.

```python
def add(a, b):
    return a + b

def five():
    return 5

print(add(3, five()))
```

### 정리

- `main` 함수
  - 프로그램이 실행될 때 가장 처음으로 호출되는 함수
- 함수를 추가할 때
  - C/C++: `[타입] [이름]([타입] [이름], [타입] [이름], ...){ }`
  - Java: `static [타입] [이름]([타입] [이름], [타입] [이름], ...) { }`
  - Python: `def [이름]([이름], [이름], ...):`