/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:47 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/01 15:20:14 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
 private:
  // T key;
  // Node *left;
  // Node *right;
  // Node *parent;

  Node() {}

 public:
 T key;
  Node *left;
  Node *right;
  Node *parent;

  Node(Node const &node) {}

  Node(T key) : key(key),
                left(static_cast<Node<T> *>(NULL)),
                right(static_cast<Node<T> *>(NULL)),
                parent(static_cast<Node<T> *>(NULL)) {}

  ~Node(){};

  Node &operator=(Node const &rhs) {}

  // void setLeft(Node &node) { this->left = &node; }
  // void setRight(Node &node) { this->right = &node; }
  // void setParent(Node &node) { this->parent = &node; }

  // Node<T> const &getLeft() const {
  //   if (this->left == static_cast<Node<T> *>(0))
  //     return (static_cast<Node<T> >(0));  // TODO: warning 제거
  //   return (*(this->left));
  // }
  // Node<T> const &getRight() const {
  //   if (this->right == static_cast<Node<T> *>(0))
  //     return (static_cast<Node<T> >(0));  // TODO: warning 제거
  //   return (*(this->right));
  // }
  // Node<T> const &getParent() const {
  //   if (this->parent == static_cast<Node<T> *>(0))
  //     return (static_cast<Node<T> >(0));  // TODO: warning 제거
  //   return (*(this->parent));
  // }

  // T const &getKey() const { return (this->key); }

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
