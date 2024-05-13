while(True):
    h = int(input('Height: '))

    if h < 1:
        print('Invalid Input. Please enter a positive integer. ')
    else:
        break
for i in range(h):
    for j in range(h - i):
        print(' ')
    for k in range(i - 1):
        print('#')
    print('\n')
