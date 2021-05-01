/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:32:47 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/01 18:33:27 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <exception>
#include <sstream>

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
    if (this->key == node.key)
      throw std::exception();
    if (this->key > node.key) {
      if (this->left == static_cast<Node<T> *>(NULL))
        this->left = &node;
      else
        this->left->insert(node);
    } else {
      if (this->right == static_cast<Node<T> *>(NULL))
        this->right = &node;
      else
        this->right->insert(node);
    }
  }

  void inorder() {
    // std::cout << "A B C D E F G H I J ";
    if (this == static_cast<Node<T> *>(NULL))
      return ;
    this->left->inorder();
    std::cout << this->key << " ";
    this->right->inorder();
  }

  void preorder() {
    if (this == static_cast<Node<T> *>(NULL))
      return ;
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
