//***************************
//CLASS FOR CUSTOMERS
//***************************

 class customer
  {
	   int cno;
	   char name[10];
	   float mbno;
	   int points;
   public :
	   void create_cust()
	    {
	     clrscr();
	     cout<<"\n...NEW CUSTOMER ENTRY...\n";
	     cout<<"\nEnter the customer number : ";
	     cin>>cno;
	     cout<<"\nEnter the name of the customer : ";
	     gets(name);
	     cout<<"\nEnter mobile number : ";
	     cin>>mbno;
	     points=0;
	    }

	   void show_cust()
	    {
	     clrscr();
	     cout<<"\nCustomer number : "<<cno;
	     cout<<"\nCustomer name : ";
	     puts(name);
	     cout<<"\nMobile number : "<<mbno;
	     if(points>0)
	      {
	       cout<<"\nBonus points : "<<points;
	      }
	    }

	   void modify_cust()
	    {
	     clrscr();
	     char reply;
	     cout<<"\nwhat do you want to modify?";
	     cout<<"\nC. Customer Number";
	     cout<<"\nN. Name";
	     cout<<"\nM. Mobile Number";
	     cin>>reply;
	     if(reply=='C'&& reply=='c')
	      {
	       cout<<"\nNew customer number : ";
	       cin>>cno;
	      }
	     else if(reply=='N' && reply=='n')
	      {
	       cout<<"\nNew name : ";
	       cin>>name;
	      }
	     else if(reply=='M' && reply=='m')
	      {
	       cout<<"\nNew mobile number : ";
	       cin>>mbno;
	      }
	    }

	   void add_points()
	    { points++; }

	   void reset_points()
	    { points=0; }

	   int return_cno()
	    { return cno; }

	   int return_points()
	    { return points; }

	   int return_mbno()
	    { return mbno; }

	   void report()
	    { cout<<"\t"<<cno<<name<<points<<endl; }
  }c1;
