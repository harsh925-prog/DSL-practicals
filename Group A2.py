#Harsh Gangadhar Chakote
#SE-II (Q)
#Roll No.: 31
#PRN: F23112034
'''
Write a python program to store marks stored in subject "Fundamentals of Data Structure" by
N students in the class. Write functions to compute following:
1. The average score of the class.
2. Highest score and lowest score of the class.
3. Count of students who were absent for the test.
4. Display mark with highest frequency.
'''
num=int (input("Enter number of students:"))
marks=[]
for i in range(0,num):
    marks.append(int(input('Enter marks of student:')))
print(marks)    
#average of class
def avg(sum,num):
    sum=0
    for i in range(0,num):
        sum+=marks[i]
        i+=1
    print('Average of class is: ',sum/num)  
avg(sum,num)

#highest and lowest
def maxm(num):
    c=0
    for j in range(0,num):
        if(marks[j]>c):
           c=marks[j]
           j+=1
    print('Maximum of the class:',c) 
def minm(num):
    d=marks[num-1]
    for j in range(0,num):
        if(marks[j]<d):
            d=marks[j]
            j+=1
    print('Minimum of the class:',d)      
maxm(num)
minm(num)    

# absent students
def absent(marks):
    count=0
    for i in range(0,num):
        if(marks[i]<0):
            count+=1
            i+=1
    print('Count of Absent studemts is:',count)    
absent(marks)

#Highest freq
def display_highest_frequency(marks):
    frequency = {}
    for mark in marks:
        if mark != -1:
            frequency[mark] = frequency.get(mark, 0) + 1
    max_frequency = max(frequency.values())
    highest_frequency_marks = [mark for mark, freq in frequency.items() if freq == max_frequency]
    return highest_frequency_marks 
print("Marks with highest frequency: ",display_highest_frequency(marks))          

#Output:
"""
Enter number of students:10
Enter marks of student:88
Enter marks of student:98
Enter marks of student:78
Enter marks of student:98
Enter marks of student:97
Enter marks of student:97
Enter marks of student:97
Enter marks of student:97
Enter marks of student:100
Enter marks of student:93
[88, 98, 78, 98, 97, 97, 97, 97, 100, 93]
Average of class is:  94.3
Maximum of the class: 100
Minimum of the class: 78
Count of Absent studemts is: 0
Marks with highest frequency: [97]
"""