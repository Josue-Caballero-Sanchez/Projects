//Name: Josue Caballero Sanchez 
//Date: 11/26/22

#include "Caballero_list.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){

    //creates a linked list of integers and fills it with 1,2,3,4,5 then prints the list
    cout << "Creates linked list with 1,2,3,4,5" << endl;
    LinkedList<int> list;    
    list.AddToFront(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    list.AddToEnd(4);
    list.AddToEnd(5);
    list.PrintList();
    cout << "\n";

    //calls AddAtIndex() and adds 6 at index 5 of the list and 7 at index 3. It also tries to add 8 to index 8
    //but fails. It then prints the list
    cout << "Adds 6 to the end of the list and 7 at index 3.Also attempts to add 8 to an out of bounds index" << endl;
    list.AddAtIndex(6, 5);
    list.AddAtIndex(7, 3);
    list.PrintList();
    if(list.AddAtIndex(8,8) == false){
        cout << "Index is out of bounds" << endl;
    }
    cout << "\n";

    //calls AddBefore() and passes in the pointer of 0 by calling the Find method and adds 0 to the begginig of the list.
    //then calls AddBefore() again and passes in the pointer of 5 and adds 8 before 5
    cout << "Adds 0 to the beggining of the list, and 8 before 5" << endl;
    list.AddBefore(list.Find(1), 0);
    list.AddBefore(list.Find(5), 8);
    list.PrintList();
    cout << "\n";

    //calls AddAfter() and passes in the pointer to the last element in the list and adds 7 to the end of the list
    //then it calls AddAfter() again and passes in the pointer of 1 and adds 9 after 1 to the list
    cout << "Adds 7 to the end of the list, and 9 after 1" << endl;
    list.AddAfter(list.getlast(), 7);
    list.AddAfter(list.Find(1), 9);
    list.PrintList();
    cout << "\n";

    //calls RemoveFromFront() and removes the first element in the list and prints out the removed value
    cout << "Removes the first element in the list and prints it out: ";
    cout << list.RemoveFromFront() << endl;
    list.PrintList();
    cout << "\n";

    //calls RemoveFromEnd() and removes the last element in the list and prints out the removed value
    cout << "Removes the last element in the list and prints it out: ";
    cout << list.RemoveFromEnd() << endl;
    list.PrintList();
    cout << "\n";

    //calls RemoveTheFirst() and passes in 5, it removes the first 5 in the list and the prints the list
    cout << "Removes the first 5 in the list" << endl;
    list.RemoveTheFirst(5);
    list.PrintList();
    cout << "\n";

    //calls RemoveAllOf() and passes in 6, it removes every 6 in the list and the prints the list
    cout << "Removes every 6 in the list" << endl;
    list.RemoveAllOf(6);
    list.PrintList();
    cout << "\n";

    //calls RemoveBefore() and passes in Find(2) to get the pointer of 2 and remove the element before 2
    cout << "Removes the 2nd element in the list and prints it: ";
    cout << list.RemoveBefore(list.Find(2)) << endl;
    list.PrintList();
    cout << "\n";

    //calls RemoveAfter() and passes in Find(3) to get the pointer of 3 and remove the element after 3
    cout << "Removes the 4th element in the list and prints it: ";
    cout << list.RemoveAfter(list.Find(3)) << endl;
    list.PrintList();
    cout << "\n";

    //calls ElementExists() on 1, 3, and 9 and tells the user if it is in the list or not
    cout << "Looks for1, 3, and 9 in the list and says if it exists in the list" << endl;
    if(list.ElementExists(1) == true){
        cout << "1 is in the list" << endl;
    }
    if(list.ElementExists(3) == true){
        cout << "3 is in the list" << endl;
    }
    if (list.ElementExists(9) == false){
        cout << "9 is not in the list" << endl;
    }
    list.PrintList();
    cout << "\n";
    

    //calls Find() of 4 and prints the pointer value of 4
    cout << "Prints the pointer value of 4: ";
    cout << list.Find(4) << endl;
    list.PrintList();
    cout << "\n";


    //calls IndexOf() with 8 passed in, it returns the index of 8 with the first element in the list at index 0
    cout << "Prints the index of 8 in the list :";
    cout << list.IndexOf(8) << endl;
    list.PrintList();
    cout << "\n";

    //calls RetrieveFront() which just returns the first value in the list
    cout << "Retrieves the first value in the list and prints it: ";
    cout << list.RetrieveFront() << endl;
    list.PrintList();
    cout << "\n";

    //calls RetrieveEnd() which just returns the first value in the list
    cout << "Retrieves the last value in the list and prints it: ";
    cout << list.RetrieveEnd() << endl;
    list.PrintList();
    cout << "\n";

    //calls Retrieve() with 2 passed in so it retrieves the value at index 2
    cout << "Retrieves the value at index 2 and prints it: ";
    cout << list.Retrieve(2) << endl;
    list.PrintList();
    cout << "\n";

    //calls Length() which just retruns the length of the list and prints it
    cout << "Prints the length of the list: ";
    cout << list.Length() << endl;
    list.PrintList();
    cout << "\n";

    cout << "Emptys the list: " << endl;
    list.Empty();
    list.PrintList();
    cout << "\n";


    return 0;
}