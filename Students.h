#include <iostream>
#include <string>
#include <vector>		

using namespace std;

class Student
{
private: 
	string firstName;
	string lastName;
	string pasportNumber;
	int studentNumber;
	int scholarship;
	vector<int> semGrades;
	float mediumGrade;
public: 
	Student();
	Student(string firstName, string lastName, string pasportNumber, int studentNumber, int scholarship, vector<int> semGrades, float mediumGrade); 
	void setName(string name);
	void setLastName(string familyName);
	void setPasportNumber(string pasport);
	void setStudentNumber(int number);
	void setScholarship(int moneyz);
	void setSemGrades(vector<int> grades);
	void setGradeI(int grade);
	void printParams();
	Student& Student::operator=(const Student &input);
	bool Student::operator==(const Student & input);
	string getName();
	string getLastName();
	string getPasportNumber();
	int getStudentNumber();
	int getScholarship();
	int getSemGradeI(int j);
	vector<int> getSemGrades();
	float calculateMediumGrade();
	float getMediumGrade();
	~Student();
};