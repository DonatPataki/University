// lzw_binary_tree_main.cc
//
// Example usage of the LZWBinaryTree class
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
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

void Usage();

int main (int argc, char *argv[]) {
  bool print_tree = false;

	// if the program doesn't receive the right number of parameters
	// we'll help the user a bit
  if (argc < 5) {
      Usage();

      return -1;
  }
  else if (argc == 6)
    print_tree = true; // a bit lazy

  std::string input_name(*++argv);

  // we let the user limit the amount of kilobytes read
  long long int bytes_limit = std::stol(*++argv);

  bytes_limit *= 1024; // kilobytes -> bytes

  // I didn't want to hardcode the -1 value, so we read
  // the whole file when negative limit is given
  if (bytes_limit < 0)
  	bytes_limit = std::numeric_limits<long long int>::max();

  if (*((*++argv) + 1) != 'o') {
  	Usage();

  	return -1;
  }

  std::fstream input_stream (input_name, std::ios_base::in);

  // error opening the input file
	if (input_stream == nullptr)  {
      std::cout << " The file " << input_name << " doesn't exist!" << std::endl;

      return -1;
   }

  std::fstream output_stream (*++argv, std::ios_base::out);

  LZWBinaryTree lzwbtree;
  char b;
  long long int bytes_read = 0;
  bool is_comment = false;

  while ((input_stream.read((char *) &b, sizeof (char))) && (bytes_read++ < bytes_limit)) {
  	// if the character is '<' then the line is a comment
    if (b == 0x3e) {
 	  	is_comment = true;
 	  }
 	  // newline ends the comment
  	if (b == 0x0a) {
    	is_comment = false;
    }

    // we don't process comment, newline and 'N'
    if ((!is_comment) && (b != 0x0a)  && (b != 0x4e)) {
    	// each bit is converted into 1 or 0 (char)
    	// the conversion is done using bit masking and shifting
    	// the mask is shifted like: 1000_0000 -> 0100_0000
      for (int i = 0x80; i > 0x00; i >>= 1) {
        lzwbtree << ((b & i) ? '1' : '0');
			}
    }
  }

  input_stream.close();

  // see the implementation of LZWBinaryTree
  if (print_tree)
    output_stream << lzwbtree;

  output_stream << "depth = " << lzwbtree.get_max_depth() << std::endl
  							<< "mean = " 	<< lzwbtree.Mean() << std::endl
  							<< "var = " 	<< lzwbtree.Variance() << std::endl;

  output_stream.close();

  return 0;
}

void Usage() {
	std::cout << "Usage: lzw input kilobytes -o output [-tree]" << std::endl
						<< "kilobytes: -1 means the whole file" << std::endl
            << "-tree: print tree into output" << std::endl;
}
