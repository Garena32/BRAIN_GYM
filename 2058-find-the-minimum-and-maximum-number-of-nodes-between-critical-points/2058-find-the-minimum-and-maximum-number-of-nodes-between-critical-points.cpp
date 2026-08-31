/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if(head->next->next == nullptr) return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* front = curr->next;

        int num = 1;

        vector<int> t, res;

        while(front != nullptr){
            // local _ min check
            if(prev->val<curr->val && curr->val>front->val){
                t.push_back(num);
            } 
            /// local max check
            else if(prev->val>curr->val && curr->val<front->val){
                t.push_back(num);
            }
            num++;
            prev = curr;
            curr = front;
            front=front->next;
        }
        if(t.size()<2) return {-1, -1};
        // sort(t.begin(), t.end());
        int a = INT_MAX;
        for(int i=1; i<t.size(); i++){
            a = min(a, t[i]-t[i-1]);
        }
        int b = t.back()-t[0];

        res.push_back(a);
        res.push_back(b);

        return res;
    }
};