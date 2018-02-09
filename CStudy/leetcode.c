#include "leetcode.h"

/*
NO 1. Accepted Runtime: 93 ms
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/**
* Note: The returned array must be malloced, assume caller calls free().
  返回的数组必须被分配，假设调用者负责释放

  调用示例:
  int nums[] = {2,7,11,15};
  int *p  = twoSum(nums, 4, 9);
  free(p);
*/

int * twoSum(int * nums, int numsSize, int target)
{
	int i, j;
	int* arr = (int*)malloc(2 * sizeof(int));;
	int index1, index2;
	int flag = 0;
	for (i = 0; i < numsSize; i++)
	{
		for (j = i+1; j < numsSize; j++)
		{
			//if (nums[i] != 0 && nums[j] != 0)
			//{
				if (nums[i] + nums[j] == target)
				{
					arr[0] = i;
					arr[1] = j;
					return arr;								
				}
			//}
		}

	}	
	return NULL;
}

/*
NO 2.  Runtime:  ms
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

}