#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// here is the Grocery class that will check for the file / items in the txt file 
class Grocery{
    private:
        map<string, int> items;
    public:
        // checking getting the file and checking to make sure it opens if not it will out put an error message 
        void readFiles(string fileName){
            ifstream inputFile;
            inputFile.open(fileName);

            if(inputFile.is_open()){
                string item;
                while (inputFile >> item){
                    items[item]++;
                }
                inputFile.close();
            }else{
                cout << "There was an issue opening the file, please look further into the issue" << endl;
            }
        }
        //creating a file for us to write to and if there is an issue opening / creating the file it will out put an error message 
        void writeFiles(string fileName){
            ofstream outputFile;
            outputFile.open(fileName);

            if (outputFile.is_open()){
                for (auto const& item : items){
                    outputFile << item.first << " " << item.second << endl;
                }
                outputFile.close();
            } else {
                cout << "There was an issue opening the file, please look further into the issue" << endl; 
            }
         } 
        // here we are chcking to see how many time the items appears in the list 
         int findGrocery (string item){
            if (items.count(item) > 0){
                return items[item];
            }else {
                return 0;
            }
         }
         // here we are printing out the item and how many times appears on the list 
         void printNumberOfTimes(){
            for (auto const& item : items){
                cout << item.first << " " << item.second << endl;
            }
         }
        // here we are printing out the item and * char as many times as it appears on the list 
        void printHistogram(){
            for (auto const& item : items){
                cout << item.first << " ";
                for (int i = 0; i < item.second; ++i){
                    cout << "*";
                }
                cout << endl;
            }
        }
    };

int main(){
    // creating a Grocery object
    Grocery grocery;
    //opening the file that I download for the test file 
    grocery.readFiles("CS210_Project_Three_input_file.txt");
    // creating a .dat file to store the information 
    grocery.writeFiles("frequency.dat");

    // delaring var for the while loop and user choice
    int userSelection;
    string choice;

    // using a while loop to run through the program option until the user is done 
    while (userSelection != 4) {
        cout << "Please make a selection below" << endl;
        cout << "1: will find the number of times the item you are suching for exist." << endl;
        cout << "2: will print the number of times all of the items exist" << endl;
        cout << "3: will print a histrogram for all of the items that exist" << endl;
        cout << "4: This will exit the program" << endl; 

        cin >> userSelection;

        // using a switch statement for the user choice 
        switch (userSelection){
        case 1:
            cout << "Enter the items you are looking for: ";
            cin >> choice;
            cout << "Frequency: " << grocery.findGrocery(choice) << endl;
            break;
        case 2:
            grocery.printNumberOfTimes();
            break;
        case 3:
            grocery.printHistogram();
            break;
        case 4:
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
  return 0;
}
    