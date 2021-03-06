---
title: 백준
category: 디버그용 페이지
regenerate: true
---

{% include solved_class.html class=1 %}
{% include solved_class.html class=2 %}
{% include solved_class.html class=3 %}
{% include solved_class.html class=4 %}
{% include solved_class.html class=5 %}
{% include solved_class.html class=6 %}
{% include solved_class.html class=7 %}
{% include solved_class.html class=8 %}
{% include solved_class.html class=9 %}
{% include solved_class.html class=10 ess=true %}

{% include boj_diff.html diff=30 mode=1 %} {% include boj_diff.html diff=29 mode=1 %} {% include boj_diff.html diff=28 mode=1 %} {% include boj_diff.html diff=27 mode=1 %} {% include boj_diff.html diff=26 mode=1 %}<br/>
{% include boj_diff.html diff=25 mode=1 %} {% include boj_diff.html diff=24 mode=1 %} {% include boj_diff.html diff=23 mode=1 %} {% include boj_diff.html diff=22 mode=1 %} {% include boj_diff.html diff=21 mode=1 %}<br/>
{% include boj_diff.html diff=20 mode=1 %} {% include boj_diff.html diff=19 mode=1 %} {% include boj_diff.html diff=18 mode=1 %} {% include boj_diff.html diff=17 mode=1 %} {% include boj_diff.html diff=16 mode=1 %}<br/>
{% include boj_diff.html diff=15 mode=1 %} {% include boj_diff.html diff=14 mode=1 %} {% include boj_diff.html diff=13 mode=1 %} {% include boj_diff.html diff=12 mode=1 %} {% include boj_diff.html diff=11 mode=1 %}<br/>
{% include boj_diff.html diff=10 mode=1 %} {% include boj_diff.html diff=9 mode=1 %} {% include boj_diff.html diff=8 mode=1 %} {% include boj_diff.html diff=7 mode=1 %} {% include boj_diff.html diff=6 mode=1 %}<br/>
{% include boj_diff.html diff=5 mode=1 %} {% include boj_diff.html diff=4 mode=1 %} {% include boj_diff.html diff=3 mode=1 %} {% include boj_diff.html diff=2 mode=1 %} {% include boj_diff.html diff=1 mode=1 %}<br/>
{% include boj_diff.html diff=0 mode=1 %}

`test` content

|Col1|Col2|
|:-:|:-:|
|Cell11|Cell12|
|Cell21|Cell22|

### 풀이

#### Python 3

```c
#include <stdio.h>

int main() {
    int n = 5;
    // Why is it 21??
    char c[21] = "Hello World!";
    /*
    Dunno
    */

    for (int i = 0; i < n; i++) {
        if (n / i == 0) {
            printf("%d", i);
        }
    }
}
```

```cpp
#include "algostuff.hpp"
using namespace std;

bool bothEvenOrOdd (int elem1, int elem2)
{
    return elem1 % 2 == elem2 % 2;
}

int main()
{
    vector<int> coll1;
    list<int> coll2;

    float m = 40.0f;

    INSERT_ELEMENTS(coll1,1,7);
    INSERT_ELEMENTS(coll2,3,9);

    PRINT_ELEMENTS(coll1,"coll1: \n");
    PRINT_ELEMENTS(coll2,"coll2: \n");

    // check whether both collections are equal
    if (equal (coll1.begin(), coll1.end(),  // first range
               coll2.begin())) {            // second range
        cout << "coll1 == coll2" << endl;
    } /* TODO Shouldn't there be an 'else' case? */

    // check for corresponding even and odd elements
    if (equal (coll1.begin(), coll1.end(),  // first range
               coll2.begin(),               // second range
               bothEvenOrOdd)) {            // comparison criterion
        cout << "even and odd elements correspond" << endl;
    }
}
```

```java
/**
 * This is about <code>ClassName</code>
 * {@link}
 * @author author
 * @deprecated use <code>OtherClass</code>
 */

public class ClassName<E> extends AnyClass implements B {
    enum Color { RED, GREEN, BLUE };
    /* This comment may span multiple lines. */
    static Object staticField;
    // This comment may span only this line.
    private E field;
    private AbstractClassName field2;
    // TASK: refactor
    @SuppressWarnings(value="all")
    public int foo(Integer parameter) {
        abstractMethod(inheritedField);
        int local = 42 * hashCode();
        staticMethod();
        return bar(local) + parameter;
    }
}
```

```python
a, b = map(int, input().split())
op = ['+', '-', '*', '/', '%']

print([eval("{}{}{}".format(a, c, b)) for c in op])
```

```html
<html>
    <head>
        <meta content="text/html">
        <title>HTML Highlighting Preferences</title>
    </head>
    <body>
        <!--we need a flaming logo! -->
        <p>three&nbsp;&nbsp;&nbsp;spaces</p>
    </body>
</html>
```

```css
@import url("../sample2.css")
/* Sample Styles */
BODY {
    color: black;
    background-color: rgb(181, 253, 211);
    text-align: center;
    font-family: "Heisei Mincho W3", serif
}
#content > div *.links a[href~="http://"]:hover {
    text-decoration: underline;
}
```