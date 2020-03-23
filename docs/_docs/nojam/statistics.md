---
title: 백준
category: 통계
---

**난이도**와 **푼 문제 수**를 클릭하면 정렬이 가능합니다. 전체 문제 수는 2020-03-23 14:10 기준입니다.

<table id="problems">
    <thead>
        <tr>
            <th onclick="sortTable(0)">난이도</th>
            <th onclick="sortTable(1)" class="num_col">푼 문제 수</th>
            <th onclick="sortTable(2)" class="num_col">전체 문제 수</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td class="diff_unrated"><div style="display:none;">31</div>&#65311; Unrated</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 0 | size }}</td>
            <td>6897</td>
        </tr>
        <tr>
            <td class="diff_bronze"><div style="display:none;">30</div>&#9316; Bronze V</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 30 | size }}</td>
            <td>58</td>
        </tr>
        <tr>
            <td class="diff_bronze"><div style="display:none;">29</div>&#9315; Bronze IV</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 29 | size }}</td>
            <td>85</td>
        </tr>
        <tr>
            <td class="diff_bronze"><div style="display:none;">28</div>&#9314; Bronze III</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 28 | size }}</td>
            <td>337</td>
        </tr>
        <tr>
            <td class="diff_bronze"><div style="display:none;">27</div>&#9313; Bronze II</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 27 | size }}</td>
            <td>534</td>
        </tr>
        <tr>
            <td class="diff_bronze"><div style="display:none;">26</div>&#9312; Bronze I</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 26 | size }}</td>
            <td>391</td>
        </tr>
        <tr>
            <td class="diff_silver"><div style="display:none;">25</div>&#9316; Silver V</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 25 | size }}</td>
            <td>359</td>
        </tr>
        <tr>
            <td class="diff_silver"><div style="display:none;">24</div>&#9315; Silver IV</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 24 | size }}</td>
            <td>293</td>
        </tr>
        <tr>
            <td class="diff_silver"><div style="display:none;">23</div>&#9314; Silver III</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 23 | size }}</td>
            <td>389</td>
        </tr>
        <tr>
            <td class="diff_silver"><div style="display:none;">22</div>&#9313; Silver II</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 22 | size }}</td>
            <td>302</td>
        </tr>
        <tr>
            <td class="diff_silver"><div style="display:none;">21</div>&#9312; Silver I</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 21 | size }}</td>
            <td>436</td>
        </tr>
        <tr>
            <td class="diff_gold"><div style="display:none;">20</div>&#9316; Gold V</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 20 | size }}</td>
            <td>442</td>
        </tr>
        <tr>
            <td class="diff_gold"><div style="display:none;">19</div>&#9315; Gold IV</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 19 | size }}</td>
            <td>450</td>
        </tr>
        <tr>
            <td class="diff_gold"><div style="display:none;">18</div>&#9314; Gold III</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 18 | size }}</td>
            <td>410</td>
        </tr>
        <tr>
            <td class="diff_gold"><div style="display:none;">17</div>&#9313; Gold II</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 17 | size }}</td>
            <td>422</td>
        </tr>
        <tr>
            <td class="diff_gold"><div style="display:none;">16</div>&#9312; Gold I</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 16 | size }}</td>
            <td>434</td>
        </tr>
        <tr>
            <td class="diff_platinum"><div style="display:none;">15</div>&#9316; Platinum V</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 15 | size }}</td>
            <td>421</td>
        </tr>
        <tr>
            <td class="diff_platinum"><div style="display:none;">14</div>&#9315; Platinum IV</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 14 | size }}</td>
            <td>414</td>
        </tr>
        <tr>
            <td class="diff_platinum"><div style="display:none;">13</div>&#9314; Platinum III</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 13 | size }}</td>
            <td>424</td>
        </tr>
        <tr>
            <td class="diff_platinum"><div style="display:none;">12</div>&#9313; Platinum II</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 12 | size }}</td>
            <td>379</td>
        </tr>
        <tr>
            <td class="diff_platinum"><div style="display:none;">11</div>&#9312; Platinum I</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 11 | size }}</td>
            <td>354</td>
        </tr>
        <tr>
            <td class="diff_diamond"><div style="display:none;">10</div>&#9316; Diamond V</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 10 | size }}</td>
            <td>334</td>
        </tr>
        <tr>
            <td class="diff_diamond"><div style="display:none;">09</div>&#9315; Diamond IV</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 9 | size }}</td>
            <td>324</td>
        </tr>
        <tr>
            <td class="diff_diamond"><div style="display:none;">08</div>&#9314; Diamond III</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 8 | size }}</td>
            <td>228</td>
        </tr>
        <tr>
            <td class="diff_diamond"><div style="display:none;">07</div>&#9313; Diamond II</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 7 | size }}</td>
            <td>166</td>
        </tr>
        <tr>
            <td class="diff_diamond"><div style="display:none;">06</div>&#9312; Diamond I</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 6 | size }}</td>
            <td>152</td>
        </tr>
        <tr>
            <td class="diff_ruby"><div style="display:none;">05</div>&#9316; Ruby V</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 5 | size }}</td>
            <td>121</td>
        </tr>
        <tr>
            <td class="diff_ruby"><div style="display:none;">04</div>&#9315; Ruby IV</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 4 | size }}</td>
            <td>60</td>
        </tr>
        <tr>
            <td class="diff_ruby"><div style="display:none;">03</div>&#9314; Ruby III</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 3 | size }}</td>
            <td>33</td>
        </tr>
        <tr>
            <td class="diff_ruby"><div style="display:none;">02</div>&#9313; Ruby II</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 2 | size }}</td>
            <td>11</td>
        </tr>
        <tr>
            <td class="diff_ruby"><div style="display:none;">01</div>&#9312; Ruby I</td>
            <td>{{ site.docs | where: "category", "백준" | where: "solve_diff", 1 | size }}</td>
            <td>6</td>
        </tr>
    </tbody>
</table>

<script src="{{ site.baseurl }}/scripts/sort.js" charset="utf-8">
