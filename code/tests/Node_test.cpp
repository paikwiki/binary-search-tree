/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:45:55 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/01 15:24:44 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Node.hpp"
#include "gtest/gtest.h"

TEST(Node는, 상위노드를_가질_수_있다) {
  // setup
  Node<int> *node = new Node<int>(42);
  int parentKey = 21;


  node->parent = new Node<int>(parentKey);

  // test
  EXPECT_EQ(node->parent->key, parentKey);

  // teardown
  delete node;
}

TEST(Node는, 좌우_각각_하위노드를_가질_수_있다) {
  // setup
  Node<int> *node = new Node<int>(42);
  node->left = new Node<int>(21);
  node->right = new Node<int>(84);


  // test
  EXPECT_EQ(node->left->key, 21);
  EXPECT_EQ(node->right->key, 84);

  // teardown
  delete node;
}

TEST(Node는, 생성시_하위노드의_값은_NULL이다) {
  // setup
  Node<int> *node = new Node<int>(42);

  // test
  EXPECT_EQ(node->right, static_cast<Node<int> *>(0));
  EXPECT_EQ(node->left, static_cast<Node<int> *>(0));

  // teardown
  delete node;
}

TEST(Node는, 생성시_반드시_키값을_갖는다) {
  // setup
  Node<int> *node = new Node<int>(42);

  // test
  EXPECT_EQ(node->key, 42);

  // teardown
  delete node;
}
