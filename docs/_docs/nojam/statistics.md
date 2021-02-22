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

    if (document.location.href.indexOf("orb-h.github.io") > -1) {
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

            // rating
            var user_data = await(await fetch("https://api.solved.ac/v2/users/show.json?id=orb_h")).json();
            user_data = user_data.result.user[0];
            prob_count = 100;
            rating = 0;
            class_exp = [0, 25, 50, 100, 150, 200, 210, 220, 230, 240, 250];
            for(i = 30; i >= 0; i--) {
                var count = Math.min(diff_data[i].solved, prob_count);
                prob_count -= count;
                rating += i * count;
            }
            rating += Math.round(175 * (1 - Math.pow(0.995, user_data.solved)));
            rating += Math.round(25 * (1 - Math.pow(0.9, user_data.vote_count)));
            rating += class_exp[user_data.class];
            document.getElementById("solved_rating").innerHTML = rating;
            solved_exp = [0, 30, 60, 90, 120, 150, 200, 300, 400, 500, 650, 800, 950, 1100, 1250, 1400, 1600, 1750, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2850, 2900, 2950, 3000, Infinity];
            solved_tier = 0;
            while (solved_exp[solved_tier] < rating) {
                solved_tier += 1;
            }
            solved_tier -= 1;
            if (solved_tier === 0) {
                document.getElementById("solved_rating").innerHTML = document.getElementById("solved_rating").innerHTML + ' / <span class="diff_unrated">Unrated</span>';
            } else if (solved_tier === 31) {
                document.getElementById("solved_rating").innerHTML = document.getElementById("solved_rating").innerHTML + ' / <span class="diff_master">Master</span>';
            } else {
                document.getElementById("solved_rating").innerHTML = document.getElementById("solved_rating").innerHTML + ' / <span class="diff_' + diffs[Math.floor((solved_tier - 1) / 5)] + '">' + diff_names[Math.floor((solved_tier - 1) / 5)] + ' ' + roman[(solved_tier - 1) % 5]; + '</span>';;
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
    }
</script>

{% assign docs = site.docs | where: "category", "백준" | where_exp: "item", "item.solve_exclude == nil" %}

각 표의 제목을 클릭하면 항목 별 정렬이 가능합니다. 전체 문제 수는 ~~2020-03-24 00:00 기준입니다.~~실시간입니다.

[![Solved.ac
프로필](http://mazassumnida.wtf/api/v2/generate_badge?boj=orb_h)](https://solved.ac/orb_h)
<br/><small><small>(↑ 크흑... 감사합니다 mori8, strawji02, malkoG, EatChangmyeong센세...)</small></small>

Solved.ac Rating: <span id="solved_rating"></span>

이 사이트에 등록된 맞춘 문제 개수: {{ docs.size }}개

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
            <td>
            {% assign num = 0 %}
            {% assign new_docs = docs | where_exp: "item", "item.solve_detail != nil" %}
            {% for doc in new_docs %}
            {% for info in doc.solve_detail %}
            {% if info.solve_lang == lang[0] %}
            {% assign num = num | plus: 1 %}
            {% endif %}
            {% endfor %}
            {% endfor %}
            {{ docs | where: "solve_lang", lang[0] | size | plus: num }}
            </td>
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
