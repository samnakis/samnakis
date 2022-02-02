#include <string>
using namespace std;

class Node {
    public:
        // default constructor/destructor
        Node();
        ~Node();

        // other stuff
        string item;
        Node * next;
};