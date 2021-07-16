/*

Structure:  A structure is a collection of variable data types. We can refer a structure as a single variable, and its members by using dot(.) or arrow(->) operator. 

Student Structure:   To represent a student we need to store his/her name, age, and marks. We can store these all information in a structure and refer this structure as a single student. The student structure can be shown as:

struct  student {

    string name;

    int age;

    float marks;

};

Task: In this programming assignment, you are required to write code that assigns the input values to name, age, and marks of a specific student. There is a function initiateStudent() which should initialize a student structure. After initializing all student's structure, your next task is to identify the topper among all students  ( if there are multiple toppers then return the first topper according to given input sequence). The function highestScorer()  should give the topper student.

Example: 

Suppose in class there are 3 students and their information is as given in the following table:

Student_ID	name	age	marks
1	stud1	19	23.5
2	stud2	20	24
3	stud3	19	23.8
So, when you compare all students' marks you will see that stud2 is the topper with 24 marks.

You need to complete the code of two functions 1) initiateStudent() and 2) highestScorer(). In the supplied reference program, the main function is coded as shown below.

int main ( ) {

int totalStudents = 1;

string name;

int age;

float marks;

cin >> totalStudents;

student *stud[totalStudents];

for( int i = 0; i < totalStudents; i++ )  {

cin >> name >> age >> marks;

stud[i] = initiateStudent(name,age,marks);

}

student *topper = highestScorer(stud,totalStudents);

cout << topper->name << " is the topper with " << topper->marks << " marks" << endl;

return 0;

}

You are required to write 2 functions:

Function 1:  initiateStudent(string name, int age, float marks):

This function has three parameters:

string name: name of the student.
int age: age of student.
float marks: marks obtained by student.
The function should do the following:

Allocate a memory to structure variable.
Assign the input variables to function member.
Return the structure pointer.
Function 2:  highestScorer(student **stud, int totalStudents):

This function has two parameters:

student **stud: stud is array of pointers to students.
int totalStudents: total number of students.
The function should do the following:

Compare student structures based on marks.
Extract the student with highest marks.
If there are multiple toppers then return the first topper according to given input sequence.

*/


#include<iostream>
using namespace std;

struct  student {

    string name;
    int age;
    float marks;

};
    
student* initiateStudent(string name,int age,float marks){
	
	student* newStudent;
	newStudent = new student;
	
	newStudent->name = name;
	newStudent->age = age;
	newStudent->marks = marks;
	
	return newStudent; 

}
    
student *highestScorer(student **stud, int totalStudents) 		{
		float max=0;
		int holder=0;
		
		for(int i=0 ; i<totalStudents ; i++) {
		
			if( stud[i]-> marks > max ) { 
				max = stud[i]->marks;  
				holder=i; 
			}
		}
		
		return stud[holder];
	
}



int main ( ) {

	int totalStudents = 3;

	string name;
	int age;
	float marks;
	
	cin >> totalStudents;
	student *stud[totalStudents];

	for( int i = 0; i < totalStudents; i++ )  {

		cin >> name >> age >> marks;
		stud[i] = initiateStudent(name,age,marks);

	}

	student *topper = highestScorer(stud,totalStudents);
	cout << topper->name << " is the topper with " << topper->marks << " marks" << endl;
	return 0;

}
