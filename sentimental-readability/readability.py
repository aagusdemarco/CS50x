import cs50

text = cs50.get_string('Text: ')
length = len(text)
letters = 0
words = 1
sentences = 0

for letter in text:

    if letter.isalpha():
        letters += 1
    elif letter.isspace():
        words += 1
    elif letter == '.' or c == '?' or c == '!':
        sentences += 1

L = (letters / float(words)) * 100
S = (sentences / float(words)) * 100
index = 0.0588 * L - 0.296 * S - 15.8
index = round(index)

if index >= 16:
    print('Grade 16+')
elif index < 1:
    print('Before Grade 1')
else:
    print(f'Grade {index}')

