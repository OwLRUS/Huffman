#include <iostream>

using namespace std;

class Node
{
    int frequence;
    char letter;
    Node *leftChild;
    Node *rightChild;
public:
    Node(int freq, char lett);
    Node() { frequence = 0; letter = -1; }

    int getFrequence() { return frequence; }
    char getLetter() { return letter; }
    Node& getLeftChild() { return *leftChild; }
    Node& getRightChild() { return *rightChild; }

    void addChild(Node*);

    bool isLeaf();
};

Node::Node(int freq, char lett)
{
    frequence = freq;
    letter = lett;
    leftChild = NULL;
    rightChild = NULL;
}

void Node::addChild(Node *Child)
{
    if (!leftChild) leftChild = Child;
    else
    {
        if (leftChild->getFrequence() <= Child->getFrequence())
            rightChild = Child;
        else
        {
            rightChild = leftChild;
            leftChild = Child;
        }
    }

    frequence += Child->getFrequence();
}

bool Node::isLeaf()
{
    if (!leftChild && !rightChild) return true;
    return false;
}

int main()
{
    cout << "Hello World!\n";
}