#include <iostream>
#include <vector>

using namespace std;

class counted {
friend ostream& operator<< (ostream& out, const counted& o);
public:
    counted() : id(count++) { cout << "counted created, id: " << id << endl; }
    ~counted() { cout << "counted destroyed; id: " << id << endl; }
private:
    int id;
    static int count;
};

int counted::count = 0;

ostream& operator<< (ostream& out, const counted& o) {
    out << o.id;
    return out;
}

int main() {

    vector<counted*> v;

    //filling vector
    for (int i = 0; i < 5; i++)
        v.push_back(new counted);

    cout << "\nVector elements: " << v.size() << endl;
    cout << "\nPrinting counted objects" << endl;

    //printing vector
    for (int i = 0; i < v.size(); i++)
        cout << *v[i] << ' ';

    cout << "\n\nDestroying: " << endl;

    //deleting
    while (v.size() > 0) {
        counted* temp = v.back();
        v.pop_back();
        delete temp;
    }

return 0;
}
