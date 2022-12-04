letters=[str(i) for i in range(10)] + list("abcdefghijklmnopqrstuvwxyz") + list("abcdefghijklmnopqrstuvwxyz".upper()) 

guess = [0]

def readInput():
    raw = input().split()
    if len(raw)==2: return 0
    return int(raw[2][1:])

def doGuess():
    global guess
    ans = "".join([letters[i] for i in guess])
    print(ans)

doGuess()
delay = readInput()
while delay==5:
    guess+=[0]
    doGuess()
    delay = readInput()

while (delay != 0):
    correct = (delay-14)//9
    guess[correct] += 1
    doGuess()
    delay = readInput()
