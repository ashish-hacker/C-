def convert(m):
    words = {1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five',
             6: 'six', 7: 'seven', 8: 'eight', 9: 'nine', 10: 'ten',
             11: 'eleven', 12: 'twelve', 13: 'thirteen', 14: 'fourteen',
             15: 'fifteen', 16: 'sixteen', 17: 'seventeen', 18: 'eighteen',
             19: 'nineteen', 20: 'twenty', 30: 'thirty', 40: 'forty',
             50: 'fifty', 60: 'sixty', 70: 'seventy', 80: 'eighty',
             90: 'ninety', 0: 'zero'}
    if m in words.keys():
        result = words[m]
        # print(result)
    else:
        result = words[m-m % 10] + words[m % 10].lower()
    return result


def count(str):
    s = 0
    s += str.count('a')
    s += str.count('e')
    s += str.count('i')
    s += str.count('o')
    s += str.count('u')
    return s


def main():
    n = int(input())
    ar = input()
    ar = [int(i) for i in ar.split(' ')]

    ar1 = []
    for item in ar:
        x = convert(item)
        ar1.append(x)

    sum1 = 0
    for i in ar1:
        sum1 += count(i)

    # print(sum1)
    dic = []
    pair = 0
    for item in ar:
        dic.append(sum1 - item)

    for i in dic:
        if i in ar:
            # print(i)
            pair += 1
    k = pair//2
    # print(k)
    item = convert(k)
    print(item)
