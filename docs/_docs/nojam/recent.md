---
title: ""
category: 최근
regenerate: true
---

{% assign latest_date = "0" %}
{% assign latest_num = 0 %}
{% assign docs = site.docs | where: "category", "백준" %}
{% for doc in docs %}
  {% if doc.solve_date %}
    {% if doc.solve_date > latest_date %}
      {% assign latest_date = doc.solve_date %}
      {% assign latest_num = doc.solve_num %}
    {% endif %}
  {% elsif doc.solve_detail %}
    {% if doc.solve_detail[0].solve_date > latest_date %}
      {% assign latest_date = doc.solve_detail[0].solve_date %}
      {% assign latest_num = doc.solve_num %}
    {% endif %}
  {% endif %}
{% endfor %}
<script>
  window.location.replace("{{ site.baseurl }}{{ site.url }}/nojam/{{ latest_num }}");
</script>