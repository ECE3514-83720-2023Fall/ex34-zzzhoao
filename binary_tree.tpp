#include "binary_tree.hpp"

#include <stdexcept>
#include <iostream>

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(
    const TreeItemType &rootItem) {
  root = new NodeType(rootItem);
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(const TreeItemType &rootItem,
                                                   BinaryTree &leftTree,
                                                   BinaryTree &rightTree) {
  root = new NodeType(rootItem);

  attachLeftSubtree(leftTree);
  attachRightSubtree(rightTree);
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(NodeType *nodePtr) {
  root = nodePtr;
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(const BinaryTree &tree) {
  copyTree(tree.root, root);
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType> &
BinaryTree<TreeItemType, FunctionType>::operator=(const BinaryTree &rhs) {
  if (this != &rhs) {
    destroyTree(root);        // deallocate left-hand side
    copyTree(rhs.root, root); // copy right-hand side
  }
  return *this;
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>::~BinaryTree() {
  destroyTree(root);
}

template <typename TreeItemType, typename FunctionType>
bool BinaryTree<TreeItemType, FunctionType>::isEmpty() const noexcept {
  return (root == nullptr);
}

template <typename TreeItemType, typename FunctionType>
TreeItemType BinaryTree<TreeItemType, FunctionType>::rootData() const

{
  if (root == nullptr) {
    throw std::logic_error("Empty tree in BinaryTree:rootData");
  }
  return root->item;
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::setRootData(
    const TreeItemType &newItem) {
  if (root != nullptr) {
    root->item = newItem;
  } else {
    root = new NodeType(newItem);
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachLeft(
    const TreeItemType &newItem) {
  if (root == nullptr) {
    throw std::logic_error("Empty tree in BinaryTree::attachLeft");
  } else if (root->leftChildPtr != nullptr) {
    throw std::logic_error("Cannot overwrite left subtree");
  } else {
    root->leftChildPtr = new NodeType(newItem);
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachRight(
    const TreeItemType &newItem) {
 //TODO
 if (root == nullptr) {
    throw std::logic_error("Empty tree in BinaryTree::attachRight");
  } else if (root->rightChildPtr != nullptr) {
    throw std::logic_error("Cannot overwrite right subtree");
  } else {
    root->rightChildPtr = new NodeType(newItem);
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachLeftSubtree(
    BinaryTree &leftTree) {
  if (root == nullptr) {
    throw std::logic_error("Empty tree in BinaryTree::attachLeftSubtree");
  } else if (root->leftChildPtr != nullptr) {
    throw std::logic_error("Cannot overwrite left subtree");
  } else {
    root->leftChildPtr = leftTree.root;
    leftTree.root = nullptr;
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachRightSubtree(
    BinaryTree &rightTree) {
//TODO
 if (root == nullptr) {
    throw std::logic_error("Empty tree in BinaryTree::attachRightSubtree");
  } else if (root->rightChildPtr != nullptr) {
    throw std::logic_error("Cannot overwrite right subtree");
  } else {
    root->rightChildPtr = rightTree.root;
    rightTree.root = nullptr;
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::detachLeftSubtree(
    BinaryTree &leftTree) {
  if (root == nullptr) {
    throw std::logic_error("Empty tree in BinaryTree::detachLeftSubtree");
  } else {
    leftTree = BinaryTree(root->leftChildPtr);
    root->leftChildPtr = nullptr;
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::detachRightSubtree(
    BinaryTree &rightTree) {
  //TODO
  if (root == nullptr) {
    throw std::logic_error("Empty tree in BinaryTree::detachRightSubtree");
  } else {
    rightTree = BinaryTree(root->rightChildPtr);
    root->rightChildPtr = nullptr;
  }
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>
BinaryTree<TreeItemType, FunctionType>::leftSubtree() const {
  NodeType *subTreePtr = nullptr;
  copyTree(root->leftChildPtr, subTreePtr);
  return BinaryTree(subTreePtr);
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType>
BinaryTree<TreeItemType, FunctionType>::rightSubtree() const {
  //TODO
   NodeType *subTreePtr = nullptr;
  copyTree(root->rightChildPtr, subTreePtr);
  return BinaryTree(subTreePtr);
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::preorderTraverse(
    FunctionType visit) {
  preorder(root, visit);
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::inorderTraverse(
    FunctionType visit) {
  inorder(root, visit);
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::postorderTraverse(
    FunctionType visit) {
  postorder(root, visit);
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::copyTree(
    NodeType *treePtr, NodeType *&newTreePtr) const {
  // preorder traversal
  if (treePtr != nullptr) { 
    //TODO
    // copy root node
     newTreePtr = new NodeType(treePtr->item);
    // copy left subtree
     copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
    // copy right subtree
     copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
   
  } else {
    newTreePtr = nullptr; // copy empty tree
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::destroyTree(NodeType *&treePtr) {
  // postorder traversal
  if (treePtr != nullptr) {
    //TODO
    //destroy left subtree
     destroyTree(treePtr->leftChildPtr);
    //destroy right subtree
     destroyTree(treePtr->rightChildPtr);
    // delete root
    delete treePtr;
    treePtr = nullptr;
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::preorder(NodeType *treePtr,
                                                      FunctionType visit) {
  if (treePtr != nullptr) {
   //TODO
    visit(treePtr->item);
    preorder(treePtr->leftChildPtr, visit);
    preorder(treePtr->rightChildPtr, visit);
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::inorder(NodeType *treePtr,
                                                     FunctionType visit) {
  if (treePtr != nullptr) {
   //TODO
   inorder(treePtr->leftChildPtr, visit);
    visit(treePtr->item);
    inorder(treePtr->rightChildPtr, visit);
  }
}

template <typename TreeItemType, typename FunctionType>
void BinaryTree<TreeItemType, FunctionType>::postorder(NodeType *treePtr,
                                                       FunctionType visit) {
  if (treePtr != nullptr) {
   //TODO
   postorder(treePtr->leftChildPtr, visit);
    postorder(treePtr->rightChildPtr, visit);
    visit(treePtr->item);
  }
}

template <typename TreeItemType, typename FunctionType>
BinaryTree<TreeItemType, FunctionType> BinaryTree<TreeItemType, FunctionType>::makeBinaryTree(const TreeItemType *array, int low, int high) {
    std::cout << "low, high = " << low << " " << high << std::endl;
    //TODO
     if (low > high) { // Base case: empty segment
        return BinaryTree(); // Returns an empty tree
    }

    int mid = low + (high - low) / 2; // Find the middle element

    BinaryTree leftSubtree = makeBinaryTree(array, low, mid - 1);
    BinaryTree rightSubtree = makeBinaryTree(array, mid + 1, high);

    BinaryTree newTree(array[mid]);

    if (!leftSubtree.isEmpty()) {
        newTree.attachLeftSubtree(leftSubtree);
    }
    if (!rightSubtree.isEmpty()) {
        newTree.attachRightSubtree(rightSubtree);
    }

    return newTree;
}
