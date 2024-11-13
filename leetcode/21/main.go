package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

/*
Node* mergeLists(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    // Head and Tail of the merged list
    Node* head = NULL;
    Node* tail = NULL;

    // Initialize the head and tail pointers
    if (a->data <= b->data) {
        head = tail = a;
        a = a->next;
    } else {
        head = tail = b;
        b = b->next;
    }

    // Merge the remaining nodes
    while (a && b) {
        if (a->data <= b->data) {
            tail->next = a;
            tail = a;
            a = a->next;
        } else {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }

    // Attach the remaining part of
    // the list that is not yet exhausted
    tail->next = (a) ? a : b;

    return head;
}
*/

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil && list2 == nil {
		return nil
	} else if list1 == nil {
		return list2
	} else if list2 == nil {
		return list1
	}

	head := &ListNode{0, nil}
	curr := head

	for {
		if list1 == nil || list2 == nil {
			break
		}

		if list1.Val < list2.Val {
			curr.Next = list1
			list1 = list1.Next
		} else {
			curr.Next = list2
			list2 = list2.Next
		}

		curr = curr.Next
	}

	if list1 != nil {
		curr.Next = list1
	} else {
		curr.Next = list2
	}

	return head.Next
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	var list1, list2 = new(ListNode), new(ListNode)

	list1_c, list2_c := list1, list2

	for i := range n {
		var a int
		fmt.Scan(&a)

		if i == 0 {
			list1_c.Val = a
			continue
		}

		list1_c.Next = new(ListNode)
		list1_c = list1_c.Next

		list1_c.Val = a
		list1_c.Next = nil
	}

	for i := range m {
		var a int
		fmt.Scan(&a)

		if i == 0 {
			list2_c.Val = a
			continue
		}

		list2_c.Next = new(ListNode)
		list2_c = list2_c.Next

		list2_c.Val = a
		list2_c.Next = nil
	}

	result := mergeTwoLists(list1, list2)
	for result.Next != nil {
		fmt.Println(result.Val)
		result = result.Next
	}

	// NO WORKY INPUT
}
