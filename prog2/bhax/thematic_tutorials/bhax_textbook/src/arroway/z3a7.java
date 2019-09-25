import java.io.FileInputStream;
import java.io.PrintWriter;
import java.lang.Exception;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.File;
import java.io.FileWriter;
import javax.servlet.*;
import javax.servlet.http.*;


final class Node {
  public Node(char c) {
    value = c;
  }

  public Node() {
    this('/');
  }

  public char getValue() {
    return value;
  }

  public boolean hasChild() {
    return ((leftChild != null) || (rightChild != null));
  }

  public Node getLeftChild() {
    return leftChild;
  }

  public void setLeftChild(Node node) {
    if (node == this) {
      return;
    }

    leftChild = node;
  }

  public Node getRightChild() {
    return rightChild;
  }

  public void setRightChild(Node node) {
    if (node == this) {
      return;
    }

    rightChild = node;
  }

  @Override
  public boolean equals(Object obj) {
    if (!(obj instanceof Node)) {
      return false;
    }
    if (obj == this) {
      return true;
    }

    Node rhs = (Node)obj;

    return (value == rhs.getValue());
  }

  @Override
  public String toString() {
    return String.valueOf(value);
  }

  private final char value;

  private Node leftChild, rightChild;
}

 final class LZWBinTree {
  public LZWBinTree() {
    rootNode = new Node();

    currentNode = rootNode;

    // all other fields will be initialized with the default values (0 and 0.0d)
    nodeCount = externalNodes = 1;
  }

  public int getMaxDepth() {
    return maxDepth;
  }

  public void insert(char c) {
    // depending on the parameter, the right or left child is selected
    Node tempNode =
      (c == '0') ? currentNode.getRightChild() : currentNode.getLeftChild();

    // we are going deeper in the tree as a new child is inserted or
    // a step is made
    ++insertionDepth;

    // go one step deeper
    if (tempNode != null) {
      currentNode = tempNode;
    }
    else {
      // a new node is inserted
      Node newNode = new Node(c);

      // the only scenario when the number of external nodes
      // would increase
      if (currentNode.hasChild()) {
        ++externalNodes;

        // meanSum is calculated at insertion-time
        meanSum += insertionDepth;
      }
      else {
        ++meanSum;
      }

      if (c == '0') {
        currentNode.setRightChild(newNode);
      }
      else {
        currentNode.setLeftChild(newNode);
      }

      ++nodeCount;

      if (insertionDepth > maxDepth) {
        maxDepth = insertionDepth;
      }

      // jump back to root
      insertionDepth = 0;

      currentNode = rootNode;
    }
  }

  public double mean() {
    return (double)meanSum / externalNodes;
  }

  public double variance() {
    traverseDepth = 0;

    varianceSum = 0.0d;

    // start the recursion
    calculateVariance(rootNode);

    if (externalNodes - 1 > 0) {
        return Math.sqrt((double)varianceSum / (externalNodes - 1));
    }

    return Math.sqrt(varianceSum);
  }

  private void calculateVariance(Node node) {
    if (node == null) {
      return;
    }

    // PostOrder tree traversal
    ++traverseDepth;
    calculateVariance(node.getLeftChild());

    calculateVariance(node.getRightChild());
    --traverseDepth;

    // calls to mean() are quite cheap so these won't cause any performance drop
    if (!node.hasChild()) {
      varianceSum += ((double)(traverseDepth - mean()) * (traverseDepth - mean()));
    }
  }

  public void printTree(PrintWriter printWriter) {
    traverseDepth = 0;

    printNode(rootNode, printWriter);
  }

  private void printNode(Node node, PrintWriter printWriter) {
    if (node == null) {
      return;
    }

    ++traverseDepth;
    printNode(node.getLeftChild(), printWriter);

    for (int i = 0; i < traverseDepth; ++i) {
      printWriter.print("---");
    }

    printWriter.printf("%c(%d)%n", node.getValue(), traverseDepth - 1);

    printNode(node.getRightChild(), printWriter);
    --traverseDepth;
  }

  private final Node rootNode;

  private Node currentNode;

  private int insertionDepth, traverseDepth, maxDepth;
  private int meanSum;
  private int externalNodes;
  private int nodeCount;

  private double varianceSum;
}


 public class z3a7 {
    public static void main(String[] args) {
      if ((args.length < 4) || (!args[2].equals("-o")))  {
        printUsage();

        return;
      }

      long bytesLimit = -1;

      try {
        bytesLimit = Long.parseLong(args[1]) * 1024;
      }
      catch (NumberFormatException nfe) {
        System.out.println("Invalid numeric value, will be using the max value instead!");
      }

      if (bytesLimit < 0) {
        bytesLimit = Long.MAX_VALUE;
      }

      LZWBinTree lzwbt = new LZWBinTree();

      try {
        FileInputStream inputStream = new FileInputStream(args[0]);

        int b;
        long bytesRead = 0;
        boolean isComment = false;

        while (((b = inputStream.read()) != -1) && (bytesRead++ < bytesLimit)) {
          if (b == 0x3e) {
            isComment = true;
          }

          if (b == 0x0a) {
            isComment = false;
          }

          if ((!isComment) && (b != 0x0a)  && (b != 0x4e)) {
            for (int i = 0x80; i > 0x00; i >>= 1) {
              lzwbt.insert((b & i) == 0 ? '0' : '1');
                   }
          }
        }
      }
      catch (java.io.IOException ioe) {
        System.err.println(ioe.getMessage());
      }

      try {
        PrintWriter printWriter = new PrintWriter(new java.io.BufferedWriter(
                                                  new java.io.FileWriter(args[3])));

        lzwbt.printTree(printWriter);
        output.print("depth " + theTree.getDepth () + "\n");
        output.print("mean " + theTree.getMean () + "\n");
        output.print("var " + theTree.getVariance () + "\n");

        output.close();
        PrintWriter out = response.getWriter();

        out.println("<html>");
        out.println("<head><title>LZWBinFa</title></head>");
        out.println("<body>");
        out.println("<h1>Binfa</h1>");
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(new File("o")))))
        {
            for(String line; (line = br.readLine()) != null; ) 
            {
                out.println("<p>" + line + "</p>");
            }
        }
        out.println("</body></html>");


        printWriter.flush();
      }
      catch (java.io.FileNotFoundException fnfe) {
        System.err.println(fnfe.getMessage());
      }
      catch (java.io.IOException ioe) {
        System.err.println(ioe.getMessage());
      }
    }

    public static void printUsage() {
      System.out.println("input kilobytes -o output");
    }
}
