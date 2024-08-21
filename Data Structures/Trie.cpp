struct Node {
    Node*ch[26];
    int prefix;
    int end;
    Node(){
        clr(ch, 0);
        prefix = 0;
        end = 0;
    }
};

struct Trie{
    Node *root;
    Trie(){
        root = new Node();
    }
    void insert(const string&s){
        Node*cur = root;
        for(auto&it : s){
            int index = it - 'a';
            if(cur -> ch[index] == 0){
               cur -> ch[index] = new Node();
            }
            cur = cur -> ch[index];
            cur -> prefix += 1;
        }
        cur -> end += 1;
    }

    int count_apperance(const string &s){
        Node*cur = root;
        bool found = true;
        for(auto&it:s){
            int index = it - 'a';
            if(cur -> ch[index] == 0)
            { found = false;
                break;
            }
            cur =  cur -> ch[index];
        }
        return found ? cur -> end : 0;
    }

    int count_prefix(const string&s){
        Node *cur = root;
        bool found = true;
        for(auto&it:s){
            int index = it - 'a';
            if(cur -> ch[index] == 0)
            { found = false;
                break;
            }
            cur =  cur -> ch[index];
        }
        return found ? cur -> prefix : 0;
    }
};
