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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * first; 
        if(l1 && l2){
            if(l1->val < l2->val){
                first = l1; 
                l1 = l1->next; 
            }else{
                first = l2; 
                l2 = l2->next; 
            }
        }
        else if(l1 == nullptr && l2 != nullptr){
            first = l2; 
        }
        else if(l2 == nullptr && l1 != nullptr){
            first = l1; 
        }else{
            return first; 
        }

        ListNode * current = first; //initially current will be first. 
        
        while(l1 != nullptr || l2 != nullptr){
            ListNode * temp = nullptr; 
            if(l1 && l2 == nullptr){
                temp = l1;
                l1 = l1->next; 
                current->next = temp; 
                current = temp; //move current forward by one. 
            }//if l2 is nullptr
            else if(l2 && l1 == nullptr){
                temp = l2; 
                l2 = l2->next; 
                current->next = temp; 
                current = temp; 
            }//if l1 is nullptr
            else{
                if(l2->val < l1->val){
                    temp = l2; 
                    l2 = l2->next; 
                    current->next = temp; 
                    current = temp; 
                }
                else{
                    temp = l1; 
                    l1 = l1->next;
                    current->next = temp; 
                    current = temp; 
                }//if they are the same or if l1->val < l2->val
            }//when both are not null
        }//while atleast one of them is not null

        return first; 
    }
};
