/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:47 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/01 15:37:58 by cbaek            ###   ########.fr       */
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
