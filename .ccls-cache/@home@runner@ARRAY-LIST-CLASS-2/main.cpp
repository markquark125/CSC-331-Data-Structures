#include "AList.cpp"


/***************************************************************/
/* Programmer: Anna Salvati                                    */   
/* Date: February 3, 2022                                      */   
/* Purpose: Test the array list class using a menu driven      */
/*          program                                            */
/* Input: user’s choice to perform an operation                */   
/* Output: menu of choices and results of user’s operations.   */   /***************************************************************/

// printMenu displays a menu of choices and returns the user's choice
 
int printMenu();

// InsertList inserts an item into the list parameter

void insertListItem ( AList<int> & );

// deleteList deletes an item from the list parameter

void deleteListItem ( AList<int> & );

// searchItem searches for an item in the list parameter

void searchListItem ( AList<int>  ); 

//************************** main program ************************/

int main()
{
   
   int max;

   cout<<"\nEnter the maximum size of the list : ";
   cin>>max;

   AList<int> l (max);
   

   int choice;
   
   cout<<"\nOperations allowed on the unsorted list of integers are below."
      <<"\nPlease enter the number of your choice and press return.\n\n"; 

   choice = printMenu();

   while ( choice != 6 )
   {

       switch ( choice )
      {
   
         case 1 : insertListItem( l );
                  break;
    
         case 2 : deleteListItem ( l );
                  break;

         case 3 : l.printList();
                  break;
                   
         case 4 : searchListItem ( l );
                  break;
                     
         case 5 : cout<<"\nThe list contains "<<l.getLength()
                      << " items\n";
                  break; 
                 
         default :cout<<"\nNumber is not correct. Please look at "
                      <<"choices and reenter\n\n";
                 break;
      }

      choice = printMenu();
   }
  

   AList<int> l2(max); 

  l2 = l;  

   cout<<"\nPrinting a new list with the same values as the old list \n";
   
   l2.printList();
   
   cout<<"\nProgram terminated\n\n";
   
   return 0;
}

//********************functions implementation ********************//

int printMenu ()
{
   int c;

   cout<<"\n1: Add an item to the list.";
   cout<<"\n2: Delete an item from the list.";
   cout<<"\n3: Print the list.";
   cout<<"\n4: Search the list for a given item";
   cout<<"\n5: Return the number of items in the list";
   cout<<"\n6: Quit.\n\n";
   cin>>c;

   return c;
}

void insertListItem ( AList<int> &l )
{
   int num;  
   
   if ( l.isFull() )
      cout<<"\nList is Full – No more insertions allowed \n "; 
   else
   {   cout<<"\nEnter the number to insert : ";
       cin>>num;
       l.insertItem(num);
       cout<<"\nThe number has been inserted\n\n";
   }
    
}

void deleteListItem ( AList<int> &l )
{

   int num;

   cout<<"\nEnter the number to delete : ";
   cin>>num;
   
   if ( l.searchItem (num))
   { 
      l.deleteItem (num);
      cout<<"\nThe number has been deleted\n\n";
   }
   else  cout<<"\nThe number is NOT in the list\n\n";
 
       
}

void searchListItem ( AList<int> l )
{

   int num;

   cout<<"\nEnter the number to search for : ";
   cin>>num;
       
   if ( l.searchItem (num))
   
       cout<<"\nThe number is in the list\n\n";
   
   else  cout<<"\nThe number is NOT in the list\n\n";
          
}



