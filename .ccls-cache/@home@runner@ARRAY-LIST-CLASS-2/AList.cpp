#include "AList.h"

/***************************************************************/
/* Programmer: Anna Salvati                                    */   
/* Date: February 3, 2022                                      */   
/* Purpose: Array  List class  -   implementation file         */ 
/* Input: none                                                 */
/* Output: printList function prints all current items in      */
/*         the list                                            */
/***************************************************************/

template <class T>
AList<T> :: AList ( int size )
{
   max = size;
   length = 0;
   data = new T [max]; 
}

template <class T>
AList<T> :: ~AList ()
{
   delete [] data;
}

template <class T>
AList<T> :: AList (const AList<T> &other)
{
   max = other.max;
   length = other.length;
   data = new T[max];
   for ( int i = 0; i < length; i++)
      data[i] = other.data[i];
}

template <class T>
const AList<T> & AList<T> :: operator= (const AList<T> &other)
{
  if ( this != &other )
  {
   delete [] data;
   max = other.max;
   length = other.length;
   data = new T[max];
   for ( int i = 0; i < length; i++)
      data[i] = other.data[i];
   } 

   return *this;
}  

template <class T>
int AList<T> :: getLength ()
{
   return length;
}

template <class T>
bool AList<T> :: isEmpty()
{
   return length == 0;
}

template <class T>
bool AList<T> :: isFull()
{
   return length == max;
}

template <class T>
void AList<T> :: insertItem (T item)
{
   if ( isFull() )
       cout<<"\nERROR - LIST IS FULL\n";
   else 
       data[length++] = item;
}

template <class T>
void AList<T> :: deleteItem (T item)
{
   if ( isEmpty() )
      cout<<"\nERROR - LIST IS EMPTY\n"; 
   else
   {
      bool found = false;
      int position = 0;

      while ( !found && position < length )
        {
           if ( data[position] == item )
              found = true;
           else
              position++;
        }  

      if ( found )
         data [position] = data[--length];      
        
   }  
}

template <class T>
bool AList<T> :: searchItem( T item)
{
   for ( int i = 0; i < length; i++ )
   {
      if ( data[i] == item ) 
         return true;
   }
 
   return false;   
}

template <class T>
void AList<T> :: printList ()
{
    if ( isEmpty() )
       cout<<"\nLIST IS EMPTY\n";
    else
    {
       cout<<"\n\nLIST : \n";
       for ( int i = 0; i < length; i++ )
         cout<<data[i]<<"\n";
    }  
}


