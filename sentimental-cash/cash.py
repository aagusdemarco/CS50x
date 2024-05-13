import cs50
c = 0
while True:
    c = cs50.get_float('Change owed: ')

    if c > 0:
        break
    else:
        print('Invalid input. ')

c = round(c * 100)
q = 25
d = 10
n = 5
p = 1
counter = 0

while c > 0:
    if c >= q:
        c = c - q
        counter += 1
    elif c >= d and c < q:
        c = c - d
        counter += 1
    elif c >= n and c < d:
        c = c - n
        counter += 1
    elif c >= p and c < n:
        c = c - p
        counter += 1
print(counter)
