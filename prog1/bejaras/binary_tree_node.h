// binary_tree_node.h
//
// This file contains the definition and the implementation of the
// BinaryTreeNode class. The name of the class speaks for itself
// but a short explanation is provided.
// The node stores some data and pointers to its children.
// T can be int, char, a class etc.
//
// Considering the small size of the class, there's no separate
// .cc file.
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

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

template <typename T>
class BinaryTreeNode {
	public:
		BinaryTreeNode<T>(T init_data) {
			data = init_data;
			rchild = lchild = nullptr; // More elegant than 0 and safer than NULL
		}

		T get_data() {
			return data;
		}

		// Getter functions
		BinaryTreeNode<T> *get_right_child() const {
			return rchild;
		}
		BinaryTreeNode<T> *get_left_child() const {
			return lchild;
		}

		// Setter functions
		void set_right_child(BinaryTreeNode<T> *node) {
			rchild = node;
		}
		void set_left_child(BinaryTreeNode<T> *node) {
			lchild = node;
		}

		// returns whether the tree node has any child nodes
		bool HasChild(void) {
			return (rchild != nullptr) || (lchild != nullptr);
		}
	private:
		T data;
		BinaryTreeNode<T> *rchild, *lchild; // pointer to the right and left child, respectively
};

#endif
