//Name:Gaurav Sable
//Roll no. 23339
//Assignment 10
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class Student
{
	int rollno;
	char name[20];
	char gender;
	int div;
	float marks;
public:
	void getData();
	void showData();
	int getrollno();
}s;
void Student::getData()
{
	cout<<"\n\nEnter Student Details......\n";
	cout<<"Enter Roll No.     : "; cin>>rollno;
	cout<<"Enter Full Name         : "; cin.ignore(); cin.getline(name,20);
	cout<<"Enter Gender (M/F)      : "; cin>>gender;
	cout<<"Enter Division          : "; cin>>div;
	cout<<"Enter Marks (out of 100): "; cin>>marks;
	cout<<endl;
}
void Student::showData()
{
	cout<<"\n\n.......Student Details......\n";
	cout<<"Roll No.     : "<<rollno<<endl;
	cout<<"Full Name         : "<<name<<endl;
	cout<<"Gender            : "<<gender<<endl;
	cout<<"Division          : "<<div<<endl;
	cout<<"Marks (out of 100): "<<marks<<endl;
	cout<<endl;
}
int Student::getrollno()
{
	return rollno;
}
void addData()
{
	ofstream fout;
	fout.open("StudentRec.txt",ios::binary|ios::out|ios::app);
	s.getData();
	fout.write((char*)&s,sizeof(s));
	fout.close();
	cout<<"\n\nData Successfully Saved to File....\n";
}
void displayData()
{
	ifstream fin;
	fin.open("StudentRec.txt",ios::in|ios::binary);
	while(fin.read((char*)&s,sizeof(s)))
	{
		s.showData();
	}
	fin.close();
	cout<<"\n\nData Reading from File Successfully Done....\n";
}
void searchData()
{
	int n, flag=0;
	ifstream fin;
	fin.open("StudentRec.txt",ios::in|ios::binary);
	cout<<"Enter Roll Number you want to search : ";
	cin>>n;
	while(fin.read((char*)&s,sizeof(s)))
	{
		if(n==s.getrollno())
		{
			cout<<"The Details of Roll No. "<<n<<" shown herewith:\n";
			s.showData();
			flag++;
		}
	}
	fin.close();
	if(flag==0)
		cout<<"The Roll No. "<<n<<" not found....\n\n";
	cout<<"\n\nData Reading from File Successfully Done....\n";
}
void deleteData()
{
	int n, flag=0;
	ifstream fin;
	ofstream fout,tout;
	fin.open("StudentRec.txt",ios::in|ios::binary);
	fout.open("TempStud.txt",ios::out|ios::app|ios::binary);
	tout.open("TrashStud.txt",ios::out|ios::app|ios::binary);
	cout<<"Enter Roll Number you want to move to Trash : ";
	cin>>n;
	while(fin.read((char*)&s,sizeof(s)))
	{
		if(n==s.getrollno())
		{
			cout<<"The Following Roll No. "<<n<<" has been moved to Trash:\n";
			s.showData();
			tout.write((char*)&s,sizeof(s));
			flag++;
		}
		else
		{
			fout.write((char*)&s,sizeof(s));
		}
	}
	fout.close();
	tout.close();
	fin.close();
	if(flag==0)
		cout<<"The Roll No. "<<n<<" not found....\n\n";
	remove("StudentRec.txt");
	rename("tempStud.txt","StudentRec.txt");
}
void getTrash()
{
	ifstream fin;
	fin.open("TrashStud.txt",ios::in|ios::binary);
	while(fin.read((char*)&s,sizeof(s)))
	{
		s.showData();
	}
	fin.close();
	cout<<"\n\nData Reading from Trash File Successfully Done....\n";
}
void modifyData()
{
	int n, flag=0, pos;
	fstream fio;
	fio.open("StudentRec.txt",ios::in|ios::out|ios::binary);
	cout<<"Enter Roll Number you want to Modify : ";
	cin>>n;
	while(fio.read((char*)&s,sizeof(s)))
	{
		pos=fio.tellg();
		if(n==s.getrollno())
		{
			cout<<"The Following Roll No. "<<n<<" will be modified with new data:\n";
			s.showData();
			cout<<"\n\nNow Enter the New Details....\n";
			s.getData();
			fio.seekg(pos-sizeof(s));
			fio.write((char*)&s,sizeof(s));
			flag++;
		}
	}
	fio.close();
	if(flag==0)
		cout<<"The Roll No. "<<n<<" not found....\n\n";
}
int main()
{
	int ch;
		do
		{
			cout<<"...............STUDENT MANAGEMENT SYSTEM..............\n";
			cout<<"======================================================\n";
			cout<<"1. Write Data to File\n";
			cout<<"2. Read Data From File\n";
			cout<<"3. Search Data From File\n";
			cout<<"4. Delete Data From File\n";
			cout<<"5. Get Deleted Records from Trash file\n";
			cout<<"6. Modify Data in File\n";
			cout<<"7. Exit from Program\n";
			cout<<"Enter your choice  : ";
			cin>>ch;
			switch(ch)
			{
				case 1: addData();
						break;
				case 2: displayData();
						break;
				case 3: searchData();
						break;
				case 4: deleteData();
						break;
				case 5: getTrash();
						break;
				case 6: modifyData();
						break;
				case 7:cout<<"===Thank you for using our services===";
						cout<<"======================================";
						exit(0);
			}
		}while(ch);

	return 0;
}

