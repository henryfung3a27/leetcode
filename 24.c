// Swap Nodes in Pairs
// Given  1->2->3->4
// Return 2->1->4->3

/*    My solution (0 ms!?)    */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head) return NULL;             // 0 node
    if (!(head->next)) return head;     // 1 node
    
    int flag = 0;
    struct ListNode* dummy_head = malloc(sizeof(struct ListNode));
    struct ListNode* pfirst;    // pointer of the first node of swap
    struct ListNode* pnext;     // pointer of the third node
    struct ListNode* current;
    
    dummy_head->next = head;
    current = dummy_head;
    
    while (current->next) {
        if (flag) { // current = second node of swap
            flag = 0;
            pnext = current->next;
            current->next = pnext->next;
            pfirst->next = pnext;
            pnext->next = current;
        }
        else {      // current = first node of swap
            flag = 1;
            pfirst = current;
            current = current->next;
        }
    }
	
    return dummy_head->next;
}

/* ====A c++ solution from jexxllz==== */
/* Brilliant recursive solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* left=head;
        ListNode* right=head->next;
        left->next=swapPairs(right->next);
        right->next=left;
        return right;
    }
};


