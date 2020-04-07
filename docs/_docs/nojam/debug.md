---
title: 백준
category: 디버그용 페이지
regenerate: true
---

<details>
<summary>solved.ac 태그가 없는 문제</summary>
<table id="prob_no_solved_tag">
    <thead>
        <tr>
            <th onclick="sortTable(0,'prob_no_solved_tag')" class="num_col">문제 번호</th>
            <th onclick="sortTable(1,'prob_no_solved_tag')">문제 이름</th>
            <th onclick="sortTable(2,'prob_no_solved_tag')" class="num_col">난이도</th>
        </tr>
    </thead>
    <tbody>
        {% assign diff = site.data.nojam_diff %}
        {% assign docs = site.docs | where: "category", "백준" | where_exp: "item", "item.solve_solved_tag == nil" %}
        {% for doc in docs %}
        {% assign num = doc.solve_diff %}
        <tr>
            <td>{{ doc.solve_num }}</td>
            <td><a href="{{ site.baseurl }}/nojam/{{ doc.solve_num }}">{{ doc.solve_name }}</a></td>
            <td class="diff_{{ diff[num].class }}"><div style="display:none;">{{ num | plus:10 }}</div>{{ diff[num].sym_light }} {{ diff[num].text }}</td>
        </tr>
        {% endfor %}
    </tbody>
</table>
</details>

<details>
<summary>백준 태그가 없는 문제</summary>
<table id="prob_no_tag">
    <thead>
        <tr>
            <th onclick="sortTable(0,'prob_no_tag')" class="num_col">문제 번호</th>
            <th onclick="sortTable(1,'prob_no_tag')">문제 이름</th>
            <th onclick="sortTable(2,'prob_no_tag')" class="num_col">난이도</th>
        </tr>
    </thead>
    <tbody>
        {% assign diff = site.data.nojam_diff %}
        {% assign docs = site.docs | where: "category", "백준" | where_exp: "item", "item.solve_tag == nil" %}
        {% for doc in docs %}
        {% assign num = doc.solve_diff %}
        <tr>
            <td>{{ doc.solve_num }}</td>
            <td><a href="{{ site.baseurl }}/nojam/{{ doc.solve_num }}">{{ doc.solve_name }}</a></td>
            <td class="diff_{{ diff[num].class }}"><div style="display:none;">{{ num | plus:10 }}</div>{{ diff[num].sym_light }} {{ diff[num].text }}</td>
        </tr>
        {% endfor %}
    </tbody>
</table>
</details>

<details>
<summary>solved.ac 난이도가 확정되지 않은 문제</summary>
<table id="prob_solved_not_set">
    <thead>
        <tr>
            <th onclick="sortTable(0,'prob_solved_not_set')" class="num_col">문제 번호</th>
            <th onclick="sortTable(1,'prob_solved_not_set')">문제 이름</th>
            <th onclick="sortTable(2,'prob_solved_not_set')" class="num_col">난이도</th>
        </tr>
    </thead>
    <tbody>
        {% assign diff = site.data.nojam_diff %}
        {% assign docs = site.docs | where: "category", "백준" | where_exp: "item", "item.solve_solved_not_set" %}
        {% for doc in docs %}
        {% assign num = doc.solve_diff %}
        <tr>
            <td>{{ doc.solve_num }}</td>
            <td><a href="{{ site.baseurl }}/nojam/{{ doc.solve_num }}">{{ doc.solve_name }}</a></td>
            <td class="diff_{{ diff[num].class }}"><div style="display:none;">{{ num | plus:10 }}</div>{{ diff[num].sym_light }} {{ diff[num].text }}</td>
        </tr>
        {% endfor %}
    </tbody>
</table>
</details>

<details>
<summary>못 푼 문제</summary>
<table id="prob_not_solved">
    <thead>
        <tr>
            <th onclick="sortTable(0,'prob_not_solved')" class="num_col">문제 번호</th>
            <th onclick="sortTable(1,'prob_not_solved')">문제 이름</th>
            <th onclick="sortTable(2,'prob_not_solved')" class="num_col">난이도</th>
        </tr>
    </thead>
    <tbody>
        {% assign diff = site.data.nojam_diff %}
        {% assign docs = site.docs | where: "category", "백준" | where_exp: "item", "item.solve_exclude != nil" %}
        {% for doc in docs %}
        {% assign num = doc.solve_diff %}
        <tr>
            <td>{{ doc.solve_num }}</td>
            <td><a href="{{ site.baseurl }}/nojam/{{ doc.solve_num }}">{{ doc.solve_name }}</a></td>
            <td class="diff_{{ diff[num].class }}"><div style="display:none;">{{ num | plus:10 }}</div>{{ diff[num].sym_light }} {{ diff[num].text }}</td>
        </tr>
        {% endfor %}
    </tbody>
</table>
</details>

<script src="{{ site.baseurl }}/scripts/sort.js" charset="utf-8">
