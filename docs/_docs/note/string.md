---
title: "기초: 문자열(자료형)"
order: 60
category: 노트
layout: note

diff: 27

written: "2021-01-24 22:57"
edited:
---

문자열은 문자의 나열을 자료형으로 지정한 것이다. 프로그램의 입출력에서 직접적으로 가장 많이 쓰이는 자료형이라고 할 수 있다.

### C

#### 저장 방식

C에서의 문자열은 `char` 타입의 배열 중 특수한 것을 문자열이라고 할 수 있다. 문자 배열 중에서 마지막 원소가 널 문자(`\0`)인 것들은 C가 문자열이라고 인식한다. 예를 들어, `"Hello!"`라는 문자열이 있다고 하면, 그 구조는 아래와 같을 것이다.

|H|e|l|l|o|!|`NULL`|
|0x48|0x65|0x6c|0x6c|0x6f|0x21|0x00|

이러한 형태의 문자열을 C-String이라고 부른다.

#### 관련 함수

관련 함수는 `<string.h>` 헤더에 포함되어있다. 이 중 일부 함수를 정리하면 아래와 같다.

|함수|기능|
|:-:|:-:|
|`strcpy(s1, s2)`|`s1`에 `s2`를 복사|
|`strncpy(s1, s2, n)`|`s1`에 `s2`의 첫 `n`문자를 복사|
|`strcat(s1, s2)`|`s1`의 끝에 `s2`를 덧붙임|
|`strncat(s1, s2, n)`|`s1`의 끝에 `s2`의 첫 `n`문자를 덧붙임|
|`strcmp(s1, s2)`|`s1`과 `s2`를 비교|
|`strncmp(s1, s2)`|`s1`과 `s2`의 첫 `n`문자를 비교|
|`strlen(s)`|`s`의 길이를 반환|
|`memcpy(p1, p2, n)`|`p1`의 위치에 `p2`의 데이터를 `n`바이트만큼 복사|
|`memset(p, val, n)`|`p`의 위치부터 `n`바이트만큼 `val`(`unsigned char` 값)으로 설정|
|`s[n]`|`s`의 `n` 위치의 문자 반환|

```c
#include <stdio.h>
#include <string.h>

int main() {
    char input[20] = {1,};
    char goal[20] = {0,};

    while (strcmp(goal, input) != 0) { // 이전 입력값과 같을 경우 탈출
        strncpy(goal, input, 20); // 이전 입력값 복사
        scanf("%s", input); // 입력
    }

    printf("연속으로 중복된 값 출력\n");
}
```

### C++

#### 문자열 자료형

C++은 `<string>` 헤더의 `string` 클래스를 사용한다. `string` 클래스의 변수/함수 목록을 살펴보면 `vector` 클래스와 많이 닮았다. 정확히는 `vector` 클래스의 함수를 모두 가지고 있고(>C++11), 여기에 `string`만을 위한 함수와 변수가 몇 개 더 있다.

#### 관련 함수

`string`은 `vector<char>`이 가진 함수를 모두 가지고 있고, 여기에 추가적으로 문자열만을 위한 함수를 몇 개 가진다. 이 중 일부를 소개하자면 아래와 같다.

|함수|기능|
|:-:|:-:|
|`s.size()`, `s.length()`|`s`의 길이를 반환|
|`s.copy()`|`s`를 `char[]`형 또는 `char*`형 변수에 복사|
|`string(s)`|`s`의 내용을 가진 새로운 `string` 생성|
|`s.append(t)`, `s += t`|`s`의 뒤에 `t`를 덧붙임|
|`s.substr(x, n)`, `string(s, x, n)`|`s`의 `x` 위치부터 `n`개의 문자를 가진 `string` 반환|
|`s.at(n)`, `s[n]`|`s`의 `n` 위치의 문자 반환|

```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
    string input;
    string res;

    while (res.length() < 100) { // 지금까지 축적한 문자열의 길이가 100 이상이면 탈출
        cin >> input; // 입력
        res.append(input.substr(0, input.length() / 2)); // 입력값의 앞 절반만 축적
    }

    cout << res << endl; // 축적값 출력
}
```

### Java

#### 문자열 타입

Java는 `String` 클래스가 내장되어있다. 따로 패키지나 클래스를 import할 필요없이 그냥 사용할 수 있다.

#### 관련 메서드

`String` 클래스는 메서드가 상당히 많다. [여기](https://docs.oracle.com/javase/8/docs/api/java/lang/String.html)에서 모두 확인할 수 있다. 그래도 일부 추려보자면 아래와 같다.

|메서드|기능|
|:-:|:-:|
|`s.charAt(i)`|`s`의 `i` 위치의 문자를 반환|
|`s.contains(t)`|`s` 안에 `t`가 존재하는지 여부를 반환|
|`s.equalsIgnoreCase(t)`|`s`와 `t`가 부호를 무시하고 같은지 여부를 반환|
|`String.format(x, o...)`|포맷 문자열 `x`에 `o...`에 해당하는 `Object`를 대입한 문자열을 반환(C의 `printf`와 유사)|
|`s.indexOf(c)`|문자 `c`가 `s`의 어느 위치에 있는지 반환|
|`String.join(del, s...)`|`s`의 모든 문자열을 `del`을 구분자로 하여 하나의 문자열로 합침|
|`s.length()`|`s`의 길이를 반환|
|`s.replace(old, new)`|`old`에 해당하는 문자/문자열을  `new`로 대체|
|`s.replaceAll(re, new)`|`re`의 정규식에 해당하는 부분문자열을 `new`로 대체|
|`s.split(re)`|`re`의 정규식에 해당하는 문자열을 기준으로 문자열 분할|
|`s.substring(begin, end)`|`begin` 위치부터 `end` 위치까지의 substring을 반환|
|`s.toUpperCase()` / `s.toLowerCase()`|`s`의 모든 알파벳을 대문자/소문자로 변환|

```java
public class Program {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String t[] = br.readLine().split("/");
        if (t[0].equalsIgnoreCase("Orb_H")) {
            System.out.println("Welcome, Orb_H");
            System.out.println("[MSG] " + t[1].replace("+", " "));
        } else {
            System.out.println("Nooo... " + t[0].toLowerCase() + " is not authenticated");
        }
    }
}
```

### Python

#### 저장 방식

Python의 문자열은 보통 `str`이라는 타입이라고 불린다. 다른 타입을 문자열로 캐스팅하는 경우 `str()` 함수를 사용한다.

#### 관련 함수

Python의 `str` 관련 코드는 대부분 `list`의 것과 공유한다.

|코드|기능|
|:-:|:-:|
|`str(s)`|`s`를 문자열로 변환(`s.__str()__` 실행)|
|`s[n]`|`s`의 `n` 위치의 문자 반환|
|`s[begin, end]`|`s`의 `begin`부터 `end`까지의 substring 반환|
|`len(s)`|`s`의 길이를 반환|
|`c in s`|문자 `c`가 `s`에 들어있는지 여부를 반환|
|`s.join(t)`|문자열 리스트 `t`의 각 문자열을 `s`를 구분자로 하여 하나의 문자열로 합침|
|`s.replace(old, new, lim)`|`s`의 `old`에 해당하는 부분을 `new`만큼 최대 `lim`회 대체|
|`s.format(o...)`|`s`의 포맷 문자열에 `o...`의 객체를 대입한 문자열을 반환|
|`s.strip(del)`|`s`의 양쪽 끝을 자르되, `del`에 속하는 모든 문자를 자름|
|`s.split(del, lim)`|`s`를 `del`을 기준으로 최대 `lim`회 분할|
|`s += t`|`s` 뒤에 `t` 문자열을 덧붙임|

```python
s = '    010-1234-5678        '
s = s.strip()
print(s.replace('-', ''))

t = s.split('-')
print('.'.join(t))
```

<hr/>

<small>소스 코드 아이디어가 하나도 안 떠오릅니다... ㅎㅎ;;ㅈㅅ..ㅋㅋ!! (__)</small>
