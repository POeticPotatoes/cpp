from string import ascii_letters, digits


def get_input():
    s = input()
    if s == "ACCESS GRANTED":
        exit()
    return int(s.split()[2][1:])


def make_a_guess(s):
    print(s, flush=True)


if __name__ == "__main__":
    len = 1
    make_a_guess('a')
    while get_input() == 5:
        len += 1
        make_a_guess('a' * len)
    pwd = ['a'] * len
    poss = ascii_letters + digits
    for i in range(len):
        for gs in poss:
            pwd[i] = gs
            make_a_guess(''.join(pwd))
            tm = get_input()
            if tm > 5 + (i + 1) * 9:
                break
