arr=[1,2,9,7,88,00,22,8,3,2]


def bubble(arr):
    n=len(arr)

    for i in range(n):
        for j in range(n-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]


    return arr

print(bubble(arr))

def selection(arr):
    n=len(arr)

    for i in range(n):
        min=i
        for j in range(i+1,n):
            if arr[j]<arr[min]:
                min=j
                arr[min],arr[i]=arr[i],arr[min]
    
    return arr


print(selection(arr))



def shell(arr):
    n=len(arr)
    gap=n//2

    while gap>0:

        for i in range(gap,n):
            temp=arr[i]
            j=i

            while j>=gap and arr[j-gap]>temp:
                arr[j]=arr[j-gap]
                j=j-gap


            arr[j]=temp

        gap//=2    


    return arr

print(shell(arr))



def insertion (arr):
    for i in range(1,len(arr)):
        key=arr[i]
        j=i-1

        while j>=0 and key<arr[j]:
            arr[j+1]=arr[j]
            j-=1

        arr[j+1]=key


    return arr

print(insertion(arr))    
