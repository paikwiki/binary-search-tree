/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTreeNode_test.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 21:45:55 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/08 15:23:12 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BinarySearchTreeNode.hpp"

#include <sstream>

#include "gtest/gtest.h"

TEST(BinarySearchTreeNode의find함수는, 일치하는_노드를_찾아_반환할수있다) {
  // setup
  BinarySearchTreeNode<char> *A = new BinarySearchTreeNode<char>('A');
  BinarySearchTreeNode<char> *B = new BinarySearchTreeNode<char>('B');
  BinarySearchTreeNode<char> *C = new BinarySearchTreeNode<char>('C');
  BinarySearchTreeNode<char> *D = new BinarySearchTreeNode<char>('D');
  BinarySearchTreeNode<char> *E = new BinarySearchTreeNode<char>('E');
  BinarySearchTreeNode<char> *F = new BinarySearchTreeNode<char>('F');
  BinarySearchTreeNode<char> *G = new BinarySearchTreeNode<char>('G');
  BinarySearchTreeNode<char> *H = new BinarySearchTreeNode<char>('H');
  BinarySearchTreeNode<char> *I = new BinarySearchTreeNode<char>('I');
  BinarySearchTreeNode<char> *J = new BinarySearchTreeNode<char>('J');

  A->insert(A, *B);
  A->insert(A, *C);
  A->insert(A, *D);
  A->insert(A, *E);
  A->insert(A, *F);
  A->insert(A, *G);
  A->insert(A, *H);
  A->insert(A, *I);

  // test
  EXPECT_EQ(A->find(A), A);
  EXPECT_EQ(A->find(B), B);
  EXPECT_EQ(A->find(C), C);
  EXPECT_EQ(A->find(D), D);
  EXPECT_EQ(A->find(E), E);
  EXPECT_EQ(A->find(F), F);
  EXPECT_EQ(A->find(G), G);
  EXPECT_EQ(A->find(H), H);
  EXPECT_EQ(A->find(I), I);


  // teardown
  delete A;
  delete B;
  delete C;
  delete D;
  delete E;
  delete F;
  delete G;
  delete H;
  delete I;
  delete J;
}

TEST(BinarySearchTreeNode의postorder함수는, 후위순회를_할수있다) {
  // setup
  BinarySearchTreeNode<char> *A = new BinarySearchTreeNode<char>('A');
  BinarySearchTreeNode<char> *B = new BinarySearchTreeNode<char>('B');
  BinarySearchTreeNode<char> *C = new BinarySearchTreeNode<char>('C');
  BinarySearchTreeNode<char> *D = new BinarySearchTreeNode<char>('D');
  BinarySearchTreeNode<char> *E = new BinarySearchTreeNode<char>('E');
  BinarySearchTreeNode<char> *F = new BinarySearchTreeNode<char>('F');
  BinarySearchTreeNode<char> *G = new BinarySearchTreeNode<char>('G');
  BinarySearchTreeNode<char> *H = new BinarySearchTreeNode<char>('H');
  BinarySearchTreeNode<char> *I = new BinarySearchTreeNode<char>('I');
  BinarySearchTreeNode<char> *J = new BinarySearchTreeNode<char>('J');

  E->setLeft(*A);
  D->setLeft(*B);
  D->setRight(*C);
  E->setRight(*D);
  J->setLeft(*E);
  I->setLeft(*F);
  H->setLeft(*G);
  I->setRight(*H);
  J->setRight(*I);

  // test
  testing::internal::CaptureStdout();
  J->postorder();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "A B C D E F G H I J ");

  // teardown
  delete A;
  delete B;
  delete C;
  delete D;
  delete E;
  delete F;
  delete G;
  delete H;
  delete I;
  delete J;
}

TEST(BinarySearchTreeNode의inorder함수는, 중위순회를_할수있다) {
  // setup
  BinarySearchTreeNode<char> *A = new BinarySearchTreeNode<char>('A');
  BinarySearchTreeNode<char> *B = new BinarySearchTreeNode<char>('B');
  BinarySearchTreeNode<char> *C = new BinarySearchTreeNode<char>('C');
  BinarySearchTreeNode<char> *D = new BinarySearchTreeNode<char>('D');
  BinarySearchTreeNode<char> *E = new BinarySearchTreeNode<char>('E');
  BinarySearchTreeNode<char> *F = new BinarySearchTreeNode<char>('F');
  BinarySearchTreeNode<char> *G = new BinarySearchTreeNode<char>('G');
  BinarySearchTreeNode<char> *H = new BinarySearchTreeNode<char>('H');
  BinarySearchTreeNode<char> *I = new BinarySearchTreeNode<char>('I');
  BinarySearchTreeNode<char> *J = new BinarySearchTreeNode<char>('J');

  B->setLeft(*A);
  F->setLeft(*B);
  D->setLeft(*C);
  B->setRight(*D);
  D->setRight(*E);

  F->setRight(*G);
  G->setRight(*I);
  I->setLeft(*H);
  I->setRight(*J);

  // test
  testing::internal::CaptureStdout();
  F->inorder();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "A B C D E F G H I J ");

  // teardown
  delete A;
  delete B;
  delete C;
  delete D;
  delete E;
  delete F;
  delete G;
  delete H;
  delete I;
  delete J;
}

TEST(BinarySearchTreeNode의preorder함수는, 전위순회를_할수있다) {
  // setup
  BinarySearchTreeNode<char> *A = new BinarySearchTreeNode<char>('A');
  BinarySearchTreeNode<char> *B = new BinarySearchTreeNode<char>('B');
  BinarySearchTreeNode<char> *C = new BinarySearchTreeNode<char>('C');
  BinarySearchTreeNode<char> *D = new BinarySearchTreeNode<char>('D');
  BinarySearchTreeNode<char> *E = new BinarySearchTreeNode<char>('E');
  BinarySearchTreeNode<char> *F = new BinarySearchTreeNode<char>('F');
  BinarySearchTreeNode<char> *G = new BinarySearchTreeNode<char>('G');
  BinarySearchTreeNode<char> *H = new BinarySearchTreeNode<char>('H');
  BinarySearchTreeNode<char> *I = new BinarySearchTreeNode<char>('I');
  BinarySearchTreeNode<char> *J = new BinarySearchTreeNode<char>('J');

  A->setLeft(*B);
  B->setLeft(*C);
  C->setLeft(*D);
  D->setRight(*E);
  B->setRight(*F);
  F->setLeft(*G);
  F->setRight(*H);
  A->setRight(*I);
  I->setRight(*J);

  // test
  testing::internal::CaptureStdout();
  A->preorder();
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "A B C D E F G H I J ");

  // teardown
  delete A;
  delete B;
  delete C;
  delete D;
  delete E;
  delete F;
  delete G;
  delete H;
  delete I;
  delete J;
}

TEST(BinarySearchTreeNode의insert함수는, 트리에_이미_해당값이_있을_경우_예외를_발생한다_2) {
  // setup
  BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(42);
  BinarySearchTreeNode<int> *node1 = new BinarySearchTreeNode<int>(4);
  BinarySearchTreeNode<int> *node2 = new BinarySearchTreeNode<int>(2);
  BinarySearchTreeNode<int> *node3 = new BinarySearchTreeNode<int>(42);
  BinarySearchTreeNode<int> *node4 = new BinarySearchTreeNode<int>(2);

  root->insert(root, *node1);
  root->insert(root, *node2);

  // test
  EXPECT_THROW(root->insert(root, *node3), std::exception);
  EXPECT_THROW(root->insert(root, *node4), std::exception);

  // teardown
  delete root;
  delete node1;
  delete node2;
  delete node3;
  delete node4;
}

TEST(BinarySearchTreeNode의insert함수는, 트리에_이미_해당값이_있을_경우_예외를_발생한다_1) {
  // setup
  BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(42);
  BinarySearchTreeNode<int> *node1 = new BinarySearchTreeNode<int>(42);

  // test
  EXPECT_THROW(root->insert(root, *node1), std::exception);

  // teardown
  delete root;
  delete node1;
}

TEST(BinarySearchTreeNode의insert함수는, 하위노드가_있을_경우_재귀적으로_삽입위치를_찾는다_3) {
  // setup
  //        4
  //       / \
  //      2  21
  //          \
  //          42

  BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(4);
  BinarySearchTreeNode<int> *node1 = new BinarySearchTreeNode<int>(2);
  BinarySearchTreeNode<int> *node2 = new BinarySearchTreeNode<int>(21);
  BinarySearchTreeNode<int> *node3 = new BinarySearchTreeNode<int>(42);
  root->insert(root, *node1);
  root->insert(root, *node2);
  root->insert(root, *node3);

  // test
  EXPECT_EQ(root->getLeft()->getKey(), 2);
  EXPECT_EQ(root->getRight()->getKey(), 21);
  EXPECT_EQ(root->getRight()->getRight()->getKey(), 42);
  EXPECT_EQ(root->getLeft()->getLeft(),  static_cast<void *>(NULL));
  EXPECT_EQ(root->getLeft()->getRight(),  static_cast<void *>(NULL));
  EXPECT_EQ(root->getRight()->getLeft(),  static_cast<void *>(NULL));

  // teardown
  delete root;
  delete node1;
  delete node2;
  delete node3;
}

TEST(BinarySearchTreeNode의insert함수는, 하위노드가_있을_경우_재귀적으로_삽입위치를_찾는다_2) {
  // setup
  //       42
  //       /
  //      4
  //    /  \
  //   2   21

  BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(42);
  BinarySearchTreeNode<int> *smallerNode = new BinarySearchTreeNode<int>(4);
  BinarySearchTreeNode<int> *smallNode = new BinarySearchTreeNode<int>(21);
  BinarySearchTreeNode<int> *smallestNode = new BinarySearchTreeNode<int>(2);
  root->insert(root, *smallerNode);
  root->insert(root, *smallNode);
  root->insert(root, *smallestNode);

  // test
  EXPECT_EQ(root->getLeft()->getKey(), 4);
  EXPECT_EQ(root->getLeft()->getLeft()->getKey(), 2);
  EXPECT_EQ(root->getLeft()->getRight()->getKey(), 21);
  EXPECT_EQ(root->getRight(),  static_cast<void *>(NULL));

  // teardown
  delete root;
  delete smallNode;
  delete smallerNode;
  delete smallestNode;
}

TEST(BinarySearchTreeNode의insert함수는, 하위노드가_있을_경우_재귀적으로_삽입위치를_찾는다_1) {
  // setup
  //       42
  //       /
  //      21
  //     /
  //    4
  //   /
  //  2

  BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(42);
  BinarySearchTreeNode<int> *smallNode = new BinarySearchTreeNode<int>(21);
  BinarySearchTreeNode<int> *smallerNode = new BinarySearchTreeNode<int>(4);
  BinarySearchTreeNode<int> *smallestNode = new BinarySearchTreeNode<int>(2);
  root->insert(root, *smallNode);
  root->insert(root, *smallerNode);
  root->insert(root, *smallestNode);

  // test
  EXPECT_EQ(root->getLeft()->getKey(), 21);
  EXPECT_EQ(root->getLeft()->getLeft()->getKey(), 4);
  EXPECT_EQ(root->getLeft()->getLeft()->getLeft()->getKey(), 2);
  EXPECT_EQ(root->getRight(),  static_cast<void *>(NULL));
  EXPECT_EQ(root->getLeft()->getRight(),  static_cast<void *>(NULL));
  EXPECT_EQ(root->getLeft()->getLeft()->getRight(),  static_cast<void *>(NULL));
  EXPECT_EQ(root->getLeft()->getLeft()->getLeft()->getRight(),  static_cast<void *>(NULL));

  // teardown
  delete root;
  delete smallNode;
  delete smallerNode;
  delete smallestNode;
}

TEST(BinarySearchTreeNode의insert함수는, 삽입시_부모노드를_설정한다) {
  // setup
  BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(42);

  BinarySearchTreeNode<int> *leftNode = new BinarySearchTreeNode<int>(7);
  BinarySearchTreeNode<int> *rightNode = new BinarySearchTreeNode<int>(43);
  root->insert(root, *leftNode);
  root->insert(root, *rightNode);

  // test
  EXPECT_EQ(root->getLeft()->getParent(), root);
  EXPECT_EQ(root->getRight()->getParent(), root);

  // teardown
  delete root;
  delete leftNode;
  delete rightNode;
}

TEST(BinarySearchTreeNode의insert함수는, key보다_큰_노드를_우측_하위노드에_추가한다) {
  // setup
  BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(42);
  BinarySearchTreeNode<int> *bigNode = new BinarySearchTreeNode<int>(84);
  node->insert(node, *bigNode);

  // test
  EXPECT_EQ(node->getRight()->getKey(), 84);
  EXPECT_EQ(node->getLeft(),  static_cast<void *>(NULL));

  // teardown
  delete node;
  delete bigNode;
}

TEST(BinarySearchTreeNode의insert함수는, key보다_작은_노드를_좌측_하위노드에_추가한다) {
  // setup
  BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(42);
  BinarySearchTreeNode<int> *smallNode = new BinarySearchTreeNode<int>(21);
  node->insert(node, *smallNode);

  // test
  EXPECT_EQ(node->getLeft()->getKey(), 21);
  EXPECT_EQ(node->getRight(),  static_cast<void *>(NULL));

  // teardown
  delete node;
  delete smallNode;
}

TEST(BinarySearchTreeNode는, 상위노드를_가질_수_있다) {
  // setup
  BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(42);
  BinarySearchTreeNode<int> *parentNode = new BinarySearchTreeNode<int>(21);

  node->setParent(*parentNode);

  // test
  EXPECT_EQ(node->getParent(), parentNode);

  // teardown
  delete parentNode;
  delete node;
}

TEST(BinarySearchTreeNode는, 좌우_각각_하위노드를_가질_수_있다) {
  // setup
  BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(42);
  BinarySearchTreeNode<int> *leftNode = new BinarySearchTreeNode<int>(21);
  BinarySearchTreeNode<int> *rightNode = new BinarySearchTreeNode<int>(84);
  node->setLeft(*leftNode);
  node->setRight(*rightNode);

  // test
  EXPECT_EQ(node->getLeft()->getKey(), 21);
  EXPECT_EQ(node->getRight()->getKey(), 84);

  // teardown
  delete node;
}

TEST(BinarySearchTreeNode는, 생성시_하위노드의_값은_NULL이다) {
  // setup
  BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(42);

  // test
  EXPECT_EQ(node->getRight(), static_cast<void *>(NULL));
  EXPECT_EQ(node->getLeft(), static_cast<void *>(NULL));

  // teardown
  delete node;
}

TEST(BinarySearchTreeNode는, 생성시_반드시_키값을_갖는다) {
  // setup
  BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(42);

  // test
  EXPECT_EQ(node->getKey(), 42);

  // teardown
  delete node;
}
