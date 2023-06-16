using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //iterative
        // ListNode* middle = head;
        // int mid_count =0;
        // while (head){
        //     head = head->next;
        //     mid_count++;
        // }
        // mid_count = mid_count/2 + 1;
        // while (mid_count>1){
        //     middle = middle->next;
        //     mid_count--;
        // }
        // return middle;

        //two pointers
        ListNode* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            head = head->next;
        }
        return head;
        
    }
};