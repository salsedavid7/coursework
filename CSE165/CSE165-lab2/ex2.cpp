#include <iostream>
using namespace std;
#define PR(EX) cout << #EX << ": " << EX << endl;

//function that sets each byte in range to specified value
void setBytes(void* v, size_t num_bytes, int val) {
    unsigned char* p_address = reinterpret_cast<unsigned char*>(v);
    unsigned char byte = static_cast<unsigned char>(val);

    for(size_t i = 0; i < num_bytes; i++){
        *p_address = byte++;
        p_address++;
  }
  PR(num_bytes);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5}; //array declaration
    int value = 100;
    void* arr_void = static_cast<void*>(&arr);    

    setBytes(arr_void, sizeof(arr), value);

    unsigned char* byte = reinterpret_cast<unsigned char*>(arr_void);

    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        cout << "arr[" << i << "] = ";
            for(int j = 0; j < sizeof(int); j++){
                cout << reinterpret_cast<int*>(*byte) << " ";
                byte++;
                }
    cout << endl;
  }
    return 0;
}
