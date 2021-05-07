/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:47 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/07 13:45:13 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
#define NODE_H

#include <exception>
#include <iostream>

#include "BaseBinaryNode.hpp"

//
template <typename Node>
void insertByBST(Node *tree, Node &node) {
  if (tree->getKey() == node.getKey())
    throw std::exception();
  if (tree->getKey() > node.getKey()) {
    if (tree->getLeft() == NULL)
      tree->setLeft(node);
    else
      tree->getLeft()->insert(tree->getLeft(), node);
  } else {
    if (tree->getRight() == NULL)
      tree->setRight(node);
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
class Node : public BaseBinaryNode<T> {
 private:
  Node() {}

 public:
  Node(Node const &node) {}

  Node(T key) : BaseBinaryNode<T>(key) {
    this->insert = insertByBST;
  }

  ~Node(){};

  void postorder() {
    this->travesal = postorderByBST;
    this->travesal(this, printValue);
  }

  void inorder() {
    this->travesal = inorderByBST;
    this->travesal(this, printValue);
  }

  void preorder() {
    this->travesal = preorderByBST;
    this->travesal(this, printValue);
  }
};

#endif
