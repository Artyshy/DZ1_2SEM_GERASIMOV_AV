#include "Groups.h"

int main()
{
	cout << "\nCreating an empty student..." << endl;
	Student objStudent;
	cout << "\nPrinting out default parameters..." << endl;
	objStudent.printParams();
	cout << "\nSetting up all parameters..." << endl;
	objStudent.setName("Test");
	objStudent.setLastName("Test");
	objStudent.setPasportNumber("9999");
	objStudent.setStudentNumber(1);
	objStudent.setScholarship(500);
	vector<int>test; 
	for (int i = 0; i < 8; i++)
	{
		test.insert(test.end(), 1);
	}
	objStudent.setSemGrades(test);
	objStudent.calculateMediumGrade();
	objStudent.printParams();
	cout << "\nCreating a default Group..." << endl;
	Group objGroup;
	cout << "\nAll group parameters:" << endl;
	objGroup.printGroupList();
	cout << "\nLets input some custom parameters..." << endl;
	Group objGroup1("Group 1", "1", "2");
	cout << "\n Adding some students..." << endl;
	objGroup1.addStudent(); objGroup1.addStudent(); 
	objGroup1.addStudent(); objGroup1.addStudent();
	cout << "\n Printing out new group parameters..." << endl;
	objGroup1.printGroupList();
	cout << "\n Checking who is a good/bad student..." << endl;
	objGroup1.printGoodies();
	cout << "\nDeleting student from list..." << endl;
	objGroup1.delStudent(objGroup1.getStudentFromVector(0));
	cout << "\nRefreshed student list..." << endl;
	objGroup1.printStudentList();
	cout << "\n Checking who is a good/bad student after refreshing the list..." << endl;
	objGroup1.printGoodies();
	system("pause");
	return 0;
}