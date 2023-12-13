arr=[1,2,3,4,5,6,7,8,9]

def linear(arr,key):
    for i in range(len(arr)):
        if arr[i]==key:
            return i
    return -1


def binary(arr,s,e,key):
    mid=(s+e)//2

    if arr[mid]==key:
        return mid
    elif arr[mid]>key:
        return binary(arr,s,mid-1,key)

    else:
        return binary(arr,mid+1,e,key)
    
    return -1


def sentinal (arr,key):

    arr.append(key)

    for i in range(len(arr)):
        if key==arr[i]:
            arr.pop()
            return i
        

    arr.pop()
    return -1    


def fibs(arr,key):
    n=len(arr)
    fib1,fib2=0,1
    fib3=1

    while n>=fib3:
        fib3=fib1+fib2 
        fib1=fib2
        fib2=fib3

    offset=-1

    while fib3>1:

        i=min(offset+fib1,n-1)

        if n==0:
            return -1
        
        elif arr[i]<key:
            fib3=fib2
            fib2=fib1
            fib1=fib3-fib2
            offset=i

        elif arr[i]>key:
            fib3=fib1
            fib2=fib2-fib1
            fib1=fib3-fib2


        else:
            return i
    
    if fib2==1 and arr[offset+1]==key:
        return offset+1
    else:
        return -1
    









print(linear(arr,5))
print(sentinal(arr,9))
print(fibs(arr,2))