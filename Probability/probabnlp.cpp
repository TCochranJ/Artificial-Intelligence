//***********************************
// CS471  N-gram probability use
// The input file can be of any format
// ***********************************

// add includes here
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
  const int SIZE = 39;
  struct Probabilities
  {
    string letters;
    float prob;
  };
  string fileName;
  string uInput;
  Probabilities array[SIZE];

  // Ask the user for the input file name
  cout << "Enter a file name: ";
  cin >> fileName;

  // Read in the trigram probabilties
  ifstream fin;
  fin.open(fileName.c_str());

  if(!fin)
    {
      cout << fileName << " does not exit" << endl;
    }
  else
    {
      for(int i = 0; i < SIZE; i++)
	{
	  fin >> array[i].letters >> array[i].prob;
	}

      fin.close();

      // Ask the user to enter a word
      cout << "Enter a word: ";
      cin >> uInput;
      
      // Repeat the following until the user
      // wants to quit:
      while(uInput != "quit")
	{
	  float pWord = 1;

	  // Show all the probabilities you used
	  // to calculate the P(word)
	  for(int i = 0; i < uInput.size(); i++)
	    {
	      string p1 = "x", p2 = "x";
	      string search;

	      if(i == 1)
		{
		  p1 = uInput[i-1];
		}
	      else if(i >= 2)
		{
		  p1 = uInput[i-2];
		  p2 = uInput[i-1];
		}

	      search = uInput[i] + p1 + p2;  // search is the current character of the input +
                                             // the 2 preceding characters. If the preceding
	                                     // characters don't exist, 'x' is used as placeholder
	      
	      for(int k = 0; k < SIZE; k++)
		{
		  // if the current search characters match with entry in array of probabilities.
		  if(array[k].letters[0] == search[0] && array[k].letters[2] == search[1] && array[k].letters[3] == search[2])
		    {
		      cout << "P(" << array[k].letters << ") * " << array[k].prob << " ";
		      pWord *= array[k].prob;
		    }
		}
	    }
	  // Show the P(word)
	  cout << endl;
	  cout << "P(word) = " << pWord << endl;
	  cout << "Enter a word: ";
	  cin >> uInput;
	}
    }
}
