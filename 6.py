arr = [1, 2, 9, 7, 88, 0, 22, 8, 3, 2]

def partition(arr, start, end):
    pivot = arr[end]
    i = start - 1

    for j in range(start, end):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    # Swap the pivot to its correct position
    i+=1
    arr[i], arr[end] = arr[end], arr[i]

    return i 

def quicksort(arr, start, end):

    if start >= end:
        return

    pivot = partition(arr, start, end)

    quicksort(arr, pivot + 1, end)
    quicksort(arr, start, pivot - 1)

print("Original array:", arr)
quicksort(arr, 0, len(arr) - 1)
print("Sorted array:", arr)
