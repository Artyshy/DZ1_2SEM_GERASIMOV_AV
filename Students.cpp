#include "Students.h"

Student::Student()
{
	firstName = "Default";
	lastName = "Default";
	pasportNumber = "Undefined";
	studentNumber = 0;
	scholarship = 0;
	mediumGrade = 0;
	for (int i = 0; i < 8; i++)
	{
		semGrades.insert(semGrades.end(), 0);
	}
};

Student::Student(string firstName, string lastName, string pasportNumber, int studentNumber, int scholarship, vector<int> semGrades, float mediumGrade)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->pasportNumber = pasportNumber;
	this->studentNumber = studentNumber;
	this->scholarship = scholarship;
	this->semGrades = semGrades;
	this->mediumGrade = mediumGrade;
};

void Student::setName(string name)
{
	firstName = name;
};

void Student::setLastName(string familyName)
{
	lastName = familyName;
};

void Student::setPasportNumber(string pasport)
{
	pasportNumber = pasport;
};


void Student::setStudentNumber(int number)
{
	studentNumber = number;
};

void Student::setScholarship(int moneyz)
{
	scholarship = moneyz;
};

void Student::setSemGrades(vector<int> grades)
{
	for (int i = 0; i < 8; i++)
	{
		semGrades.insert(semGrades.end(), grades[i]);
	}
};

string Student::getName()
{
	return firstName;
};

string Student::getLastName()
{
	return lastName;
};

string Student::getPasportNumber()
{
	return pasportNumber;
};


int Student::getStudentNumber()
{
	return studentNumber;
};

int Student::getScholarship()
{
	return scholarship;
};

vector<int> Student::getSemGrades()
{
	return semGrades;
};

int Student::getSemGradeI(int j)
{
	return semGrades[j];
};

float Student::getMediumGrade()
{
	if (!mediumGrade)
	{
		cout << "\nMedium grade has not been calculated yet!" << endl;
	}
	else
	{
		return mediumGrade;
	}
};

void Student::printParams()
{
	cout << "\nStudent #: "<< studentNumber << ":" << "\nName: " << firstName << "\nLast name: " << lastName << "\nPasport #: " << pasportNumber << "\nStudent's scholarship: "<< scholarship << "\nStudent's semester grades: " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "\n Subject #" << i+1 << ": " << semGrades[i] << endl;
	}
	cout << "\n Medium grade: " << mediumGrade << endl;
};

float Student::calculateMediumGrade()
{

		mediumGrade = 0;
		for (int i = 0; i < 8; i++)
		{
			mediumGrade = mediumGrade + semGrades[i];
		}
		mediumGrade = mediumGrade / 8;
		return mediumGrade;
};

void Student::setGradeI(int grade)
{
	semGrades.insert(semGrades.end(), grade);
};

Student& Student::operator=(const Student &input)
{
	Student *newStudent = new Student(input.firstName, input.lastName, input.pasportNumber, input.studentNumber, input.scholarship, input.semGrades, input.mediumGrade);
	return *newStudent;
};

bool Student::operator==(const Student & input)
{
	if (input.firstName == this->firstName &&
		input.lastName == this->lastName &&
		input.pasportNumber == this->pasportNumber &&
		input.studentNumber == this->studentNumber &&
		input.scholarship == this->scholarship &&
		input.semGrades == this->semGrades &&
		input.mediumGrade == this->mediumGrade)
		return true;
	else return false;
}

Student::~Student()
{

};








