---
title: ""
category: 최근
regenerate: true
---

{% assign doc = site.docs | where: "category", "백준" | sort: "solve_date" | last %}
<script>
  window.location.replace("{{ site.baseurl }}{{ doc.url }}");
</script>