/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:45:55 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/01 16:26:54 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Node.hpp"
#include "gtest/gtest.h"

TEST(Node의insert함수는, 하위노드가_있을_경우_재귀적으로_삽입위치를_찾는다_3) {
  // setup
  //        4
  //       / \
  //      2  21
  //          \
  //          42

  Node<int> *root = new Node<int>(4);
  Node<int> *node1 = new Node<int>(2);
  Node<int> *node2 = new Node<int>(21);
  Node<int> *node3 = new Node<int>(42);
  root->insert(*node1);
  root->insert(*node2);
  root->insert(*node3);

  // test
  EXPECT_EQ(root->left->key, 2);
  EXPECT_EQ(root->right->key, 21);
  EXPECT_EQ(root->right->right->key, 42);
  EXPECT_EQ(root->left->left, static_cast<Node<int> *>(0));
  EXPECT_EQ(root->left->right, static_cast<Node<int> *>(0));
  EXPECT_EQ(root->right->left, static_cast<Node<int> *>(0));

  // teardown
  delete root;
  delete node1;
  delete node2;
  delete node3;
}

TEST(Node의insert함수는, 하위노드가_있을_경우_재귀적으로_삽입위치를_찾는다_2) {
  // setup
  //       42
  //       /
  //      4
  //    /  \
  //   2   21

  Node<int> *node = new Node<int>(42);
  Node<int> *smallerNode = new Node<int>(4);
  Node<int> *smallNode = new Node<int>(21);
  Node<int> *smallestNode = new Node<int>(2);
  node->insert(*smallerNode);
  node->insert(*smallNode);
  node->insert(*smallestNode);

  // test
  EXPECT_EQ(node->left->key, 4);
  EXPECT_EQ(node->left->left->key, 2);
  EXPECT_EQ(node->left->right->key, 21);
  EXPECT_EQ(node->right, static_cast<Node<int> *>(0));

  // teardown
  delete node;
  delete smallNode;
  delete smallerNode;
  delete smallestNode;
}

TEST(Node의insert함수는, 하위노드가_있을_경우_재귀적으로_삽입위치를_찾는다_1) {
  // setup
  //       42
  //       /
  //      21
  //     /
  //    4
  //   /
  //  2

  Node<int> *node = new Node<int>(42);
  Node<int> *smallNode = new Node<int>(21);
  Node<int> *smallerNode = new Node<int>(4);
  Node<int> *smallestNode = new Node<int>(2);
  node->insert(*smallNode);
  node->insert(*smallerNode);
  node->insert(*smallestNode);

  // test
  EXPECT_EQ(node->left->key, 21);
  EXPECT_EQ(node->left->left->key, 4);
  EXPECT_EQ(node->left->left->left->key, 2);
  EXPECT_EQ(node->right, static_cast<Node<int> *>(0));
  EXPECT_EQ(node->left->right, static_cast<Node<int> *>(0));
  EXPECT_EQ(node->left->left->right, static_cast<Node<int> *>(0));
  EXPECT_EQ(node->left->left->left->right, static_cast<Node<int> *>(0));

  // teardown
  delete node;
  delete smallNode;
  delete smallerNode;
  delete smallestNode;
}

TEST(Node의insert함수는, key보다_큰_노드를_우측_하위노드에_추가한다) {
  // setup
  Node<int> *node = new Node<int>(42);
  Node<int> *bigNode = new Node<int>(84);
  node->insert(*bigNode);

  // test
  EXPECT_EQ(node->right->key, 84);
  EXPECT_EQ(node->left, static_cast<Node<int> *>(0));

  // teardown
  delete node;
  delete bigNode;
}

TEST(Node의insert함수는, key보다_작은_노드를_좌측_하위노드에_추가한다) {
  // setup
  Node<int> *node = new Node<int>(42);
  Node<int> *smallNode = new Node<int>(21);
  node->insert(*smallNode);

  // test
  EXPECT_EQ(node->left->key, 21);
  EXPECT_EQ(node->right, static_cast<Node<int> *>(0));

  // teardown
  delete node;
}

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
