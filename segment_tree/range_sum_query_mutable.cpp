class NumArray {
private:
    int n;
    class node{
        public:
        int data;

        node* left;
        node* right;

        node(int t){
            this -> data = t;
            this -> left = nullptr;
            this -> right = nullptr;
        }
    };

node* root = nullptr;


node* build_tree(vector<int>& nums,int l,int r){
    node* temp = new node(0);
    if(l==r){
        temp->data=nums[l];

        return temp;
    }

    int mid = (l+r)/2;

    temp->left = build_tree(nums,l,mid);
    temp->right = build_tree(nums,mid+1,r);

    temp->data=temp->left->data + temp->right->data;

    return temp;
}


void update_tree(int index,int val,int l,int r,node* root){
    int mid = (l+r)/2;

    if(l==r){
        cout << "updated on index    : " << l << endl;
        root->data=val;
        return;
    }

    if(index <= mid){
        update_tree(index,val,l,mid,root->left);
    }else{
        update_tree(index,val,mid+1,r,root->right);
    }

    root->data=root->left->data + root->right->data;
}



int find_sum(node* root,int l,int r,int tl,int tr){
    int mid=(l+r)/2;

    if(tl==l && tr==r){
        return root->data;
    }else if(tr <= mid) { // entire query is in the left child
    return find_sum(root->left, l, mid, tl, tr);
    } else if(tl > mid) { // entire query is in the right child
        return find_sum(root->right, mid+1, r, tl, tr);
    } else { // spans both
        return find_sum(root->left, l, mid, tl, mid) +
           find_sum(root->right, mid+1, r, mid+1, tr);
    }

}



public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        root = build_tree(nums,0,n-1);
    }
    
    void update(int index, int val) {
        update_tree(index,val,0,n-1,root);
    }
    
    int sumRange(int l, int r) {
        return find_sum(root,0,n-1,l,r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
