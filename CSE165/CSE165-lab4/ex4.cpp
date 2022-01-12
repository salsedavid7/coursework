#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//define class text
class Text
{
    //will contain the text of test.txt
    string content;
    
    public:

    //Constructor
    Text() {}

    //Constructor with string filename parameter (name of file to open)
    Text(string filename) {
        //Opening file
        string temp;
        ifstream file;
        file.open(filename.c_str());

        //Concatenating text file into string content
        while(file >> temp)
        {
            //Adding a space between words
            content += (temp + " ");
        }
    }

    //Function to return contents of txt class object
    string contents()
    {
        //Return content of file as string
        return content;
    }
};

int main() {
    //Default constructor call
    cout << "DEFAULT CONSTRUCTOR CALL" << endl;
    //text object using default constructor
    Text a;
    //prints contents of Text a
    cout << a.contents() << endl;

    //String arg constructor call
    cout << "STRING ARG CONSTRUCTOR CALL" << endl;
    //Creating text object using constructor with filename, using "test.txt"
    Text b = Text("test.txt");
    //Printing contents of Text b
    cout << b.contents() << endl;

}