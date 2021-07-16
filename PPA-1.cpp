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
