while True:
    h = int(input('Height: '))

    if h >= 1 and h <= 8:
          break
    else:
          print('Invalid input' )

for i in range(h):
    for j in range(h - i - 1):
         print(' ', end='')
    for k in range(i + 1):
         print('#', end='')
    print()

