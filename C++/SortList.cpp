#include "LeetCode.h"

using namespace std;
using namespace LeetCode;

int Solution148::Partition(ListNode* head, int leftIndex, int rightIndex)
{
    ListNode *endNode = head;
    ListNode *beginNode = head;
    for(int i = 0; i < rightIndex; i++)
    {
        if(i == leftIndex-1)
            beginNode = endNode;

        endNode = endNode->next;
    }

    int pivot = endNode->val;
    ListNode *current = beginNode->next;
    int middleIndex = leftIndex - 1;
    for(int i = leftIndex; i < rightIndex; i++)
    {
        if(current->val <= pivot)
        {
            beginNode = beginNode->next;
            middleIndex++;
            swap(beginNode->val, current->val);
        }
        current = current->next;
    }

    beginNode = beginNode->next;
    middleIndex++;
    swap(beginNode->val, endNode->val);
    return middleIndex;
}

void Solution148::QuickSort(ListNode* head, int leftIndex, int rightIndex)
{
    if(leftIndex < rightIndex)
    {
        int middleIndex = Partition(head, leftIndex, rightIndex);

        QuickSort(head, leftIndex, middleIndex-1);
        QuickSort(head, middleIndex+1, rightIndex);

    }
}

ListNode* Solution148::sortList(ListNode* head) {
    ListNode* current = head;
    int length = 0;

    while(current)
    {
        current = current->next;
        length++;
    }

    QuickSort(head, 0, length-1);
    return head;
}