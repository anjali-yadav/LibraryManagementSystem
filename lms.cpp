#include<bits/stdc++.h>
#include<windows.h>
#include <conio.h>
#include<iomanip>
#include<iostream>
#include <stdlib.h>
#include<string>
#include <cstdio>
#include<stdio.h>
using namespace std;

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}


class book 
{
    char bno[6];
    char bname[50];
    char aname[20];
    public:
    void createbook()
    {
        
        cout<<"\nCREATE BOOK "<<endl;
        cout<<"\nEnter the book no. ";
        cin>>bno;
        cout<<"\nEnter Book Name";
        gets(bname);
        cout<<"Enter author name";
        gets(aname);
        
        cout<<"\n\nBOOK CREATED!!"<<endl;
    }
    void showbook()
    {
        cout<<endl;
        cout<<"Book NO. : "<<bno<<endl;
        cout<<"Book Name. : ";
        puts(bname);
        cout<<endl;
        cout<<"Author Name. : ";
        puts(aname);
        cout<<endl;

    }
    void modifybook()
    {
        cout<<"Book Number : "<<bno<<endl;
        cout<<"Modify Book Name : ";
        gets(bname);
        cout<<"Modify Author Name : ";
        gets(aname);
    }
    char* retbno()
    {
        return bno;
    }

    void report()
    {
        cout<<bno<<setw(20);
        puts(bname);
        cout<<setw(25);
        puts(aname);
        cout<<endl;

    }
};

class student 
{
    char admno[6];
    char name[20];
    char stbno[6];
    int token;
    public:
    void createstudent ()
    {
        system("cls");
        
        cout<<"\n ADD NEW STUDENT \n";
        cout<<"\n Enter the admission no. ";
        cin>>admno;
        
        
        cout<<"\nEnter the student name";
        cin.get(name,20, '\n');
        
        token=0;
        stbno[0]='\0';
        cout<<"Student Record Created"<<endl;

    }

    void showstudent() 
    {
        cout<<"Admission no. : "<<admno<<endl;
        cout<<"Student name : ";
        puts(name);
        cout<<"Number of books issued : "<<token<<endl;
        if(token==1)
        {
            cout<<"Book No. : "<<stbno<<endl;
        }
    }

    void modifystudent()
    {
        cout<<"Admission no. : "<<admno<<endl;
        cout<<"Modify Student name : ";
        gets(name);
    }

    char* retadmno()
    {
        return admno;
    }

    char* retstbno()
    {
        return stbno;
    }

    int rettoken()
    {
        return token;
    }

    void addtoken()
    {
        token=1;
    }

    void resettoken()
    {
        token=0;
    }

    void getstbno(char t[])
    {
        strcpy(stbno, t);

    }

    void report ()
    {
        cout<<"\t"<<admno<<setw(10)<<name<<setw(20)<<token<<endl;
    }
};

fstream fp, fp1;
book bk;
student st;

void writestudent()
{
    char ch;
    fp.open("student.dat", ios::out | ios::app);
    do{
        system("cls");
        st.createstudent();
        fp.write((char*)&st, sizeof(student));
        cout<<endl;
        cout<<"Do you want to add more record..(y/n)";
        cin>>ch;

    } while (ch=='y'||ch=='Y');
    fp.close();
}


void writebook()
{
    char ch;
    fp.open("book.dat", ios::out | ios::app);
    do{
        system("cls");
        bk.createbook();
        fp.write((char*)&bk, sizeof(book));
        cout<<endl;
        cout<<"Do you want to add more record..(y/n)";
        cin>>ch;

    } while (ch=='y'||ch=='Y');
    fp.close();
}

void displayspb(char n[])
{
    cout<<endl;
    cout<<"BOOK DETAILS"<<endl;
    int flag=0;
    fp.open ("book.dat", ios::in);
    while(fp.read((char* )&bk, sizeof(book)))
    {
        if(strcmpi(bk.retbno(), n)==0)
        {
            bk.showbook();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)
    {
        cout<<endl;
        cout<<"BOOK DOES NOT EXIST"<<endl;
        
    }
    getch();
}

void displaysps(char n[])
{
    cout<<endl;
    cout<<"STUDENT DETAILS"<<endl;
    int flag=0;
    fp.open ("student.dat", ios::in);
    while(fp.read((char* )&st, sizeof(student)))
    {
        if(strcmpi(st.retadmno(), n)==0)
        {
            st.showstudent();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)
    {
        cout<<endl;
        cout<<"STUDENT DOES NOT EXIST"<<endl;
        
    }
    getch();
}

void modifybook()
{
    char n[6];
    int found=0;
    system("cls");
    cout<<endl;
    cout<<"MODIFY BOOK RECORD"<<endl;
    cout<<endl;
    cout<<"ENTER THE BOOK NUMBER : ";
    cout<<endl;
    cin>>n;
    fp.open("book.dat", ios::in | ios:: out);
    while(fp.read((char* )&bk, sizeof(book)) && found == 0)
    {
        if(strcmpi(bk.retbno(), n)==0 )
        {
            bk.showbook();
            cout<<endl;
            cout<<"ENTER NEW DETAILS OF BOOK"<<endl;
            bk.modifybook();
            int pos = -1*sizeof(bk);
            fp.seekp(pos, ios::cur);
            fp.write((char*)&bk, sizeof(book));
            cout<<endl;
            cout<<"RECORD UPDATED"<<endl;
            found=1;
        }
    }
    fp.close();
    if(found==0)
    {
        cout<<endl;
        cout<<"RECORD NOT FOUND"<<endl;
    }

    getch();

}

void modifystudent()
{
    char n[6];
    int found=0;
    system("cls");
    cout<<endl;
    cout<<"MODIFY STUDENT RECORD"<<endl;
    cout<<endl;
    cout<<"ENTER THE ADMISSION NUMBER : ";
    cout<<endl;
    cin>>n;
    fp.open("student.dat", ios::in | ios:: out);
    while(fp.read((char* )&st, sizeof(student)) && found == 0)
    {
        if(strcmpi(st.retadmno(), n)==0 )
        {
            st.showstudent();
            cout<<endl;
            cout<<"ENTER NEW DETAILS OF STUDENT"<<endl;
            st.modifystudent();
            int pos = -1*sizeof(st);
            fp.seekp(pos, ios::cur);
            fp.write((char*)&st, sizeof(student));
            cout<<endl;
            cout<<"RECORD UPDATED"<<endl;
            found=1;
        }
    }
    fp.close();
    if(found==0)
    {
        cout<<endl;
        cout<<"RECORD NOT FOUND"<<endl;
    }

    getch();

}

void deletestudent() 
{
    char n[6];
    int flag=0;
    system("cls");
    cout<<"DELETE STUDENT"<<endl;
    cout<<"Enter the admission no. : "<<endl;
    cin>>n;
    fp.open("student.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while(fp.read((char* )&st, sizeof(student)))
    {
        if(strcmpi(st.retadmno(),n)!=0)
        {
            fp2.write((char* )&st, sizeof(student));
        }
        else
        {
            flag=1;
        }
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
    if(flag==1)
    {
        cout<<endl;
        cout<<"RECORD DELETED";

    }
    else
    {
        cout<<endl;
        cout<<"RECORD NOT FOUND"<<endl;
    }
    getch();
}

void deletebook() 
{
    char n[6];
    int flag=0;
    system("cls");
    cout<<"DELETE BOOK"<<endl;
    cout<<"Enter the book no. : "<<endl;
    cin>>n;
    fp.open("book.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while(fp.read((char* )&bk, sizeof(book)))
    {
        if(strcmpi(bk.retbno(),n)!=0)
        {
            fp2.write((char* )&bk, sizeof(book));
        }
        else
        {
            flag=1;
        }
    }
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat", "book.dat");
    if(flag==1)
    {
        cout<<endl;
        cout<<"RECORD DELETED";

    }
    else
    {
        cout<<endl;
        cout<<"RECORD NOT FOUND"<<endl;
    }
    getch();
}

void displayalls()
{
    system("cls");
    fp.open("student.dat", ios::in);
    if(!fp)
    {
        cout<<endl;
        cout<<"FILE COULD NOT BE OPENED"<<endl;
        getch();
        return;
    }
    else
    {
        cout<<endl;
        cout<<"\t Student List"<<endl;
        cout<<"-----------------------------------------------------------------------------------------"<<endl;
        cout<<"\t Admission no."<<setw(10)<<"Name"<<setw(20)<<"Book issued"<<endl;
        cout<<"------------------------------------------------------------------------------------------"<<endl;
        while(fp.read((char *)&st, sizeof(student)))
        {
            st.report();

        }
        fp.close();
        getch();
    }
}

void displayallb()
{
    system("cls");
    fp.open("book.dat", ios::in);
    if(!fp)
    {
        cout<<endl;
        cout<<"FILE COULD NOT BE OPENED"<<endl;
        getch();
        return;
    }
    else
    {
        cout<<endl;
        cout<<"\t Book List"<<endl;
        cout<<"-----------------------------------------------------------------------------------------"<<endl;
        cout<<"\t Book no."<<setw(20)<<"Book Name"<<setw(25)<<"Author"<<endl;
        cout<<"------------------------------------------------------------------------------------------"<<endl;
        while(fp.read((char *)&bk, sizeof(book)))
        {
            bk.report();
        }
        fp.close();
        getch();
    }
}

void bookissue()
{
    char sn[6], bn[6];
    int found=0, flag=0;
    system("cls");
    cout<<"\n\nBOOK ISSUE"<<endl;
    cout<<"\n\n\tEnter student admission number"<<endl;
    cin>>sn;
    fp.open("student.dat", ios::in|ios::out);
    fp1.open("book.dat", ios::in| ios::out);
    while(fp.read((char *)&st, sizeof(student))&& found==0)
    {
        if(strcmpi(st.retadmno(), sn)==0)
        {
            found=1;
            if(st.rettoken()==0)
            {
                cout<<"\n\tEnter the book no.";
                cin>>bn;
                while(fp1.read((char *)&bk, sizeof(book))&& flag==0)
                {
                    if(strcmpi(bk.retbno(), bn)==0)
                    {
                        flag=1;
                        st.addtoken();
                        st.getstbno(bk.retbno());
                        int pos= -1*sizeof(st);
                        fp.seekg(pos, ios::cur);
                        fp.write((char *)&st, sizeof(student));
                        cout<<endl;
                        cout<<"BOOK ISSUE SUCCESSFUL"<<endl;
                        cout<<"Write book issue date on the backside of book and return the book within 10 days.\nFine:Rs.10 per day "<<endl;

                    }
                }
                if(flag==0)
                {
                    cout<<"Book doesn't exist"<<endl;
                }
                
            }
            else
            {
                cout<<"RETURN THE LAST BOOK"<<endl;
            }
        }
    }
    if(found==0)
    {
        cout<<endl;
        cout<<"STUDENT RECORD NOT FOUND"<<endl;
    }
    getch();
    fp.close();
    fp1.close();
}

void bookdeposit()
{
    char sn[6], bn[6];
    int found=0, flag=0, day, fine;
    system("cls");
    cout<<"\n\nBOOK DEPOSIT"<<endl;
    cout<<"\n\n\tEnter student admission number"<<endl;
    cin>>sn;
    fp.open("student.dat", ios::in|ios::out);
    fp1.open("book.dat", ios::in| ios::out);
    while(fp.read((char *)&st, sizeof(student))&& found==0)
    {
        if(strcmpi(st.retadmno(), sn)==0)
        {
            found=1;
            if(st.rettoken()==1)
            {
                
                while(fp1.read((char *)&bk, sizeof(book))&& flag==0)
                {
                    if(strcmpi(bk.retbno(), st.retstbno())==0)
                    {
                        flag=1;
                        bk.showbook();
                        cout<<endl;
                        cout<<"Book deposited in no. of days"<<endl;
                        int day;
                        cin>>day;
                        int fine;
                        if(day>10)
                        {
                            fine=(day-10)*10;
                            cout<<"Fine is Rs."<<fine<<endl;
                        }
                    
                        st.resettoken();
                        
                        int pos= -1*sizeof(st);
                        fp.seekg(pos, ios::cur);
                        fp.write((char *)&st, sizeof(student));
                        cout<<endl;
                        cout<<"BOOK DEPOSIT SUCCESSFUL"<<endl;
                        
                    }
                }
                if(flag==0)
                {
                    cout<<"Book doesn't exist"<<endl;
                }
                
            }
            else
            {
                cout<<"NO BOOK WAS ISSUED"<<endl;
            }
        }
    }
    if(found==0)
    {
        cout<<endl;
        cout<<"STUDENT RECORD NOT FOUND"<<endl;
    }
    getch();
    fp.close();
    fp1.close();
}

void start()
{
    system("cls"); 
    gotoxy(35,1);
    cout<<"LIBRARY"<<endl;

    gotoxy(35,3);
    cout<<"MANAGEMENT"<<endl;

    gotoxy(35,5);
    cout<<"SYSTEM"<<endl;

    cout<<endl;
    cout<<"BY ANJALI YADAV"<<endl;
    cout<<"Press Enter"<<endl;

    getch();
}

void adminmenu() {
    system("cls");
    int ch2;
    cout<<endl;
    cout<<"\t ADMIN MENU:"<<endl;
    cout<<"\t1) Create Student Record"<<endl;
    cout<<"\t2) Display All Students Record"<<endl;
    cout<<"\t3) Display Specific Student Record"<<endl;
    cout<<"\t4) Modify Student Record"<<endl;
    cout<<"\t5) Delete Student Record"<<endl;
    cout<<"\t6) Create Book"<<endl;
    cout<<"\t7) Display All Books"<<endl;
    cout<<"\t8) Display Specific Book"<<endl;
    cout<<"\t9) Modify Book Record"<<endl;
    cout<<"\t10) Delete Book Record"<<endl;
    cout<<"\t11) Back TO MAIN MENU"<<endl;
    cout<<"\t Enter an option"<<endl;
    cin>>ch2;
    switch(ch2)
    {
        case 1:
        writestudent();
        break;

        case 2:
        displayalls();
        break;

        case 3:
        {char num[6];
        system("cls");
        cout<<"Enter the admission no."<<endl;
        cin>>num;
        displaysps(num);
        }
        break;

        case 4:
        modifystudent();
        break;

        case 5:
        deletestudent();
        break;

        case 6:
        writebook();
        break;

        case 7:
        displayallb();
        break;

        case 8:
        {
            char num[6];
            system("cls");
            cout<<"Enter the book no."<<endl;
            cin>>num;
            displayspb(num);
        }
        break;

        case 9:
        modifybook();
        break;

        case 10:
        deletebook();
        break;

        case 11:
            return;
        break;

        default :
        cout<<"Invallid choice, try again"<<endl;

    }
    adminmenu();
}

int main ()
{
    system("cls"); 
    char ch;
    start();

    do
    {
        system("cls"); 
        cout<<endl;
        cout<<endl;
        cout<<"\t";
        cout<<"MAIN MENU"<<endl;
        cout<<"\t1)  BOOK ISSUE"<<endl;
        cout<<"\t2)  BOOK DEPOSIT"<<endl;
        cout<<"\t3)  ADMINISTRATOR MENU"<<endl;
        cout<<"\t4)  EXIT"<<endl;
        cout<<"\t Select options between 1 and 4"<<endl;
        ch=getche();
        switch(ch)
        {
            case '1' : 
            bookissue();
            break;

            case '2' :
            bookdeposit();
            break;

            case '3' :
            adminmenu();
            break;

            case '4' :
            exit(0);
            break;

            default  :
            cout<<"Invalid Option" <<endl;
        }
    } while(ch!=4);
    
    getch();
    return 0;
}