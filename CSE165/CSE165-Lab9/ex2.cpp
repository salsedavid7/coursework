#include<iostream>
using namespace std;

//base class which will contain member functions to throw exceptions
class Person{
        string name;
        int DOB;
public:
//defining exception class which will be thrown if DOB is invalid
        class InvalidDOBException : public exception{
                public:
                        //char to store the exception message
                        const char* msg;
                        //constructor accepting the error message
                        InvalidDOBException(const char* errorMsg) {msg = errorMsg;}
        };

        //constructor that will take name and DOB and throws Exception if the Date of birth is invalid
        Person(string NAME, int dob) throw(InvalidDOBException){
                name = NAME;
                setDOB(dob);
        }
        
        //sets DOB parameters based on my own, throws invalidDOBexception if DOB is not 2000
        void setDOB(int dob) throw(InvalidDOBException){
                //throwing InvalidDOBException if DOB is not 2000
                if(dob != 2000){
                        //passing an error message to InvalidDOBException 
                        throw InvalidDOBException("David's Date of Birth is 2000");
                }
                DOB = dob;
        }
        
        //gets name
        string getName() {
                return name;
        }
        //gets DOB
        int getDOB() {
                return DOB;
        }
};

int main(){
        //try block 
        try{
                //generating person based on my name and DOB
                Person me("David", 2000);
                cout << "Name: " << me.getName() << ", Date of Birth: " << me.getDOB() << endl;
                cout << "Setting Date of Birth to 1999..." << endl;
                //this parameter will throw InvalidDOBException
                me.setDOB(1999);
        }
        catch(Person::InvalidDOBException exception){
                //if exception is caught, display error message
                cout << exception.msg << endl;
        }
        return 0;
}
