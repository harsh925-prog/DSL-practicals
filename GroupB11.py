#Harsh Gangadhar Chakote
#SE-II (Q)
#Roll No.: 31
#PRN: F23112034
'''
a) Write a pythonprogram to store roll numbers of student in array who attended
training program in random order. Write function for searching whether particular
student attended training program or not, using Linear search and Sentinel search.
b) Write a python program to store roll numbers of student array who attended training
program in sorted order. Write function for searching whether particular student
attended training program or not, using Binary search and Fibonacci search
'''

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def binary_search(arr, target, low, high):
    if low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            return binary_search(arr, target, mid + 1, high)
        else:
            return binary_search(arr, target, low, mid - 1)
    else:
        return -1
    
def sentinelSearch(arr, n, target):
    last = arr[n - 1]
    arr[n - 1] = target
    i = 0
    while (arr[i] != target):
        i += 1
    arr[n - 1] = last
    if ((i < n - 1) or (arr[n - 1] == target)):
        print(target, "is present at index", i)
    else:
        print("Element Not found")

def fibonacci_search(arr, n, target):
   offset = -1
   Fm2 = 0
   Fm1 = 1
   Fm = Fm2 + Fm1
   while (Fm < n):
      Fm2 = Fm1
      Fm1 = Fm
      Fm = Fm2 + Fm1
   while (Fm > 1):
      i = min(offset + Fm2, n - 1)
      if (arr[i] < target):
         Fm = Fm1
         Fm1 = Fm2
         Fm2 = Fm - Fm1
         offset = i
      elif (arr[i] > target):
         Fm = Fm2
         Fm1 = Fm1 - Fm2
         Fm2 = Fm - Fm1
      else:
         return i
   if (Fm1 == 1 and arr[offset + 1] == target):
      return offset + 1
   return -1


flag=1
while(flag==1):
   arr = []
   print("-MENU-")
   print("1.Unsorted search\n2.Sorted search\n3.Exit")
   opt=int(input("enter the option: "))
   if(opt==1):
       print("Which type of search?\na.Linear Search\nb.Sentinel Search\n")
      
   if(opt==2):
       print("Which type of search?\ni.Binary Search\nii.Fibonacci Search\n")
       
   opt2=input("enter your search option: ")
        
   if(opt==1):
       print("enter unsorted array for search.")
       
   elif(opt==2):
       print("enter sorted array for search.")
       
   else:
       print("Thanks for using this program!")
       flag=0
       break
   n=int(input("enter number of students:"))
   for i in range(0,n):
       rollno=int(input("enter roll no:"))
       arr.append(rollno)
       i+=1
   target = int(input("enter target to be found: "))
   print("\n")
   
       
   if(opt2=='a'):
       result = linear_search(arr, target)
       if result != -1:
           print(f"Linear Search: Element found at index {result}")
       else:
           print("Linear Search: Element not found")
       a = input("\n\nDo you want to continue (yes/no) :")
       if a == "yes":
            flag = 1
       else:
            flag = 0
            print("Thanks for using this program!")
       

   if(opt2=='b'):
       sentinelSearch(arr, n, target)
       a = input("\n\nDo you want to continue (yes/no) :")
       if a == "yes":
           flag = 1
       else:
           flag = 0
           print("Thanks for using this program!")
       

   if(opt2=='i'):
       result = binary_search(sorted(arr), target, 0, len(arr) - 1)
       if result != -1:
           print(f"Binary Search: Element found at index {result}")
       else:
           print("Binary Search: Element not found")
       a = input("\n\nDo you want to continue (yes/no) :")
       if a == "yes":
           flag = 1
       else:
           flag = 0
           print("Thanks for using this program!")
       

   if(opt2=='ii'):
       index = fibonacci_search(arr, n, target)
       if(index >= 0):
            print("The element is found at index: ", (index))
       else:
            print("Unsuccessful Search")
       a = input("\n\nDo you want to continue (yes/no) :")
       if a == "yes":
            flag = 1
       else:
            flag = 0
            print("Thanks for using this program!")
            
            
#Output:
'''
-MENU-
1.Unsorted search
2.Sorted search
3.Exit
enter the option: 1
Which type of search?
a.Linear Search
b.Sentinel Search

enter your search option: a
enter unsorted array for search.
enter number of students:6
enter roll no:2
enter roll no:9
enter roll no:3
enter roll no:7
enter roll no:5
enter roll no:1
enter target to be found: 7


Linear Search: Element found at index 3


Do you want to continue (yes/no) :yes
-MENU-
1.Unsorted search
2.Sorted search
3.Exit
enter the option: 1
Which type of search?
a.Linear Search
b.Sentinel Search

enter your search option: b
enter unsorted array for search.
enter number of students:6
enter roll no:2
enter roll no:9
enter roll no:7
enter roll no:1
enter roll no:6
enter roll no:4
enter target to be found: 1


1 is present at index 3


Do you want to continue (yes/no) :yes
-MENU-
1.Unsorted search
2.Sorted search
3.Exit
enter the option: 2
Which type of search?
i.Binary Search
ii.Fibonacci Search

enter your search option: i
enter sorted array for search.
enter number of students:6
enter roll no:2
enter roll no:4
enter roll no:5
enter roll no:6
enter roll no:7
enter roll no:8
enter target to be found: 6


Binary Search: Element found at index 3


Do you want to continue (yes/no) :yes
-MENU-
1.Unsorted search
2.Sorted search
3.Exit
enter the option: 2
Which type of search?
i.Binary Search
ii.Fibonacci Search

enter your search option: ii
enter sorted array for search.
enter number of students:6
enter roll no:1
enter roll no:2
enter roll no:4
enter roll no:5
enter roll no:7
enter roll no:8
enter target to be found: 6


Unsuccessful Search


Do you want to continue (yes/no) :no
Thanks for using this program!
'''