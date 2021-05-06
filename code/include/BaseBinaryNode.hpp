/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseBinaryNode.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:21:37 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/06 21:30:48 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_BINARY_NODE_H
#define BASE_BINARY_NODE_H

#include <iostream>

template <typename T>
class BaseBinaryNode {
 private:
  T key;
  BaseBinaryNode *parent;
  BaseBinaryNode *left;
  BaseBinaryNode *right;

  BaseBinaryNode() {}

 public:
  BaseBinaryNode(BaseBinaryNode const &node) {}

  BaseBinaryNode(T key) : key(key),
                parent(NULL),
                left(NULL),
                right(NULL) {}

  ~BaseBinaryNode(){};

  BaseBinaryNode &operator=(BaseBinaryNode const &rhs) {}

  void setKey(T &key) { this->key = &key; }
  void setLeft(BaseBinaryNode<T> &left) { this->left = &left; }
  void setRight(BaseBinaryNode<T> &right) { this->right = &right; }
  void setParent(BaseBinaryNode<T> &parent) { this->parent = &parent; }

  T const getKey() const { return (this->key); }
  BaseBinaryNode<T> const *getLeft() const { return (this->left); }
  BaseBinaryNode<T> const *getRight() const { return (this->right); }
  BaseBinaryNode<T> const *getParent() const { return (this->parent); }

  friend bool operator==(BaseBinaryNode const &lhs, BaseBinaryNode const &rhs) {
    return (lhs.key == rhs.key);
  }

  friend bool operator>(BaseBinaryNode const &lhs, BaseBinaryNode const &rhs) {
    return (lhs.key > rhs.key);
  }

  friend bool operator<(BaseBinaryNode const &lhs, BaseBinaryNode const &rhs) {
    return (lhs.key < rhs.key);
  }
};

#endif
