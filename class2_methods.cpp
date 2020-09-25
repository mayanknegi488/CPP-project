//***************************************************************
//  Definition of methods declared in items class (class2.cpp)
//***************************************************************



//**************************************
//FUNCTION TO CREATE ITEM RECORD
//**************************************

 void write_item()
  {
   char ch;
   f1.open("ITEM.dat",ios::out|ios::binary);
   do
    {
     i1.create_item();
     f1.write((char*)&i1,sizeof(i1));
     cout<<"\nDo you want to enter more : ";
     cin>>ch;
    }
   while(ch=='y' || ch=='Y');
   f1.close();
  }
  
//*****************************************
//FUNCTION TO MODIFY ITEM'S RECORD
//*****************************************

 void modify_item()
  {
   clrscr();
   int flag=0;
   char no=0;
   cout<<"\nEnter item number you want to modify : ";
   cin>>no;
   f1.open("ITEM.dat",ios::in|ios::binary);
   while(f1.read((char*)&i1,sizeof(i1)) && flag==0)
    {
     if(i1.return_ino()==no)
      {
       cout<<"\nItem found!";
       i1.show_item();
       cout<<"\nEnter the new details...";
       i1.modify_item();
       int pos=-1*sizeof(i1);
       f1.seekg(pos,ios::cur);
       f1.write((char*)&i1,sizeof(i1));
       flag=1;
      }
    }
   f1.close();
   if(flag==0)
    {
     cout<<"\nItem not fund!";
    }
   getch();
  }
  
//************************************
//FUNCTION TO DELETE ITEM'S RECORD
//************************************

 void delete_item()
  {
   clrscr();
   char no=0;
   fstream f2;
   cout<<"\nEnter the item number of record you want to delete : ";
   cin>>no;
   f1.open("ITEM.dat",ios::in|ios::binary);
   f2.open("temp2.dat",ios::out|ios::binary);
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&i1,sizeof(i1)))
    {
     if(i1.return_ino()!=no)
      {
       f2.write((char*)&i1,sizeof(i1));
      }
    }
   f1.close();
   f2.close();
   remove("ITEM.dat");
   rename("temp2.dat","ITEM.dat");
   cout<<"\nRecord deleted!";
   getch();
  }

//*******************************************
//FUNCTION TO DISPLAY LIST OF ALL THE ITEMS
//*******************************************

 void disp_item()
  {
   clrscr();
   f1.open("ITEM.dat",ios::in|ios::binary);
   if(!f1)
    {
     cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
     cout<<"\n\n\n Program is closing ....";
     getch();
     return;
    }
   cout<<"\n\n\t\tProduct MENU\n\n";
   cout<<"====================================================\n";
   cout<<"P.NO.\t\tNAME\t\tPRICE\t\tSTOCK\n";
   cout<<"====================================================\n";
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&i1,sizeof(i1)))
    {
      i1.report();
      cout<<endl;
    }
   f1.close();
  }
