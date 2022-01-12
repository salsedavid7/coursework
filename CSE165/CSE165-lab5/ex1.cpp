//copy pasting from textbook but will add a virtual function prepare and call prepare in tune
#include <iostream>

using namespace std;

enum note { 
    middleC, Csharp, Cflat 
    };

class Instrument {
public:
//calling virtual functions 
  virtual void play(note) const {
    cout << "Instrument::play" << endl;
  }

  virtual void prepare() const {
    cout << "Instrument::prepare" << endl;
  }
};

class Wind : public Instrument {
public:
  void play(note) const {
    cout << "Wind::play" << endl;
  }
};

//calls prepare in function tune 
void tune(Instrument& i) {
  i.prepare();
  i.play(middleC);
}

int main() {
  Wind flute;
  tune(flute);
}