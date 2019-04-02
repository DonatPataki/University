// lzw_binary_tree.h
//
// This file contains the definition of the LZWBinaryTree and the TreeNode classes.
// Assuming that the reader has a basic knowledge about trees,
// and the LZW compression the following class is pretty simple.
// The tree has a root ('/') node. Each node has 2 children (the reason it's called binary):
//  left - 0 right - 1
// As we are reading the input, we traverse the tree and
// insert a new node if needed.
//
// -----------------------------------
// Copyright (C) Attila Bagossy 2015.
// -----------------------------------
//
// The following terms and conditions apply:
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef LZW_BINARY_TREE_H
#define LZW_BINARY_TREE_H

#include "binary_tree_node.h"
#include <functional>
#include <iostream>
#include <cmath>
#include <string>


enum TraverseOrder {
	PREORDER 	= 0,
	INORDER 	= 1,
	POSTORDER = 2
};

class LZWBinaryTree {
	public:
		LZWBinaryTree(): root('/'), node_count(1), traverse_depth(0), insertion_depth(0), mean_sum(0), external_nodes(1) {
			current_node = &root;
			max_depth = 0;
		}
		// in older versions mean_sum was initialized with "-1" instead of "0", so the program
		// gave false results when ran on smaller files (typically under 1 KB)
		// The value of "-1" indicated in the first version that the mean_sum should be recalculated
		// This indication became deprecated but the initialization wasn't modified.
		// see: lzw_binary_tree.cc line 97
		~LZWBinaryTree() {
			FreeNode(root.get_right_child());
			FreeNode(root.get_left_child());
		}
		// The class takes input through the "<<" operator.
		// A new node is created if needed. The depth is calculated after each insertion
		void operator<< (char c);

		// The basic idea behind this function is pretty simple:
		// The traverse code is provided and you can define your own code to be executed.
		// It's like a wrapper function. The std::function comes with a little overhead when called, but
		// it's much more elegant and C++-ish than function pointers.
		// Lambdas also supported.
		void TraverseTree(TraverseOrder order, BinaryTreeNode<char> *node,
											std::function<void(BinaryTreeNode<char>*, int)> fn);

		// Calculates and returns the mean.
		double Mean(void);

		// Works just the same way as Mean()
		double Variance(void);

		// The tree's representation can be written into any output stream
		// InOrder traversal
		// recursive
		friend std::ostream & operator<< (std::ostream &os, LZWBinaryTree &lzwbt);

		// Gets the root node
		// Let others access the whole tree and avoid TraverseTree or
		// apply TraverseTree to a subtree
		BinaryTreeNode<char> *get_root_node() {
			return &root;
		}

		// Getters
		int get_node_count(void) {
			return node_count;
		}

		int get_max_depth(void) {
			return max_depth;
		}

		int get_external_nodes(void) {
			return external_nodes;
		}

	protected:
		// The function names are pretty straightforward
		// Traversal algorithms applying the TraverseTree function
		// recursive
		void PreOrder(BinaryTreeNode<char> *node);

		void InOrder(BinaryTreeNode<char> *node);

		void PostOrder(BinaryTreeNode<char> *node);

	private:
		int node_count;					// number of nodes in the tree
		int insertion_depth; 		// depth of *current_node
		int traverse_depth;			// depth of the recently visited node
		int max_depth;					// maximal depth
		int external_nodes;			// number of nodes without children (both pointers set to nullptr)

		int mean_sum;
		double variance_sum;

		BinaryTreeNode<char> root, *current_node;
		std::function<void(BinaryTreeNode<char>*, int)> traverse_function;

		// free the allocated memory of a node
		// recursive
		void FreeNode(BinaryTreeNode<char> *node);

		LZWBinaryTree (const LZWBinaryTree&);
    LZWBinaryTree& operator= (const LZWBinaryTree&);
};

#endif
