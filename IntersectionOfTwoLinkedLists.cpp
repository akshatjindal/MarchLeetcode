/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// https://leetcode.com/problems/intersection-of-two-linked-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //O(n) time, O(1) space

        //find length of first and second linked lists. 
        auto firstIter = headA; 
        int countA = 0; 
        while(firstIter != nullptr){
            ++countA; 
            firstIter = firstIter->next; 
        }

        auto secondIter = headB; 
        int countB = 0; 
        while(secondIter != nullptr){
            ++countB; 
            secondIter = secondIter->next; 
        }

        //line up the longer linked list with the shorter one 
        if(countA > countB){
            firstIter = headA; 
            int diff = countA - countB; 
            for(int i = 0; i < diff; ++i){
                firstIter = firstIter->next; 
            }
            secondIter = headB; 
        }else if(countB > countA){
            secondIter = headB;
            int diff = countB - countA; 
            for(int i = 0; i < diff; ++i){
                secondIter = secondIter->next; 
            }//loop

            firstIter = headA; 
        }else if(countA == countB){
            firstIter = headA; 
            secondIter = headB; 
        }

        //now they are lined up, keep moving ptrs one by one until u find the start of the tail. 
        ListNode * start_of_tail = nullptr; 

        while(firstIter != nullptr && secondIter != nullptr){
            if(firstIter == secondIter){
                start_of_tail = firstIter; 
                return start_of_tail; 
            }
            else{
                firstIter = firstIter->next; 
                secondIter = secondIter->next; 
            }
        }
        return start_of_tail; 
    }
};