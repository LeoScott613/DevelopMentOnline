album=['Blinding Lights','In Your Eyes','Save your tears'];
for song in album:
    if(song!=album[-1]):
        print(song,end=',')
    else:
        print(song,end='')
        