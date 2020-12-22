#include <stdio.h>
#include <queue>

int main() {
    int t, k, loc, tmp, tmp2;
    char input_c[2];
    long long input_i;
    std::priority_queue<long long> max, min, max_del, min_del;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        std::priority_queue<long long> max_tmp, min_tmp, max_del_tmp, min_del_tmp;
        std::swap(max, max_tmp);
        std::swap(min, min_tmp);
        std::swap(max_del, max_del_tmp);
        std::swap(min_del, min_del_tmp);

        scanf("%d\n", &k);

        for (int j = 0; j < k; j++) {
            scanf("%s %lld", input_c, &input_i);

            if (input_c[0] == 'D') {
                if (input_i == 1) {
                    if (!max.empty()) {
                        min_del.push(-max.top());
                        max.pop();

                        while (!min_del.empty() && !min.empty() && min.top() == min_del.top()) {
                            min.pop();
                            min_del.pop();
                        }
                        while (!max_del.empty() && !max.empty() && max.top() == max_del.top()) {
                            max.pop();
                            max_del.pop();
                        }
                    }
                } else {
                    if (!min.empty()) {
                        max_del.push(-min.top());
                        min.pop();

                        while (!min_del.empty() && !min.empty() && min.top() == min_del.top()) {
                            min.pop();
                            min_del.pop();
                        }
                        while (!max_del.empty() && !max.empty() && max.top() == max_del.top()) {
                            max.pop();
                            max_del.pop();
                        }
                    }
                }
            } else {
                min.push(-input_i);
                max.push(input_i);
            }
        }

        if (max.empty() || min.empty()) printf("EMPTY\n");
        else printf("%lld %lld\n", max.top(), -min.top());
    }
}