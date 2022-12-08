#include <iostream>

using namespace std;

class Node {
public:
    Node(int iData) : m_iData(iData), mp_nodeNext(nullptr) { }
    ~Node() { }
public:
    // These are declared public so that they can be accessed 
    // without using member accessor functions.
    int m_iData;
    Node* mp_nodeNext;

public:
    /// Display a list of Node objects to standard output given
    /// the head of the list of Nodes. (This is a static 
    /// member function; it behaves differently from ordinary
    /// member functions. You cannot use this->m_iData within 
    /// this fuction, for example.)
    /// @param [in] p_nodeHead pointer to Node object that is the
    /// head node of a list of Node objects. 
    /// @return void
    static void displayList(Node* p_nodeHead)
    {
        Node* p_node = p_nodeHead;
        // Iterate over the list of Nodes beginning from the
        // head of the list. Print the data out for each node. 
        // Then, set p_node to point to the next node in the list.
        // Continue until mp_nodeNext is set to nullptr, indicating
        // the end of the list.

        // Add a while loop that continues to iterate so long as
        // p_node is not the null pointer, nullptr.
        while (p_node != nullptr)
        {
            // Insert cout statement to display the data.
            cout << p_node->m_iData << endl;

            // Update p_node to point to the next node in
            // the liked list.
            p_node = p_node->mp_nodeNext;
        }
        return;
    }
};

int main()
{
    // Allocate three node objects within heap memory.
    Node* p_node1 = new Node(10);
    Node* p_node2 = new Node(20);
    Node* p_node3 = new Node(30);

    // Set p_nodeHead to point to the head or leading node
    // in the list of nodes, in this case p_node1.
    Node* p_nodeHead = p_node1;
    p_node1->mp_nodeNext = p_node2; // append p_node2 to the list of Node objects after p_node1.
    p_node2->mp_nodeNext = p_node3; // append p_node3 to the list of Node objects after p_node2.
    p_node3->mp_nodeNext = nullptr; // The end of the list is indicated by a mp_nodeNext value of nullptr.

    Node::displayList(p_nodeHead);  // display the list of nodes to standard output.
}
