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
    <table id="problems">
        <thead>
            <tr>
                <th onclick="sortTable(0)">번호</th>
                <th onclick="sortTable(1)">이름</th>
                <th onclick="sortTable(2)">언어</th>
                <th onclick="sortTable(3)">날짜</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>1000</td>
                <td>asdf</td>
                <td>Python</td>
                <td>2020-03-21 23:42:47</td>
            </tr>
            <tr>
                <td>1001</td>
                <td>fdsa</td>
                <td>C++</td>
                <td>2020-03-21 23:42:57</td>
            </tr>
            <!--{% assign items = site.docs | where: 'category', "nojam" %}
            {% for item in items %}
                <tr>
                </tr>
            {% endfor %}-->
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
