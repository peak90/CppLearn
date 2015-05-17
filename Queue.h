#pragma once
#define NULL 0
template <typename Item> class Queue {
private:
  class Node {
  public:
    Item item_;
    Node *next;
    Node(const Item &item) {
      item_ = item;
      next = NULL;
    }
  };

public:
  Queue() {
    head = NULL;
    tail = NULL;
  }

  ~Queue() {
    while (head != NULL) {
      Node *next = head->next;
      delete head;
      head = next;
    }
  }

  void enqueue(const Item &item) {
    Node *newNode = new Node(item);
    if (NULL == head) {
      head = newNode;
      tail = head;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  Item dequeue() {
    if (NULL == head) {
      return NULL;
    } else {
      Item item = head->item_;
      Node *next = head->next;
      delete head;
      head = next;
      return item;
    }
  }

  bool isEmpty() { return head == NULL; }

private:
  Node *head;
  Node *tail;
};
