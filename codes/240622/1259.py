while(True):
    s = input()
    if s=="0" : break
    slist = list(s)
    slist.reverse()
    rs = ''.join(slist)
    if s == rs:
        print("yes")
    else:
        print("no")