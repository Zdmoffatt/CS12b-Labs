/*
Zachary Moffatt
zmoffatt
CS12m
5/29/16
Lab7
Dictionary.java
Creates a binary search tree of keys and values and provides opperations to act on the list
*/

public class Dictionary implements DictionaryInterface{

//Node stuff
    private class Node{
        String value;
        String key;
        Node left;
        Node right;

        //Node constructor
        Node(String k, String v){
            key = k;
            value = v;
            left = null;
            right = null;
        }
    }

    private Node root;
    private int numItems;

//Dictionary Stuff
    //Dictionary Constructor
    public Dictionary(){
        root = null;
        numItems = 0;
    }

    //Public Functions

    //True if dictionary is empty, false otherwise
    public boolean isEmpty(){
        return (numItems == 0);
    }

    //Returns number of items in dictionary
    public int size(){
        return (numItems);
    }

    //Checks if a key is in the dictionary are returns its corresponding value if it is there
    //Otherwise returns null
    public String lookup(String key){
        Node N = findKey(root, key);
        return ( N==null ? null : N.value );
    }

    //Inserts a new key, value pair into the tree
    public void insert(String key, String value) throws DuplicateKeyException{
        if(lookup(key)!=null){
            throw new DuplicateKeyException("Called insert on already existing string");
        }
        else{
            Node Z = new Node(key, value);
            Node N = root;
            Node M = null;
            while(N!=null){
                M = N;
                if(N.key.compareTo(key)>0){
                    N = N.left;
                }
                else{
                    N = N.right;
                }
            }
            if(M==null){
                root = Z;
            }
            else{
                if(M.key.compareTo(key)>0){
                    M.left = Z;
                }
                else{
                    M.right = Z;
                }
            }
            numItems++;
        }
    }

    //Removes the node with the given key from the tree
    //Throws KeyNotFoundException is key does not exist
    public void delete(String key) throws KeyNotFoundException{
        if(lookup(key)== null){
            throw new KeyNotFoundException("Called delete on nonexistant string");
        }
        else{
            Node N = findKey(root, key);
            //Case 1 - no children
            if(N.left == null && N.right == null){
                if(N == root){
                    root = null;
                }
                else{    
                    Node M = findParent(N, root);
                    if(M.left == N){
                        M.left = null;
                    }
                    else{
                        M.right = null;
                    }
                }
            }
            else{
                //Case 2 - one child
                if(N.left != null || N.right != null){
                    //Subcase - left child
                    if(N.left != null){
                        if(N == root){
                            root = N.left;
                        }
                        else{
                            Node P = findParent(N, root);
                            if(P.right == N){
                                P.right = N.left;
                            }
                            else{
                                P.left = N.left;
                            }
                        }
                    }
                    //Subcase - right child
                    else{
                        if(N == root){
                            root = N.right;
                        }
                        else{
                            Node P = findParent(N, root);
                            if(P.right == N){   
                                P.right = N.right;
                            }
                            else{
                                P.left = N.right;
                            }
                        }
                    }
                }
                else{
                    //Case 3 - two children
                    if(N.left != null && N.right != null){
                        Node S = findLeftmost(N.right);
                        N.key = S.key;
                        N.value = S.value;
                        Node P = findParent(S, N);
                        if(P.right == S){
                            P.right = S.right;
                        }
                        else{
                            P.left = S.right;
                        }
                    }
                }
            }
            numItems--;
        }
    }

    //Empties the given dictionary returning it to the intial state
    public void makeEmpty(){
        root = null;
        numItems = 0;
    }

    //Prints out the given dictionary
    public String toString(){
        Node N = root;
        return(writeOut(N));
    }

    //Private functions

    //Recursive function used by toString()
    private String writeOut(Node N){
        StringBuilder out = new StringBuilder();
        if(N!=null){
            out.append(writeOut(N.left));
            out.append(N.key).append(" ").append(N.value).append("\n");
            out.append(writeOut(N.right));     
        }
        return(new String(out));
    }

    //Finds the given key in the subtree rooted at N
    //Returns the node
    private Node findKey(Node N, String key){
        if(N==null || N.key.equals(key)){
            return N;
        }
        if(key.compareTo(N.key)<1){
            return findKey(N.left, key);
        }
        else{
            return findKey(N.right, key);
        }
    }

    //Finds parent of N in subtree R
    //Returns the parent Node
    private Node findParent(Node N, Node R){
        Node P = null;
        if(N!=R){
            P=R;
            while(P.left!=N && P.right!=N){
                if(N.key.compareTo(P.key)<0){
                    P = P.left;
                }
                else{
                    P = P.right;
                }
            }
        }
        return P;
    }

    //Finds the leftmost node in the subtree T
    //Returns the Node
    private Node findLeftmost(Node T){
        Node N = T;
        if(N!=null){
            for( ; N.left!=null; N=N.left);
        }
        return N;
    }
}