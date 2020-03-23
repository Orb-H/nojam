---
title: 백준
category: 문제를 푼 흔적
order: 1
---

백준이 제가 처음 접하게 된 PS 사이트인데요, 사실 접한 지는 몇 년 됐습니다. 하지만 PS에 큰 관심도 없고 해서 제대로 풀어보지도 않았고, 대학교 PS 동아리도 몇 번 해보면서 이 사이트를 쓰기도 했는데도 기록상으로는 몇 문제 없더군요. 그래서 ~~개인정보가 덜 들어있는~~ 계정을 새로 파서 뭔가 해보려고 했습니다만 역시 흥미가 제대로 잡히지 않았습니다. 이렇게 공들여서 페이지를 만들었는데 백준을 잘 안 해서 잘 쓸지 모르겠습니다.

이 페이지에는 제가 푼 백준 문제와 풀이 과정~~이라 쓰고 의식의 흐름이라 읽는 것~~을 포함하고 있는 페이지의 목록이 있고, 이 목록에는 해당 페이지로 가는 링크가 포함되어있습니다.

### 푼 문제 목록

<details>
    <summary>푼 문제 목록 펼치기/접기</summary>
    * 헤더를 클릭하면 항목 별 정렬이 가능합니다.
    <table id="problems">
        <thead>
            <tr>
                <th onclick="sortTable(0)">번호</th>
                <th onclick="sortTable(1)">이름</th>
                <th onclick="sortTable(2)">언어</th>
                <th onclick="sortTable(3)">난이도</th>
                <th onclick="sortTable(4)">날짜</th>
            </tr>
        </thead>
        <tbody>
            {% assign items = site.docs | where: 'category', "백준" %}
            {% for item in items %}
                <tr>
                    <td>{{ item.solve_num }}</td>
                    <td><a href="{{ item.url | relative_url }}">{{ item.solve_name }}</a></td>
                    <td>{{ item.solve_lang.name }}</td>
					<td><div style="display: none;">{{ item.solve_diff }}</div>
					{% assign rank = item.solve_diff | minus: 1 | divided_by: 5 %}
                    {% case rank %}
                        {% when 0 %}
							{% assign diff = item.solve_diff %}
							<b class="diff_ruby">&#{{ diff | plus: 9311 }}; Ruby
                        {% when 1 %}
							{% assign diff = item.solve_diff | minus: 5 %}
							<b class="diff_diamond">&#{{ diff | plus: 9311 }}; Diamond
                        {% when 2 %}
							{% assign diff = item.solve_diff | minus: 10 %}
							<b class="diff_platinum">&#{{ diff | plus: 9311 }}; Platinum
                        {% when 3 %}
							{% assign diff = item.solve_diff | minus: 15 %}
							<b class="diff_gold">&#{{ diff | plus: 9311 }}; Gold
                        {% when 4 %}
							{% assign diff = item.solve_diff | minus: 20 %}
							<b class="diff_silver">&#{{ diff | plus: 9311 }}; Silver
                        {% when 5 %}
        					{% assign diff = item.solve_diff | minus: 25 %}
							<b class="diff_bronze">&#{{ diff | plus: 9311 }}; Bronze
                        {% else %}
							<b class="diff_unrated">&#9471; Unrated
                    {% endcase %}

					{% case diff %}
						{% when 1 %}
							I
						{% when 2 %}
							II
						{% when 3 %}
							III
						{% when 4 %}
							IV
						{% when 5 %}
							V
					{% endcase %}
					</b>
					</td>
                    <td>{{ item.solve_date | date: "%Y-%m-%d %H:%M:%S" }}</td>
                </tr>
            {% endfor %}
        </tbody>
    </table>
</details>

<script>
// Code from W3school.net
function sortTable(n) {
  var table, rows, switching, i, x, y, shouldSwitch, dir, switchcount = 0;
  table = document.getElementById("problems");
  switching = true;
  dir = "asc";
  while (switching) {
    switching = false;
    rows = table.rows;
    for (i = 1; i < (rows.length - 1); i++) {
      shouldSwitch = false;
      x = rows[i].getElementsByTagName("TD")[n];
      y = rows[i + 1].getElementsByTagName("TD")[n];
      if (dir == "asc") {
        if (x.innerHTML.toLowerCase() > y.innerHTML.toLowerCase()) {
          shouldSwitch = true;
          break;
        }
      } else if (dir == "desc") {
        if (x.innerHTML.toLowerCase() < y.innerHTML.toLowerCase()) {
          shouldSwitch = true;
          break;
        }
      }
    }
    if (shouldSwitch) {
      rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
      switching = true;
      switchcount ++;
    } else {
      if (switchcount == 0 && dir == "asc") {
        dir = "desc";
        switching = true;
      }
    }
  }
}
</script>
