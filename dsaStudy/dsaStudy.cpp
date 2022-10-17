#include "data-structures/binary-search-tree/binary-search-tree.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};

    MyBinarySearchTree tree{};
    MyBinarySearchTree* root{ new MyBinarySearchTree{ 6 } };

    tree.insert(root, 555);
    tree.insert(root, 34);
    tree.insert(root, 32);
    tree.insert(root, 322);
    tree.insert(root, 32);
    tree.insert(root, 78);

    tree.inorderWalk(root);
    std::cout << '\n';

    tree.remove(root, 322);

    tree.inorderWalk(root);
    std::cout << '\n';

    tree.remove(root, 78);

    tree.inorderWalk(root);
    std::cout << '\n';

    return 0;
}
