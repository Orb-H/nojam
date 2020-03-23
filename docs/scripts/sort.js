// Code from W3school.net
function sortTable(n) {
    var table, rows, switching, i, x, y, shouldSwitch, dir, switchcount = 0;
    var isnum;
    table = document.getElementById("problems");
    switching = true;
    dir = "asc";
    while (switching) {
        switching = false;
        rows = table.rows;
        isnum = rows[0].getElementsByTagName("TH")[n].classList.contains("num_col");
        for (i = 1; i < (rows.length - 1); i++) {
            shouldSwitch = false;
            x = rows[i].getElementsByTagName("TD")[n];
            y = rows[i + 1].getElementsByTagName("TD")[n];
            if (dir == "asc") {
                if (!isnum) {
                    if (x.innerHTML.toLowerCase() > y.innerHTML.toLowerCase()) {
                        shouldSwitch = true;
                        break;
                    }
                } else {
                    if (Number(x.innerHTML) > Number(y.innerHTML)) {
                        shouldSwitch = true;
                        break;
                    }
                }
            } else if (dir == "desc") {
                if (!isnum) {
                    if (x.innerHTML.toLowerCase() < y.innerHTML.toLowerCase()) {
                        shouldSwitch = true;
                        break;
                    }
                } else {
                    if (Number(x.innerHTML) < Number(y.innerHTML)) {
                        shouldSwitch = true;
                        break;
                    }
                }
            }
        }
        if (shouldSwitch) {
            rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
            switching = true;
            switchcount++;
        } else {
            if (switchcount == 0 && dir == "asc") {
                dir = "desc";
                switching = true;
            }
        }
    }
}