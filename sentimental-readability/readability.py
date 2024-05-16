import cs50

text = cs50.get_string('Text: ')
letters = 0
words = 1
sentences = 0

for letter in text:
    if letter.isalpha():
        letters += 1
    elif letter.isspace():
        words += 1
    elif letter == '.' or letter == '?' or letter == '!':
        sentences += 1

L = (letters / float(words)) * 100
S = (sentences / float(words)) * 100
index = 0.0588 * L - 0.296 * S - 15.8
index = round(index)

if index >= 16:
    print('Grade 16+\n')
elif index > 1 and index < 16:
    print(f'Grade {index}\n')
else:
    print('Before Grade 1')
