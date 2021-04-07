// AnkiMarch29.cpp
//https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 */

#include <cmath>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto A_ptr = headA; 
        int lenOfA = 0; 
        int lenOfB = 0; 
        auto B_ptr = headB; 

        while(A_ptr != nullptr){
            ++lenOfA; 
            A_ptr = A_ptr->next; 
        }

        while(B_ptr != nullptr){
            ++lenOfB; 
            B_ptr = B_ptr->next; 
        }

        int diff = std::abs(lenOfB-lenOfA); 
        if(diff > 0){
            if(lenOfA > lenOfB){
                A_ptr = headA; 
                for(int i = 0; i < diff; ++i){
                    A_ptr = A_ptr->next; 
                }
                B_ptr = headB; 
            }//if lenA > lenB

            else if(lenOfB > lenOfA){
                B_ptr = headB; 
                for(int i = 0; i < diff; ++i){
                    B_ptr = B_ptr->next; 
                }
                A_ptr = headA; 
            }
        }//if there is a difference in lengths
        else if(diff == 0){
            A_ptr = headA; 
            B_ptr = headB; 
        }//else if there is no difference in lengths

        ListNode * startOfCommonTail = nullptr; 
        while(A_ptr && B_ptr){
            if(A_ptr == B_ptr){
                startOfCommonTail = A_ptr; 
                break; 
            }
            else{
                A_ptr = A_ptr->next; 
                B_ptr = B_ptr->next; 
            }
        }
        
        return startOfCommonTail; 
    }
};
