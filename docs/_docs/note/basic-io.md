---
title: "기본적인 입출력"
order: 1
category: 노트
layout: note

diff: "<span class='diff_bronze'>Bronze V</span>"

written: "2021-01-12 22:48"
edited: "2021-01-12 23:16"
---

### C

입력 함수로는 주로 `scanf`, 출력 함수로는 주로 `printf`를 사용한다. `stdio.h` 헤더에 포함되어있으며, 함수의 형태는 `f("포맷 문자열", 변수...);`이다. 포맷 문자열은 변수로 입력받거나 변수를 출력할 때 어떤 형식으로 할지를 정의한다. 주로 쓰는 것들은 아래와 같다.

|포맷|의미|
|:-:|:-:|
|%c|문자 하나(아스키 코드)|
|%d|int 범위의 정수|
|%ld|long 범위의 정수|
|%lld|long long 범위의 정수|
|%o|8진수 숫자(0aaaa... 꼴)|
|%x|16진수 숫자(0xgggg... 꼴)|
|%f|float 범위의 실수|
|%lf|double 범위의 실수|
|%s|다음 whitespace 전까지의 문자열|

사용 예시는 아래와 같다.

```c
#include <stdio.h>
...
int age;
double score;
char name[21] = "Geek Nerd";
scanf("%d %lf", &age, &score);
printf("%s(%x): %o\n", name, age, (int)score);
```

### C++

C와는 다르게 stdin으로부터 입력받는 `istream` 객체가 존재한다. 마찬가지로 stdout으로 출력하는 `ostream` 객체도 존재한다. 각각 `cin`, `cout`이며 `iostream` 헤더에 포함되어있다. 각각 사용법은 아래와 같다.

```cpp
#include <iostream>
...
int a;
cin >> a;
cout << a * a;
```

와중에 `istream`의 `>>` 연산자는 반환형이 그대로(정확히는 `istream&`)라서 연달아서 계속 사용할 수 있다. 마찬가지로 `ostream`의 `<<` 연산자도 반환형이 그대로(정확히는 `ostream&`)라서 연달아 계속 사용이 가능하다.

```cpp
#include <iostream>
...
int a, b, c;
cin >> a >> b >> c;
cout << a + b << " " << b + c << endl;
```

위의 `endl`은 개행 문자 + flush를 의미하는 상수이다. PS에서는 사용할 때마다 flush 데에 시간을 소비하므로 이왕이면 `\n`으로 대체하여 쓰는 것이 좋다.

난이도가 어려워질수록 cin과 cout을 그냥 쓰는 것보다 더 빠른 속도가 필요할 때가 있다. 그럴 때는 아래의 두 줄을 추가해주면 된다.

```cpp
ios::sync_with_stdio(false);
std::cin.tie(NULL);
```

자세한 내용은 까먹었다.

### Java

입력에는 처리를 알아서 해주지만 `System.in`이라는 `InputStream` 객체의 Reader class인 `InputStreamReader` 객체를 매개 변수로 하는 `BufferedReader` 객체를 사용하는 것 같다.(자바로는 PS를 해보지는 않았다) 출력은 `System.out`이 충분한 기능을 가지고 있어서 웬만해서는 그냥 사용한다. 개행과 함께 출력은 `System.out.println()`, 개행 없이 출력하는 것은 `System.out.print()`를 사용한다. 그리고 혹시 포맷에 맞춰 출력해야할 경우 `System.out.printf()`도 있다. 이 세 개면 웬만한거는 다 된다.

```java
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
String s = br.readLine();
String t[] = s.split();

System.out.print(t.length() + " ");
System.out.println(t[0] + " " + t[1].toLowerCase());
System.out.printf("%x\n", t[1].length());
```

입력받을 때 `Scanner`를 사용하기도 한다. 이 클래스 자체 함수로 다음으로 나타나는 정수를 읽는다거나, 실수를 읽는다거나 등의 C에서의 `scanf`와 거의 비슷하거나 그 이상의 역할을 할 수 있다. 다만 `BufferedReader`에 비해서는 약간 느리기 때문에 속도를 중요시하는 PS에서는 쉬운 문제가 아닌 이상 `BufferedReader`로 문자열을 읽고, `String.split()` / `Integer.parseInt()` / `Double.parseDouble()` 등을 통해서 원하는 부분을 원하는 타입으로 따로 저장하는 편이다. 그래도 `Scanner`를 사용하는 법을 쓰자면 아래와 같다.

```java
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
double d = sc.nextDouble();
```

Java API를 뒤져보면 `Scanner`가 상당히 많은 양의 입력 방식을 지원하고, 심지어는 다음에 나올 토큰의 타입을 판별하여 `boolean`값으로 주기도 한다. 하지만 왠지 모르게 PS에서 사람들은 `BufferedReader`를 선호하는 것 같다.

찾아보니 `System.out` 대신 `BufferedWriter`를 사용하기도 하는 것 같다. 이유는 flush를 줄이기 위해서다. 출력 버퍼에서 콘솔로 데이터를 보내는 것을 최소화하여 시간을 아끼는 것이 주된 목적인 것 같다. 반대로 `System.out.print` 계열 함수는 호출할 때마다 flush가 일어나므로 `BufferedWriter`보다는 시간이 더 걸릴 것이다.

### Python 3

Python은 상당히 간편하다. 입력받기는 `input()`, 출력하기는 `print()`. 다만 입력받는 것은 한 줄 단위로 입력받기 때문에 원하는 형식으로 파싱은 해주어야 한다. 이 때 사용할 수 있는 방법은 문자열을 특정 문자 기준으로 나누는 `split()`과 원하는 타입으로 바꾸는 `int()`, `float()` 등이 있다. 그와 반대로 출력의 경우는 그냥 어떤 타입이든 집어넣으면 알아서 출력해준다. 간편하다.

```python
a = int(input())
print(a)
```

그러고보니 일일이 문자열을 자르고 각 문자열에 대해 타입 변환을 해주는게 좀 귀찮다. 이 때 쓸 수 있는 방법은 `map()`이다. `map()`은 첫 번째 원소로 함수, 두 번째 원소로 iterable을 받는다. 이걸 받아서 두 번째 원소로 들어온 iterable에 있는 모든 원소에 대해 첫 번째 원소로 주어진 함수를 적용시킨 `map` object를 반환한다. 예시는 아래와 같다.

```python
a = [1, 2, 3, 4, 5]
b = map(lambda x: x ** 2, a) # [1, 4, 9, 16, 25]
```

이것과 형변환 함수를 활용하면 한 줄 단위로 들어오는 문자열을 한 번에 적용시킬 수 있다.

```python
a, b, c = map(int, input().split())
x = list(map(float, input().split()))
```

이렇게 하면 주어진 입력을 원하는 방식으로 쉽게 바꿀 수 있을 것이다.

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

Python도 마찬가지로 입력의 속도를 높이는 방법이 있다. 바로 `input()`함수를 호출하는 것이 아닌 `sys` 라이브러리의 `stdin`을 직접 참조하는 것이다. 아래와 같이 말이다.

```python
import sys
n = int(sys.stdin.readline())
```

이게 더 빠른 이유는 모르겠는데 아무래도 `input()` 함수를 실행할 때 숨겨진 무언가가 있는 것 같다.