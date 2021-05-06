# ./tests/BUILD

cc_test(
  name = "base_node",
  srcs = ["BaseBinaryNode_test.cpp"],
  deps = [
    "//include:base_node",
  "@googletest//:gtest_main"
  ]
)

cc_test(
  name = "node",
  srcs = ["Node_test.cpp"],
  deps = [
    "//include:node",
  "@googletest//:gtest_main"
  ]
)

cc_test(
  name = "bstree",
  srcs = ["BSTree_test.cpp"],
  deps = [
    "//include:node",
    "//include:bstree",
  "@googletest//:gtest_main"
  ]
)
