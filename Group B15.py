#Harsh Gangadhar Chakote
#SE-II (Q)
#Roll No.: 31
#PRN: F23112034
'''
Write a python program to store second year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using
a) Insertion sort
b) Shell Sort and display top five scores
'''

def Insertion_Sort(arr):
    n = len(arr) 
      
    if n <= 1:
        return arr 
 
    for i in range(1, n): 
        key = arr[i] 
        j = i-1
        while j >= 0 and key < arr[j]:  
            arr[j+1] = arr[j]  
            j -= 1
        arr[j+1] = key
    return arr

def Shell_Sort(arr):
    n = len(arr)
    gap = n//2
 
    while gap > 0:
        for i in range(gap,n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j-gap] >temp:
                arr[j] = arr[j-gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    return arr

# Function for displaying top five marks
def top_five_marks(marks):
    print("Top 5 Marks are : ")
    print(marks[-1:-6:-1], sep="\n")

#Main
marks=[]
n = int(input("Enter number of students whose marks are to be displayed : "))
print("Enter marks for",n,"students: ")
for i in range(0, n):
    ele = int(input())
    marks.append(ele)  # adding the element

print("The marks of",n,"students are : ")
print(marks)

flag=1
while flag==1:
    print("\n---------------MENU---------------")
    print("1. Insertion Sort of the marks")
    print("2. Shell Sort of the marks")
    print("3. Exit")
    ch=int(input("\n\nEnter your choice (from 1 to 3) : "))

    if ch==1:
        print(Insertion_Sort(marks))
        a=input("\nDo you want to display top marks from the list (y/n) : ")
        if a=='y':
            top_five_marks(marks)
        else:
            print("\nThanks for using this program!")
            flag=0

    elif ch==2:
        print(Shell_Sort(marks))
        a = input("\nDo you want to display top five marks from the list (y/n) : ")
        if a == 'y':
            top_five_marks(marks)
        else:
            print("\nThanks for using this program!")
            flag = 0

    elif ch==3:
        print("\nThanks for using this program!!")
        flag=0

    else:
        print("\nEnter a valid choice!!")
        print("\nThanks for using this program!!")
        flag=0
        
#Output:
'''
Enter number of students whose marks are to be displayed : 10
Enter marks for 10 students: 
19
56
4
3
5
7
2
5
86
45
The marks of 10 students are : 
[19, 56, 4, 3, 5, 7, 2, 5, 86, 45]

---------------MENU---------------
1. Insertion Sort of the marks
2. Shell Sort of the marks
3. Exit


Enter your choice (from 1 to 3) : 1
[2, 3, 4, 5, 5, 7, 19, 45, 56, 86]

Do you want to display top marks from the list (y/n) : y
Top 5 Marks are :
[86, 56, 45, 19, 7]

---------------MENU---------------
1. Insertion Sort of the marks
2. Shell Sort of the marks
3. Exit


Enter your choice (from 1 to 3) : 2
[2, 3, 4, 5, 5, 7, 19, 45, 56, 86]

Do you want to display top five marks from the list (y/n) : y
Top 5 Marks are :
[86, 56, 45, 19, 7]

---------------MENU---------------
1. Insertion Sort of the marks
2. Shell Sort of the marks
3. Exit


Enter your choice (from 1 to 3) : 3

Thanks for using this program!!
'''