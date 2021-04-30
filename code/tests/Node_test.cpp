/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:45:55 by cbaek             #+#    #+#             */
/*   Updated: 2021/04/30 22:22:01 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Node.hpp"
#include "gtest/gtest.h"

TEST(Node는, 상위노드를_가질_수_있다) {
  // setup
  Node<int> *node = new Node<int>(42);
  int parentKey = 21;

  Node<int> *parentNode = new Node<int>(parentKey);

  node->setParent(*parentNode);

  // test
  EXPECT_EQ(node->getParent(), *parentNode);

  // teardown
  delete parentNode;
  delete node;
}

TEST(Node는, 좌우_각각_하위노드를_가질_수_있다) {
  // setup
  Node<int> *node = new Node<int>(42);
  int leftKey = 21;
  int rightKey = 84;

  Node<int> *leftNode = new Node<int>(leftKey);
  Node<int> *rightNode = new Node<int>(rightKey);
  node->setLeft(*leftNode);
  node->setRight(*rightNode);

  // test
  EXPECT_EQ(node->getLeft(), *leftNode);
  EXPECT_EQ(node->getRight(), *rightNode);

  // teardown
  delete leftNode;
  delete rightNode;
  delete node;
}

TEST(Node는, 생성시_반드시_키값을_갖는다) {
  // setup
  Node<int> *node = new Node<int>(42);

  // test
  EXPECT_EQ(node->getKey(), 42);

  // teardown
  delete node;
}
