//Harsh Gangadhar Chakote
//SE-II (Q)
//Roll No.: 31
//PRN: F23112034
/*
Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set
B of students like butterscotch ice-cream. Write C++ program to store two sets using
linked list. compute and displaya) Set of students who like both vanilla and butterscotch
b) Set of students who like either vanilla or butterscotch or not both
c) Number of students who like neither vanilla nor butterscotch
*/

#include <iostream>
using namespace std;
struct node{
   int roll;
   struct node *next;
};
class info{
   node *head1 = NULL, *temp1 = NULL, *head2 = NULL, *temp2 = NULL, *head = NULL, *temp = NULL, *h1 = NULL, *head3 = NULL, *temp3 = NULL;
   int c, i, f, j, k;
public:
   node *create();
   void insert();
   void allstud();
   void vanila();
   void butters();
   void uice();
   void nice();
   void notice();
   void display();
};
node *info::create(){
   node *p = new (struct node);
   cout << "Enter student roll no: ";
   cin >> c;
   p->roll = c;
   p->next = NULL;
   return p;
}
void info::insert(){
   node *p = create();
   if (head == NULL){
      head = p;
   }
   else{
      temp = head;
      while (temp->next != NULL){
         temp = temp->next;
      }
      temp->next = p;
   }
}
void info::display(){
   temp = head;
   while (temp->next != NULL){
      cout << "\n"
           << temp->roll;
      temp = temp->next;
   }
   cout << "\n"
        << temp->roll;
}
void info::allstud(){
   cout << "enter no. of students";
   cin >> k;
   head = NULL;
   for (i = 0; i < k; i++){
      insert();
      h1 = head;
   }
   display();
   head = NULL;
}
void info::vanila(){
   cout << "Enter no. of  students who like vanilla: ";
   cin >> k;
   head = NULL;
   for (i = 0; i < k; i++){
      insert();
      head1 = head;
   }
   display();
   head = NULL;
}
void info::butters(){
   cout << "Enter no. of students who like butterscotch: ";
   cin >> j;
   head = NULL;
   for (i = 0; i < j; i++){
      insert();
      head2 = head;
   }
   display();
   head = NULL;
}
void info::uice(){
   cout << "Students who like vanilla or butterscotch: ";
   temp1 = head1;
   while (temp1 != NULL){
      node *p = new (struct node);
      p->roll = temp1->roll;
      p->next = NULL;
      if (head3 == NULL){
         head3 = p;
      }
      else{
         temp3 = head3;
         while (temp3->next != NULL){
            temp3 = temp3->next;
         }
         temp3->next = p;
      }
      temp1 = temp1->next;
   }
   temp2 = head2;
   while (temp2 != NULL){
      f = 0;
      temp1 = head1;
      while (temp1 != NULL){
         if (temp2->roll == temp1->roll){
            f = 1;
         }
         temp1 = temp1->next;
      }
      if (f == 0){
         node *p = new (struct node);
         p->roll = temp2->roll;
         p->next = NULL;
         if (head3 == NULL){
            head3 = p;
         }
         else{
            temp3 = head3;
            while (temp3->next != NULL){
               temp3 = temp3->next;
            }
            temp3->next = p;
         }
      }
      temp2 = temp2->next;
   }
   temp3 = head3;
   while (temp3->next != NULL){
      cout << "\n"
           << temp3->roll;
      temp3 = temp3->next;
   }
   cout << "\n"
        << temp3->roll;
}
void info::nice(){
   cout << "\nStudents who like both vanilla and butterscotch\n";
   temp1 = head1;
   while (temp1 != NULL){
      temp2 = head2;
      while (temp2 != NULL){
         if (temp1->roll == temp2->roll){
            cout << "\n"
                 << temp1->roll;
         }
         temp2 = temp2->next;
      }
      temp1 = temp1->next;
   }
}
void info::notice(){
   cout << "\nStudents who like neither vanila nor butterscotch\n";
   temp = h1;
   while (temp != NULL){
      temp3 = head3;
      f = 0;
      while (temp3 != NULL){
         if (temp->roll == temp3->roll){
            f = 1;
         }
         temp3 = temp3->next;
      }
      if (f == 0){
         cout << "\n"
              << temp->roll;
      }
      temp = temp->next;
   }
}
int main(){
   info s;
   int i;
   char ch;
   do{
      cout << "\n Choose the options";
      cout << "\n  1. To enter all students rollno  ";
      cout << "\n  2. To enter the rollno of student who like vanila";
      cout << "\n  3.  To enter the rollno of student who like butterscotch";
      cout << "\n  4.  To display the rollno of student who like vanila or butterscotch";
      cout << "\n  7.  To display the rollno of student who like both vanila and butterscotch ";
      cout << "\n  8.  To display the rollno of student who neither like vanila nor butterscotch";
      cout << "\n Choice: ";
      cin >> i;
      switch (i){
      case 1:
         s.allstud();
         break;
      case 2:
         s.vanila();
         break;
      case 3:
         s.butters();
         break;
      case 4:
         s.uice();
         break;
      case 5:
         s.nice();
         break;
      case 6:
         s.notice();
         break;
      default:
         cout << "\n Wrong choice";
      }
      cout << "\n Do you want to continue enter y/Y : ";
      cin >> ch;
   } while (ch == 'y' || ch == 'Y');
   return 0;
}

//Output:
/*
Choose the options
1. To enter all students rollno
2. To enter the rollno of student who like vanila
3. To enter the rollno of student who like butterscotch
4. To display the rollno of student who like vanila or butterscotch
5. To display the rollno of student who like only vanila
6. To display the rollno of student who like only butterscotch
7. To display the rollno of student who like both vanila and butterscotch
8. To display the rollno of student who neither like vanila nor butterscotch
Choice: 1
enter no. of students10
Enter student roll no: 1
Enter student roll no: 2
Enter student roll no: 3
Enter student roll no: 4
Enter student roll no: 5
Enter student roll no: 6
Enter student roll no: 7
Enter student roll no: 8
Enter student roll no: 9
Enter student roll no: 10
1
2
3
4
5
6
7
8
9
10
Do you want to continue enter y/Y : y
Choose the options
1. To enter all students rollno
2. To enter the rollno of student who like vanila
3. To enter the rollno of student who like butterscotch
4. To display the rollno of student who like vanila or butterscotch
5. To display the rollno of student who like only vanila
6. To display the rollno of student who like only butterscotch
7. To display the rollno of student who like both vanila and butterscotch
8. To display the rollno of student who neither like vanila nor butterscotch
Choice: 2
Enter no. of students who like vanilla: 6
Enter student roll no: 2
Enter student roll no: 4
Enter student roll no: 5
Enter student roll no: 6
Enter student roll no: 8
Enter student roll no: 9
2
4
5
6
8
9
Do you want to continue enter y/Y : y
Choose the options
1. To enter all students rollno
2. To enter the rollno of student who like vanila
3. To enter the rollno of student who like butterscotch
4. To display the rollno of student who like vanila or butterscotch
5. To display the rollno of student who like only vanila
6. To display the rollno of student who like only butterscotch
7. To display the rollno of student who like both vanila and butterscotch
8. To display the rollno of student who neither like vanila nor butterscotch
Choice: 3
Enter no. of students who like butterscotch: 4
Enter student roll no: 7
Enter student roll no: 8
Enter student roll no: 9
Enter student roll no: 10
7
8
9
10
Do you want to continue enter y/Y : y
Choose the options
1. To enter all students rollno
2. To enter the rollno of student who like vanila
3. To enter the rollno of student who like butterscotch
4. To display the rollno of student who like vanila or butterscotch
5. To display the rollno of student who like only vanila
6. To display the rollno of student who like only butterscotch
7. To display the rollno of student who like both vanila and butterscotch
8. To display the rollno of student who neither like vanila nor butterscotch
Choice: 4
Students who like vanilla or butterscotch:
2
4
5
6
8
9
7
10
Do you want to continue enter y/Y : y
Choose the options
1. To enter all students rollno
2. To enter the rollno of student who like vanila
3. To enter the rollno of student who like butterscotch
4. To display the rollno of student who like vanila or butterscotch
5. To display the rollno of student who like only vanila
6. To display the rollno of student who like only butterscotch
7. To display the rollno of student who like both vanila and butterscotch
8. To display the rollno of student who neither like vanila nor butterscotch
Choice: 5
Students who like only vanilla
2
4
5
6
Do you want to continue enter y/Y : y
Choose the options
1. To enter all students rollno
2. To enter the rollno of student who like vanila
3. To enter the rollno of student who like butterscotch
4. To display the rollno of student who like vanila or butterscotch
5. To display the rollno of student who like only vanila
6. To display the rollno of student who like only butterscotch
7. To display the rollno of student who like both vanila and butterscotch
8. To display the rollno of student who neither like vanila nor butterscotch
Choice: 6
Students who like only butterscotch
7
10
Do you want to continue enter y/Y : y
Choose the options
1. To enter all students rollno
2. To enter the rollno of student who like vanila
3. To enter the rollno of student who like butterscotch
4. To display the rollno of student who like vanila or butterscotch
5. To display the rollno of student who like only vanila
6. To display the rollno of student who like only butterscotch
7. To display the rollno of student who like both vanila and butterscotch
8. To display the rollno of student who neither like vanila nor butterscotch
Choice: 7
Students who like both vanilla and butterscotch
8
9
Do you want to continue enter y/Y : y
Choose the options
1. To enter all students rollno
2. To enter the rollno of student who like vanila
3. To enter the rollno of student who like butterscotch
4. To display the rollno of student who like vanila or butterscotch
5. To display the rollno of student who like only vanila
6. To display the rollno of student who like only butterscotch
7. To display the rollno of student who like both vanila and butterscotch
8. To display the rollno of student who neither like vanila nor butterscotch
Choice: 8
Students who like neither vanila nor butterscotch
1
3
Do you want to continue enter y/Y : n
*/