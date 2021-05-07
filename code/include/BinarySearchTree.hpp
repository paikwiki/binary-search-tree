/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:49:51 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/07 14:06:26 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

#include "BinarySearchTreeNode.hpp"

template <typename _Node>
class BinarySearchTree {
 private:
  _Node &root;

  BinarySearchTree() {}

 public:
  BinarySearchTree(BinarySearchTree const &BinarySearchTree) {}
  BinarySearchTree(_Node &root) : root(root) {}
  ~BinarySearchTree() {}

  BinarySearchTree &operator=(BinarySearchTree const &rhs) {}

  void postorderTraversal() {
    this->root.postorder();
  }

  void inorderTraversal() {
    this->root.inorder();
  }

  void preorderTraversal() {
    this->root.preorder();
  }

  void insertNode(_Node &node) {
    this->root.insert(&root, node);
  }

  _Node const &getRoot() { return (this->root); }
};

#endif
