//Harsh Gangadhar Chakote
//SE-II (Q)
//Roll No.: 31
//PRN: F23112034

/*Problem Statement: Implement C++ program using linked list data structure to conduct
elections to elect last representative of SE-II. Reconduct voting if there is a tie. 
Also set CGPA, eligibility criteria.*/ 
#include <iostream>
#include <string>
using namespace std;

// Node structure for linked list with age and CGPA
struct CandidateNode
{
    string name;
    int age;
    double cgpa;
    int votes;
    CandidateNode *next;

    CandidateNode(string n, int a, double c) : name(n), age(a), cgpa(c), votes(0), next(nullptr) {}
};

// Class to handle the voting system
class VotingSystem
{
private:
    CandidateNode *head;

public:
    VotingSystem() : head(nullptr) {}

    // Function to add a candidate to the linked list if their CGPA is above 8
    void addCandidate(string candidateName, int candidateAge, double candidateCgpa)
    {
        if (candidateCgpa <= 8.0)
        {
            cout << "Candidate " << candidateName << " is not eligible for nomination due to CGPA below 8.0.\n";
            return;
        }

        CandidateNode *newNode = new CandidateNode(candidateName, candidateAge, candidateCgpa);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            CandidateNode *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Candidate " << candidateName << " has been added successfully!\n";
    }

    // Function to cast a vote for a candidate by selecting from the list
    void castVote(int candidateIndex)
    {
        CandidateNode *temp = head;
        int index = 1; // Start index from 1 for easier readability
        while (temp != nullptr)
        {
            if (index == candidateIndex)
            {
                temp->votes++;
                cout << "Vote cast for " << temp->name << "!\n";
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "Invalid candidate selection!\n";
    }

    // Function to display only the list of candidates' names with their index
    void displayCandidatesNames()
    {
        if (head == nullptr)
        {
            cout << "No candidates found.\n";
            return;
        }
        CandidateNode *temp = head;
        int index = 1;
        cout << "\nCandidate List:\n";
        while (temp != nullptr)
        {
            cout << index << ". " << temp->name << "\n";
            temp = temp->next;
            index++;
        }
        cout << endl;
    }

    // Function to display the full list of candidates with votes and details
    void displayCandidatesWithDetails()
    {
        if (head == nullptr)
        {
            cout << "No candidates found.\n";
            return;
        }
        CandidateNode *temp = head;
        int index = 1;
        cout << "\nCandidate List:\n";
        while (temp != nullptr)
        {
            cout << index << ". Candidate: " << temp->name << " | Age: " << temp->age << " | CGPA: " << temp->cgpa << " | Votes: " << temp->votes << "\n";
            temp = temp->next;
            index++;
        }
        cout << endl;
    }

    // Function to determine the winner and handle tie situations
    void determineWinner()
    {
        if (head == nullptr)
        {
            cout << "No candidates available for voting.\n";
            return;
        }

        // Find the maximum votes
        int maxVotes = 0;
        CandidateNode *temp = head;
        while (temp != nullptr)
        {
            if (temp->votes > maxVotes)
            {
                maxVotes = temp->votes;
            }
            temp = temp->next;
        }

        // Check for winners and count the number of candidates with the max votes
        temp = head;
        int countMaxWinners = 0;
        while (temp != nullptr)
        {
            if (temp->votes == maxVotes)
            {
                countMaxWinners++;
            }
            temp = temp->next;
        }

        // If there is a tie, reconduct voting
        if (countMaxWinners > 1)
        {
            cout << "\nIt's a tie between " << countMaxWinners << " candidates with " << maxVotes << " votes each.\n";
            reconductVoting(maxVotes);
        }
        else
        {
            temp = head;
            while (temp != nullptr)
            {
                if (temp->votes == maxVotes)
                {
                    cout << "\nNew CR of SE-II is: " << temp->name << " with " << temp->votes << " votes!\n";
                    cout<<"Congratulations "<<temp->name<<"!!!"<<endl;
                    return;
                }
                temp = temp->next;
            }
        }
    }

    // Function to reconduct voting in case of a tie
    void reconductVoting(int maxVotes)
    {
        cout << "\nReconducting voting for candidates with " << maxVotes << " votes...\n";
        resetVotes();
        displayCandidatesNames();
        cout << "Please cast your votes again for the tied candidates.\n";
        conductVoting();
        determineWinner();
    }

    // Function to reset all votes to zero
    void resetVotes()
    {
        CandidateNode *temp = head;
        while (temp != nullptr)
        {
            temp->votes = 0;
            temp = temp->next;
        }
    }

    // Function to conduct voting
    void conductVoting()
    {
        int numVotes;
        cout << "Enter the number of votes to cast: ";
        cin >> numVotes;

        for (int i = 0; i < numVotes; ++i)
        {
            displayCandidatesNames(); // Show only the list of candidate names before each vote
            int candidateIndex;
            cout << "Select the candidate number to vote for: ";
            cin >> candidateIndex;
            castVote(candidateIndex);
        }
    }

    // Destructor to free memory
    ~VotingSystem()
    {
        while (head != nullptr)
        {
            CandidateNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Function to input valid Candidates
void inputCandidates(VotingSystem &system, int numCandidates)
{
    int count = 0;
    while (count < numCandidates)
    {
        string name;
        int age;
        double cgpa;
        
        // Loop to re-input if candidate is ineligible
        while (true)
        {
            cout << "Enter candidate name: ";
            getline(cin, name);
            cout << "Enter candidate age: ";
            cin >> age;
            cout << "Enter candidate CGPA: ";
            cin >> cgpa;

            // Clear the input buffer manually
            cin.ignore(); // Ignores the newline character left in the buffer after reading CGPA

            // Check for eligibility based on CGPA
            if (cgpa > 8.0)
            {
                // If eligible, break out of the inner loop to proceed
                system.addCandidate(name, age, cgpa);
                break;
            }
            else
            {
                cout << "Candidate " << name << " is ineligible due to CGPA below 8.0. Please re-enter the candidate's details.\n";
            }
        }

        // Increment count after adding an eligible candidate
        count++;
    }
}

// Main function
int main()
{
    VotingSystem system;

    cout<<"Welcome to the Voting System!!!"<<endl;
    cout<<"Today we will be conducting SE-II class's CR elections."<<endl;
    cout<<"\nRules for Candidate entry:\n1.Candidate should be passed with CGPA greater than 8.0 ."<<endl;
    cout<<"\nClass teacher should set the candidates limit."<<endl;
    // Input candidate names, ages, and CGPA
    int numCandidates;
    cout << "Enter number of candidates: ";
    cin >> numCandidates;

    cin.ignore(); // Ignores the newline character left in the buffer after reading numCandidates
    cout<<"Candidates please enter your details:"<<endl;
    // Input Candidates with validation
    inputCandidates(system, numCandidates);

    // Display candidates with details before voting
    system.displayCandidatesWithDetails();
    cout<<"So let us start with the elections now!!!"<<endl;
    // Conduct voting
    system.conductVoting();

    // Display updated votes and full details
    system.displayCandidatesWithDetails();

    // Determine the winner or handle tie
    system.determineWinner();

    return 0;
}


//Output:
/*
Welcome to the Voting System!!!
Today we will be conducting SE-II class's CR elections.
Rules for Candidate entry:
1.Candidate's age should be 18 or more.
2.Candidate should be passed with CGPA greater than 8.0 .
Class teacher should set the candidates limit.
Enter number of candidates: 3
Candidates please enter your details:
Enter candidate name: Harsh
Enter candidate age: 19
Enter candidate CGPA: 9.93
Candidate Harsh has been added successfully!
Enter candidate name: Vishal
Enter candidate age: 18
Enter candidate CGPA: 8.0
Candidate Vishal is ineligible due to CGPA below 8.0. Please re-enter the candidate's details.
Enter candidate name: Rahul
Enter candidate age: 19
Enter candidate CGPA: 9.6
Candidate Rahul has been added successfully!
Enter candidate name: Prem
Enter candidate age: 19
Enter candidate CGPA: 8.2
Candidate Prem has been added successfully!
Candidate List:
1. Candidate: Harsh | Age: 19 | CGPA: 9.93 | Votes: 0
2. Candidate: Rahul | Age: 19 | CGPA: 9.6 | Votes: 0
3. Candidate: Prem | Age: 19 | CGPA: 8.2 | Votes: 0
So let us start with the elections now!!!
Enter the number of votes to cast: 10
Candidate List:
1. Harsh
2. Rahul
3. Prem
Select the candidate number to vote for: 1
Vote cast for Harsh!
Candidate List:
1. Harsh
2. Rahul
3. Prem
Select the candidate number to vote for: 1
Vote cast for Harsh!
Candidate List:
1. Harsh
2. Rahul
3. Prem
Select the candidate number to vote for: 2
Vote cast for Rahul!
Candidate List:
1. Harsh
2. Rahul
3. Prem
Select the candidate number to vote for: 3
Vote cast for Prem!
Candidate List:
1. Harsh
2. Rahul
3. Prem
Select the candidate number to vote for: 1
Vote cast for Harsh!
Candidate List:
1. Harsh
2. Rahul
3. Prem
Select the candidate number to vote for: 2
Vote cast for Rahul!
Candidate List:
1. Harsh
2. Rahul
3. Prem
Select the candidate number to vote for: 2
Vote cast for Rahul!
Candidate List:
1. Harsh
2. Rahul
3. Prem
Select the candidate number to vote for: 1
Vote cast for Harsh!
Candidate List:
1. Harsh
2. Rahul
3. Prem
Select the candidate number to vote for: 1
Vote cast for Harsh!
Candidate List:
1. Harsh
2. Rahul
3. Prem
Select the candidate number to vote for: 2
Vote cast for Rahul!
Candidate List:
1. Candidate: Harsh | Age: 19 | CGPA: 9.93 | Votes: 5
2. Candidate: Rahul | Age: 19 | CGPA: 9.6 | Votes: 4
3. Candidate: Prem | Age: 19 | CGPA: 8.2 | Votes: 1
New CR of SE-II is: Harsh with 5 votes!
Congratulations Harsh!!!
*/