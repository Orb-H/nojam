---
title: 백준
category: 문제를 푼 흔적
order: 1
regenerate: true
---

백준이 제가 처음 접하게 된 PS 사이트인데요, 사실 접한 지는 몇 년 됐습니다. 하지만 PS에 큰 관심도 없고 해서 제대로 풀어보지도 않았고, 대학교 PS 동아리도 몇 번 해보면서 이 사이트를 쓰기도 했는데도 기록상으로는 몇 문제 없더군요. 그래서 ~~개인정보가 덜 들어있는~~ 계정을 새로 파서 뭔가 해보려고 했습니다만 역시 흥미가 제대로 잡히지 않았습니다. 이렇게 공들여서 페이지를 만들었는데 백준을 잘 안 해서 잘 쓸지 모르겠습니다.

~~여기서 쓰는 풀이는 직접적/구체적으로 작성하지 않고 두루뭉실하게, 간접적으로 적을 예정입니다. 구체적으로 적게 되면 이걸 그대로 코드로 베껴서 쓸 수 있기 때문이죠.~~아몰랑 그냥 생각나는거 다 쓸거임

이 페이지에는 제가 푼 백준 문제와 풀이 과정~~이라 쓰고 의식의 흐름이라 읽는 것~~을 포함하고 있는 페이지의 목록이 있고, 이 목록에는 해당 페이지로 가는 링크가 포함되어있습니다.

### 푼 문제 목록

<details>
    <summary>푼 문제 목록 펼치기/접기</summary>
    * 헤더를 클릭하면 항목 별 정렬이 가능합니다.
    <table id="problems">
        <thead>
            <tr>
                <th onclick="sortTable(0,'problems')" class="num_col">번호</th>
                <th onclick="sortTable(1,'problems')">이름</th>
                <th onclick="sortTable(2,'problems')">언어</th>
                <th onclick="sortTable(3,'problems')">난이도</th>
                <th onclick="sortTable(4,'problems')">날짜</th>
            </tr>
        </thead>
        <tbody>
            {% assign items = site.docs | where: 'category', "백준" | where_exp: "item", "item.solve_exclude == nil" | sort: "solve_num" %}
            {% for item in items %}
                <tr>
                    <td>{{ item.solve_num }}</td>
                    <td><a href="{{ item.url | relative_url }}">{{ item.solve_name }}</a></td>
                    {% if item.solve_detail %}
                    {% assign lang_array = item.solve_detail | map: "solve_lang" | uniq %}
                    <td>
                    {% for lang in lang_array %}
                    {% assign lang_ = site.data.languages[lang] %}
                    {% unless forloop.first %} / {% endunless %}<span class="lang_{{ lang_.class }}">{{ lang_.name }}</span>
                    {% endfor %}
                    </td>
                    {% else %}
                    {% assign lang = site.data.languages[item.solve_lang] %}
                    <td class="lang_{{ lang.class }}">{{ lang.name }}</td>
                    {% endif %}
                    {% assign diff = site.data.nojam_diff %}
                    {% assign num = item.solve_diff %}
                    <td class="diff_{{ diff[num].class }}"><div style="display: none;">{{ num | plus: 10 }}</div>{{ diff[num].sym_light }} {{ diff[num].text }}</td>
                    <td>{% if item.solve_detail %}{{ item.solve_detail[0].solve_date | date: "%Y-%m-%d %H:%M:%S" }}{% else %}{{ item.solve_date | date: "%Y-%m-%d %H:%M:%S" }}{% endif %}</td>
                </tr>
            {% endfor %}
        </tbody>
    </table>

</details>

<script src="{{ site.baseurl }}/scripts/sort.js" charset="utf-8">
