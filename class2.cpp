//**************************
//CLASS FOR ITEMS
//**************************

 class item
  {
	   int ino;
	   char iname[10];
	   float iprice;
	   int istock;
	   int idiscount;

   public :
	   void create_item()
	    {
	     clrscr();
	     cout<<"\nEnter item number : ";
	     cin>>ino;
	     cout<<"\nEnter item name : ";
	     cin>>iname;
	     cout<<"\nEnter item price : ";
	     cin>>iprice;
	     cout<<"\nEnter discount on item : ";
	     cin>>idiscount;
	     istock=100;
	    }

	   void show_item()
	    {
	     clrscr();
	     cout<<"\nItem number "<<ino;
	     cout<<"\nItem name ";
	     puts(iname);
	     cout<<"\nItem price "<<iprice;
	     cout<<"\nDiscount on item : "<<idiscount;
	     cout<<"\nAvailibilty : "<<istock<<" "<<cout<<" is left!";
	    }

	   void modify_item()
	    {
	     clrscr();
	     cout<<"\nNew item number : ";
	     cin>>ino;
	     cout<<"\nNew item name : ";
	     cin>>iname;
	     cout<<"\nNew itmen price : ";
	     cin>>iprice;
	     cout<<"\nNew discount on item : ";
	     cin>>idiscount;
	     cout<<"\nStock availability : ";
	     reset_stock();
	     cin>>istock;
	    }

	   int return_idiscount()
	    { return idiscount; }

	   int return_ino()
	    { return ino; }

	   int return_istock()
	    { return istock; }

	   void sub_stock()
	    {  istock--; }

	   int return_iprice()
	    { return iprice; }

	   void reset_stock()
	    { istock=0; }

	   void report()
	    { cout<<ino<<"\t\t"<<iname<<"\t"<<iprice<<"\t\t"<<istock; }

	   char* return_name()
	    { return iname; }
  }i1;
