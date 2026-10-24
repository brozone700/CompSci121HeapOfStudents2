#include <iostream>
#include "Date.h"
#include "Address.h"
#include "Student.h"
using namespace std;

void options();

int choice;

int main(){
  cout << "Hello!" << endl;
  options();
  cout << choice;
  return 0;
} // end main

void options(){
	cout << "0) quit\n1) print all student names\n2) print all student data\n3) find a student\n" << endl;
	cout << "please choose 0-3: ";
	cin >> choice;
	cout << "\n";
}
