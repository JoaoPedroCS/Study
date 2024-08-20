lst = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens = ["", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred"]
word = ""
for i in range(1, 1000):
    hundreds = i // 100
    rbhun = i % 100
    tenz = (i%100) // 10
    rbtens = i % 10
    if hundreds == 0:
        if i <= 19:
            word += lst[i]
        elif i >= 20:
            word += tens[tenz]
            word += lst[rbtens]
    elif hundreds > 0:
        word += lst[hundreds]
        word += tens[10]
        if rbhun >= 20:
            word += "and"
            word += tens[tenz]
            word += lst[rbtens]
        elif rbhun <= 19:
            if rbhun != 0:
                word += "and"
            word += lst[rbhun]
            
word += "onethousand"
print(word)
print(len(word))