def is_palindrome(n):
   temp = n
   rev = 0
   while(n > 0):
       dig = n % 10
       rev = rev * 10 + dig
       n = n // 10
   return temp == rev

l = tuple(range(100, 1000))
_l = []
for i in l:
    for j in l:
        _l.append(i * j)
l = tuple(set(_l))
l = filter(is_palindrome, l)
with open('102-result', 'wt', encoding="utf-8") as f:
    f.write(str(max(l)))
