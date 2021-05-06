/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseBinaryNode_test.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:24:40 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/06 21:33:19 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BaseBinaryNode.hpp"

#include "gtest/gtest.h"

TEST(BaseBinaryNode는, 상위노드를_가질_수_있다) {
  // setup
  BaseBinaryNode<int> *node = new BaseBinaryNode<int>(42);
  BaseBinaryNode<int> *parentNode = new BaseBinaryNode<int>(21);

  node->setParent(*parentNode);

  // test
  EXPECT_EQ(node->getParent(), parentNode);

  // teardown
  delete parentNode;
  delete node;
}

TEST(BaseBinaryNode는, 좌우_각각_하위노드를_가질_수_있다) {
  // setup
  BaseBinaryNode<int> *node = new BaseBinaryNode<int>(42);
  BaseBinaryNode<int> *leftNode = new BaseBinaryNode<int>(21);
  BaseBinaryNode<int> *rightNode = new BaseBinaryNode<int>(84);
  node->setLeft(*leftNode);
  node->setRight(*rightNode);

  // test
  EXPECT_EQ(node->getLeft()->getKey(), 21);
  EXPECT_EQ(node->getRight()->getKey(), 84);

  // teardown
  delete node;
}

TEST(BaseBinaryNode는, 생성시_하위노드의_값은_NULL이다) {
  // setup
  BaseBinaryNode<int> *node = new BaseBinaryNode<int>(42);

  // test
  EXPECT_EQ(node->getRight(), static_cast<void *>(NULL));
  EXPECT_EQ(node->getLeft(), static_cast<void *>(NULL));

  // teardown
  delete node;
}

TEST(BaseBinaryNode는, 생성시_반드시_키값을_갖는다) {
  // setup
  BaseBinaryNode<int> *node = new BaseBinaryNode<int>(42);

  // test
  EXPECT_EQ(node->getKey(), 42);

  // teardown
  delete node;
}
