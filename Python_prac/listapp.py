# append a list
muslim=[1,2,3]
for i in muslim:
    print(i,end=" ")
print('')

muslim.append(4)
for i in muslim:
    print(i,end=" ")
print('')

nigger=[5,6,7,8]
muslim.extend(nigger)
for i in muslim:
    print(i,end=" ")
print('')