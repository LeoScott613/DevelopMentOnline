from re import match
# matched
# regex='MyName'
# string='MyName'

# mismatch
regex='MyName'
string='myname'

if match(regex,string,0):
    print('matched')
else:
    print('mismatch')