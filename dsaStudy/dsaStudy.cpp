#include "data-structures/red-black-tree/red-black-tree.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};

    MyRedBlackTree tree{};

    tree.insertKey(55);
    tree.insertKey(40);
    tree.insertKey(65);
    tree.insertKey(60);
    tree.insertKey(75);
    tree.insertKey(57);

    tree.printTree();

    return 0;
}
