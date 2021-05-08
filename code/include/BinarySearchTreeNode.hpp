/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTreeNode.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:47 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/08 13:05:09 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_NODE_H
#define BINARY_SEARCH_TREE_NODE_H

#include <exception>
#include <iostream>

#include "BaseBinaryNode.hpp"

template <typename Node>
void insertByBST(Node *tree, Node &node) {
  if (tree->getKey() == node.getKey())
    throw std::exception();
  if (tree->getKey() > node.getKey()) {
    if (tree->getLeft() == NULL) {
      node.setParent(*tree);
      tree->setLeft(node);
    } else
      tree->getLeft()->insert(tree->getLeft(), node);
  } else {
    if (tree->getRight() == NULL) {
      node.setParent(*tree);
      tree->setRight(node);
    } else
      tree->getRight()->insert(tree->getRight(), node);
  }
}

template <typename Node>
Node *inorderByBST(Node *node, bool (*f)(Node *node)) {
  if (node == static_cast<void *>(NULL))
    return (node);
  inorderByBST(node->getLeft(), f);
  if (f(node))
    return (node);
  inorderByBST(node->getRight(), f);
  return (static_cast<Node *>(NULL));
}

template <typename Node>
Node *preorderByBST(Node *node, bool (*f)(Node *node)) {
  if (node == static_cast<void *>(NULL))
    return (node);
  if (f(node))
    return (node);
  preorderByBST(node->getLeft(), f);
  preorderByBST(node->getRight(), f);
  return (static_cast<Node *>(NULL));
}

template <typename Node>
Node *postorderByBST(Node *node, bool (*f)(Node *node)) {
  if (node == static_cast<void *>(NULL))
    return (node);
  postorderByBST(node->getLeft(), f);
  postorderByBST(node->getRight(), f);
  if (f(node))
    return (node);
  return (static_cast<Node *>(NULL));
}

template <typename Node>
bool printValue(Node *node) {
  std::cout << node->getKey() << " ";
  return false;
}

// template <typename Node, typename T>
// Node *getValue(T val) {
//   std::cout << val << " ";
// }

template <typename T>
class BinarySearchTreeNode : public BaseBinaryNode<T> {
 private:
  BinarySearchTreeNode() {}

 public:
  BinarySearchTreeNode(BinarySearchTreeNode const &node) {}

  BinarySearchTreeNode(T key) : BaseBinaryNode<T>(key) {
    this->insert = insertByBST;
  }

  ~BinarySearchTreeNode(){};

  void postorder() {
    this->traversal = postorderByBST;
    this->traversal(this, printValue);
  }

  void inorder() {
    this->traversal = inorderByBST;
    this->traversal(this, printValue);
  }

  void preorder() {
    this->traversal = preorderByBST;
    this->traversal(this, printValue);
  }
};

#endif
