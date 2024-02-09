struct Node{
    Node *left;
    Node *right;
    int data;
    Node(){
        left = nullptr;
        right = nullptr;
        data = 0;
    }
    explicit Node(int data){
        this -> left = nullptr;
        this -> right = nullptr;
        this -> data = data;
    }
    bool isLeaf(){
        return this -> left == nullptr && this -> right == nullptr;
    }
};

class BS_Sagara {
private:
    Node *root = new Node();

    static Node *createNode(int data = 0){
        Node *newNode = new Node(data);
        return newNode;
    }

    Node *INSERT(Node *root , int el){
        if(!root)
            return createNode(el);
        if(el > root -> data)
            root -> right = INSERT(root->right, el);
        else
            root -> left = INSERT(root->left, el);
        return root;
    }
    int maxHieght(Node *rt){
        if(!rt){
            return 0;
        }
        int mx = 0;
        mx = max(mx, max(maxHieght(rt -> right) + 1, maxHieght(rt -> left) + 1));
        return mx;
    }

    void preOrderTraverse(Node *rt){
        if(!rt)
            return;
        cout << rt -> data << " ";
        preOrderTraverse(rt -> left);
        preOrderTraverse(rt -> right);
    }

    void inOrderTraverse(Node *rt){
        if(!rt)
            return;
        inOrderTraverse(rt -> left);
        cout << rt -> data << " ";
        inOrderTraverse(rt -> right);
    }

    void postOrderTraverse(Node *rt){
        if(!rt)
            return;
        postOrderTraverse(rt -> left);
        postOrderTraverse(rt -> right);
        cout << rt -> data << " ";
    }
public:
    BS_Sagara(){
        root = nullptr;
        Node();
    }
    void add(int val){
        INSERT(root, val);
    }
    bool isEmpty(){
        return root == nullptr;
    }
    int hieght(){
        return maxHieght(root);
    }

    // print the node you are in then
    // the left subtree
    // the right subtree
    void preOrderTraverse(){
        preOrderTraverse(root);
    }

    // print the left subtree then
    // the current node
    // the right subtree
    void inOrderTraverse(){
        inOrderTraverse(root);
    }

    // traverse the left subtree
    // traverse the right subtree
    // then print the nodes
    void postOrderTraverse(){
        postOrderTraverse(root);
    }
};
