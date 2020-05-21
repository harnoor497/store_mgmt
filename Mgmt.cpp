#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
class store
{public:
int pno;
char name[20];
float price,qty;
public:
void create()
{cout<<"\nEnter the no. of Product:"<<endl;
cin>>pno;
cout<<"Enter The Product Name :"<<endl;
gets(name);
cout<<"Enter Price of Product:"<<endl;
cin>>price;
cout<<"Enter Quantity of Price:"<<endl;
cin>>qty;
}
void showproduct()
{cout<<"\nThe Product No of Product:"<<pno;
cout<<"\nThe Name of Product:";
puts(name);
cout<<"The Price of Product :"<<price<<endl;
cout<<"The Quantity of Product:"<<qty<<endl;
}
/*int retpno()
{return pno;}
float retprice()
{return price;}
char* retname()
{return name;}*/
};
//**global declaration**
fstream fp;
store sr;
//**func to write enter record**
void write_product()
{
fp.open("shp.dat",ios::out|ios::app);
sr.create();
fp.write((char*)&sr,sizeof(sr));
fp.close();
cout<<"\n\nThe Product has been Created";
getch();
}
//**func to read all records**
void display_all()
{clrscr();
cout<<"Display All Record"<<endl;
fp.open("shp.dat",ios::in);
while(fp.read((char*)&sr,sizeof (sr)))
{sr.showproduct();
cout<<"\n\n==================================================\n";
getch();
}
fp.close();
getch();
}
//**func to read specific record**
void dis_sp(int n)
{ int flag=0;
fp.open("shp.dat",ios::in);
while(fp.read((char*)&sr,sizeof (sr)))
{if(sr.pno==n)
{clrscr();
sr.showproduct();
flag=1;
}
}
fp.close();
if(flag==0)
cout<<"\n\nrecord not exist";
getch();
}
//**func to modify record**
void modify_pr()
{int n1,found=0;
cout<<"enter product no. of product"<<endl;
cin>>n1;
fp.open("shp.dat",ios::in);]
f2.open("temp.dat",ios::out|ios::ate);
while(fp.read((char*)&sr,sizeof(sr))
}
if (s.pno==n1)
{cout<<"\tdetail before update";
display_all();
cout<<"now update";
sr.create;
found=1;
}
f2.write((char*)&sr,sizeof(sr));
}
if(found!=1)
{cout<<endl<<"wrong code";
}
fp.close();
remove("shp.dat");
f2.close();
rename("temp.dat","shp.dat");
cout<<"record modified"<<endl;
getch();
break;
}
//**func to del record**//
void delete_product()
{
int no;
clrscr();
cout<<"\n\nDelete Record"<<endl;
cout<<"\n\nPlease enter the product no u want to delete";
cin>>no;
fp.open("shp.dat",ios::in|ios::out);
fstream fp2;
fp2.open("temp.dat",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&sr,sizeof(sr)));
{
if(sr.pno!=no)
{fp2.write((char*)&sr,sizeof(sr));
}
}
fp2.close();
fp.close();
remove("shp.dat");
rename("temp.dat","shp.dat");
cout<<"\n\nRecord deleted";
getch();
}
//*func to display all product price list**
void menu()
{clrscr();
fp.open("shp.dat",ios::in);
if(!fp)
{cout<<"file could not open"<<endl;
getch();
exit(0);
}
cout<<"\n\n\nPRODUCT MENU\n\n";
cout<<"=====================================================\n";
cout<<"P.NO\t\tNAME\t\tPRICE\n";
cout<<"=====================================================\n";
while(fp.read((char*)&sr,sizeof(sr)))
{
cout<<sr.pno<<"\t\t"<<sr.name<<"\t\t"<<sr.price<<endl;
}
fp.close();
}
//**func to place order and generate bill**
void place_order()
{
int order_arr[50],quan[50],c=0;
float amt,total=0;
char ch;
menu();
do
{
cout<<"\n\n\n\n==========================================";
cout<<
"\n ->>PLACE UR ORDER<<-";
cout<<"\n================================================\n";
cout<<"\n\nEnter the product no of the product";
cin>>order_arr[c];
cout<<"quantity in no:";
cin>>quan[c];
c++;
cout<<"proceed(y/n)";
cin>>ch;
}
while(ch=='y'||ch=='Y');
cout<<"Thanks for placing order";
getch();
clrscr();
cout<<"\n***************************INVOICE**************************\n";
cout<<"\nPR NO.\tPR.NAME\tQUANTITY\tPRICE\tAMONT\n";
for(int x=0;x<=c;x++)
{
fp.open("shp.dat",ios::in);
fp.read((char*)&sr,sizeof(sr));
while(!fp.eof())
{if(sr.pno==order_arr[x])
{amt=sr.price*quan[x];
cout<<"\n"<<order_arr[x]<<"\t"<<sr.name<<"\t"<<quan[x]<<"\t\t"<<sr.price<<"\t\t"<<amt;
total+=amt;
}
fp.read((char*)&sr,sizeof(sr));}
fp.close();
}
cout<<"\n\n\n\t\t\tTOTAL="<<total;
getch();
}
//**administrative func**
void admin_menu()
{
a:
int ch2;
cout<<"\n\n\nADMINISTRATIVE MENU\n";
cout<<"\t
";
cout<<"\n\n\t1:CREATE PRODUCT";
cout<<"\n\n\t2:DISPLAY ALL PRODUCT";
cout<<"\n\n\t3:QUERY";
cout<<"\n\n\t4:MODIFY PRODUCT";
cout<<"\n\n\t5:DELETE PRODUCT";
cout<<"\n\n\t6:VIEW PRODUCT MENU";
cout<<"\n\n\t7:GO TO MAIN MENU";
cout<<"enter ur choice"<<endl;
cin>>ch2;
switch(ch2)
{
case 1:clrscr();
write_product();
goto a;
case 2:
display_all();
goto a;
case 3:
int num;
clrscr();
cout<<"\n\tplease enter the product no";
cin>>num;
dis_sp(num);
goto a;
case 4:
modify_pr();
goto a;
case 5:
delete_product();
goto a;
case 6:
menu();
getch();
goto a;
case 7:
break;
default:
cout<<"\a";
// admin_menu();
}
}
//**main function**
void main()
{int ch1;
cout<<"\n-->>WELCOME TO DPS STORE<<-- \n";
cout<<"\t******************************************************\n\n";
abc:
cout<<"\n\n\n\tMAIN MENU\n";
cout<<"\t
";
cout<<"\n\n\t1:CUSTOMER";
cout<<"\n\n\t2:ADMINISTRATOR";
cout<<"\n\n\t3:exit";
cout<<"\n\nPlease enter ur option";
cin>>ch1;
switch(ch1)
{case 1:
{ clrscr();
place_order();
getch();
goto abc;
}
case 2:
{ admin_menu();
getch();
goto abc;
}
case 3:
{ cout<<"thanks for shopping";
getch();
exit(-1);
}}
getch();
}

