#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // Dummy head for the result list
        ListNode* current = dummyHead; // Pointer to build the new list
        int carry = 0; // To store carry value

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with the carry

            if (l1 != nullptr) {
                sum += l1->val; // Add value from the first list
                l1 = l1->next; // Move to the next node
            }

            if (l2 != nullptr) {
                sum += l2->val; // Add value from the second list
                l2 = l2->next; // Move to the next node
            }

            carry = sum / 10; // Calculate new carry
            current->next = new ListNode(sum % 10); // Create a new node with the digit
            current = current->next; // Move to the next node in the result list
        }

        return dummyHead->next; // Return the next node of dummy head (the actual result)
    }
};

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val;
        if (node->next != nullptr) {
            cout << " -> ";
        }
        node = node->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Creating first linked list: 2 -> 4 -> 3 (represents the number 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Creating second linked list: 5 -> 6 -> 4 (represents the number 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result linked list
    printList(result); // Output should be: 7 -> 0 -> 8 (represents the number 807)

    // Clean up memory (not shown for brevity)
    return 0;
}