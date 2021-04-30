/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:49:51 by cbaek             #+#    #+#             */
/*   Updated: 2021/04/30 22:38:02 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_S_TREE_H
#define B_S_TREE_H

#include <iostream>

#include "../include/Node.hpp"
template <typename _Node>
class BSTree {
 private:
  _Node *root;

  BSTree();
 public:
  BSTree(BSTree cosnt &bstree);
  ~BSTree();

  BSTree &operator=(BSTree const &rhs) {};
};

#endif
