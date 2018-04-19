/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// beat 33.70%
ListNode* rotateRight_1(ListNode* head, int k) {
    if (head == NULL) return head;

    ListNode *prev = head;
    ListNode *cut = head;   // previous position of the new head
    ListNode *end = head;   // position of the last element
    int ori = k;

    while (prev != NULL) {
        end = prev;
        prev = prev->next;
        if (k-- < 0) cut = cut->next;
    }
    
    if (k > 0) {        // k is longer than the list
        k = ori - k;
        k = ori % k;
        return rotateRight(head, k);
    } else if (k < 0) { // k is shorter than the list
        end->next = head;
        head = cut->next;
        cut->next = NULL;
    }

    return head;
}