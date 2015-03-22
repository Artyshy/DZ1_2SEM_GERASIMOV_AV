#include "Groups.h"

Group::Group()
{
	groupName = "Default group";
	groupCourse = "0";
	groupSemester = "0";
	studentAmount = 0;
	groupMediumGrade = 0;
	for (int i = 0; i < 8; i++)
	{
		mediumGradePerSubject.insert(mediumGradePerSubject.end(), 0);
	}
};

Group::Group(string groupName, string groupCourse, string groupSemester)
{
	this->groupName = groupName;
	this->groupCourse = groupCourse;
	this->groupSemester = groupSemester;
};

void Group::setGroupName(string gName)
{
	groupName = gName;
};

void Group::setCourse(string course)
{
	groupCourse = course;
};

void Group::setSemester(string semester)
{
	groupSemester = semester;
};

void Group::setStudentAmount(vector<Student>vector)
{
	studentAmount = vector.size();
};

string Group::getGroupName()
{
	return groupName;
};

string Group::getCourse()
{
	return groupCourse;
};

string Group::getSemester()
{
	return groupSemester;
};

int Group::getStudentAmount()
{
	return studentAmount;
};

float Group::getGroupMediumGrade()
{
	return groupMediumGrade;
};

vector<Student>& Group::getStudents()
{
	return vectorStudents;
};

void Group::addStudent()
{
	string tempString;
	int tempInt;
	int tempArray[8];  
	vector<int>temp;
	Student objStudent("0","0","0",0,0,temp,0);
	cout << "\n Enter student's name:" << endl;
	cin >> tempString;
	objStudent.setName(tempString);
	cout << "\n Enter student's last name:" << endl;
	cin >> tempString;
	objStudent.setLastName(tempString);
	cout << "\n Enter student's pasport number" << endl;
	cin >> tempString;
	objStudent.setPasportNumber(tempString);
	fflush(stdin);
	cout << "\n Enter student's number:" << endl;
	cin >> tempInt;
	objStudent.setStudentNumber(tempInt);
	cout << "\n Enter student's scholarship:" << endl;
	cin >> tempInt;
	objStudent.setScholarship(tempInt);
	cout << "\n Enter student's semester grades:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "\n Subject #" << i+1 << "grade: " << endl;
		cin >> tempArray[i];
		objStudent.setGradeI(tempArray[i]);
	}
	objStudent.calculateMediumGrade();
	vectorStudents.insert(vectorStudents.end(), objStudent);
	setStudentAmount(vectorStudents);
};

float Group::calculateGroupMediumGrade()
{
	if (studentAmount != 0)
	{
		for (int i = 0; i < studentAmount; i++)
		{
			groupMediumGrade = groupMediumGrade + vectorStudents[i].calculateMediumGrade();
		}
		groupMediumGrade = groupMediumGrade / studentAmount;
	}
	return groupMediumGrade;
};

void Group::calculateMediumGradePerSubject()
{

	float tempInt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < studentAmount; j++)
		{
			tempInt = tempInt + vectorStudents[j].getSemGradeI(i);
		}
		tempInt = tempInt / studentAmount;
		mediumGradePerSubject.insert(mediumGradePerSubject.end(), tempInt);
		tempInt = 0;
	};
};

void Group::printGoodies()
{
	vector<int>goodies;
	vector<int>badies;
	int vectorSize1;
	int vectorSize2;
	for (int i = 0; i < studentAmount; i++)
	{
		if (vectorStudents[i].calculateMediumGrade()>4)
		{
			goodies.insert(goodies.end(), i);
		}
		if (vectorStudents[i].calculateMediumGrade()<3)
		{
			badies.insert(badies.end(), i);
		}
	}

	vectorSize1 = goodies.size();
	vectorSize2 = badies.size();


	cout << "\nGood students are:" << endl;
	for (int i = 0; i < vectorSize1; i++)
	{
		cout << "\n" << i+1 << "." << vectorStudents[goodies[i]].getName() << " " << vectorStudents[goodies[i]].getLastName() << endl;
	}
	cout << "\nBad students are:" << endl;
	for (int i = 0; i < vectorSize2; i++)
	{
		cout << "\n" << i+1 << "." << vectorStudents[badies[i]].getName() << " " << vectorStudents[badies[i]].getLastName() << endl;
	}

};

Group& Group::operator+(Group &input)
{
	Group *newGroup = new Group();
	newGroup->setGroupName(this->getGroupName() + " and group " + input.getGroupName());
	vector<Student> newVector = this->getStudents();
	newVector.insert(newVector.end(), input.getStudents().begin(), input.getStudents().end());
	newGroup->setStudentAmount(newVector);
	newGroup->setCourse(this->getCourse() + " and " + input.getCourse());
	newGroup->setSemester(this->getSemester() + " and " + input.getSemester());
	return *newGroup;
}; 

void Group::printGroupList()
{
	cout << "\n Group " << getGroupName() << "\n:" << endl;
	cout << "\n Amount of students:" << getStudentAmount() << endl;
	cout << "\n Current semester:" << getSemester() << endl;
	cout << "\n Current course:" << getCourse() << endl;
	calculateGroupMediumGrade();
	cout << "\n Group's medium grade: " << getGroupMediumGrade() << endl;
	cout << "\n Medium grade per subject:" << endl;
	calculateMediumGradePerSubject();
	for (int i = 0; i < 8; i++)
	{
		cout << "\n Subject #" << i+1 << " " <<mediumGradePerSubject[i];
	}
	cout << "\nStudent list:" << endl;
	for (int i = 0; i < studentAmount; i++)
	{
		vectorStudents[i].printParams();
	}
};

void Group::printStudentList()
{
	cout << "\nStudent list:" << endl;
	for (int i = 0; i < studentAmount; i++)
	{
		vectorStudents[i].printParams();
	}
};

void Group::delStudent(Student& arg1)
{
	vector<Student>::iterator position = find(vectorStudents.begin(), vectorStudents.end(), arg1);
	if (position != vectorStudents.end())
	{
		vectorStudents.erase(position);
		studentAmount--;
	}
	else cout << "This student doesn't exist!" << endl;
} 

Student& Group::getStudentFromVector(int i)
{

	return vectorStudents[i];
};

Group::~Group()
{
	vectorStudents.clear();
};



