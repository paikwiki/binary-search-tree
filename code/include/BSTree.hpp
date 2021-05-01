/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:49:51 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/01 15:58:56 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_S_TREE_H
#define B_S_TREE_H

#include <iostream>

#include "Node.hpp"

template <typename _Node>
class BSTree {
 private:
  _Node &root;

  BSTree() {}

 public:
  BSTree(BSTree const &bstree) {}
  BSTree(_Node &root) : root(root) {}
  ~BSTree();

  BSTree &operator=(BSTree const &rhs) {}

  void insertNode(_Node &node) {
    this->root.insert(node);
  }

  _Node const &getRoot() { return (this->root); }

};

#endif
