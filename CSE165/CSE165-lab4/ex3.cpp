#include <iostream>

using namespace std;

class intArray{
    public: //must be set to public
        //Creating array of int
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int *arrP  ;

        //func will index array using pointer member
        void ptrIndex(){
            //sets pointer to array
            arrP = arr;

            //Iterating through array
            for(int i = 0; i < 10; i++) {
                //Printing out using pointer member
                cout << arrP[i] << ", ";
            }

            cout << endl;
        }
};

int main()
{
    //creates object of type intarray
    intArray x;

    //Call function to the print array using pointer
    x.ptrIndex();
}