#include <iostream>

using namespace std;
//class counted that will contain the id and static int count
class counted{
    public:
    counted(): id(count++){
        cout << "counted created, id: " <<id << endl;
    }
    ~counted(){
        cout << "counted destroyed; id:" << id << endl;
    }
    private:
    int id;
    static int count;
};

int counted:: count = 0;

int main(){
    counted c1;
    counted c2;

    return 0;
}