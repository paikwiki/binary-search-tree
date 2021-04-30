/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTree_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:01:10 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/01 02:00:44 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BSTree.hpp"
#include "gtest/gtest.h"

TEST(BSTree는, 생성시_반드시_루트노드를_인자로_받는다) {
  // setup
  Node<int> *node = new Node<int>(42);
  BSTree< Node<int> > *bst = new BSTree< Node<int> >(*node);

  // test
  EXPECT_EQ(bst->getRoot(), *node);

  // teardown
  delete node;
  // delete bst; // TODO: delete
}
