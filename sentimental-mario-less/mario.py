h = int(input('Height: '))

if h < 1:
    for i in range(h):
        for j in range(h-i):
            print(' ')
        for k in range(i + 1):
            print('#')
        print('\n')
else:
    
