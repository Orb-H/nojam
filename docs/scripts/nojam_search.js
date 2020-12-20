---
layout: _
regenerate: true
---

var db = JSON.parse(
    '{% assign docs = site.docs | where: "category", "백준" | where_exp: "item", "item.solve_exclude == nil" %}[{% for doc in docs %}{"num":{{ doc.solve_num }},"name":"{{ doc.solve_name }}","lang":"{{ doc.solve_lang }}","diff":{{ doc.solve_diff }},"date":"{{ doc.solve_date }}","share":"{{ doc.solve_share }}",{% endfor %} null],"exclude":{% if doc.solve_exclude != nil %}true{% else %}false {% endif %}}{% unless forloop.last %},{% endunless %}{% endfor %}]'
);
var lang_db = JSON.parse(
    '{ {% for lang in site.data.languages %}"{{ lang[0] }}":{ {% for item in lang[1] %}"{{ item[0] }}":"{{ item[1] }}"{% unless forloop.last %},{% endunless %}{% endfor %}}{% unless forloop.last %},{% endunless %}{% endfor %}}'
);
var diff_db = JSON.parse(
    '[{% for diff in site.data.nojam_diff %}{ {% for item in diff %}"{{ item[0] }}":"{{ item[1] }}"{% unless forloop.last %},{% endunless %}{% endfor %}}{% unless forloop.last %},{% endunless %}{% endfor %}]'
);

var cond_is = ["num", "lang", "diff", "share", "exclude"];
var cond_in = ["name"];

function get_db(queries) {
    f = function (item) {
        r = true;
        for (i = 0; i < queries.length; i++) {
            q = queries[i];
            if (cond_is.includes(q[0])) {
                r = r & (q[1] == item[q[0]]);
            } else if (cond_in.includes(q[0])) {
                r = r & item[q[0]].includes(q[1]);
            }
        }
        return r;
    };
    return db.filter(f);
}

function query_search() {
    var query = document.getElementById("search").value;
    var queries = query.split(",");
    for (i = 0; i < queries.length; i++) {
        queries[i] = queries[i].trim().split(":");
    }

    var qdb = get_db(queries);

    var table = document.getElementById("prob_search");
    var tbody = table.tBodies[0];
    tbody.innerHTML = "";

    for (i = 0; i < qdb.length; i++) {
        var row = tbody.insertRow();

        var num = row.insertCell();
        num.innerHTML = qdb[i]["num"];

        var name = row.insertCell();
        name.innerHTML =
            '<a href="{{ site.baseurl }}/nojam/' +
            qdb[i]["num"] +
            '">' +
            qdb[i]["name"] +
            "</a>";

        var lang = row.insertCell();
        var db_lang = lang_db[qdb[i]["lang"]];
        lang.innerHTML =
            '<span class="lang_' +
            db_lang["class"] +
            '">' +
            db_lang["name"] +
            "</span>";

        var diff = row.insertCell();
        var db_diff = diff_db[qdb[i]["diff"]];
        diff.innerHTML =
            '<span class="diff_' +
            db_diff["class"] +
            '">' +
            db_diff["sym_light"] +
            " " +
            db_diff["text"] +
            "</span>";
    }
}
