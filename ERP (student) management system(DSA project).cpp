#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
class Admin
{
	private:
    string password = "programmer";
   
   friend class Password;
		
};
class Password: private Admin
{
	public:
		Password(Admin a, string pasword)
		{
		    if (a.password == pasword)
	        {
	        	system("cls");
	            cout << "\n\n\tLogin successfully" << endl;
	        }
	        else
	        {
	            cout << "\n\n\tInvalid password" << endl;
	            exit(0); 
	        }	
		}
};	
class Person
{
	public:
		string name,  ph_no, resident;
		int id;
		int  age, studentClass;
		string gender ;
		string position;
		Person * next;
		Person * next1;
		Person * next2;
		Person * next3;
		Person * next4;
		int vote =0;
		
	
	
};
int count1=0, count2=0, count3=0, count4= 0, count5=0, count6=0;
Person * head = NULL;
Person * head1 = NULL;
Person * head2 = NULL;
Person * head3 = NULL;
Person * head4 = NULL;
class Student: public Person
{
   
	public:
    void CheckInFees();
    void StudentFees (int roll_num);
	void displayStudent(int roll_num);
	 void addStudent ();
    void generateAttendanceReport(int roll_num) ;
	void generateFine(int roll_number);
    void  validateSubjectMarks(int index);
    void generateAcademicReport( int roll_number);
};
int count =0;

void readDetail()
{
	fstream display;
	display.open("student.txt", ios::app | ios::in);
	if(display.fail())
	{
		cout <<"\nError Opening File\n";
		return ;
	}
	while (!display.eof())
	{
		Person * temp = new Person;
		display.ignore();
	   	getline(display, temp->name);
	   	getline(display, temp->resident);
	   	getline(display, temp->ph_no);
	   	display >> temp->id;
	   	display >> temp->gender;
	   	display >> temp->age;
	   	display >> temp->studentClass;
	   	temp->next= NULL;
	   	if(head == NULL)
	   	{
	   		head = temp;
		}
	    else{
	    	Person * temp1 = head;
	    	while(temp1->next != NULL)
	    	{
	    		temp1 = temp1->next;
			}
			temp1->next = temp;
		}
}
display.close();
}
void Student :: addStudent ()
{
	    
		ofstream out;
	    out.open("student.txt", ios::out | ios::app);
	    if (out.fail()) 
		{
	        cout << "\nError Opening File." << endl;
	        return;
	    }
		Person * temp = new Person;
		cout <<"Enter the name: ";
		cin.ignore();
		getline(cin, temp->name);
		out <<temp->name << endl;
		cout <<"Enter the Resident of student: ";
		getline(cin, temp->resident);
		out << temp->resident << endl;
		cout <<"Enter the Phone Number of student: ";
		getline(cin,temp->ph_no);
		out << temp->ph_no << endl;
		cout <<"Enter the ID: ";
		cin>> temp->id;
		Person *ptr = head;
        while(ptr != NULL)
        {
        	if(ptr->id == temp->id)
        	{
        		cout <<"please this id exit already";
        		exit(0);
        		
			}
			ptr = ptr->next;
		}
		out << temp->id << endl; 
		cout <<"Enter the Gender: ";
		cin >> temp->gender;
		out << temp->gender << endl;
		cout <<"Enter the Age: ";
		cin >> temp->age;
		out << temp->age << endl;
		cout <<"Enter the student class: ";
        cin>>temp->studentClass;
        
		out << temp->studentClass << endl;	
		temp->next = NULL;
    	if(head == NULL)
    	{
    		head =temp;
		}
		else
		{
			Person *temp1 = head;
			while(temp1->next != NULL)
			{
				temp1 = temp1->next;
			}
			temp1->next = temp;
		}
		 out.close();
}



void Student::displayStudent(int roll_num )
{
	Person *temp = head;
	while(temp!= NULL)
	{

		if(temp->id == roll_num)
		{
			cout <<"\n\n\t------Required Student ID Displayed Successfully-------\n\n";
	    	 cout <<"\t\tRoll Number: " << temp->id << endl;
	  		 cout <<"\t\tName: " << temp->name << endl;
	  		 cout <<"\t\tPhone Number: " << temp->ph_no << endl;
	  		 cout <<"\t\tResident: " << temp->resident << endl;
	  		 cout <<"\t\tAge: " << temp->age << endl;
	  		 cout <<"\t\tStudent Class: " << temp->studentClass << endl;
	  		 cout <<"\t\tGender: " << temp->gender  << endl;
	  		cout <<"\n\t-------------------------------------------------------\n";
		}
		temp = temp->next;
	}
}
   

  void Student::CheckInFees()
{
    Person* temp = head;
    int countP1 = 0, countP2 = 0, countP3 = 0, countP4 = 0;

    while (temp != NULL)
    {
        if (temp->studentClass >= 1 && temp->studentClass <= 5)
        {
            countP1++;
        }
        else if (temp->studentClass >= 6 && temp->studentClass <= 8)
        {
            countP2++;
        }
        else if (temp->studentClass >= 9 && temp->studentClass <= 10)
        {
            countP3++; 
        }
        else if (temp->studentClass >= 11 && temp->studentClass <= 12)
        {
            countP4++;
        }
        temp = temp->next;
    }
	if(countP1 != NULL)
	{
    cout << "\n\n\t\t---------------PRIMARY STUDENT------------------\n\n";
    cout << "\t\tTotal Admitted Student : " << countP1 << endl;
    cout << "\t\tTotal Fees Of '" << countP1 << "' Students: ";
    cout << countP1 * 2500;
    }
    if(countP2 != NULL)
    {
    cout << "\n\n\t\t---------------MIDDLE STUDENT-------------------\n\n";
    cout << "\t\tTotal Admitted Student : " << countP2 << endl;
    cout << "\t\tTotal Fees Of '" << countP2 << "' Students: ";
    cout << countP2 * 3500;
    }
    if(countP3 != NULL)
    {
    cout << "\n\n\t\t---------------MATRIC STUDENT-------------------\n\n";
    cout << "\t\tTotal Admitted Student : " << countP3 << endl;
    cout << "\t\tTotal Fees Of '" << countP3 << "' Students: ";
    cout << countP3 * 4500;
	}
	if(countP4 != NULL)
	{
    cout << "\n\n\t\t---------------INTER STUDENT--------------------\n\n";
    cout << "\t\tTotal Admitted Student : " << countP4 << endl;
    cout << "\t\tTotal Fees Of '" << countP4 << "' Students: ";
    cout << countP4 * 6000;
	}
    cout << "\n\n\t\t-------------------------------------------------\n\n";
}

void Student::StudentFees(int roll_num)
{
	Person *temp = head;
	int count = 0;
   while(temp!= NULL)
   {
	if (temp->id ==  roll_num)
    {
    	string studentClass;
    	if (temp->studentClass >=1 && temp->studentClass <=5)
    	{
    		studentClass = "PRIMARY STUDENT";
		}
		else if (temp->studentClass >=6 && temp->studentClass <=8)
    	{
    		studentClass = "MIDDLE STUDENT";
		}
		else if (temp->studentClass >=9 && temp->studentClass <=10)
    	{
    		studentClass = "MATRIC STUDENT";
		}
		else if (temp->studentClass >=11 && temp->studentClass <=12)
    	{
    		studentClass = "INTER STUDENT";
		}
		cout <<"\n\n\t-----------------"<<studentClass<<"----------------------\n\n";
    //	cout <<"\t-------------------------------------------------------\n";
        cout << "\t  Roll Number: " << temp->id << endl;
        cout << "\t  Student Name: " << temp->name << endl;
        cout << "\t  Student Class: " << temp->studentClass << endl ;
        cout << "\t  Student Phone Number: " << temp->ph_no << endl;
        cout <<"\n\t-------------------------------------------------------\n";
    	cout <<"\t       Student Fees Received Successfully\n";
    	cout <<"\t-------------------------------------------------------\n";
    	count++;
        
	}
   	temp= temp->next;
  }
  if (count == 0)
  {
  	  cout << "\nSorry! Student Fees Have Not Received Yet.\n";
  }
  
}

	double attendancePercentage;
void Student::generateAttendanceReport( int roll_num)
{
	  system("cls"); 
	  int i=0;
	  double totalWorkingDays, daysPresent;
	  Person *temp = head;
	  while(temp != NULL)
	  {
	    if (roll_num == temp->id)
	    {
	    	cout <<" NAME: \n \t"<<temp->name << endl; 
	    	cout <<" CLASS: \n \t"<<temp->studentClass << endl << endl; 
		    cout << "\nEnter total number of working days (1 - 366): ";
		    cin >> totalWorkingDays;
		    cout << "Enter number of days student " << temp->id << " was present (1 - 366): ";
		    cin >> daysPresent;
		    attendancePercentage = ((daysPresent / totalWorkingDays) * 100.00);
		    cout << "Attendance Percentage = " << attendancePercentage << "%" << endl;
		    if (attendancePercentage >= 80)
		    {
		    	cout <<"\nAttendance Are Above 80%, So Student Can Sit In Exams Without Fine\n\n";
			}
			else if (attendancePercentage <= 79.9 && attendancePercentage >=75)
			{
				cout <<"\nAttendance Are Below 80%, So Student Have to Charge 5000RS To Sit In Exams\n\n";
			}
			else if (attendancePercentage < 75)
			{
				cout <<"\nSorry! Student Is Drop\n\n";
			}
			i++;
		
	      break;
	      
	    }
	    temp = temp->next;
	  }
	  if (i != 0)
	  {
	      cout <<"\nStudent Attendance Percentage Generated Succefully\n\n";
	  }
	  else
	  {
	    cout << "No match found.";
	  }
}
	
	
	
	void Student::generateFine(int roll_number)
	{
		system ("cls");
		int i=0;
		Person *temp = head;
		while(temp != NULL)
		{
		   	if (temp->id == roll_number)
		   	{
		   		cout <<"Name: " << temp->name << endl;
				cout <<"Class: " << temp->studentClass << endl;
				cout <<"Roll Number: " <<temp->id << endl;
				cout <<"Attendance Percentage: " << attendancePercentage <<"%" << endl; 
			   	if (attendancePercentage >= 80)
			    {
			    	cout <<"\nAttendance is above 80%, So Student Can Sit In Exams Without Fine\n\n";
				}
				else if (attendancePercentage <= 79.9 && attendancePercentage >=75)
				{
					cout <<"\nAttendance is below 80%, So Student Have to Charge 5000RS To Sit In Exams\n\n";
				}
				else if (attendancePercentage < 75)
				{
					cout <<"\nSorry! Student Is Drop\n\n";
				}
			}
			temp = temp->next;
			i++;
		}
		if (i == 0)
		{
			cout <<"Sorry! Student ID Not Found\n";
		}

	}


 float marks[5];
void Student:: validateSubjectMarks(int index) {
	string subject[5] = {"Science", "Math", "English", "Urdu", "Pak Studies"};
    if (marks[index] < 0 || marks[index] > 100) {
    	
        cout << "\nInvalid marks " << index + 1 << ". Marks should be between 0 and 100." << endl;
        cout <<"\nPlease Enter Marks Again for " << subject[index] << ": ";
        cin >> marks[index];
    }
}
void Student::generateAcademicReport( int roll_number)
{
  system("cls");
  int i=0;
 
  float obtainingMarks, totalMarks =500.0, percentage;
  
  string grade, status;
   Person * temp = head;
   while(temp != NULL)
   { 
	    if (temp->id== roll_number)
	    {
	    	
		    cout << "\nEnter marks of student (" <<temp->id << ") between 0 to 100 in subjects asked below: ";
		    cout << "\n1. Science = ";
		    cin >> marks[0];
		    validateSubjectMarks(0);
		    cout << "2. Maths = ";
		    cin >> marks[1];
		    validateSubjectMarks(1);
		    cout << "3. English = ";
		    cin >> marks[2];
		    validateSubjectMarks(2);
		    cout << "4. Urdu = ";
		    cin >> marks[3];
		    validateSubjectMarks(3);
		    cout << "5. Social Studies = ";
		    cin >> marks[4];
		    validateSubjectMarks(4);
		    
		    obtainingMarks = (marks[0] + marks[1] + marks[2] + marks[3] + marks[4]);
		    percentage = (obtainingMarks / totalMarks) * 100; 
			cout <<"Max. Marks = " << totalMarks <<"\nObtain. Marks = " <<  obtainingMarks << endl;
		    cout << "Percentage = " << percentage << "%" << endl;
		    if (percentage >= 85)
			{
				grade = "A";
			}
			else if (percentage >=70)
	  		{
				grade = "B";
			}
			else if (percentage >=60)
			{
				grade = "C";
			}
			else if (percentage >=50)
			{
				grade = "D";
			}
			else if (percentage < 50 )
			{
				grade = "F";
			}
			cout << "Grade = " << grade << endl;
			if (grade != "F")
			{
				status = "Pass";
			}
			else 
			{
				status = "Fail";
			}
			cout <<"Status = " << status << endl << endl;
			break;
		  }
	    
	      temp = temp->next; 
    }
   
  }
  


void searchStudent(int roll_num)
{
	Person * temp = head;
	if(temp == NULL)
	{
		cout <<"Sorry, student data not found." << endl;
		return;
	}
	while (temp != NULL)
	{

		if (temp->id == roll_num)
		{
			cout <<"\n\n\t------Required Student ID Searched Successfully-------\n\n";
	    	 cout <<"\t\tRoll Number: " << temp->id << endl;
	  		 cout <<"\t\tName: " << temp->name << endl;
	  		 cout <<"\t\tPhone Number: " << temp->ph_no << endl;
	  		 cout <<"\t\tResident: " << temp->resident << endl;
	  		 cout <<"\t\tAge: " << temp->age << endl;
	  		 cout <<"\t\tStudent Class: " << temp->studentClass << endl;
	  		 cout <<"\t\tGender: " << temp->gender  << endl;
	  		cout <<"\n\t-------------------------------------------------------\n";
		}
    	temp = temp->next;
	}
	
}		  
void deleteStd(int roll_num)
{
    ofstream write;
    write.open("new.txt", ios::app | ios::out);
    ifstream dlt;
    dlt.open("student.txt", ios::app | ios::in);
    if (write.fail() || dlt.fail())
    {
        cout << "\nError Opening File." << endl;
    }
    while (dlt >> ws)
    {
        Person *temp = new Person;
        dlt.ignore();
        getline(dlt, temp->name);
        getline(dlt, temp->resident);
        getline(dlt, temp->ph_no);
        dlt >> temp->id;
        dlt >> temp->gender;
        dlt >> temp->age;
        dlt >> temp->studentClass;
        temp->next1 = NULL;
        if (temp->id == roll_num)
        {
            Person *ptr = head;
            if(ptr == NULL)
			{
				cout <<"Sorry, nothing to delete." << endl;
				return;
			}
			if(ptr->id == roll_num)
			{
				head = ptr->next;
				delete ptr;
				cout <<"Congratulation! Last student data deleted." << endl;
				return;
			}
            while (ptr->next != NULL)
            {
                if (ptr->id == roll_num)
                {
                    Person *ptr1 = ptr;
                    ptr->next = ptr1->next;
                    ptr = ptr->next;
                    delete ptr1;
                }
                else
                {
                    ptr = ptr->next;
                }
            }
        }
        else
        {
            write << temp->name << endl;
            write << temp->resident << endl;
            write << temp->ph_no << endl;
            write << temp->id << endl;
            write << temp->gender << endl;
            write << temp->age << endl;
            write << temp->studentClass << endl;

            if (head1 == NULL)
            {
                head1 = temp;
            }
            else
            {
                Person *temp1 = head1;
                while (temp1->next1 != NULL)
                {
                    temp1 = temp1->next1;
                }
                temp1->next1 = temp;
            }
        }
    }
    dlt.close();
    write.close();
    remove("student.txt");
    rename("new.txt", "student.txt");
    cout << "\nCongratulation! Data Deleted Successfully.\n\n";
}

void updateStd(int roll_num)
{
	Person * temp = head;
	while(temp != NULL)
	{
		if(temp->id == roll_num)
		{
			cout <<"Enter the name: ";
			cin.ignore();
			getline(cin, temp->name);
			cout <<"Enter the Resident of student: ";
			getline(cin, temp->resident);
			cout <<"Enter the Phone Number of student: ";
			getline(cin,temp->ph_no);
			cout <<"Enter the ID: ";
			cin>> temp->id;
			cout <<"Enter the Gender: ";
			cin >> temp->gender;
			cout <<"Enter the Age: ";
			cin >> temp->age;
			cout <<"Enter the student class: ";
	        cin>>temp->studentClass;
		}
		temp = temp->next;
	}
}
void addcandidate(int roll_num)
{
	Person *temp = head;
	string reason;
	while(temp!= NULL)
	{
		if(temp->id == roll_num)
		{
			
	    	cin.ignore();
		   	cout <<"what is your name?";
			getline(cin, reason);
			cout <<"what is your hobby?";
			getline(cin, reason);
			cout <<"why you want to be 'SVL', 'CLUB MEMBER', & 'GR'? ";
			getline(cin, reason);
			if(reason == "SVL")
			{
				Person * svl = new Person;
				svl->position = reason;
				if(head2== NULL)
				{
					head2 = svl;
				}
				else
				{
					Person * nextSvl = head2;
					while(nextSvl->next2 !=NULL)
					{
						nextSvl = nextSvl->next2;
					 }
					 nextSvl->next2 = svl; 
				}
			}
			else if(reason == "CLUB MEMBER")
			{
				Person * club = new Person;
				club->position = reason;
				if(head3== NULL)
				{
					head3 = club;
				}
				else
				{
					Person * nextClub = head3;
					while(nextClub->next3 !=NULL)
					{
						nextClub = nextClub->next3;
					 }
					 nextClub->next3 = club; 
				}
			}
			else if(reason == "GR")
			{
				Person * gr = new Person;
				gr->position = reason;
				if(head4 == NULL)
				{
					head4 = gr;
				}
				else
				{
					Person * nextGr = head4;
					while(nextGr->next4 !=NULL)
					{
						nextGr = nextGr->next4;
					 }
					 nextGr->next4 = gr; 
				}
			}
			cout <<"What is your previous result in your past life?";
			getline(cin, reason);
			cout <<"Do you think you can handle student in a good manner?";
			getline(cin, reason);
			cout <<"1. Add\n2. back" << endl;
			cin >> reason;
			if(reason == "1")
			{
				 system("cls");
				cout <<"Document Submitted Successfully" << endl;
				getch();
				system("cls");
			}
			else
			{
				system("cls"); 
			}
		
		}
		temp = temp->next;
	}
}
void voteForSVL() 
{
    string vote;
    Person *temp = head;
    cout << "\nVote for SVL\n\n";
    while (temp->next != NULL)
    {
        Person *svl = head2;
        cout << "Enter vote for student ID " << temp->id << " (svl1/svl2): ";
        cin >> vote;
        if (vote == "svl1") 
		{
            count1++;
        } 
		else if (vote == "svl2") 
		{
            count2++;
        }
        temp = temp->next;
    }

    cout << "\nVoting Results for SVL:\n";
    cout << "Total Votes for SVL1: " << count1 << endl;
    cout << "Total Votes for SVL2: " << count2 << endl;

    if (count1 > count2) 
	{
        cout << "SVL1 wins!" << endl;
    } 
	else if (count2 > count1) 
	{
        cout << "SVL2 wins." << endl;
    } 
	else 
	{
        cout << "It's a tie!" << endl;
    }
}

void voteForCM() 
{
    int student_id;
    Person *temp = head;
    cout << "\nVote for CLUB MEMBER\n\n";
    while (temp->next != NULL) 
	{
        Person *club = head3;
        cout << "Enter vote for student ID " << temp->id << " (cm1/cm2): ";
        cin >> student_id;

        if (student_id == temp->id) 
		{
            count3++;
        } 
		else 
		{
            count4++;
        }
        temp = temp->next;
    }

    cout << "\nVoting Results for Club Member:\n";
    cout << "Total Votes for CM1: " << count3 << endl;
    cout << "Total Votes for CM2: " << count4 << endl;

    if (count3 > count4) 
	{
        cout << "Club Member1 wins!" << endl;
    } 
	else if (count4 > count3) 
	{
        cout << "Club Member2 wins." << endl;
    } 
	else 
	{
        cout << "It's a tie!" << endl;
    }
}

void voteForGR() 
{
    int student_id;
    Person *temp = head;
    cout << "\nVote for GR\n\n";
    while (temp->next != NULL) 
	{
        Person *gr = head4;
        cout << "Enter vote for student ID " << temp->id << " (gr1/gr2): ";
        cin >> student_id;

        if (student_id == temp->id) 
		{
            count5++;
        } 
		else 
		{
            count6++;
        }
        temp = temp->next;
    }

    cout << "\nVoting Results for GR:\n";
    cout << "Total Votes for GR1: " << count5 << endl;
    cout << "Total Votes for GR2: " << count6 << endl;

    if (count5 > count6) 
	{
        cout << "GR1 wins!" << endl;
    } 
	else if (count6 > count5) 
	{
        cout << "GR2 wins." << endl;
    } 
	else 
	{
        cout << "It's a tie!" << endl;
    }
}

void menu()
{
					
	cout << "\n\n\t Select the following Key To Continue the Process: " << endl <<endl;
	cout << "\t 1.  Add the Student Details: " << endl;
	cout << "\t 2.  Check In Fees : " << endl;
	cout << "\t 3.  To Check Fees Receive or Not: " << endl;
	cout << "\t 4.  Generates Attendance Report: " << endl;
	cout << "\t 5.  Generates Attendance Fine: " << endl;
	cout << "\t 6.  Generates Academic Report: " <<endl;
	cout << "\t 7. Add Candidate: " << endl;
    cout << "\t 8. Vote for Candidate: " << endl;   
	cout << "\t 0.  Back To Menu : " << endl;
}




int main()
{
	
	int choice;
	Student s;
     readDetail();
	int student_id;
	cout<<endl<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"===   Wellcome to Superior  ==="<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"==== Superior Education Center ===="<<endl;
	cout<<"       "<<"======================================"<<endl;
	string password;
	cout <<"\n\nPlease Enter the Login Password: ";
	cin >> password;
	Admin ad;
	Password p1(ad, password);
	cout<<" \n\n\nPress Enter to Continue...";
	getch();
	system ("cls");

	cout << "\n\t\t\t\t*************************";
    cout << "\n\t\t\t\t STUDENT MANAGEMENT SYSTEM";
    cout << "\n\t\t\t\t      * MAIN MENU *";
    cout << "\n\t\t\t\t*************************";
    B:
	cout << "\n\n\n\t\t\t1. Add Student Details"<<endl;
	cout<<"\t\t\t2. Display Student Record"<<endl;
	cout<<"\t\t\t3. Search Student Record"<< endl;
	cout<<"\t\t\t4. Update Student Record"<< endl;
	cout<<"\t\t\t5. Delete Student Record"<< endl;
	cout<<"\t\t\t0. exit" <<endl;
	cout << "\n\t\t\tEnter Your Choice: ";
	cin>>choice;
    system ("cls");
    
    switch (choice)
	{
    	case 1: 
            A:
			menu();
           	cin >>choice;
           	system("cls");
		switch (choice)
		{
			case 1:
				{
					s.addStudent();
	                goto A;
                }
                
            case 2:
            	{
	            	s.CheckInFees();
	            	goto A;
            	}
            case 3:
            	{
	            	cout << "Enter the roll number of student whose fees you want to receive: ";
			        cin>>student_id;		 
	            	s.StudentFees(student_id);
	            	goto A;
            	}
            case 4:
            	{
	            	cout << "Enter student roll number whose attendance report you want to generate: ";
	                cin >> student_id;
	                s.generateAttendanceReport(student_id);
	                goto A;
            	}
            case 5:
	            {
					cout << "Enter student roll number whose attendance fine you want to generate: ";
	                cin >> student_id;
	                s.generateFine(student_id);
                	goto A;
                }
            case 6:
            	{
	            	cout << "Enter student roll number whose academic report you want to generate: ";
	 				cin >> student_id;
	 				s.generateAcademicReport(student_id);
 					goto A;
 				}
 			case 7:
 				{
					int  rollNumber;
                    cout << "Enter the roll number of the candidate: ";
                    cin >> rollNumber;
                    addcandidate(rollNumber);
                    goto A;
                }
                case 8:
                	{
                	cout <<"1. Election For SVl " << endl;
                	cout <<"2. Election for Club Member " << endl;
                	cout <<"3. Election for GR " << endl;
                	cin >> choice;
                	switch(choice)
                	{
                		case 1:
                			voteForSVL();
                			goto A;
                		case 2:
                			voteForCM();
                			goto A;
                		case 3:
                			voteForGR();
                			goto A;
					}
                }
            case 0:
            	goto B;
			}
			break;
		case 2:
	    	{
	    	cout << "Enter the ID of student to search: ";	 
				cin>>student_id;
			  s.displayStudent(student_id);
			   goto B;
		    }
		case 3:
		    {
		  		cout << "Enter the ID of student to search: ";	 
				cin>>student_id;
				searchStudent(student_id);
				goto B;
			}
	  	case 4:
		{
		    cout << "Enter the ID of student to Update: ";	 
			cin>>student_id;
			updateStd(student_id);
			goto B;
		}
		case 5:
			{
			    cout << "Enter the ID of student to delete: ";	 
				cin>>student_id;
				deleteStd(student_id);
				goto B;
			}
	
		case 0:
				cout <<"\n\nThank You For visiting My Education Center." << endl;
				exit(0);
}
}
