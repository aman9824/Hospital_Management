/*--------------------------------------------------------*/
/*	            Header files                          */
/*--------------------------------------------------------*/

#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<graphics.h>
#include<dos.h>

/*---------------------------------------------------------*/
/*                           Function Protoype             */
/*---------------------------------------------------------*/


void menuq();
void assign(int );
void menu();


/*--------------------------------------------------------*/
/*                                CLASSES	          */
/*--------------------------------------------------------*/

class doctor
{
	int idd;
	char named[20];
	int age;
	char type[30];
	char address[20];
	char time[10];
	long nod;

	public:

	doctor()
	{
		idd=age=nod=z=0;
		strcpy(named,"not");
		strcpy(type,"not");
		strcpy(address,"not");
		strcpy(type,"not");
	}
	int z;
	void getdatad();
	void putdatad();
	int getrno();
	void modifyd();
};

class patient
{
	int roomno;
	char namep[20];
	int agep;
	char disease[30];
	char roomtype[5];
	char address[20];
	long nop;
	int b;
	long pay;

	public:

	patient()
	{
		agep=roomno=nop=z=pay=b=0;
		strcpy(namep,"not");
		strcpy(disease,"not");
		strcpy(roomtype,"not");
		strcpy(address,"not");
	}

	int z;

	void getpay(long n)
	{	pay=pay+n;	}
	long gpay()
	{	return pay;	}
	void putpay(long b)
	{	cout<<setfill(' ')<<setw(14)<<b;	}
	void getdatap();
	void days()
	{
		if(strcmp(roomtype,"ac")==0)
		{
			pay=pay+(1000*b);
		}
		else
		{
			pay=pay+(700*b);
		}
	}
	void putdatap();
	int getrno();
	void modifyp();
	void assign(int e);
	void paypay(int f)
	{
	      pay=pay-f;
	}

};

class medicine
{
	int mno;
	char name[20];
	char dom[20];
	char doe[20];
	int mrp;

	public:

	medicine()
	{
		mno=mrp=0;
		strcpy(name,"not");
		strcpy(dom,"not");
		strcpy(doe,"not");
	}

	void getq(int q)
	{	mno=q;	}
	void getdatam();
	void putdatam();
	int getrno()
	{	return mno;	}
	int getmrp()
	{	return mrp;	}
	void modifym();
	void amt();
	void bi();
	void bii(int z[20],int n,long b);
};


/*---------------------------------------------------------*/
/*	            Functions                              */
/*---------------------------------------------------------*/

/*---------------------------------------------------------*/
/*	            Functions MEDICINE	                   */
/*---------------------------------------------------------*/


void medicine::getdatam()
{
	cout<<"\nEnter Medicine Name :";
	gets(name);
	cout<<"\nEnter Date of Manufacturing of Medicine :";
	gets(dom);
	cout<<"\nEnter Date of Expiry of Medicine :";
	gets(doe);
	cout<<"\nEnter Price of Medicine :";
	cin>>mrp;
}

void medicine::putdatam()
{
	cout<<"\n Medicine Number :"<<mno;
	cout<<"\n Medicine Name :"<<name;
	cout<<"\n Date of Manufacturing of Medicine :"<<dom;
	cout<<"\n Date of Expiry of Medicine :"<<doe;
	cout<<"\n Price of Medicine :"<<mrp;
}

void medicine::modifym()
{
	char named[20];
	char domd[20];
	char doed[20];
	int mrpd;

	mrpd=0;
	strcpy(named,"not");
	strcpy(domd,"not");
	strcpy(doed,"not");


	cout<<"\nEnter Medicine Name (Press . to keep it unchange):";
	gets(named);
	cout<<"\nEnter Date of Manufacturing of Medicine (Press . to keep it unchange):";
	gets(domd);
	cout<<"\nEnter Date of Expiry of Medicine (Press . to keep it unchange):";
	gets(doed);
	cout<<"\nEnter Price of Medicine (Press -1 to keep it unchange):";
	cin>>mrpd;

	if(mrpd!=(-1))
	{	mrp=mrpd;	}
	if(strcmp(named,".")!=0)
	{	strcpy(name,named);	}
	if(strcmp(domd,".")!=0)
	{	strcpy(dom,domd);	}
	if(strcmp(doed,".")!=0)
	{	strcpy(doe,doed);	}

}

void medicine::amt()
{       clrscr();
	long b=0;
	patient p;
	medicine m;
	ifstream ifile2;
	fstream og;
	int z[20];
	int q=0,n=0,flag=0;
	long pos=0;
	q=q-1;
	og.open("patient.dat",ios::in|ios::out);
	cout<<"\nEnter Ward Number of patient for which you want to buy medicine ";
	cin>>n;
	while(!og.eof())
	{       pos=og.tellg();
		og.read((char*)&p,sizeof(p));
		if(og.eof())
		break;
		if(p.getrno()==n)
		{       p.putdatap();
			delay(2000);

			m.bi();

			do
			{
				q++;
				cin>>z[q];
			}while(z[q]!=(100));

			ifile2.open("m.dat",ios::in);
			int l=0;
			while(!ifile2.eof())
			{
				l=0;
				ifile2.read((char*)&m,sizeof(m));
				if(ifile2.eof())
				break;
				do
				{
					if(z[l]==m.getrno())
					{
						b=b+m.getmrp();
					}
					l++;
				}while(z[l]!=100);
			}

			p.getpay(b);

			og.seekg(pos);

			og.write((char*)&p,sizeof(p));

			cout<<"\n\nCreating bill ";
			for(int o=0;o<4;o++)
			{	cout<<".";	delay(1000);	}

			flag=1;

			ifile2.close();
		}
	}
	if(flag==0)
	{	cout<<"\npatient Details Not Found .";	}
	og.close();

	ifile2.open("patient.dat",ios::in);
	while(!ifile2.eof())
	{
		ifile2.read((char*)&p,sizeof(p));
		if(ifile2.eof())
		break;
		if(p.getrno()==n)
		{
			m.bii(z,n,b);
			delay(4000);
		}
	}
	ifile2.close();

}

void medicine::bi()
{       clrscr();
	medicine m;
	int i=0;
	ifstream ifile2;
	ifile2.open("m.dat",ios::in);
	clrscr();
	cout<<"\n|------------------------------------------------------|";
	cout<<"\n|		    MEDICINE	        |     Price    |";
	cout<<"\n|------------------------------------------------------|";
	while(!ifile2.eof())
	{	i++;
		ifile2.read((char*)&m,sizeof(m));
		if(ifile2.eof())
		break;
		cout.setf(ios::left);
		cout<<"\n|"<<i<<".";
		cout<<setfill(' ')<<setw(37)<<m.name;
		cout<<"|";
		cout<<setfill(' ')<<setw(14)<<m.mrp;
		cout<<"|";
	}
	cout<<"\n|------------------------------------------------------|";
	ifile2.close();

	cout<<"\n\nSelect Your Medicines (100 to terminate):";
}

void medicine::bii(int z[20],int n,long b)
{
	clrscr();
	medicine m;
	patient p;
	int i=0,q=1;
	ifstream ifile2;
	ifstream ifile;
	ifile2.open("m.dat",ios::in);
	cout<<"\n|-------------------------------------------------------|";
	cout<<"\n|		    MEDICINE	         |    Price     |";
	cout<<"\n|-------------------------------------------------------|";
	while(!ifile2.eof())
	{	i=0;
		ifile2.read((char*)&m,sizeof(m));
		if(ifile2.eof())
		break;
		do{
			if(z[i]==m.getrno())
			{
				cout.setf(ios::left);
				cout<<"\n|"<<q<<".";
				cout<<setfill(' ')<<setw(38)<<m.name;
				cout<<"|";
				cout<<setfill(' ')<<setw(14)<<m.mrp;
				cout<<"|";
				q++;
			}
			i++;
		}while(z[i]!=0);

	}
	cout<<"\n|-------------------------------------------------------|";
	cout.setf(ios::left);
	cout<<"\n|";
	cout<<setfill(' ')<<setw(40)<<"Total";
	cout<<"|";
	ifile.open("patient.dat",ios::in);
	while(!ifile.eof())
	{	ifile.read((char*)&p,sizeof(p));
		if(ifile.eof())
		break;
		if(p.getrno()==n)
		{
			p.putpay(b);
		}
	 }
	 ifile.close();
	cout<<"|";
	cout<<"\n|-------------------------------------------------------|";
	ifile2.close();

}

void menum()
{
	int z=0;
	do
	{
	clrscr();
	medicine m;
	ifstream ifile2;
	ofstream ofile;
	fstream og;
	int flag=0,n=0;
	cout<<"\n\n\t\t\t\t MEDICINE MENU";
	cout<<"\n\n\t01. Add Medicine stock";
	cout<<"\n\n\t02. Medicine Detail";
	cout<<"\n\n\t03. Search Medicine Details";
	cout<<"\n\n\t04. Modify Medicine Details";
	cout<<"\n\n\t05. Remove Medicine Stock";
	cout<<"\n\n\t06. Buy Medicine";
	cout<<"\n\n\t07. Return to main menu";
	cout<<"\n\n\t08. Exit";
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\tSelect Your Option (1-8) :";
	cin>>z;
	switch(z)
	{
		case 1 : {	clrscr();
				int  q=1;
				ifile2.open("m.dat",ios::in);
				while(!ifile2.eof())
				{
					ifile2.read((char*)&m,sizeof(m));
					if(ifile2.eof())
					break;
					if(m.getrno()==0)
					{	break;	}
					else
					{	q++;	}

				}
				ifile2.close();
				ofile.open("m.dat",ios::app);
				{
					m.getq(q);
					m.getdatam();
					ofile.write((char*)&m,sizeof(m));
				}
				ofile.close();
				break;
			 }
		case 2 : {	clrscr();
				ifile2.open("m.dat",ios::in);
				while(!ifile2.eof())
				{
					cout<<"\n-------------------------------------------------------------------"<<endl;
					ifile2.read((char*)&m,sizeof(m));
					if(ifile2.eof())
					break;
					m.putdatam();
					delay(2000);
				}
				ifile2.close();
				break;
			 }
		case 3 : {	clrscr();
				ifile2.open("m.dat",ios::in);
				cout<<"Enter Medicine Number You want to search :";
				cin>>n;
				while(!ifile2.eof())
				{
					ifile2.read((char*)&m,sizeof(m));
					if(ifile2.eof())
					break;
					if(m.getrno()==n)
					{
						m.putdatam();
						flag=1;
						delay(2000);
					}
				}
				if(flag==0)
				{	cout<<"\nMedicine not Found .";	}
				ifile2.close();
				break;
			 }
		case 4 : {	clrscr();
				flag=0;
				long pos;
				og.open("m.dat",ios::in|ios::out);
				cout<<"Enter Medicine number you want to modify ";
				cin>>n;
				while(!og.eof())
				{
					pos=og.tellg();
					og.read((char*)&m,sizeof(m));
					if(og.eof())
					break;
					if(m.getrno()==n)
					{
						m.modifym();
						og.seekg(pos);
						og.write((char*)&m,sizeof(m));
						cout<<"\nModified Details are "<<endl;
						m.putdatam();
						flag=1;
						delay(2000);
						break;
					}
				}
				if(flag==0)
				{	cout<<"\nMedicine Details Not Found .";	}
				og.close();
				break;
			 }
		case 5 : {	clrscr();
				flag=0;
				ofile.open("temp.dat",ios::out);
				ifile2.open("m.dat",ios::in);
				int q;
				char e='y';
				cout<<"Enter Medicine number you want to serch ";
				cin>>q;
				while(!ifile2.eof())
				{
					ifile2.read((char*)&m,sizeof(m));
					if(ifile2.eof())
					break;
					if(m.getrno()==q)
					{
						m.putdatam();
						flag=1;
						cout<<"Are you sure you want to delete (y/n)";
						cin>>e;
						if(n=='n')
						ofile.write((char*)&m,sizeof(m));
					 }
					 else
					 {
						ofile.write((char*)&m,sizeof(m));
					 }
				}
				if(flag==0)
				cout<<"Medicine details not found ";
				else
				cout<<"Record Deleted ";
				ifile2.close();
				ofile.close();
				remove("m.dat");
				rename("temp.dat","m.dat");
				break;
			 }

		case 6 : m.amt();	break;
		case 7 : menu();	break;
		case 8 : {	clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t THANK YOU FOR VISITING ";
				for(int i=0;i<4;i++)
				{      cout<<".";
				       delay(1000);
				}
				delay(1000);
				exit(0);
			  }
	}
	}while(z!=8);
}
/*---------------------------------------------------------*/
/*	            Functions DOCTOR	                   */
/*---------------------------------------------------------*/


void menud()
{       int z=0;
	do
	{
	clrscr();
	doctor d;
	ifstream ifile;
	ofstream ofile;
	fstream og;
	int n=0,flag=0;
	cout<<"\n\n\t\t\t\t DOCTOR MENU";
	cout<<"\n\n\t01. Add New Doctor Details";
	cout<<"\n\n\t02. Doctors Detail";
	cout<<"\n\n\t03. Search Doctor Details";
	cout<<"\n\n\t04. Modify Doctor Details";
	cout<<"\n\n\t05. Delete Doctor Details";
	cout<<"\n\n\t06. Return to main menu";
	cout<<"\n\n\t07. Exit";
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\tSelect Your Option (1-7) :";
	cin>>z;
	switch(z)
	{
		case 1 : {	clrscr();
				ofile.open("doctor.dat",ios::app);
				{
					d.getdatad();
					ofile.write((char*)&d,sizeof(d));
				}
				ofile.close();
				break;
			 }
		case 2 : {	clrscr();
				ifile.open("doctor.dat",ios::in);
				while(!ifile.eof())
				{
					cout<<"\n-------------------------------------------------------------------"<<endl;
					ifile.read((char*)&d,sizeof(d));
					if(ifile.eof())
					break;
					d.putdatad();
					delay(2000);
				}
				ifile.close();
				break;
			 }
		case 3 : {	clrscr();
				ifile.open("doctor.dat",ios::in);
				cout<<"Enter id number of doctor you want to serch ";
				cin>>n;
				while(!ifile.eof())
				{
					ifile.read((char*)&d,sizeof(d));
					if(ifile.eof())
					break;
					if(d.getrno()==n)
					{
						d.putdatad();
						delay(2000);
						flag=1;
					}
				}
				if(flag==0)
				{	cout<<"\nDoctor Details Not Found .";	}
				ifile.close();
				break;
			 }
		case 4 : {	clrscr();
				flag=0;
				long pos;
				og.open("doctor.dat",ios::in|ios::out);
				cout<<"Enter id number of doctor you want to modify ";
				cin>>n;
				while(!og.eof())
				{
					pos=og.tellg();
					og.read((char*)&d,sizeof(d));
					if(og.eof())
					break;
					if(d.getrno()==n)
					{
						d.modifyd();
						og.seekg(pos);
						og.write((char*)&d,sizeof(d));
						cout<<"\nModified Details are "<<endl;
						d.putdatad();
						delay(2000);
						flag=1;
						break;
					}
				}
				if(flag==0)
				{	cout<<"\nDoctor Details Not Found .";	}
				og.close();
				break;
			 }
		case 5 : {	clrscr();
				flag=0;
				ofile.open("temp.dat",ios::out);
				ifile.open("doctor.dat",ios::in);
				int q;
				char e='y';
				cout<<"Enter id number of doctor you want to serch ";
				cin>>q;
				while(!ifile.eof())
				{
					ifile.read((char*)&d,sizeof(d));
					if(ifile.eof())
					break;
					if(d.getrno()==q)
					{
						d.putdatad();
						flag=1;
						cout<<"Are you sure you want to delete (y/n)";
						cin>>e;
						if(n=='n')
						ofile.write((char*)&d,sizeof(d));
					 }
					 else
					 {
						ofile.write((char*)&d,sizeof(d));
					 }
				}
				ifile.close();
				ofile.close();
				remove("doctor.dat");
				rename("temp.dat","doctor.dat");
				if(flag==0)
				{	cout<<"\nDoctor Details not found ";	}
				else
				{	cout<<"Record Deleted ";	}
				break;
			 }
		case 6 : menu();	break;
		case 7 : {	clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t THANK YOU FOR VISITING ";
				for(int i=0;i<4;i++)
				{      cout<<".";
				       delay(1000);
				}
				delay(1000);
				exit(0);
			  }
	}
	}while(z!=7);
}

void doctor::getdatad()
{       int flag=1;
	cout<<"\nEnter Doctor ID Number :";
	cin>>idd;
	cout<<"\nEnter Doctor Name :";
	gets(named);
	cout<<"\nEnter Doctor Age :";
	cin>>age;
	cout<<"\nSelect Type of Doctor :";
	do{	int h=0;
		cout<<"\n1. Allergist ";
		cout<<"\n2. Andrologist ";
		cout<<"\n3. Cardiologist ";
		cout<<"\n4. Emergency (ER) Doctor ";
		cout<<"\n5. Hyperbaric Physician ";
		cout<<"\n6. Infectious Disease Specialist ";
		cout<<"\n7. Neurologist ";
		cout<<"\n8. Neurosurgeon ";
		cout<<"\n9. Oncologist ";
		cout<<"\n10. Ophthalmologist ";
		cin>>h;
		switch(h)
		{
			case 1 : {	strcpy(type,"Allergist");	z=1;	}	break;
			case 2 : {	strcpy(type,"Andrologist");	z=2;	}	break;
			case 3 : {	strcpy(type,"Cardiologist");	z=3;	}	break;
			case 4 : {	strcpy(type,"Emergency (ER) Doctor");	z=4;		}	break;
			case 5 : {	strcpy(type,"Hyperbaric Physician");	z=5;	}	break;
			case 6 : {	strcpy(type,"Infectious Disease Specialist"); z=6;	}	break;
			case 7 : {	strcpy(type,"Neurologist");  z=7;	}	break;
			case 8 : {	strcpy(type,"Neurosurgeon");	z=8;	}	break;
			case 9 : {	strcpy(type,"Oncologist");	z=9;	}	break;
			case 10 :{	strcpy(type,"Ophthalmologist");	z=10;	}	break;
			default : { cout<<"Wrong Option selected ";
				    flag=0;
				  }
		}
	}while(flag==0);
	cout<<"\nEnter Doctor Address :";
	gets(address);
	cout<<"\nEnter Doctor Shift :";
	gets(time);
	cout<<"\nEnter Doctor contact Number :";
	cin>>nod;
}


void doctor::putdatad()
{
	cout<<"\nDoctor ID Number : "<<idd;
	cout<<"\nDoctor Name : "<<named;
	cout<<"\nDoctor Age : "<<age;
	cout<<"\nType of Doctor : "<<type;
	cout<<"\nDoctor Address : "<<address;
	cout<<"\nDoctor Shift : "<<time;
	cout<<"\nDoctor contact Number : "<<nod;
}

void doctor::modifyd()
{
	int no=0,aged=0,flag=1;
	long mo=0;
	char namedd[20],typed[30],addressd[20],timed[10];
	strcpy(namedd,"not");
	strcpy(typed,"not");
	strcpy(addressd,"not");
	strcpy(timed,"not");

	cout<<"\nEnter Doctor ID Number (Press -1 to keep it unchange) :";
	cin>>no;
	cout<<"\nEnter Doctor Name (Press . to keep it unchange):";
	gets(namedd);
	cout<<"\nEnter Doctor Age (Press -1 to keep it unchange) :";
	cin>>aged;
	cout<<"\nEnter Type of Doctor (Press -1 to keep it unchange):";
	cout<<"\nSelect Type of Doctor :";
	do{	int h=0;
		cout<<"\n1. Allergist ";
		cout<<"\n2. Andrologist ";
		cout<<"\n3. Cardiologist ";
		cout<<"\n4. Emergency (ER) Doctor ";
		cout<<"\n5. Hyperbaric Physician ";
		cout<<"\n6. Infectious Disease Specialist ";
		cout<<"\n7. Neurologist ";
		cout<<"\n8. Neurosurgeon ";
		cout<<"\n9. Oncologist ";
		cout<<"\n10. Ophthalmologist ";
		cin>>h;
		switch(h)
		{
			case -1 : break;
			case 1 : {	strcpy(type,"Allergist");	z=1;	}	break;
			case 2 : {	strcpy(type,"Andrologist");	z=2;	}	break;
			case 3 : {	strcpy(type,"Cardiologist");	z=3;	}	break;
			case 4 : {	strcpy(type,"Emergency (ER) Doctor");	z=4;	}	break;
			case 5 : {	strcpy(type,"Hyperbaric Physician");	z=5;	}	break;
			case 6 : {	strcpy(type,"Infectious Disease Specialist");		z=6;	}	break;
			case 7 : {	strcpy(type,"Neurologist");	z=7;	}	break;
			case 8 : {	strcpy(type,"Neurosurgeon");	z=8;	}	break;
			case 9 : {	strcpy(type,"Oncologist");	z=9;	}	break;
			case 10 :{	strcpy(type,"Ophthalmologist");	z=10;	}	break;
			default : { cout<<"Wrong Option selected ";
				    flag=0;
				  }
		}
	}while(flag==0);
	cout<<"\nEnter Doctor Address (Press . to keep it unchange):";
	gets(addressd);
	cout<<"\nEnter Doctor Shift (Press . to keep it unchange):";
	gets(timed);
	cout<<"\nEnter Doctor contact Number (Press -1 to keep it unchange) :";
	cin>>mo;
	if(no!=(-1))
	{	idd=no;		}
	if(aged!=(-1))
	{	age=aged;	}
	if(mo!=(-1))
	{	nod=mo;		}
	if(strcmp(namedd,".")!=0)
	{	strcpy(named,namedd);	}
	if(strcmp(addressd,".")!=0)
	{	strcpy(address,addressd);	}
	if(strcmp(timed,".")!=0)
	{	strcpy(time,timed);	}
}

int doctor::getrno()
{
	return idd;
}

/*---------------------------------------------------------*/
/*	            Functions PATIENT	                   */
/*---------------------------------------------------------*/

void menup()
{
	int z=0;
	do
	{
	clrscr();
	patient p;
	ifstream ifile;
	ofstream ofile;
	fstream og;
	int n=0,flag=0;
	cout<<"\n\n\t\t\t\t PATIENT MENU";
	cout<<"\n\n\t01. Add New Patient Details";
	cout<<"\n\n\t02. Patients Detail";
	cout<<"\n\n\t03. Search Patient Details";
	cout<<"\n\n\t04. Modify Patient Details";
	cout<<"\n\n\t05. Delete Patient Details";
	cout<<"\n\n\t06. Pay Patient Fees";
	cout<<"\n\n\t07. Assign Doctor";
	cout<<"\n\n\t08. Return to main menu";
	cout<<"\n\n\t09. Exit";
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\tSelect Your Option (1-8) :";
	cin>>z;
	switch(z)
	{
		case 1 : {	clrscr();
				ofile.open("patient.dat",ios::app);
				{
					p.getdatap();
					p.days();
					ofile.write((char*)&p,sizeof(p));
				}
				ofile.close();
				break;
			 }
		case 2 : {	clrscr();
				ifile.open("patient.dat",ios::in);
				while(!ifile.eof())
				{
					cout<<"\n-------------------------------------------------------------------"<<endl;
					ifile.read((char*)&p,sizeof(p));
					if(ifile.eof())
					break;
					p.putdatap();
					delay(2000);
				}
				ifile.close();
				break;
			 }
		case 3 : {	clrscr();
				ifile.open("patient.dat",ios::in);
				cout<<"Enter Ward Number of patient you want to serch ";
				cin>>n;
				while(!ifile.eof())
				{
					ifile.read((char*)&p,sizeof(p));
					if(ifile.eof())
					break;
					if(p.getrno()==n)
					{
						p.putdatap();
						flag=1;
						delay(2000);
					}
				}
				if(flag==0)
				{	cout<<"\npatient Details Not Found .";	}
				ifile.close();
				break;
			 }
		case 4 : {	clrscr();
				flag=0;
				long pos;
				og.open("patient.dat",ios::in|ios::out);
				cout<<"Enter ward number of patient you want to modify ";
				cin>>n;
				while(!og.eof())
				{
					pos=og.tellg();
					og.read((char*)&p,sizeof(p));
					if(og.eof())
					break;
					if(p.getrno()==n)
					{
						p.modifyp();
						og.seekg(pos);
						og.write((char*)&p,sizeof(p));
						cout<<"\nModified Details are "<<endl;
						p.putdatap();
						flag=1;
						delay(2000);
						break;
					}
				}
				if(flag==0)
				{	cout<<"\npatient Details Not Found .";	}
				og.close();
				break;
			 }
		case 5 : {	clrscr();
				flag=0;
				ofile.open("temp.dat",ios::out);
				ifile.open("patient.dat",ios::in);
				int q;
				char e='y';
				cout<<"Enter ward number of patient you want to serch ";
				cin>>q;
				while(!ifile.eof())
				{
					ifile.read((char*)&p,sizeof(p));
					if(ifile.eof())
					break;
					if(p.getrno()==q)
					{
						p.putdatap();
						flag=1;
						cout<<"Are you sure you want to delete (y/n)";
						cin>>e;
						if(n=='n')
						ofile.write((char*)&p,sizeof(p));
					 }
					 else
					 {
						ofile.write((char*)&p,sizeof(p));
					 }
				}
				if(flag==0)
				cout<<"patient details not found ";
				else
				cout<<"Record Deleted ";
				ifile.close();
				ofile.close();
				remove("patient.dat");
				rename("temp.dat","patient.dat");
				break;
			 }
		case 6 : {	clrscr();
				long pos=0;
				og.open("patient.dat",ios::in|ios::out);
				cout<<"Enter Ward Number of patient you want to serch ";
				cin>>n;
				while(!og.eof())
				{
					pos=og.tellg();
					og.read((char*)&p,sizeof(p));
					if(og.eof())
					break;
					if(p.getrno()==n)
					{       long f=0;
						p.putdatap();
						flag=1;
						do
						{
						cout<<"\n\nEnter Amount of Money You want to Pay (Amount less or equal to bill :";
						cin>>f;
						}while(f>p.gpay());

						p.paypay(f);
						og.seekg(pos);
						og.write((char*)&p,sizeof(p));
						delay(2000);
					}
				}
				if(flag==0)
				{	cout<<"\npatient Details Not Found .";	}
				og.close();

				ifile.open("patient.dat",ios::in);
				cout<<"\n\nCurrent Details Are :";
				while(!ifile.eof())
				{
					ifile.read((char*)&p,sizeof(p));
					if(ifile.eof())
					break;
					if(p.getrno()==n)
					{
						p.putdatap();
						delay(2000);
					}
				}
				break;
			 }
		case 7 : {
				int flag=0;
				clrscr();
				ifile.open("patient.dat",ios::in);
				cout<<"Enter Ward Number of patient you want to assign doctor ";
				cin>>n;
				while(!ifile.eof())
				{
					ifile.read((char*)&p,sizeof(p));
					if(ifile.eof())
					break;
					if(p.getrno()==n)
					{
						p.putdatap();
						delay(1000);
						cout<<"\n\nSEARCHING ";
						for(int u=0;u<4;u++)
						{	cout<<".";	delay(1000);	}
						cout<<endl;						p.assign(p.z);
						flag=1;
						delay(2000);
					}
				}
				if(flag==0)
				{	cout<<"\nWrong Ward Number Entered.";	}
				ifile.close();
				break;
			}
		case 8 : menu();	break;
		case 9 : {	clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t THANK YOU FOR VISITING ";
				for(int i=0;i<4;i++)
				{      cout<<".";
				       delay(1000);
				}
				delay(1000);
				exit(0);
			  }
	}
	}while(z!=8);
}

void patient::getdatap()
{       int flag=1;
	cout<<"\nEnter patient Ward Number :";
	cin>>roomno;
	cout<<"\nEnter patient Name :";
	gets(namep);
	cout<<"\nEnter patient Age :";
	cin>>agep;
	cout<<"\nPatient Suffering From :";
	do{	int h=0;
		cout<<"\n1. allergie";
		cout<<"\n2. urological problems ";
		cout<<"\n3. cardiovascular problem ";
		cout<<"\n4. accident ";
		cout<<"\n5. asthma";
		cout<<"\n6. HIV/TB ";
		cout<<"\n7. nervous system problem ";
		cout<<"\n8. Neuro surgery ";
		cout<<"\n9. cancer ";
		cout<<"\n10. eye problem ";
		cin>>h;
		switch(h)
		{
			case 1 : {	strcpy(disease,"Allergie");	z=1;}	break;
			case 2 : {	strcpy(disease,"urological problems");	z=2;}	break;
			case 3 : {	strcpy(disease,"cardiovascular problem");	z=3;}	break;
			case 4 : {	strcpy(disease,"accident");	z=4;}	break;
			case 5 : {	strcpy(disease,"asthma");	z=5;}	break;
			case 6 : {	strcpy(disease,"HIV/TB");	z=6;}	break;
			case 7 : {	strcpy(disease,"nervous system problem");	z=7;}	break;
			case 8 : {	strcpy(disease,"Neuro surgery");	z=8;}	break;
			case 9 : {	strcpy(disease,"cancer");	z=9;}	break;
			case 10 :{	strcpy(disease,"eye problem");	z=10;}	break;
			default : { cout<<"Wrong Option selected ";
				    flag=0;
				  }
		}
	}while(flag==0);
	cout<<"\nPatient staying in type of room (ac / non ac):";
	gets(roomtype);
	cout<<"\nEnter Patient Address :";
	gets(address);
	cout<<"\nEnter Patient Contact Number :";
	cin>>nop;
	cout<<"\nEnter Number of days Stayed in Hospital :";
	cin>>b;
}

void patient::putdatap()
{
	cout<<"\npatient Ward Number :"<<roomno;
	cout<<"\npatient Name :"<<namep;
	cout<<"\npatient Age :"<<agep;
	cout<<"\nPatient Suffering From :"<<disease;
	cout<<"\nPatient staying in type of room :"<<roomtype;
	cout<<"\nPatient Address :"<<address;
	cout<<"\nPatient Contact Number :"<<nop;
	cout<<"\nAmount of Bill Peding :"<<pay;
	cout<<"\nNumber of Days Stayed in Hospital :"<<b;
}

void patient::modifyp()
{
	int roomnod;
	char namepd[20];
	int agepd;
	char diseased[30];
	char roomtyped[20];
	char addressd[20];
	long nopd;
	int flag=1;

	agepd=roomnod=nopd=0;
	strcpy(namepd,"not");
	strcpy(diseased,"not");
	strcpy(addressd,"not");

	cout<<"\nEnter patient Ward Number (Press -1 to keep it unchange):";
	cin>>roomnod;
	cout<<"\nEnter patient Name (Press . to keep it unchange):";
	gets(namepd);
	cout<<"\nEnter patient Age (Press -1 to keep it unchange):";
	cin>>agepd;
	cout<<"\nPatient Suffering From (Press -1 to keep it unchange):";
	do{	int h=0;
		cout<<"\n1. allergie";
		cout<<"\n2. urological problems ";
		cout<<"\n3. cardiovascular problem ";
		cout<<"\n4. accident ";
		cout<<"\n5. asthma";
		cout<<"\n6. HIV/TB ";
		cout<<"\n7. nervous system problem ";
		cout<<"\n8. Neuro surgery ";
		cout<<"\n9. cancer ";
		cout<<"\n10. eye problem ";
		cin>>h;
		switch(h)
		{
			case -1 : break;
			case 1 : {	strcpy(disease,"Allergie");	z=1;}	break;
			case 2 : {	strcpy(disease,"urological problems");	z=2;}	break;
			case 3 : {	strcpy(disease,"cardiovascular problem");	z=3;}	break;
			case 4 : {	strcpy(disease,"accident");	z=4;}	break;
			case 5 : {	strcpy(disease,"asthma");	z=5;}	break;
			case 6 : {	strcpy(disease,"HIV/TB");	z=6;}	break;
			case 7 : {	strcpy(disease,"nervous system problem");	z=7;}	break;
			case 8 : {	strcpy(disease,"Neuro surgery");	z=8;}	break;
			case 9 : {	strcpy(disease,"cancer");	z=9;}	break;
			case 10 :{	strcpy(disease,"eye problem");	z=10;}	break;
			default : { cout<<"Wrong Option selected ";
				    flag=0;
				  }
		}
	}while(flag==0);
	cout<<"\nEnter Patient Address (Press . to keep it unchange):";
	gets(addressd);
	cout<<"\nEnter Patient Contact Number (Press -1 to keep it unchange):";
	cin>>nopd;

	if(roomnod!=(-1))
	{	roomno=roomnod;		}
	if(nopd!=(-1))
	{	nop=nopd;		}
	if(agepd!=(-1))
	{	agep=agepd;		}
	if(strcmp(namepd,".")!=0)
	{	strcpy(namep,namepd);	}
	if(strcmp(addressd,".")!=0)
	{	strcpy(address,addressd);	}
}

void patient::assign(int e)
{	doctor d;
	ifstream ifile;
	int flag=0;
	ifile.open("doctor.dat",ios::in);
	while(!ifile.eof())
	{
		ifile.read((char*)&d,sizeof(d));
		if(ifile.eof())
		break;
		if(d.z==e)
		{	d.putdatad();
			delay(2000);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{	cout<<"\nDoctor Not found ";	}
	ifile.close();
}


int patient::getrno()
{
	return roomno;
}



/*---------------------------------------------------------*/
/*	            Functions MENU	                   */
/*---------------------------------------------------------*/


void menuu()
{       int z=0;
	do
	{
	clrscr();
	cout<<"\n\n\t\t\t\tHospital ";
	cout<<"\n\n\n\n\n\n\t\t\t01. Administrator";
	cout<<"\n\n\t\t\t02. Guest/Patient";
	cout<<"\n\n\t\t\t03. EXIT";
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tSelect Your Option (1-3) :";
	cin>>z;
	switch(z)
	{
		case 1 : {

				int count=0;
				while(count<3)
				{
					clrscr();
					char us[]={"admin"},user[10];
					char pass[10],ch,p[10]={"admin"};
					int k=0;
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tEnter Username :- ";
					cin.getline(user,10);
					cout<<"\t\t\tEnter Passcode :- ";
					while((ch=getch())!=13)
					{
						pass[k]=ch;
						k++;
						cout<<"*";
					}
					pass[k]='\0';
					if(strcmp(user,us)==0)
					{
						if(strcmp(p,pass)==0)
						{	clrscr();
							cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tloading";
							delay(300);
							cout<<".";
							delay(300);
							cout<<".";
							menu();
						}
						else
						{      	 clrscr();
							cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tIncorrect Password or Username";
							delay(1000);
							delay(1000);
							count++	;
						}
					}
					else
					{       clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tIncorrect Passcode or Username";
						delay(1000);
						count++;
					}
				}
				exit(0);
			}
			break;
		case 2 :  {

				int count=0;
				while(count<3)
				{
					clrscr();
					char us[]={"admin"},user[10];
					char pass[10],ch,p[10]={"life"};
					int k=0;
					cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tEnter Username :- ";
					cin.getline(user,10);
					cout<<"\t\t\tEnter Passcode :- ";
					while((ch=getch())!=13)
					{
						pass[k]=ch;
						k++;
						cout<<"*";
					}
					pass[k]='\0';
					if(strcmp(user,us)==0)
					{
						if(strcmp(p,pass)==0)
						{	clrscr();
							cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tloading";
							delay(300);
							cout<<".";
							delay(300);
							cout<<".";
							menuq();
						}
						else
						{      	 clrscr();
							cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tIncorrect Password or Username";
							delay(1000);
							delay(1000);
							count++	;
						}
					}
					else
					{       clrscr();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tIncorrect Passcode or Username";
						delay(1000);
						count++;
					}
				}
				exit(0);
			}
			break;
		case 3 : {	clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t THANK YOU FOR VISITING ";
				for(int i=0;i<4;i++)
				{      cout<<".";
				       delay(1000);
				}
				delay(1000);
				exit(0);
			  }
	}
	}while(z!=3);
}

void menuq()
{       int z=0;
	medicine m;
	do
	{
	clrscr();
	cout<<"\n\n\t\t\t\tHospital ";
	cout<<"\n\n\t\t\t01. PATIENT";
	cout<<"\n\n\t\t\t02. BUY MEDICINE";
	cout<<"\n\n\t\t\t03. EXIT";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tSelect Your Option (1-3) :";
	cin>>z;
	switch(z)
	{
		case 1 : menup();
			 break;
		case 2 : m.amt();
			 break;
		case 3 : {	clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t THANK YOU FOR VISITING ";
				for(int i=0;i<4;i++)
				{      cout<<".";
				       delay(1000);
				}
				delay(1000);
				exit(0);
			  }
	}
	}while(z!=3);
}

void menu()
{       int z=0;
	do
	{
	clrscr();
	cout<<"\n\n\t\t\t\tHospital ";
	cout<<"\n\n\n\n\n\t\t\t01. DOCTOR";
	cout<<"\n\n\t\t\t02. PATIENT";
	cout<<"\n\n\t\t\t03. MEDICINE DEPARTMENT";
	cout<<"\n\n\t\t\t04. EXIT";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tSelect Your Option (1-4) :";
	cin>>z;
	switch(z)
	{
		case 1 : menud();
			 break;
		case 2 : menup();
			 break;
		case 3 : menum();
			 break;
		case 4 : {	clrscr();
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t THANK YOU FOR VISITING ";
				for(int i=0;i<4;i++)
				{      cout<<".";
				       delay(1000);
				}
				delay(1000);
				exit(0);
			  }
	}
	}while(z!=4);
}

void intro()
{
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t	  ||	   |------| |------ ||	  ||	    ||		\n";
	cout<<"\t	  ||	      ||    ||	    ||	  ||        ||		\n";
	cout<<"\t  	  ||	      ||    ||	    ||	  ||	----||----	\n";
	cout<<"\t	  ||	      ||    ||	    ||	  ||	----||----	\n";
	cout<<"\t	  |------|    ||    ||	    ||	  ||        ||		\n";
	cout<<"\t	  |------| |------| |------ |------| 	    ||		\n";
	cout<<"								\n";

	delay(4000);
}
/*--------------------------------------------------------*/
/*	              Main   		    		  */
/*--------------------------------------------------------*/


main()
{	clrscr();
	intro();
	menuu();
	getch();
	return 0;
}



