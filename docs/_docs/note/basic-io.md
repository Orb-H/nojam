---
title: "기초: 기본적인 입출력"
order: 0
category: 노트
layout: note

diff: 30

written: "2021-01-12 22:48"
edited: "2021-02-05 23:59"
---

※ 기초 태그가 붙어있는 포스트는 까먹을 만한/더 알면 좋은 것만 정리합니다

### 특수 문자열

#### 포맷 문자열

포맷 문자열은 변수로 입력받거나 변수를 출력할 때 어떤 형식으로 입력/출력할지를 정의한다. 주로 쓰는 것들은 아래와 같다.

|포맷|의미|
|:-:|:-:|
|`%c`|문자 하나(아스키 코드)|
|`%d`|`int` 범위의 정수|
|`%ld`|`long` 범위의 정수|
|`%lld`|`long long` 범위의 정수|
|`%u`|`unsigned int` 범위의 정수|
|`%lu`|`unsigned long` 범위의 정수|
|`%llu`|`unsigned long long` 범위의 정수|
|`%o`|8진수 숫자(0aaaa... 꼴)|
|`%x`, `%X`[^1]|16진수 숫자(0xgggg... 꼴)|
|`%f`, `%F`[^1]|`float` 범위의 실수|
|`%lf`, `%lF`[^1]|`double` 범위의 실수|
|`%Lf`, `%LF`[^1]|`long double` 범위의 실수|
|`%s`|다음 whitespace 전까지의 문자열|
|`%%`|`%`|

#### 이스케이프 문자

이스케이프 문자는 일반적인 입력으로는 나타낼 수 없는 문자를 나타내기 위해 사용하는 문자인데, 주로 쓰는 것은 아래와 같다.

|이스케이프 문자|역할|
|:-:|:-:|
| `\n` |개행 문자|
| `\t` |탭 문자|
| `\\` |`\` 문자|
| `\'` |`'` 문자|
| `\"` |`"` 문자|
| `\0` |널 문자|

문자열 중간에 `"Hello World!\n"`와 같이 이스케이프 문자를 넣어 해당 문자를 나타낼 수도 있고, 문자 하나를 나타낼 때도 해당 문자를 대신하여 이스케이프 문자를 사용할 수 있다. `'\n'`, `'\\'`처럼 말이다!

### 빠른 입출력

#### C

C는 그냥 쓰면 된다. 이미 `stdio.h`의 입출력 함수는 충분히 빠르다.

#### C++

`cin`과 `cout`은 C의 `stdio.h` 입출력에 비해서는 조금 느리다. 난이도가 어려워질수록 cin과 cout을 그냥 쓰는 것보다 더 빠른 속도가 필요할 때가 있는데, 그럴 때는 아래의 두 줄을 `main()`의 최상단에 추가해주면 된다.

```cpp
ios::sync_with_stdio(false);
std::cin.tie(NULL);
```

원래는 C++의 입출력 시스템과 C의 입출력 시스템이 동기화되어있고, `cin`과 `cout`를 이용한 입출력과 `printf`와 `scanf`를 이용한 입출력을 한 프로그램에서 둘 다 사용할 수 있다. 여기서 첫 번째 줄을 삽입하면 동기화가 풀려버려 동기화에 필요한 시간만큼 이득을 볼 수 있지만 C++의 입출력과 C의 입출력을 혼용할 수 없게 된다. 두 번째 줄은 cin과 cout을 untie해버리는 것이다. 원래는 cin이 입력받기 전에 출력 버퍼를 비우는 작업을 했는데, PS에서는 그런 거 필요없다. 주어진 입력에 대해 알맞은 출력만 나오면 되므로 이를 untie해서 입력이 계속 들어오더라도 출력이 되지 않다가 버퍼가 꽉 차거나 프로그램이 종료될 때 버퍼를 비우게 하는 것이 시간을 더 줄일 수 있다.

`endl`은 개행과 더불어 출력 버퍼의 flush를 의미하는 상수이다. PS에서는 사용할 때마다 flush 하는 데에 시간을 소비하므로 `\n`으로 대체하여 쓰는 것이 좋다.

#### Java

Java의 입력에 사용되는 `Scanner`와 출력에 사용되는 `System.out`은 느리다. 이를 위해 입력에는 `System.in`이라는 `InputStream` 객체의 Reader class인 `InputStreamReader` 객체를 매개 변수로 하는 `BufferedReader` 객체를, 출력에는 `System.out`이라는 `PrintWriter` 객체의 Writer class인 `OutputStreamWriter`를 매개 변수로 하는 `BufferedWriter` 객체를 사용한다.

```java
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
```

입력받을 때에는 타입이 항상 `String`으로 들어오고 개행 문자를 기준으로 잘리기 때문에 다른 공백문자로 구분을 하려면 `String.split()` 함수를, 다른 타입으로 바꾸기 위해서는 `Integer.parseInt()`나 `Float.parseFloat()` 같은 파싱 함수를 사용해야한다.

#### Python 3

Python도 마찬가지로 입력의 속도를 높이는 방법이 있다. 바로 `input()`함수를 호출하는 것이 아닌 `sys` 라이브러리의 `stdin`을 직접 참조하는 것이다.

```python
import sys
n = int(sys.stdin.readline())
```

#### Python 3 팁

일일이 문자열을 자르고 각 문자열에 대해 타입 변환을 해주는게 좀 귀찮다. 이 때 쓸 수 있는 방법은 `map()`이다. `map()`은 첫 번째 원소로 `function`, 두 번째 원소로 `iterable`을 받는다. 이걸 받아서 두 번째 원소로 들어온 `iterable`에 있는 모든 원소에 대해 첫 번째 원소로 주어진 함수를 적용시킨 `map` object를 반환한다. 예시는 아래와 같다.

```python
a = [1, 2, 3, 4, 5]
b = list(map(lambda x: x ** 2, a)) # [1, 4, 9, 16, 25]
```

이것과 형변환 함수를 활용하면 한 줄 단위로 들어오는 문자열을 한 번에 적용시킬 수 있다.

```python
a, b, c = map(int, input().split())
x = list(map(float, input().split()))
```

출력에 대해 다시 생각해보니 한 번 출력을 하고나서 다음 줄에 출력하는 것이 아니라 그 뒤에 공백이나 다른 문자를 구분자로 해서 출력해야할 때도 있다. 그러면 어떻게 해야할까? 크게 두 가지 방법이 있다. 하나는 한 줄에 들어갈 문자열을 구성한 후 출력하는 방법, 두 번째는 `print()`의 매개 변수로 개행이 안되게 설정하는 것. 길이 5의 배열의 원소를 스페이스바로 구분해서 한 줄에 출력한다고 했을 때, 각각의 방법은 아래와 같다.

```python
a = [1, 2, 3, 4, 5]
print(" ".join(a))
```

```python
a = [1, 2, 3, 4, 5]
for i in range(len(a)):
    print(a, end=' ')
```

### 정리

- 포맷 문자열
  - 문자: `%c`
  - 부호있는 10진수 정수: `%d`, `%ld`, `%lld`
  - 부호없는 10진수 정수: `%u`, `%lu`, `%llu`
  - 16진수 정수: `%x`, `%lx`, `%llx` (`x` 대신 `X`를 사용할 경우 대문자로 입/출력)
  - 실수: `%f`, `%lf`, `%Lf` (`f` 대신 `F`를 사용할 경우 inf, nan 등을 대문자로 입/출력)
  - 문자열: `%s`
- 빠른 입출력
  - C++: `ios::sync_with_base(false);`, `cin.tie(NULL);` / `endl` 사용 회피
  - Java: Scanner 대신 BufferedReader / System.out 대신 BufferedWriter
  - Python: `sys.stdin.readline()`

<hr />

[^1]: 대문자를 사용할 경우 영어 소문자 알파벳 대신 대문자 알파벳으로 입/출력을 진행한다. (ex) 0x1a2b3c → 0x1A2B3C, nan → NAN)