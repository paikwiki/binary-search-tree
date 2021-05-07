/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:49:51 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/07 14:01:07 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_S_TREE_H
#define B_S_TREE_H

#include <iostream>

#include "BinarySearchTreeNode.hpp"

template <typename _Node>
class BSTree {
 private:
  _Node &root;

  BSTree() {}

 public:
  BSTree(BSTree const &bstree) {}
  BSTree(_Node &root) : root(root) {}
  ~BSTree() {}

  BSTree &operator=(BSTree const &rhs) {}

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
