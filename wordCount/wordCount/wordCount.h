
#include <fstream>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;



class ListNode {
   string word;     // A word, with all letters converted to lower case.
   int frequency;   // Number of times that the word occurred in the file.
   ListNode *next;  // Pointer to next nodein the list.
public:
   ListNode(){
      word = "";
      frequency = 0;
      next = nullptr;
   }
   ListNode(string text){
      word = text;
      frequency = 0;
      next = nullptr;
   }
   string readWord(istream &in);
   void insert(ListNode* &sortedList, string word);
   void makeWordList(istream &in, ListNode* &tree);
   void printWordList(ListNode *list);

};



/* Read a "word", meaning a sequence of letters, from an input stream.
 * Any non-letter characters are skipped before reading the word.  If
 * no word can be read (because of end-of-stream, for example), then
 * an empty string is returned.
 */
string ListNode::readWord(istream &in) {
   string word;  // the word read from the input stream
   char ch;      // one char read from the input stream
   while (in && !isalpha(in.peek())) {
         // skip past non-letter character
      in.get(ch);
   }
   word = "";
   while (in && isalpha(in.peek())) {
      in.get(ch);
      word += ch;
   }
   return word;
}




/*  Add a word to the sorted linked list.  If the word already exists
 *  in the list, then the associated frequency count is incremented.
 *  Otherwise, a new node is created to hold the word and is added
 *  to the list.
 */
void ListNode::insert(ListNode* &sortedList, string word) {
   if (sortedList == NULL || word < sortedList->word) {

      ListNode *newNode = new ListNode;
      newNode->word = word;
      newNode->frequency = 1;
      newNode->next = sortedList;
      sortedList = newNode;
   }
   else {
        // The word comes somewhere later in the list
      ListNode *runner = sortedList->next;
      ListNode *previous = sortedList;
      while (runner != NULL && word > runner->word) {
         previous = runner;
         runner = runner->next;
      }
      if (runner != NULL && word == runner->word) {
           // Found the word already in the list -- add 1 to the frequency.
         runner->frequency++;
      }
      else {
          // Insert a new node between previous and runner
         ListNode *newNode = new ListNode;
         newNode->word = word;
         newNode->frequency = 1;
         newNode->next = runner;
         previous->next = newNode;
      }
   }
}


void ListNode::makeWordList(istream &in, ListNode* &tree) {
   string word;
   word = readWord(in);
   while (word != "") {

      insert(tree,word);
      word = readWord(in);
   }
}





/* Print the data from the sorted linked list.
 */
void ListNode::printWordList(ListNode *list) {
   ListNode* curr = list;
   while (curr != nullptr) { // Note: OK to change list, since it's passed by value.
      cout << list->word << " (" << list->frequency << ")\n";
      list = list->next;
   }
}
