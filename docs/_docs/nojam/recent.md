---
title: ""
category: 백준
---

{% assign doc = site.docs | where: "category", "백준" | sort: "solve_date" | last %}
<script>
  window.location.replace("{{ site.baseurl }}{{ doc.url }}");
</script>