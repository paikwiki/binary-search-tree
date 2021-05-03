/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTree_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:01:10 by cbaek             #+#    #+#             */
/*   Updated: 2021/05/03 21:11:12 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BSTree.hpp"

#include "gtest/gtest.h"

TEST(BSTree_postorder함수는, 후위순회를_할수있다) {
  // setup
  Node<char> *A = new Node<char>('A');
  Node<char> *B = new Node<char>('B');
  Node<char> *C = new Node<char>('C');
  Node<char> *D = new Node<char>('D');
  Node<char> *E = new Node<char>('E');
  Node<char> *F = new Node<char>('F');
  Node<char> *G = new Node<char>('G');
  Node<char> *H = new Node<char>('H');
  Node<char> *I = new Node<char>('I');
  Node<char> *J = new Node<char>('J');

  E->left = A;
  D->left = B;
  D->right = C;
  E->right = D;
  J->left = E;
  I->left = F;
  H->left = G;
  I->right = H;
  J->right = I;
  BSTree<Node<char> > *bst = new BSTree<Node<char> >(*J);

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
  Node<char> *A = new Node<char>('A');
  Node<char> *B = new Node<char>('B');
  Node<char> *C = new Node<char>('C');
  Node<char> *D = new Node<char>('D');
  Node<char> *E = new Node<char>('E');
  Node<char> *F = new Node<char>('F');
  Node<char> *G = new Node<char>('G');
  Node<char> *H = new Node<char>('H');
  Node<char> *I = new Node<char>('I');
  Node<char> *J = new Node<char>('J');

  B->left = A;
  F->left = B;
  D->left = C;
  B->right = D;
  D->right = E;

  F->right = G;
  G->right = I;
  I->left = H;
  I->right = J;
  BSTree<Node<char> > *bst = new BSTree<Node<char> >(*F);

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
  Node<char> *A = new Node<char>('A');
  Node<char> *B = new Node<char>('B');
  Node<char> *C = new Node<char>('C');
  Node<char> *D = new Node<char>('D');
  Node<char> *E = new Node<char>('E');
  Node<char> *F = new Node<char>('F');
  Node<char> *G = new Node<char>('G');
  Node<char> *H = new Node<char>('H');
  Node<char> *I = new Node<char>('I');
  Node<char> *J = new Node<char>('J');

  A->left = B;
  B->left = C;
  C->left = D;
  D->right = E;
  B->right = F;
  F->left = G;
  F->right = H;
  A->right = I;
  I->right = J;

  BSTree<Node<char> > *bst = new BSTree<Node<char> >(*A);

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
  Node<int> *node = new Node<int>(42);
  BSTree<Node<int> > *bst = new BSTree<Node<int> >(*node);

  Node<int> *bigNode = new Node<int>(47);
  bst->insertNode(*bigNode);

  // test
  EXPECT_EQ(bst->getRoot().right, bigNode);
  EXPECT_EQ(bst->getRoot().left, static_cast<Node<int> *>(NULL));

  // teardown
  delete node;
  delete bst;
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
  delete bst;
}

// TEST(BSTree_루트노드는, 부모로_NULL_을_갖는다) {
//   // setup
//   Node<int> *node = new Node<int>(42);
//   BSTree<Node<int> > *bst = new BSTree<Node<int> >(*node);

//   // test
//   EXPECT_EQ((bst->getRoot()).parent, node->parent);

//   // teardown
//   delete node;
//   // delete bst;
// }

TEST(BSTree는, 생성시_반드시_루트노드를_인자로_받는다) {
  // setup
  Node<int> *node = new Node<int>(42);
  BSTree<Node<int> > *bst = new BSTree<Node<int> >(*node);

  // test
  EXPECT_EQ(bst->getRoot(), *node);

  // teardown
  delete node;
  delete bst;
}
