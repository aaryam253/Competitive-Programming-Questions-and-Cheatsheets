import string
digs = string.digits + string.ascii_letters


def int2base(x, base):
    if x < 0:
        sign = -1
    elif x == 0:
        return digs[0]
    else:
        sign = 1

    x *= sign
    digits = []

    while x:
        digits.append(digs[int(x % base)])
        x = int(x / base)

    if sign < 0:
        digits.append('-')

    digits.reverse()

    return ''.join(digits)

TC = input()

for x in range(0, int(TC)):
    num, dec = [int(x) for x in input().split()]

    print (str(num) + " " + str(int2base(dec, 8)) + " " + str(dec) + " " + str(int2base(dec, 16)))
