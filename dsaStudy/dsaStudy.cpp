#include "data-structures/linked-list/linked-list.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};
    
    MyLinkedList linkedList{};
    Node* newNode{ new Node{ 66 } };
    linkedList.insertNode(newNode);
    Node* nodeToDelete{ linkedList.findKey(66) };
    linkedList.deleteNode(nodeToDelete);

    return 0;
}
