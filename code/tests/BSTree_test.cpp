/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTree_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:01:10 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/07 14:02:47 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BSTree.hpp"

#include "gtest/gtest.h"

TEST(BSTree_postorder함수는, 후위순회를_할수있다) {
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

  BSTree<BinarySearchTreeNode<char> > *bst = new BSTree<BinarySearchTreeNode<char> >(*J);

  // test
  testing::internal::CaptureStdout();
  bst->postorderTraversal();
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
  delete bst;
}

TEST(BSTree_inorderTraveral함수는, 중위순회를_할수있다) {
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

  BSTree<BinarySearchTreeNode<char> > *bst = new BSTree<BinarySearchTreeNode<char> >(*F);

  // test
  testing::internal::CaptureStdout();
  bst->inorderTraversal();
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
  delete bst;
}

TEST(BSTree_preorder함수는, 전위순회를_할수있다) {
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

  BSTree<BinarySearchTreeNode<char> > *bst = new BSTree<BinarySearchTreeNode<char> >(*A);

  // test
  testing::internal::CaptureStdout();
  bst->preorderTraversal();
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
  delete bst;
}

TEST(BSTree_insertNode함수는, 자신보다_큰_key의_노드를_오른쪽에_삽입한다) {
  // setup
  BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(42);
  BSTree<BinarySearchTreeNode<int> > *bst = new BSTree<BinarySearchTreeNode<int> >(*node);

  BinarySearchTreeNode<int> *bigNode = new BinarySearchTreeNode<int>(47);
  bst->insertNode(*bigNode);

  // test
  EXPECT_EQ(bst->getRoot().getRight(), bigNode);
  EXPECT_EQ(bst->getRoot().getLeft(), static_cast<BinarySearchTreeNode<int> *>(NULL));

  // teardown
  delete node;
  delete bst;
}

TEST(BSTree_insertNode함수는, 자신보다_작은_key의_노드를_왼쪽에_삽입한다) {
  // setup
  BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(42);
  BSTree<BinarySearchTreeNode<int> > *bst = new BSTree<BinarySearchTreeNode<int> >(*node);

  BinarySearchTreeNode<int> *smallNode = new BinarySearchTreeNode<int>(7);
  bst->insertNode(*smallNode);

  // test
  EXPECT_EQ(bst->getRoot().getLeft(), smallNode);
  EXPECT_EQ(bst->getRoot().getRight(), static_cast<BinarySearchTreeNode<int> *>(NULL));

  // teardown
  delete node;
  delete bst;
}

TEST(BSTree_루트노드는, 부모로_NULL_을_갖는다) {
  // setup
  BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(42);
  BSTree<BinarySearchTreeNode<int> > *bst = new BSTree<BinarySearchTreeNode<int> >(*node);

  // test
  EXPECT_EQ((bst->getRoot()).getParent(), node->getParent());

  // teardown
  delete node;
  delete bst;
}

TEST(BSTree는, 생성시_반드시_루트노드를_인자로_받는다) {
  // setup
  BinarySearchTreeNode<int> *node = new BinarySearchTreeNode<int>(42);
  BSTree<BinarySearchTreeNode<int> > *bst = new BSTree<BinarySearchTreeNode<int> >(*node);

  // test
  EXPECT_EQ(bst->getRoot(), *node);

  // teardown
  delete node;
  delete bst;
}
