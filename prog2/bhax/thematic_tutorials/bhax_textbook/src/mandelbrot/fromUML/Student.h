#ifndef STUDENT_H
#define STUDENT_H

class Student : Something {

private:
	int ID;
	int age;
	int gender;
	int creditIndex;
	int eMailAddress;

public:
	Student();

	void getCreditIndex();

	void setCreditIndex(int creditIndex);

	void getEMailAddress();

	void setEMailAddress(int eMailAddress);

	void doNothingDuringLesson();
};

#endif
