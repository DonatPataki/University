import java.io.FileNotFoundException;
import java.io.PrintWriter;

public aspect aop
{
	public pointcut travel(LZWBinaryTree.Node n, PrintWriter os) 
	: call(public void LZWBinaryTree.printTree(LZWBinaryTree.Node, PrintWriter)) && args(n,os);
	
    after(LZWBinaryTree.Node n, PrintWriter os) throws FileNotFoundException : travel(n, os)
    {
    	inOrder(n,new PrintWriter("in-order.txt"));
    	depth = 0;
    	postOrder(n,new PrintWriter("post-order.txt"));
    }
    
    
    public void inOrder(LZWBinaryTree.Node n, PrintWriter p)
    {
    	if (n != null)
        {
            ++depth;
            for (int i = 0; i < depth; ++i)
                p.print("---");
            p.print(n.getValue () + "(" + depth + ")\n");
            inOrder (n.getLeftChild (), p);
            inOrder (n.getRightChild (), p);
            --depth;
        }
    }
    public void postOrder(LZWBinaryTree.Node n, PrintWriter p)
    {
    	if (n != null)
        {
            ++depth;
            postOrder (n.getLeftChild (), p);
            postOrder (n.getRightChild (), p);
            for (int i = 0; i < depth; ++i)
                p.print("---");
            p.print(n.getValue () + "(" + depth + ")\n");
            --depth;
        }
    }
    
    
}
