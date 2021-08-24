#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <vector>


using namespace std;

#include "IndexMap.h"
#include "IndexRecord.h"


int main(){


    ifstream readfile;
    readfile.open("GreatExpectations.txt");

    if(readfile.fail())
        cout << "Could not open file";


    IndexMap newIndexMap;
    int pageNum = 1;
    int wordNum = 1;


    const int TIMES_RUN = 1;
    clock_t startTime = clock();

    while(!readfile.eof())
    {
        string tempString;
        readfile >> tempString;

        transform(tempString.begin(), tempString.end(), tempString.begin(), ::tolower);


        if(tempString != "----------------------------------------"){
            newIndexMap.add(tempString, pageNum, wordNum);
            wordNum++;
        }
        else{
            pageNum++;
            wordNum = 1;
        }


    }

    clock_t endTime = clock();
    double seconds = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC/ TIMES_RUN;

    cout << "-------------------Part 3-------------------" << endl;

    cout << "The time took to build the index was " << seconds << " seconds" << endl;
    cout << "There are a total of " << newIndexMap.numKeys() << " keys(different words) in the book" << endl;

    IndexRecord location = newIndexMap.get("fathers");

    cout << "Index Record for the word 'fathers': ";
    cout << location << endl;


    cout << "-------------------Part 4-------------------" << endl;

      newIndexMap.findWordPairs("great", "expectations");

     cout << "-------------------Part 5-------------------" << endl;

     int pageForPrint = 100;
     string toPrint = newIndexMap.firstWordOnPage(pageForPrint);
     cout << "The first word on page " << pageForPrint << " is: " << toPrint << endl;

}
