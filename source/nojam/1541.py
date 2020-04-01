s = input().split('-')
m = sum(int(x) for x in s[0].split('+'))
for i in range(1, len(s)):
    m -= sum(int(x) for x in s[i].split('+'))
print(m)