//return sort algorithm
function s(dir, isnum) {
    return function (a, b) {
        a = isnum === 1 ? Number(a) : a;
        b = isnum === 1 ? Number(b) : b;
        if (a === b) {
            return 0;
        }
        return (a > b ? 1 : -1) * (dir === 1 ? 1 : -1);
    };
}

function sortTable(n, id) {
    var table = document.getElementById(id);
    var rows = table.rows;
    var dir = 0;
    var isnum = rows[0].getElementsByTagName("TH")[n].classList.contains("num_col") ? 1 : 0;
    var so = s(1, isnum);

    for (i = 1; i < rows.length - 1; i++) {
        if (so(rows[i].cells[n].textContent, rows[i + 1].cells[n].textContent) > 0) {
            console.log(i + " " + rows[i].cells[n].textContent + " " + rows[i + 1].cells[n].textContent + " " + (rows[i].cells[n].textContent > rows[i + 1].cells[n].textContent));
            dir = 1;
            break;
        }
    }

    so = s(dir, isnum);

    for (i = 1; i < rows.length - 1; i++) {
        var m = i;
        for (j = i + 1; j < rows.length; j++) {
            var x = rows[m].cells[n].textContent;
            var y = rows[j].cells[n].textContent;
            if (so(x, y) > 0) {
                m = j;
            }
        }
        if (m !== i) {
            rows[i].parentNode.insertBefore(rows[m], rows[i]);
        }
    }
}