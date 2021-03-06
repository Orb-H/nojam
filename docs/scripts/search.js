---
layout: _
---
var baseurl="{{ site.baseurl }}";

(function () {
	function getQueryVariable(variable) {
		var query = window.location.search.substring(1),
			vars = query.split("&");

		for (var i = 0; i < vars.length; i++) {
			var pair = vars[i].split("=");

			if (pair[0] === variable) {
				return decodeURIComponent(pair[1].replace(/\+/g, '%20')).trim();
			}
		}
	}

	function getPreview(query, content, previewLength) {
		previewLength = previewLength || (content.length * 2);

		var parts = query.split(" "),
			match = content.toLowerCase().indexOf(query.toLowerCase()),
			matchLength = query.length,
			preview;

		// Find a relevant location in content
		for (var i = 0; i < parts.length; i++) {
			if (match >= 0) {
				break;
			}

			match = content.toLowerCase().indexOf(parts[i].toLowerCase());
			matchLength = parts[i].length;
		}

		// Create preview
		if (match >= 0) {
			var start = match - (previewLength / 2),
				end = start > 0 ? match + matchLength + (previewLength / 2) : previewLength;

			preview = content.substring(start, end).trim();

			if (start > 0) {
				preview = "..." + preview;
			}

			if (end < content.length) {
				preview = preview + "...";
			}

			// Highlight query parts
			preview = preview.replace(new RegExp("(" + parts.join("|") + ")", "gi"), "<strong>$1</strong>");
		} else {
			// Use start of content if no match found
			preview = content.substring(0, previewLength).trim() + (content.length > previewLength ? "..." : "");
		}

		return preview;
	}

	function displaySearchResults(results, query) {
		var searchResultsEl = document.getElementById("search-results"),
			searchProcessEl = document.getElementById("search-process");

		if (results.length) {
			var resultsHTML = "";
			results.forEach(function (result) {
				var item = window.data[result.ref],
					contentPreview = getPreview(query, item.content, 170),
					titlePreview = getPreview(query, item.title);

				resultsHTML += "<li><h4><a href='"+baseurl + item.url.trim() + "'>" + titlePreview + "</a></h4><p><small>" + contentPreview + "</small></p></li>";
			});

			searchResultsEl.innerHTML = resultsHTML;
			searchProcessEl.innerText = "에 대한 검색 결과:";
		} else {
			searchResultsEl.style.display = "none";
			searchProcessEl.innerText = "에 대한 검색 결과 없음";
		}
	}

	var idx = new lunr.Index;

	idx.field("id");
	idx.field("title", {boost: 10});
	idx.field("content");
	idx.field("category");

	var query = decodeURIComponent((getQueryVariable("q") || "").replace(/\+/g, "%20")),
		searchQueryEl = document.getElementById("search-query"),
		searchInputEl = document.getElementById("search-input");

	searchInputEl.value = query;
	searchQueryEl.innerText = query;

	for (var key in window.data) {
		idx.add({
			'id': key,
			'title': window.data[key].title,
			'content': window.data[key].content,
			'category': window.data[key].category
		});
	}

	displaySearchResults(idx.search(query), query); // Hand the results off to be displayed
})();