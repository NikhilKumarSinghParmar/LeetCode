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
void insertAtHead(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    
    // Make the new node the new head
    newNode->next = head;
    head = newNode;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    deque<int> s1;
    deque<int> s2;
    std::stack<int> s3;
    int carry = 0;
    ListNode* head = nullptr;

    while (l1 != nullptr) {
        s1.push_back(l1->val);
        l1 = l1->next;
    }

    while (l2 != nullptr) {
        s2.push_back(l2->val);
        l2 = l2->next;
    }

    while (!s1.empty() || !s2.empty()) {
        int sum = carry;
        if (!s1.empty()) {
            sum += s1.front();
            s1.pop_front();
        }
        if (!s2.empty()) {
            sum += s2.front();
            s2.pop_front();
        }

        int curr = sum % 10;
        carry = sum / 10;
        s3.push(curr);
    }

    if (carry) {
        s3.push(carry);
    }

    while (!s3.empty()) {
        insertAtHead(head, s3.top());
        s3.pop();
    }

    return head;
}

};
