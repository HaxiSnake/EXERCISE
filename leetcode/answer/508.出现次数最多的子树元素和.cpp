/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    map<int,int> treesum;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root==NULL) return {};
        _dfs(root);
        vector<pair<int,int>> sum_vec(treesum.begin(),treesum.end());
        sort(sum_vec.begin(),sum_vec.end(),_compare);
        int tmp=sum_vec[0].second;
        vector<int> result;
        for(int i=0;i<sum_vec.size();i++){
            if(tmp<=sum_vec[i].second){
                tmp=sum_vec[i].second;
                result.push_back(sum_vec[i].first);
            }else{
                break;
            }
        }
        return result;
        
    }
    private:
    static bool _compare(const pair<int,int>&p1,const pair<int,int>&p2){
        return p1.second > p2.second;
    }
    int _dfs(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            if(treesum.find(root->val)==treesum.end()){
                treesum[root->val]=1;
            }else{
                treesum[root->val]+=1;
            }
            return root->val;
        }
        int leftsum=_dfs(root->left);
        int rightsum=_dfs(root->right);
        int sum=leftsum+rightsum+root->val;
        if(treesum.find(sum)==treesum.end()){
            treesum[sum]=1;
        }else{
            treesum[sum]+=1;
        }
        return sum;
    }
};