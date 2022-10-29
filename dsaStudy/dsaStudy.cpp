#include "data-structures/red-black-tree/red-black-tree.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};

    MyRedBlackTree tree{};

    tree.insertKey(41);
    tree.insertKey(38);
    tree.insertKey(31);
    tree.insertKey(12);
    tree.insertKey(19);
    tree.insertKey(8);

    tree.printTree();
    std::cout << '\n';

    tree.deleteKey(8);

    tree.printTree();
    std::cout << '\n';

    tree.deleteKey(12);

    tree.printTree();
    std::cout << '\n';

    tree.deleteKey(19);

    tree.printTree();
    std::cout << '\n';

    tree.deleteKey(31);

    tree.printTree();
    std::cout << '\n';

    tree.deleteKey(38);

    tree.printTree();
    std::cout << '\n';

    return 0;
}
