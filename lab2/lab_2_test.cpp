#include "lab_2.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(Search_Test, Key_Is_In_Tree)
{
    node* root = NewNode(2);
    node* child = NewNode(3);
    node* child_2 = NewNode(1);
    node* child_3 = NewNode(4);
    root->right = child;
    child->parent = root;
    child->right = child_3;
    child_3->parent = child;
    root->left = child_2;
    child_2->parent = root;

    node* find = Search(root, 3);
    EXPECT_EQ(find->key, 3);
}

TEST(Search_Test, Key_Is_Not_In_Tree)
{
    node* root = NewNode(2);
    node* child = NewNode(3);
    node* child_2 = NewNode(1);
    node* child_3 = NewNode(4);
    root->right = child;
    child->parent = root;
    child->right = child_3;
    child_3->parent = child;
    root->left = child_2;
    child_2->parent = root;
    node* find = Search(root, 5);
    EXPECT_TRUE(find == NULL);
}

TEST(Search_Test, Tree_Is_Empty)
{
    node* null_tree = NULL;
    node* result = Search(null_tree, 4);
    ASSERT_FALSE(result != NULL);
}

TEST(Insert_Test, Empty_Tree)
{
    node* null_tree = NULL;
    Insert(null_tree, 5);
    EXPECT_EQ(5, null_tree->key);
}

TEST(Insert_Test, Already_In_Tree)
{
    node* root = NewNode(2);
    node* child = NewNode(3);
    root->right = child;
    child->parent = root;
    Insert(root, 3);
    EXPECT_EQ(root->right->key, 3);
    EXPECT_TRUE(root->right->left == NULL);

}

TEST(Insert_Test, Adding_To_Tree)
{
    node* root = NewNode(2);
    node* child = NewNode(3);
    root->right = child;
    child->parent = root;
    node* element_1 = Insert(root, 1);
    EXPECT_EQ(root->parent->key, 1);
}

TEST(Split_Test, One_Tree_Is_Empty)
{
    node* root = NewNode(2);
    node* child = NewNode(3);
    root->right = child;
    child->parent = root;
    node* tree_1 = NULL;
    node* tree_2 = NULL;
    Split(3, root, tree_1, tree_2);
    EXPECT_TRUE(tree_2 == NULL);
    EXPECT_TRUE(tree_1->left->key == 2);
}

TEST(Split_Test, Split_By_Wrong_Key)
{
    node* root = NewNode(2);
    node* child = NewNode(3);
    root->right = child;
    child->parent = root;
    node* tree_1 = NULL;
    node* tree_2 = NULL;
    Split(1, root, tree_1, tree_2);
    EXPECT_TRUE(tree_2 == NULL);
    EXPECT_TRUE(tree_1 == NULL);
}

TEST(Split_Test, Ordinary_Split)
{
    node* root = NewNode(2);
    node* child = NewNode(3);
    node* child_2 = NewNode(1);
    node* child_3 = NewNode(4);
    root->right = child;
    child->parent = root;
    child->right = child_3;
    child_3->parent = child;
    root->left = child_2;
    child_2->parent = root;
    node* tree_1 = NULL;
    node* tree_2 = NULL;
    Split(3, root, tree_1, tree_2);
    EXPECT_EQ(tree_1->key, 2);
    EXPECT_EQ(tree_2->right->key, 4);
}

TEST(Merge_Test, One_Tree_Is_Empty)
{
    node* root = NewNode(2);
    node* child = NewNode(3);
    root->right = child;
    child->parent = root;
    node* null_tree = NULL;
    node* new_tree = Merge(root, null_tree);
    EXPECT_EQ(root->key, 2);
}

TEST(Merge_Test, Both_Trees_Are_Empty)
{
    node* tree_1 = NULL;
    node* tree_2 = NULL;
    node* expect_null = Merge(tree_1, tree_2);
    EXPECT_TRUE(expect_null == NULL);
}

TEST(Merge_Test, Trees_Are_Colliding)
{
    node* root_1 = NewNode(2);
    node* child_1 = NewNode(3);
    root_1->right = child_1;
    child_1->parent = root_1;
    node* root_2 = NewNode(1);
    node* child_2 = NewNode(2);
    root_2->right = child_2;
    child_2->parent = root_2;
    node* expect_null = Merge(root_1, root_2);
    EXPECT_TRUE(expect_null == NULL);
}

TEST(Merge_Test, Ordinary_Merge)
{
    node* root_1 = NewNode(2);
    node* child_1 = NewNode(3);
    root_1->right = child_1;
    child_1->parent = root_1;
    node* root_2 = NewNode(0);
    node* child_2 = NewNode(1);
    root_2->right = child_2;
    child_2->parent = root_2;
    node* new_tree = Merge(root_2, root_1);
    EXPECT_EQ(new_node->key, 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
} 