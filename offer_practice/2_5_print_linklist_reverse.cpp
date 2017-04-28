/**
 * struct ListNode{
 *      int val;
 *      struct ListNode* next;
 *      ListNode(int x):
 *          val(x), next(NULL){
 *          }
 * };
 */

class Solution{
    public:
        vector<int> printListFromTailToHead(ListNode* head){
            std::stack<ListNode*> nodes;
            vector<int> result;

            ListNode* pNode = head;
            while(pNode != NULL)
            {
                nodes.push(pNode);
                pNode = pNode->next;
            }
            while(!nodes.empty())
            {
                pNode = nodes.top();
                result.push_back(pNode->val);
                nodes.pop();
            }
            return result;
        }

}

class Solution{
    public:
        vector<int> printListFromTailToHead(ListNode* head){
            vector<int> result;

            return result;
        }
}
