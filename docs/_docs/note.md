---
title: 알고리즘 메모
order: 1
regenerate: true
layout: default
---

백준을 풀다가 안 풀다가 하니까 알고리즘을 자꾸 까먹게 됩니다. 그래서 이걸 좀 정리해보면 어떨까해서 만들게 된 페이지입니다.

### 목록

<table id="notes">
    <thead>
        <tr>
            <th onclick="sortTable(0,'notes')">이름</th>
            <th onclick="sortTable(1,'notes')">난이도</th>
        </tr>
    </thead>
    <tbody>
        {% assign items = site.docs | where: 'category', "노트" | sort: "order" %}
        {% for item in items %}
            <tr>
                <td><a href="{{ item.url | relative_url }}">{{ item.title }}</a></td>
                <td>{{ item.diff }}</td>
            </tr>
        {% endfor %}
    </tbody>
</table>

<script src="{{ site.baseurl }}/scripts/sort.js" charset="utf-8">