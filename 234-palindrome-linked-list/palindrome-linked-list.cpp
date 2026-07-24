class Solution {
public:
  ListNode * findMid(ListNode* head)
  {
     ListNode* slow= head;
     ListNode* fast= head;
    while(fast->next&&fast->next->next
    ){
       slow=slow->next;
       fast= fast->next->next;   
  }  
  return slow;

  }
       ListNode* reverse(ListNode* head)
       {
        ListNode *prev=NULL;
        ListNode *curr=head;
        while(curr)
        {
         ListNode* next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;
        }
        return prev;
       }

    bool isPalindrome(ListNode* head) {
        ListNode *mid= findMid(head);
        ListNode * second=reverse(mid->next);
        ListNode* first=head;
     
     while(second!=NULL)
     {
        if(first->val !=second->val)
        {
            return false;
        }
        first= first->next;
        second= second->next;
     }
     return true;

    }
};