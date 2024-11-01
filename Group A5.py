#Harsh Gangadhar Chakote
#SE-II (Q)
#Roll No.: 31
#PRN: F23112034
'''
Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
'''

def isPalindrome(str):
    if(str==str[::-1]):
       print("It is a palindrome.")
    else:
       print("Not a palindrome.")

def longest_word(s):
    max_len = 0
    longest_word = ""
    word = ""
    for c in s:
        if c == " ":
            if len(word) > max_len:
                max_len = len(word)
                longest_word = word
            word = ""
        else:
            word += c
    if len(word) > max_len:
        max_len = len(word)
        longest_word = word
    return longest_word

def freq(str,ch):
     count=0
     for i in str:
        if(i==ch):
           count+=1
        continue
     print("Count of ",ch,"is:",count)         

def sub_index(s, sub):
    start = 0
    end = 0
    while start < len(s):
        if s[start+end] != sub[end]:
            start += 1
            end = 0
            continue
        end += 1
        if end == len(sub):
            return start
    return -1

def word_count(s):
    count_dict = {}
    word = ""
    for c in s:
        if c == " ":
            if word in count_dict:
                count_dict[word] += 1
            else:
                count_dict[word] = 1
            word = ""
        else:
            word += c
    if word in count_dict:
        count_dict[word] += 1
    else:
        count_dict[word] = 1
    return count_dict

str=input("Enter a sentence:")
flag=1
while(flag==1):
    print("------------MENU------------\n1.Longest length word\n2.Frequency of occurrence of particular character")
    print("3.Palindrome\n4.Find substring\n5.Count occurrences of each word")
    opt=int(input("Select an option:"))
    if(opt==1):
        print("Longest word: ",longest_word(str))
        a = input("\n\nDo you want to continue (yes/no) :")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")
    elif(opt==2):
        ch=input("Enter character:")
        freq(str,ch)
        a = input("\n\nDo you want to continue (yes/no) :")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")
    elif(opt==3):
        isPalindrome(str)
        a = input("\n\nDo you want to continue (yes/no) :")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")
    elif(opt==4):
        substring = input("Enter the substring:")
        print(sub_index(str,substring))
        a = input("\n\nDo you want to continue (yes/no) :")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")
    elif(opt==5):
        print(word_count(str))
        a = input("\n\nDo you want to continue (yes/no) :")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")
    else:
        flag=0
        print("Thanks for using this program!")
        
        
#Output:
'''
Enter a sentence:This is what this is
------------MENU------------
1.Longest length word
2.Frequency of occurrence of particular character
3.Palindrome
4.Find substring
5.Count occurrences of each word
Select an option:1
Longest word:  This


Do you want to continue (yes/no) :yes   
------------MENU------------
1.Longest length word
2.Frequency of occurrence of particular character
3.Palindrome
4.Find substring
5.Count occurrences of each word
Select an option:2
Enter character:t
Count of  t is: 2


Do you want to continue (yes/no) :yes
------------MENU------------
1.Longest length word
2.Frequency of occurrence of particular character
3.Palindrome
4.Find substring
5.Count occurrences of each word
Select an option:3
Not a palindrome.


Do you want to continue (yes/no) :yes
------------MENU------------
1.Longest length word
2.Frequency of occurrence of particular character
3.Palindrome
4.Find substring
5.Count occurrences of each word
Select an option:4
Enter the substring:is
2


Do you want to continue (yes/no) :yes
------------MENU------------
1.Longest length word
2.Frequency of occurrence of particular character
3.Palindrome
4.Find substring
5.Count occurrences of each word
Select an option:5
{'This': 1, 'is': 2, 'what': 1, 'this': 1}


Do you want to continue (yes/no) :no
Thanks for using this program!
'''