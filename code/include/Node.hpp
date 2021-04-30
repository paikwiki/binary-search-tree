/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:47 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/01 03:05:50 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
 private:
  T key;
  Node *left;
  Node *right;
  Node *parent;

  Node() {}

 public:
  Node(Node const &node) {}

  Node(T key) : key(key),
                left(NULL),
                right(NULL),
                parent(NULL) {}

  ~Node(){};

  Node &operator=(Node const &rhs) {}

  void setLeft(Node &node) { this->left = &node; }
  void setRight(Node &node) { this->right = &node; }
  void setParent(Node &node) { this->parent = &node; }

  Node<T> const &getLeft() const {
    if (this->left == NULL)
      return (NULL);  // TODO: warning 제거
    return (*(this->left));
  }
  Node<T> const &getRight() const {
    if (this->right == NULL)
      return (NULL);  // TODO: warning 제거
    return (*(this->right));
  }
  Node<T> const &getParent() const {
    if (this->parent == NULL)
      return (NULL);  // TODO: warning 제거
    return (*(this->parent));
  }

  T &getKey() { return (this->key); }

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
