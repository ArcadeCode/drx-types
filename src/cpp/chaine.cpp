/*
[FR] Implementation du concept de Liste chaînée en C++ vue en cours
[ANG] Implementation of chain list concept in C++
@licence = GPL-3
@author = Dervaux Esteban
*/
#include <iostream>   // For std::cout & std::endl
#include <stdexcept>  // For std::runtime_error
#include <string>     // For std::string, std::to_string(), std::pop_back()
//#include <cassert>  // For check the code with some cases
using std::string;    // Shortcut for std::string to string

struct node {
    int value;
    node* previous;
    // Model of a constructor of an struct
    node(int val, node* prev) : value(val), previous(prev) {}
};

/* NodeChain is an node manager using none fixed memory bloc */
class NodeChain {
    private :
        unsigned int size; // Size of the chain
        node* sommet; // Pointer to an node at the first place of the chain
    public :
        /* ----- Main methods ----- */
        void pushNode(int value) {
            /* Insert new node in memory */
            sommet = new node(value, sommet);
            std::cout << "Added node with value: " << value << std::endl;
            size++;
        }

        void pullNode(const unsigned int index) {
            /* Pull a node from the chain using her index */
            if(index >= size) {
                throw std::runtime_error("IndexError, index >= size of the Chain, index = "+std::to_string(index)+", index need to be < size");
            }
            node* pulledNode = getByIndex(index);
            if (index == size-1) {
                // In cas we pulled the sommet
                sommet = sommet->previous; // Now the first element is the next one
            } else if (index == 0) {
                // In case we pulled the first element at index 0
                getByIndex(1)->previous = nullptr;
            } else {
                // In common case
                node* nextNode = getByIndex(index+1);
                node* previousNode = getByIndex(index-1);
                nextNode->previous = previousNode;
            }
            delete pulledNode; // Pull out the node from RAM
            size--; // Decrement size because we pulled an element     
        }

        node* getByIndex(unsigned int index) {
            /* Return an pointer of the node in the node chain at the index index*/
            node* actualNode = sommet;
            if(index >= size) {
                throw std::runtime_error("IndexError, index > size of the Chain, index = "+std::to_string(index));
            }
            
            for (size_t i = size-1; i > index; i--) {
                // We go back to the previous and set it the actual index time
                actualNode = actualNode->previous;
            };
            return actualNode; // Return result
        }

        /* ----- Chain representation methods ----- */
        string getChainToString() {
            /* Return the chain as a string */
            string chain = "[";
            if (size != 0) {
                node* actualNode = sommet;
                for (size_t i = size-1; i > 0; i--) {
                    chain += std::to_string(actualNode->value) + ", ";
                    actualNode = actualNode->previous;
                };
                chain.pop_back(), chain.pop_back();
            }
            return chain+"]"; // Return a chain like "[a, b, c, d]"
        }

        /* ----- Constructor and destructor ----- */
        NodeChain() {
            size = 0; // At the construction, the chain is empty
            sommet = nullptr;
        }
        ~NodeChain() {
            while (sommet != nullptr) {
                node* toDelete = sommet;
                    std::cout << "Delete sommet : " << sommet << std::endl;
                sommet = sommet->previous;
                delete toDelete;
            };
            delete sommet; // Enfin tue le sommet
            
        }
};

/* Test function for NodeChain*/
class TestNodeChain {
private:
    // Test getChainToString with empty chain
    int Test_emptyGetChainToString() {
        NodeChain lambdaChain;
        string result = lambdaChain.getChainToString();
        return (result == "[]") ? 0 : 1;
    }
    // Test push with some value
    int Test_pushNode() {
        NodeChain lambdaChain;
        lambdaChain.pushNode(10);
        lambdaChain.pushNode(0.5);
        return (lambdaChain.getChainToString() == "[10, 0.5]") ? 0 : 1;
    }


public:
    TestNodeChain() {
    };
    ~TestNodeChain(){};
};


int main(int argc, char const *argv[]) {
    NodeChain manage;
    std::cout << manage.getChainToString() << std::endl;
    manage.pushNode(10); // Create new node
    manage.pushNode(20); // Create new node
    manage.pushNode(30); // Create new node
    manage.pushNode(40); // Create new node
    std::cout << manage.getChainToString() << std::endl;
    manage.pullNode(1); // Deleted second node
    std::cout << manage.getChainToString() << std::endl;
    // "manage" stop being used so the deconstructor of NodeManager is call
    // All node's has been destroyed from the ram
    return 0;
}
