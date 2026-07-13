#include<iostream>
using namespace std;
class student
{
public:
	int roll;
	string name;
	int age;
	
	void intro()
	{
		cout<<"my name is "<<name<<endl;
		cout<<"iam "<<age<<"years old."<<endl;
		cout<<"my roll number is "<<roll<<endl;
	}
};

int main()
{

	student Aby;
	Aby.name="Aby";
	Aby.age=20;
	Aby.roll=5;
	
	Aby.intro();
	
	return 0;
	}

