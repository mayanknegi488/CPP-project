//******************************************************************
//     Method definations for the customer class (class1.cpp)
//******************************************************************



//******************************************
//FUNCTION TO CREATE CUSTOMER RECORD
//******************************************

 void write_customer()
  {
   char ch;
   f1.open("CUSTO.dat",ios::out|ios::binary);
   do
    {
     c1.create_cust();
     f1.write((char*)&c1,sizeof(c1));
     cout<<"\nDo you want to enter more : ";
     cin>>ch;
    }
   while(ch=='y' || ch=='Y');
   f1.close();
  }
  
  //*********************************************
//FUNCTION TO MODIFY CUSTOMER'S RECORD
//*********************************************

 void modify_customer()
  {
   clrscr();
   int flag=0;
   int no=0;
   cout<<"\nEnter customer number of record you want to modify : ";
   cin>>no;
   f1.open("CUSTO.dat",ios::in|ios::binary);
   while(f1.read((char*)&c1,sizeof(c1)) && flag==0)
    {
     if(c1.return_cno()==no)
      {
       cout<<"\nCustomer found !";
       c1.show_cust();
       cout<<"\nEnter the new details....";
       c1.modify_cust();
       int pos=-1*sizeof(c1);
       f1.seekg(pos,ios::cur);
       f1.write((char*)&c1,sizeof(c1));
       cout<<"\n\nRecord updated!";
       flag=1;
      }
    }
   f1.close();
   if(flag==0)
    {
     cout<<"\nRecord not found!";
    }
   getch();
  }
  
  //**************************************
//FUNCTION TO DELETE CUSTOMER'S RECORD
//**************************************

 void delete_customer()
  {
   clrscr();
   int no=0;
   int flag=0;
   cout<<"\nEnter the customer number of record you want to delete : ";
   cin>>no;
   fstream f2;
   f1.open("CUSTO.dat",ios::in|ios::binary);
   f2.open("temp.dat",ios::out|ios::binary);
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&c1,sizeof(c1)))
    {
     if(c1.return_cno()!=no)
      {
       f2.write((char*)&c1,sizeof(c1));
      }
     else
      { flag=1; }
    }
   f1.close();
   f2.close();
   remove("CUSTO.dat");
   rename("temp.dat","CUSTO.dat");
   if(flag==1)
    { cout<<"\nRecord deleted!"; }
   else
    { cout<<"\nRecord not found"; }
   getch();
  }
  
   //********************************************
 //FUNCTION TO DISPLAY RECORD OF ALL CUSTOMERS
 //********************************************

 void disp_allcust()
  {
   clrscr();
   f1.open("CUSTO.dat",ios::in|ios::binary);
   if(!f1)
    {
     cout<<"ERROR!!!FILE COULD NOT BE OPENED.\n\n\n GO BACK TO ADMIN MENU TO CREATE RECORD!";
     cout<<"PROGRAM IS CLOSING!";
     getch();
     return;
    }
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&c1,sizeof(c1)))
    {
     c1.show_cust();
    }
   f1.close();
   getch();
  }

 void disp_scust(int n)
  {
   clrscr();
   int flag=0;
   f1.open("CUSTO.dat",ios::in|ios::binary);
   while(f1.read((char*)&c1,sizeof(c1)) && flag==0)
    {
      if(c1.return_cno()==n)
       {
	 c1.show_cust();
	 flag=1;
       }
    }
   f1.close();
   if(flag==0)
    {
     cout<<"\n\nNo such customer exist!";
    }
   getch();
  }

 void disp_sitem(int n)
  {
   clrscr();
   int flag=0;
   f1.open("ITEM.dat",ios::in|ios::binary);
   while(f1.read((char*)&i1,sizeof(i1)) && flag==0)
    {
     if(i1.return_ino()==n)
      {
       i1.show_item();
       flag=1;
      }
    }
   if(flag==0)
    {
     cout<<"\n\nNo such item available!";
    }
   f1.close();
   getch();
  }
