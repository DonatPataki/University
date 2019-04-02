// lzw_binary_tree.cc
//
// Contains the implementation of the LZWBinaryTree class (see the appropriate header)
// To find out more about the compression method used read
//  man compress
// and the following site:
// 	http://www.progpater.blog.hu
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

#include "lzw_binary_tree.h"

// public

void LZWBinaryTree::operator<<(char c) {
	BinaryTreeNode<char> *temp_node =
		(c == '0') ? current_node->get_left_child() : current_node->get_right_child();
	// depending on the parameter we either select the l (0) or r (1) child

	// we are going deeper in the tree, therefore if we insert a new node
	// so the depth of the node is increasing
	++insertion_depth;

	if (temp_node != nullptr) {
		current_node = temp_node;
	}
	else {
		BinaryTreeNode<char> *new_node = new BinaryTreeNode<char>(c);

		// the only scenario when the number of external nodes
		// would increase
		if (current_node->HasChild())
		{
			external_nodes++;
			mean_sum += insertion_depth; // let's calculate the mean sum on the fly
		}
		else
			++mean_sum;

		// we assign the pointer to the newly created node of the
		// appropriate child
		if (c == '0')
			current_node->set_left_child(new_node);
		else
			current_node->set_right_child(new_node);

		node_count++; // we keep track of the node count just as a new one is inserted

		// the depth is calculated on the fly, there's no need to traverse the tree
		if (insertion_depth > max_depth)
			max_depth = insertion_depth;

		// reset
		insertion_depth = 0;

	  current_node = &root;		// jump back to root
	}
}

void LZWBinaryTree::TraverseTree(TraverseOrder order, BinaryTreeNode<char> *node,
																 std::function<void(BinaryTreeNode<char>*, int)> fn) {
	traverse_depth = 0;

	// the function is stored so we don't have to pass it to each call of the
	// appropriate function (p_PreOrder etc.)
	traverse_function = fn;

	switch(order)	{
		case PREORDER:	PreOrder(node);
										break;
		case INORDER: 	InOrder(node);
										break;
		case POSTORDER: PostOrder(node);
										break;
	}
}

double LZWBinaryTree::Mean(void)
{
	// -1 indicates that the mean must be recalculated. Otherwise we use the result of the
	// latest call.
	/*if (mean_sum == -1) {
		mean_sum = 0;

		TraverseTree(POSTORDER, &root, [this](BinaryTreeNode<char> *n, int depth) {
									if (n->HasChild())
		 								mean_sum += depth;
								});
	}*/

	// mean_sum is already calculated -> lol rekt wotm8
	return (double)mean_sum / external_nodes;
}

double LZWBinaryTree::Variance(void)
{
	double avg = Mean();
	double var;

	variance_sum = 0;

	TraverseTree(POSTORDER, &root, [&](BinaryTreeNode<char> *n, int depth) {
								if (!n->HasChild())
									variance_sum += ((depth - avg) * (depth - avg));
							});

	if (external_nodes - 1 > 0)
		var = std::sqrt(variance_sum / (external_nodes - 1));
	else
		var = std::sqrt(variance_sum);

	return var;
}

std::ostream & operator<< (std::ostream &output_stream, LZWBinaryTree &lzwbt) {
	lzwbt.TraverseTree(INORDER, lzwbt.get_root_node(), [&](BinaryTreeNode<char> *n, int depth) {
	 										output_stream << std::string(depth * 3, '-') << n->get_data()
	 								 									<< '(' << (depth - 1) << ')' << std::endl;
										 });

	return output_stream;
}

// protected

void LZWBinaryTree::PreOrder(BinaryTreeNode<char> *node) {
	if (node == nullptr) {
		return;
	}

	traverse_function(node, traverse_depth);

	++traverse_depth;
	PreOrder(node->get_right_child());
	PreOrder(node->get_left_child());
	--traverse_depth;
}

void LZWBinaryTree::InOrder(BinaryTreeNode<char> *node) {
	if (node == nullptr) {
		return;
	}

	++traverse_depth;
	InOrder(node->get_right_child());

	traverse_function(node, traverse_depth);

	InOrder(node->get_left_child());
	--traverse_depth;
}

void LZWBinaryTree::PostOrder(BinaryTreeNode<char> *node) {
	if (node == nullptr) {
		return;
	}

	++traverse_depth;
	PostOrder(node->get_right_child());
	PostOrder(node->get_left_child());
	--traverse_depth;

	traverse_function(node, traverse_depth);
}

// private

void LZWBinaryTree::FreeNode(BinaryTreeNode<char> *node) {
	if (node != nullptr) {
		FreeNode(node->get_right_child());
		FreeNode(node->get_left_child());

		delete node;
	}
}
