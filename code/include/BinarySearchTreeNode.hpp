/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTreeNode.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:47 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/07 14:55:07 by cbaek            ###   ########.fr       */
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
    }
    else
      tree->getLeft()->insert(tree->getLeft(), node);
  } else {
    if (tree->getRight() == NULL) {
      node.setParent(*tree);
      tree->setRight(node);
    }
    else
      tree->getRight()->insert(tree->getRight(), node);
  }
}

template <typename Node, typename T>
void inorderByBST(Node *node, void (*f)(T val)) {
  if (node == static_cast<void *>(NULL))
    return;
  inorderByBST(node->getLeft(), f);
  f(node->getKey());
  inorderByBST(node->getRight(), f);
}

template <typename Node, typename T>
void preorderByBST(Node *node, void (*f)(T val)) {
  if (node == static_cast<void *>(NULL))
    return;
  f(node->getKey());
  preorderByBST(node->getLeft(), f);
  preorderByBST(node->getRight(), f);
}

template <typename Node, typename T>
void postorderByBST(Node *node, void (*f)(T val)) {
  if (node == (static_cast<void *>(NULL)))
    return;
  postorderByBST(node->getLeft(), f);
  postorderByBST(node->getRight(), f);
  f(node->getKey());
}

template <typename T>
void printValue(T val) {
  std::cout << val << " ";
}

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
