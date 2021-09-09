//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Olaf Zielinski
// File type: client hw7client.cpp 
//==========================================

// Be sure to include dgraph, slist and stack

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt

#include "dgraph.h"
#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
  // use the algorithm (read carefully) in the HW7
  // assignment sheet
  char bsChar;
  slist ListOne; // Hold copy of adjacent slists.
  int count = 1; // Counter
  char inpt; // Hold the user input
  stack Stack; // Stack Object
  dgraph table; // D Graph Object
    
    
  table.fillTable();  // Fill the table
  table.displayGraph(); // Display the table
    
  table.visit(count, 'A'); // Visit A
  ListOne = table.findAdjacency('A'); // Copy the adjacent list
  cout << "... pushing ";
  ListOne.displayAll();

  while( !ListOne.isEmpty())
    {
      ListOne.deleteRear(bsChar); // Pop from adjacenct slist
      Stack.push(bsChar); //Push into stack
    }
    
  Stack.displayAll(); //display stack
    
  while(!Stack.isEmpty())
    {
      Stack.pop(bsChar);
      cout << bsChar <<" removed from stack.\n";

      if (!table.isMarked(bsChar)) // if the vertex is not visited
        {
	  count++;
	  table.visit(count, bsChar);
	  ListOne = table.findAdjacency(bsChar); // Copy adjacent list

	  if(!ListOne.isEmpty()){
	  cout << "... pushing ";
	  ListOne.displayAll();
	  }else
	    { cout << "Deadend. Backup." << endl;}

	  while( !ListOne.isEmpty())
            {
	      ListOne.deleteRear(bsChar); // Pop the adjacent list
	      Stack.push(bsChar); //Push into the stack
            }
            

        }//end of if visite
      else { //if it wasn't visited, inform user.
	cout << bsChar << " had been visited already - backup." << endl;
      }

      Stack.displayAll(); //display everything
      cout << endl; //space out nicely

    }//end of while
  table.displayGraph(); //display the table

 
  return 0;
}
