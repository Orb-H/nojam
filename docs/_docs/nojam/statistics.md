---
title: 백준
category: 통계
regenerate: true
---

<script>
    var diffs = [
        "bronze",
        "silver",
        "gold",
        "platinum",
        "diamond",
        "ruby"
    ];
    var diff_names = [
        "Bronze",
        "Silver",
        "Gold",
        "Platinum",
        "Diamond",
        "Ruby"
    ];
    var roman = ["V", "IV", "III", "II", "I"];

    window.onload = async function(){
        // difficulty
        var diff_data = await(await fetch("https://api.solved.ac/v2/users/problem_stats.json?id=orb_h")).json();
        var prob_diff = document.getElementById("prob_diff").children[1];

        diff_data = diff_data.result;

        for(i = 0; i < diff_data.length; i++){
            var row = prob_diff.insertRow(-1);
            var data = diff_data[i];

            if(diff_data[i].level === 0){
                row.insertCell(-1).innerHTML = '<div class="diff_unrated"><span style="display:none;">41</span>&#65311; Unrated</div>';
            }else{
                row.insertCell(-1).innerHTML = '<div class="diff_' + diffs[Math.floor((data.level - 1) / 5)] + '"><span style="display:none;">' + (41 - diff_data[i].level) + '</span> ' + String.fromCharCode(9311 + (5 - ((data.level - 1) % 5))) + ' ' + diff_names[Math.floor((data.level - 1) / 5)] + ' ' + roman[(data.level - 1) % 5]; + '</div>';
            }
            row.insertCell(-1).innerHTML = diff_data[i].problems;
            row.insertCell(-1).innerHTML = diff_data[i].solved;
            row.insertCell(-1).innerHTML = diff_data[i].solved_exp_sum;
        }

        // tag
        var tag_data = await(await fetch("https://api.solved.ac/v2/users/top_tags.json?id=orb_h")).json();
        var prob_tag = document.getElementById("prob_tag").children[1];

        tag_data = tag_data.result;

        for(i = 0; i < tag_data.length; i++){
            var row = prob_tag.insertRow(-1);

            row.insertCell(-1).innerHTML = tag_data[i].full_name_ko;
            row.insertCell(-1).innerHTML = tag_data[i].solved;
            row.insertCell(-1).innerHTML = tag_data[i].solved_exp_sum;
        }
    }
</script>

{% assign docs = site.docs | where: "category", "백준" | where_exp: "item", "item.solve_exclude == nil" %}

각 표의 제목을 클릭하면 항목 별 정렬이 가능합니다. 전체 문제 수는 ~~2020-03-24 00:00 기준입니다.~~실시간입니다.

[![Solved.ac
프로필](http://mazassumnida.wtf/api/v2/generate_badge?boj=orb_h)](https://solved.ac/orb_h)
<br/><small>(↑ 크흑... 감사합니다 mori8, strawji02, malkoG, EatChangmyeong센세...)</small>

<details>
<summary>난이도 통계</summary>
<table id="prob_diff">
    <thead>
        <tr>
            <th onclick="sortTable(0,'prob_diff')">난이도</th>
            <th onclick="sortTable(1,'prob_diff')" class="num_col">전체 문제 수</th>
            <th onclick="sortTable(2,'prob_diff')" class="num_col">푼 문제 수</th>
            <th onclick="sortTable(3,'prob_diff')" class="num_col">얻은 경험치</th>
        </tr>
    </thead>
    <tbody>
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
<summary>태그 통계</summary>
<table id="prob_tag">
    <thead>
        <tr>
            <th onclick="sortTable(0,'prob_tag')">태그</th>
            <th onclick="sortTable(1,'prob_tag')" class="num_col">푼 문제 수</th>
            <th onclick="sortTable(2,'prob_tag')" class="num_col">얻은 경험치</th>
        </tr>
    </thead>
    <tbody>
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
        </tr>
    </thead>
    <tbody>
    </tbody>
</table>

<script src="{{ site.baseurl }}/scripts/sort.js" charset="utf-8"></script>
<script src="{{ site.baseurl }}/scripts/nojam_search.js" charset="utf-8"></script>
