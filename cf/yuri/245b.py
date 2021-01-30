s = input()
if s[0] == 'h':
    prefix = 'http://'
    http = True
else:
    prefix = 'ftp://'
    http = False


if http:
    s = s[4:]
else:
    s = s[3:]

path = s[0]
s = s[1:].replace('ru','.ru/',1)

if s[-1] == '/':
    sufix = s[:-1]
else:
    sufix = s
    
print(prefix + path + sufix)
