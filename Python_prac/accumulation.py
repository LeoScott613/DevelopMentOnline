print('welcome to accumulator')
register=0
loop=1
while loop==1:
    add=input('')
    if(add=='to'):
        des=input('to what?:')
        des=int(des)
        for x in range(des):
            register+=x+1
        print('accumulation: '+str(register))
        break
    add=float(add)
    register+=add
    print('accumulation: '+str(register))
else:
    loop=1