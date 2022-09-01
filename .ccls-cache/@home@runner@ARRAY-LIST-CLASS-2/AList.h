#include <iostream>
using namespace std;

/************************************************************************/
/* Programmer: Anna Salvati                                             */   
/* Date:  February 3rd, 2022                                            */   
/* Purpose:  Unsorted List class, array implementation, header file     */ 
/* Input: none                                                          */
/* Output: none                                                         */
/************************************************************************/

#ifndef LIST_H
#define LIST_H

template <class T>
class AList
{
   private:
      T *data;
      int max;
      int length;

   public: 
      //Constructor with a default parameter
      AList ( int m = 100 );
      // destructor
     ~AList (); 
      // Copy constructor
      AList ( const AList<T> & );
      // Overload the = operator
      const AList<T> & operator= ( const AList<T> &);
      // Insert an item parameter into the list
      void insertItem ( T );
      // Delete an item parameter from the list
      void deleteItem ( T );
      // Search for an item parameter, return true if found false
      // otherwise
      bool searchItem ( T );
      // Return the length of the list
      int getLength ();
      // Return true if list is full, false otherwise
      bool isFull ();
      // Return true if list is empty, false otherwise
      bool isEmpty ();
      // Print all the items in the list
      void printList ();
};
#endif