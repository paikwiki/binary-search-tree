/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:47 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/01 15:56:15 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
 private:
  Node() {}

 public:
  T key;
  Node<T> *left;
  Node<T> *right;
  Node<T> *parent;

  Node(Node const &node) {}

  Node(T key) : key(key),
                left(static_cast<Node<T> *>(NULL)),
                right(static_cast<Node<T> *>(NULL)),
                parent(static_cast<Node<T> *>(NULL)) {}

  ~Node(){};

  Node &operator=(Node const &rhs) {}

  void insert(Node<T> &node) {
    if (this->key > node.key) {
      this->left = &node;
    } else {
      this->right = &node;
    }
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
