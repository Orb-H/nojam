---
title: 알고리즘 메모
order: 1
regenerate: true
layout: default
---

백준을 풀다가 안 풀다가 하니까 알고리즘을 자꾸 까먹게 됩니다. 그래서 이걸 좀 정리해보면 어떨까해서 만들게 된 페이지입니다.

난이도 항목은 이 내용을 필수적으로 사용해야 하는(모르면 못 푸는) 문제의 최소 난이도 정도로 해석하면 됩니다.(정확하지는 않습니다)

solved.ac에 따르면 아래와 같은 하한 기준이 잡혀있습니다.

|티어|내용|
|:-:|:-:|
|{% include boj_diff.html diff=30 %}|간단한 입출력, 사칙연산|
|{% include boj_diff.html diff=29 %}|if, switch 등의 조건문|
|{% include boj_diff.html diff=28 %}|for, while 등의 반복문|
|{% include boj_diff.html diff=27 %}|1차원 배열, 문자열, 함수 사용|
|{% include boj_diff.html diff=26 %}|다차원 배열, 재귀 호출|
|{% include boj_diff.html diff=25 %}|각종 제곱 미만 시간 정렬 방법|

나머지는 백준 문제에 나와있는 난이도를 바탕으로 정할 예정입니다.

### 목록

<table id="notes">
    <thead>
        <tr>
            <th onclick="sortTable(0,'notes')">이름</th>
            <th onclick="sortTable(1,'notes')">난이도</th>
            <th onclick="sortTable(2,'notes')">작성 시간</th>
            <th onclick="sortTable(3,'notes')">수정 시간</th>
        </tr>
    </thead>
    <tbody>
        {% assign items = site.docs | where: 'category', "노트" | sort: "order" %}
        {% for item in items %}
            <tr>
                <td><a href="{{ item.url | relative_url }}">{{ item.title }}</a></td>
                <td>{% include boj_diff.html diff=item.diff %}</td>
                <td>{{ item.written }}</td>
                <td>{{ item.edited }}</td>
            </tr>
        {% endfor %}
    </tbody>
</table>

<script src="{{ site.baseurl }}/scripts/sort.js" charset="utf-8">
