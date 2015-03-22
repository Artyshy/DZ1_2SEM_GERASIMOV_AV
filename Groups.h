#include "Students.h"

class Group
{
private:
	string groupName;
	string groupCourse;
	int studentAmount;
	string groupSemester;
	float groupMediumGrade; 
	vector<float> mediumGradePerSubject;
	vector<Student>vectorStudents;
public:
	Group();
	Group(string groupName, string groupCourse, string groupSemester);
	void addStudent();
	float calculateGroupMediumGrade();
	void calculateMediumGradePerSubject();
	void setGroupName(string gName);
	void setCourse(string course);
	void setSemester(string semester);
	void setStudentAmount(vector<Student>vector);
	string getGroupName();
	string getCourse();
	int getStudentAmount();
	Student& getStudentFromVector(int i);
	string getSemester();
	float getGroupMediumGrade();
	float getMediumPerSubject();
	void printGroupList();
	void printStudentList();
	void printGoodies();
	void delStudent(Student& arg1);
	Group& operator+(Group &input);
	vector<Student>& getStudents();
	~Group();
	
};