/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:47 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/06 21:10:14 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
#define NODE_H

#include <exception>
#include <iostream>
#include <sstream>

template <typename T>
class Node {
 private:
  T key;
  Node *parent;
  Node *left;
  Node *right;

  Node() {}

 public:

  Node(Node const &node) {}

  Node(T key) : key(key),
                parent(NULL),
                left(NULL),
                right(NULL) {}

  ~Node(){};

  Node &operator=(Node const &rhs) {}

  void setKey(T &key) { this->key = &key; }
  void setLeft(Node<T> &left) { this->left = &left; }
  void setRight(Node<T> &right) { this->right = &right; }
  void setParent(Node<T> &parent) { this->parent = &parent; }

  T const getKey() const { return (this->key); }
  Node<T> const *getLeft() const { return (this->left); }
  Node<T> const *getRight() const { return (this->right); }
  Node<T> const *getParent() const { return (this->parent); }

  void insert(Node<T> &node) {
    if (this->key == node.key)
      throw std::exception();
    if (this->key > node.key) {
      if (this->left == NULL)
        this->left = &node;
      else
        this->left->insert(node);
    } else {
      if (this->right == NULL)
        this->right = &node;
      else
        this->right->insert(node);
    }
  }

  void postorder() {
    if (this == (static_cast<void *>(NULL)))
      return;
    this->left->postorder();
    this->right->postorder();
    std::cout << this->key << " ";
  }

  void inorder() {
    if (this == static_cast<void *>(NULL))
      return;
    this->left->inorder();
    std::cout << this->key << " ";
    this->right->inorder();
  }

  void preorder() {
    if (this == static_cast<void *>(NULL))
      return;
    std::cout << this->key << " ";
    this->left->preorder();
    this->right->preorder();
  }

  friend bool operator==(Node const &lhs, Node const &rhs) {
    return (lhs.key == rhs.key);
  }

  friend bool operator>(Node const &lhs, Node const &rhs) {
    return (lhs.key > rhs.key);
  }

  friend bool operator<(Node const &lhs, Node const &rhs) {
    return (lhs.key < rhs.key);
  }
};

#endif
