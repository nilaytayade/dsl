string="This code creates a new list unique_list that contains only the elements from the original list my_list that are unique. It uses a list?"


def longest_word(string):
    string=string.split()
    max=0
    word=''

    for i in range(len(string)):
        if len(string[i])>max:
            max=len(string[i])
            word=string[i]


    print ("longest word=",word," with length=",max)        





def frequency(string,char):
    count=0
    for i in string:
        if char==i:
            count+=1

    print("frequency=",count)




def isPalindrom(string):
    if string==string[::1]:
        print("Palindrom")
    else:
        print("Not a Palindrom")    





def firstOccurence(main_string, substring):
    main_len = len(main_string)
    sub_len = len(substring)

    for i in range(main_len - sub_len + 1):
        if main_string[i:i + sub_len] == substring:
            return i

    return -1
    

def unique(string):
    ans=[]
    for i in string.split():
        if i in ans:
            continue
        else:
            ans.append(i)
    return(ans)


def wordCount(string):
        ulist=unique(string)
        count=0
        ans=[]

        for wordinlist in ulist:
            count=0
            for word  in string.split():
                if wordinlist.lower()==word.lower():
                    count+=1
            ans.append(f"{wordinlist}={count}")
        return ans        


longest_word(string)
frequency(string,'?')
print(firstOccurence(string,'This'))
print(wordCount(string))