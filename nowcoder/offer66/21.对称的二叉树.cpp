
/*˼·�����ȸ��ڵ��Լ���������������������������������������������ͬ
* ��������������������������������ͬ���ɣ����õݹ�
* �ǵݹ�Ҳ�ɣ�����ջ����д�ȡ�����������ڵ�
*/
public class Solution {
    boolean isSymmetrical(TreeNode pRoot)
    {
        if(pRoot == null){
            return true;
        }
        return comRoot(pRoot.left, pRoot.right);
    }
    private boolean comRoot(TreeNode left, TreeNode right) {
        // TODO Auto-generated method stub
        if(left == null) return right==null;
        if(right == null) return false;
        if(left.val != right.val) return false;
        return comRoot(left.right, right.left) && comRoot(left.left, right.right);
    }
}
