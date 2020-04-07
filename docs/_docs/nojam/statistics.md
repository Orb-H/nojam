---
title: 백준
category: 통계
regenerate: true
---

각 표의 제목을 클릭하면 항목 별 정렬이 가능합니다. 전체 문제 수는 2020-03-24 00:00 기준입니다.

{% assign exp = 0 %}
{% assign docs = site.docs | where: "category", "백준" | where_exp: "item", "item.solve_exclude == nil" %}
{% for num in (0..30) %}
{% assign exp_tmp = docs | where: "solve_diff", num | size %}
{% assign exp = exp_tmp | times: site.data.nojam_exp[num] | plus: exp %}
{% endfor %}
푼 문제 수: **{{ docs.size }}**개, solved.ac 기준 경험치: **{{ exp }}** XP

<details>
<summary>난이도 통계</summary>
<table id="prob_diff">
    <thead>
        <tr>
            <th onclick="sortTable(0,'prob_diff')">난이도</th>
            <th onclick="sortTable(1,'prob_diff')" class="num_col">푼 문제 수</th>
            <th onclick="sortTable(2,'prob_diff')" class="num_col">전체 문제 수</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td class="diff_unrated"><div style="display:none;">31</div>&#65311; Unrated</td>
            <td>{{ docs | where: "solve_diff", 0 | size }}</td>
            <td>6897</td>
        </tr>
        {% assign diff = site.data.nojam_diff %}
        {% for num in (1..30) reversed %}
        <tr>
            <td class="diff_{{ diff[num].class }}"><div style="display:none;">{{ num | plus:10 }}</div>{{ diff[num].sym_light }} {{ diff[num].text }}</td>
            <td>{{ docs | where: "solve_diff", num | size }}</td>
            <td>{{ diff[num]. tot_prob }}</td>
        </tr>
        {% endfor %}
    </tbody>
</table>
</details>

<details>
<summary>사용 언어 통계</summary>
<table id="prob_lang">
    <thead>
        <tr>
            <th onclick="sortTable(0,'prob_lang')">사용 언어</th>
            <th onclick="sortTable(1,'prob_lang')" class="num_col">푼 문제 수</th>
        </tr>
    </thead>
    <tbody>
        {% for lang in site.data.languages %}
        <tr>
            <td class="lang_{{ lang[1].class }}">{{ lang[0] }}</td>
            <td>{{ docs | where: "solve_lang", lang[0] | size }}</td>
        </tr>
        {% endfor %}
    </tbody>
</table>
</details>

<details>
<summary>백준 태그 통계</summary>
<table id="prob_tag">
    <thead>
        <tr>
            <th onclick="sortTable(0,'prob_tag')">태그</th>
            <th onclick="sortTable(1,'prob_tag')" class="num_col">푼 문제 수</th>
            <th onclick="sortTable(2,'prob_tag')" class="num_col">전체 문제 수</th>
        </tr>
    </thead>
    <tbody>
        {% for tag in site.data.nojam_tag %}
            <tr>
                <td>{{ tag[0] }}</td>
                <td>
                {% assign count = 0 %}
                {% for doc in docs %}
                    {% if doc.solve_tag contains tag[0] %}
                        {% assign count = count | plus: 1 %}
                    {% endif %}
                {% endfor %}
                {{ count }}</td>
                <td>{{ tag[1] }}</td>
            </tr>
        {% endfor %}
    </tbody>
</table>
</details>

<details>
<summary>solved.ac 태그 통계</summary>
<table id="prob_solved_tag">
    <thead>
        <tr>
            <th onclick="sortTable(0,'prob_solved_tag')">태그</th>
            <th onclick="sortTable(1,'prob_solved_tag')" class="num_col">푼 문제 수</th>
            <th onclick="sortTable(2,'prob_solved_tag')" class="num_col">전체 문제 수</th>
        </tr>
    </thead>
    <tbody>
        {% for tag in site.data.nojam_solved_tag %}
            <tr>
                <td>{{ tag[0] }}</td>
                <td>
                {% assign count = 0 %}
                {% for doc in docs %}
                    {% if doc.solve_solved_tag contains tag[0] %}
                        {% assign count = count | plus: 1 %}
                    {% endif %}
                {% endfor %}
                {{ count }}</td>
                <td>{{ tag[1] }}</td>
            </tr>
        {% endfor %}
    </tbody>
</table>
</details>

---

쿼리 검색: <input type="text" id="search" /> <button onclick="query_search()">검색</button>

<table id="prob_search">
    <thead>
        <tr>
            <th onclick="sortTable(0,'prob_search')" class="num_col">번호</th>
            <th onclick="sortTable(1,'prob_search')">이름</th>
            <th onclick="sortTable(2,'prob_search')">언어</th>
            <th onclick="sortTable(3,'prob_search')">난이도</th>
            <th onclick="sortTable(4,'prob_search')">태그</th>
        </tr>
    </thead>
    <tbody>
    </tbody>
</table>

<script src="{{ site.baseurl }}/scripts/sort.js" charset="utf-8"></script>
<script src="{{ site.baseurl }}/scripts/nojam_search.js" charset="utf-8"></script>
