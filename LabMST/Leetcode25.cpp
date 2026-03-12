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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;
        ListNode* curr = head;
        while (curr != nullptr) {
            v.push_back(curr->val);
            curr = curr->next;
        }
        for (int i = 0; i + k <= v.size(); i += k) {
            int left = i, right = i + k - 1;
            while (left < right) {
                int temp = v[left];
                v[left] = v[right];
                v[right] = temp;
                left++;
                right--;
            }
        }
        ListNode* temp = new ListNode(0);
        curr = temp;
        for (int val : v) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        return temp->next;
    }
};