from random import randint

t = 1000
print(t);
for _ in range(t):
    print(5, 5)
    test = '.'*25
    for k in range(randint(1, 25)):
        a = randint(0, 24)
        while (test[a] == '#'): a = randint(0, 24)
        test = test[:a] + '#' + test[a+1:]
    for x in range(5):
        print(test[x*5:x*5+5])
