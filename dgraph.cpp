//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Olaf Zielinski
// File Type: dgraph implementation file .cpp
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "dgraph.h"

dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
{
  countUsed = 0;
  for (int i=0; i<SIZE; i++){
    Gtable[i].vertexName = ' ';
    Gtable[i].visit = 0;
    Gtable[i].outDegree = 0;
  }
}

dgraph::~dgraph(){

}   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.

void dgraph::fillTable()  // be sure to read from a file
{
    ifstream fin ("table.txt", ios::in);
  char x;
  while ( fin >>  Gtable[countUsed].vertexName )
    {
      fin >>  Gtable[countUsed].outDegree;
      for (int i = 0; i <  Gtable[countUsed].outDegree; i++)
        {
	  fin >> x;
	  (Gtable[countUsed].adjacentOnes).addRear(x);
	}
      countUsed++;
    }
  
  fin.close();
}

// displays in an easy to read format
void dgraph::displayGraph()
{
  cout << "-------------------------------------------" << endl;
  cout << right << setw(5) << "Out" << setw(8) << "Visit" << setw(7) << "Adj"<< endl;
  cout << "-------------------------------------------" << endl;
  for (int i = 0; i < countUsed; i++)
    {
      cout << Gtable[i].vertexName << " " << Gtable[i].outDegree << " |";
      cout << setw(5);
      cout << Gtable[i].visit;
      cout << right << setw(5) << " ";
      (Gtable[i].adjacentOnes).displayAll();
      cout << endl;
    }

}

int dgraph::findOutDegree(char V)// throws exception
// does not use a loop
{
  for (int i = 0; i < countUsed; i++)
    {
      if(Gtable[i].vertexName == toupper(V))
	{
	  cout << Gtable[i].outDegree << endl;
	  return Gtable[i].outDegree;
	}
    }
  throw BadVertex();
}


slist dgraph::findAdjacency(char V)// throws exception
// does not use a loop
{
  for (int i= 0; i < this->countUsed; ++i)
    if (Gtable[i].vertexName == V)
      return Gtable[i].adjacentOnes;
  return slist();
}

void dgraph::visit(int c, char V)
{
  int temp;
  temp = V - 65;
	Gtable[temp].visit = c;
	cout << "Visiting " << Gtable[temp].vertexName << " as " << Gtable[temp].visit << endl;
	return;
}


bool dgraph::isMarked(char V)
{
  int temp;
  temp = V - 65;
    if (V == Gtable[temp].vertexName)
      {
	if (Gtable[temp].visit > 0)
	  return true;
	else
	  return false;
      }
}
