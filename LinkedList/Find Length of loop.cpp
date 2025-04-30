class Solution {
  public:
    // Helper function to find the length of the loop in the linked list.
    int findlength(Node* slow , Node* fast) {
        int cnt = 1;
        fast = fast->next; // Move fast one step ahead to start counting
        
        // Traverse the loop until fast meets slow again
        while(slow != fast) {
            cnt++;               // Increment the count
            fast = fast->next;   // Move fast one step
        }
        return cnt; // Return the total count of nodes in the loop
    }
    
    // Function to detect and count the number of nodes in a loop
    int countNodesinLoop(Node *head) {
        Node* fast = head; // Fast pointer (moves two steps at a time)
        Node* slow = head; // Slow pointer (moves one step at a time)
        
        // Traverse the linked list
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;         // Move slow by 1 step
            fast = fast->next->next;   // Move fast by 2 steps
            
            // If both pointers meet, a loop is detected
            if(slow == fast) {
                // Call helper function to count loop length
                return findlength(slow, fast);
            }
        }
        
        // If no loop is found, return 0
        return 0;
    }
};
