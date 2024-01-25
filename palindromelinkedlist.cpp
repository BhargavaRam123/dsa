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

int getlength(ListNode* head) {
    ListNode* temp = head;
    int a = 0;
    while (temp != NULL) {
        temp = temp->next;
        a++;
    }
    return a;
}

ListNode* solve1(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL) {
        fast = fast->next;
        if (fast == NULL) {
            break;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

void solve2(ListNode*& head, ListNode* prev, ListNode* curr) {
    if (curr == NULL) {
        head = prev;
        return;
    }
    ListNode* next = curr->next;
    curr->next = prev;
    solve2(head, curr, next);
}
bool solvemain(ListNode* &head) {
    int l = getlength(head);
    ListNode* middle = solve1(head);
    ListNode* t1 = middle;
    solve2(t1, NULL, t1);
    if (l % 2 == 0) {
        ListNode* temp = head;
        while (middle != NULL) {
            if (temp->val != middle->val) {
                return false;
            }
            temp = temp->next;
            middle = middle->next;
        }
        return true;
    } else {
        ListNode* temp = head;
        cout<<middle->val<<endl;
        middle = middle->next;
        while (middle != NULL) {
            cout<<temp->val<<" "<< middle->val<<endl;
            if (temp->val != middle->val) {
                return false;
            }
            temp = temp->next;
            middle = middle->next;
        }
        return true;
    }
}
    bool isPalindrome(ListNode* head) {
        return solvemain(head);
    }
};