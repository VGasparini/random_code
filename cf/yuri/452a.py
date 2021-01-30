import re
 
p=["espeon", "jolteon", "flareon", "umbreon", "leafeon", "glaceon", "sylveon","vaporeon"]
 
fodac=input()
s=input()
 
# procura via expressao regular o match do padrao s com i
x=[i for i in p if re.search(s,i)]
print(x.string)
