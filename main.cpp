#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Address.h"
#include "Student.h"
using namespace std;
 
void options();
int countStudents(string filename);
void loadStudents(Student* students, int numStudents, string filename);
 
int choice;
 
int main(){
	string filename = "students.csv";
	int numStudents = countStudents(filename);
 
	Student* students = new Student[numStudents];
	loadStudents(students, numStudents, filename);
 
	choice = -1;
	while (choice != 0){
		options();
		if (choice == 1){
			for (int i = 0; i < numStudents; i++){
				cout << students[i].getLastFirst() << endl;
			}
			cout << endl;
		}
		else if (choice == 2){
			for (int i = 0; i < numStudents; i++){
				students[i].printStudent();
			}
			cout << endl;
		}
		else if (choice == 3){
			string lastName;
			cout << "last name of student: ";
			cin >> lastName;
 
			bool found = false;
			for (int i = 0; i < numStudents; i++){
				if (students[i].getLastName() == lastName){
					students[i].printStudent();
					found = true;
				}
			}
			if (!found){
				cout << "No student found with last name " << lastName << endl;
			}
			cout << endl;
		}
		else if (choice != 0){
			cout << "Invalid choice." << endl << endl;
		}
	}
 
	delete[] students;
 
	return 0;
} // end main
 
void options(){
	cout << "0) quit\n1) print all student names\n2) print all student data\n3) find a student\n" << endl;
	cout << "please choose 0-3: ";
	cin >> choice;
	if (!cin){
		choice = 0;
	}
	cout << "\n";
}
 
int countStudents(string filename){
	ifstream file(filename);
	int count = 0;
	string line;
	while (getline(file, line)){
		if (line != ""){
			count++;
		}
	}
	file.close();
	return count;
}
 
void loadStudents(Student* students, int numStudents, string filename){
	ifstream file(filename);
	string line;
	int i = 0;
	while (i < numStudents && getline(file, line)){
		if (line != ""){
			students[i].init(line);
			i++;
		}
	}
	file.close();
}
