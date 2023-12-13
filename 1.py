cricket=input("cricket").split()
badminton=input("badminton").split()
football=input("football").split()
    

def unique(a):
    ans=[]
    for student in a:
        if student in ans:
            continue
        else:
            ans.append(student)
    
    return(ans)

def intersection(a,b):
    ans=[]
    for student in a:
        if student in b:
            ans.append(student)


    ans=unique(ans)
    print(ans)
    return 



def notBoth (a,b):
    ans = []
    for student in (a+b):
        if (a+b).count(student)==1:
            ans.append(student)
    ans=unique(ans)
    print(ans)
    return  


def neither(a,b):
    ans=[]
    for student in b :
        if (student in a):
            continue
        else:
            ans.append(student)
    ans=unique(ans)
    print(ans)
    print(len(ans))
    return  



def not_b(a,b):
    ans = []
    for student in a:
        if student in b:
            continue
        else:
            ans.append(student)

    ans=unique(ans)
    print(len(ans))
    print(ans)
    return  






unique([1,2,3,2,2,2,2,1,1,3,4,55,66,77,7,77,7])


intersection(cricket,badminton)
notBoth(cricket,badminton)
neither(cricket+badminton,football)
not_b(cricket+football,badminton)



