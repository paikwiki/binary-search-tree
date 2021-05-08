/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseBinaryNode.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:21:37 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/08 15:21:07 by cbaek            ###   ########.fr       */
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
                          right(NULL),
                          insert(NULL),
                          baseFind(NULL),
                          traversal(NULL) {}

  virtual ~BaseBinaryNode(){};

  BaseBinaryNode &operator=(BaseBinaryNode const &rhs) {}

  void (*insert)(BaseBinaryNode<T> *tree, BaseBinaryNode<T> &node);

  BaseBinaryNode<T> *(*baseFind)(BaseBinaryNode<T> *tree, BaseBinaryNode<T> *target, bool (*f)(BaseBinaryNode<T> *, BaseBinaryNode<T> *));
  BaseBinaryNode<T> *(*traversal)(BaseBinaryNode<T> *tree, bool (*f)(BaseBinaryNode<T> *node));

  virtual void setKey(T &key) { this->key = key; }
  virtual void setLeft(BaseBinaryNode<T> &left) { this->left = &left; }
  virtual void setRight(BaseBinaryNode<T> &right) { this->right = &right; }
  virtual void setParent(BaseBinaryNode<T> &parent) { this->parent = &parent; }

  virtual T const getKey() const { return (this->key); }
  virtual BaseBinaryNode<T> *getLeft() const { return (this->left); }
  virtual BaseBinaryNode<T> *getRight() const { return (this->right); }
  virtual BaseBinaryNode<T> *getParent() const { return (this->parent); }

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
