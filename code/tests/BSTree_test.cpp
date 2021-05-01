/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTree_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:01:10 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/01 15:33:51 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BSTree.hpp"

#include "gtest/gtest.h"

TEST(BSTree_insertNode함수는, 자신보다_큰_key의_노드를_오른쪽에_삽입한다) {
  // setup
  Node<int> *node = new Node<int>(42);
  BSTree<Node<int> > *bst = new BSTree<Node<int> >(*node);

  Node<int> *bigNode = new Node<int>(47);
  bst->insertNode(*bigNode);

  // test
  EXPECT_EQ(bst->getRoot().right, bigNode);
  EXPECT_EQ(bst->getRoot().left, static_cast<Node<int> *>(NULL));

  // teardown
  delete node;
  // delete bst; // TODO: delete
}

TEST(BSTree_insertNode함수는, 자신보다_작은_key의_노드를_왼쪽에_삽입한다) {
  // setup
  Node<int> *node = new Node<int>(42);
  BSTree<Node<int> > *bst = new BSTree<Node<int> >(*node);

  Node<int> *smallNode = new Node<int>(7);
  bst->insertNode(*smallNode);

  // test
  EXPECT_EQ(bst->getRoot().left, smallNode);
  EXPECT_EQ(bst->getRoot().right, static_cast<Node<int> *>(NULL));

  // teardown
  delete node;
  // delete bst; // TODO: delete
}

TEST(BSTree_루트노드는, 부모로_NULL_을_갖는다) {
  // setup
  Node<int> *node = new Node<int>(42);
  BSTree<Node<int> > *bst = new BSTree<Node<int> >(*node);

  // test
  EXPECT_EQ((bst->getRoot()).parent, node->parent);

  // teardown
  delete node;
  // delete bst; // TODO: delete
}

TEST(BSTree는, 생성시_반드시_루트노드를_인자로_받는다) {
  // setup
  Node<int> *node = new Node<int>(42);
  BSTree<Node<int> > *bst = new BSTree<Node<int> >(*node);

  // test
  EXPECT_EQ(bst->getRoot(), *node);

  // teardown
  delete node;
  // delete bst; // TODO: delete
}
