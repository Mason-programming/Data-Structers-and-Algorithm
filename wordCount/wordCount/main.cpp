
#include <fstream>
#include <string>
#include <cctype>
#include "wordCount.h"
#include <iostream>
using namespace std;


int main() {

     // file names, input by user
   ifstream in;  // stream for reading from input file
   ofstream out; // stream for writing the output
   
   ListNode *wordList = nullptr;  // Pointer to a sorted linked list that holds the words.
   ListNode l1;

   // Open the files.
   in.open("/Users/masonkirby/Desktop/dataStructer_alg/Untitled.txt");
  
   
   // Make the list of words, then count the number of words found.
   wordList = NULL;  // Start with empty list.
    
   l1.makeWordList(in,wordList);


   l1.printWordList(wordList);

} // end main()
