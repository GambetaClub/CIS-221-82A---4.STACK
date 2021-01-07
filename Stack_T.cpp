// File: Stack_T.template
//
// Author: Mariano Augusto Jalif
// Course: CIS-211-82A
// Assignment: Stack
//
// I haven't neither shown nor copied code from/to anybody.
// I also state that I typed everything in this code on my own.
// I haven't watched anyone's code.
//
// Purpose: Implementation file for templatized stack class.
// This class is being constructed to provide more flexibility
// (over an array) in the data structures we want.
// This file includes method implementations for a Stack and Link_Node.

#ifndef STACK_T_TEMPLATE
#define STACK_T_TEMPLATE

#include "Stack_T.h"

/*****************************************************************************
 * Link_Node Method Implementations
 *****************************************************************************/
template < class T >
  Link_Node < T > ::Link_Node(const T & item, Link_Node < T > * next): item_(item), next_(next) {
    if (next_ == NULL) {
      next_ = this;
    }
  }

template < class T >
  Link_Node < T > ::Link_Node(void): next_(this) {}

/*****************************************************************************
 * Stack Method Implementations
 *****************************************************************************/
// Constructor.
// Postcondition: The stack has been initialized as an empty stack.
template < class T >
  Stack < T > ::Stack(): tail_(new Link_Node < T >()), count_(0) {}

// Copy constructor.
// Postcondition: The stack has been initialized with the stack argument
//  passed in (i.e., same values, order, and number of elements).
template < class T >
  Stack < T > ::Stack(const Stack < T > & rhs):
  count_(rhs.count_) {
    if (!rhs.is_empty()) {
      this -> copy_list(tail_, rhs);
    }
  }

// Destructor
// Postcondition: Any allocated memory has been reclaimed/freed.
template < class T >
  Stack < T > ::~Stack(void) {
    delete_list(tail_);
    count_ = 0;
  }

// Postcondition: The start_node will contain a copy of the linked list in
//  the rhs argument. This can throw a std::bad_alloc exception.
template < class T >
  void
Stack < T > ::copy_list(Link_Node < T > * & start_node,
  const Stack < T > & rhs) {
  start_node = new Link_Node < T > (rhs.tail_ -> item_);
  Link_Node < T > * temp = rhs.tail_ -> next_;
  Link_Node < T > * save = start_node;
  size_t iterator = rhs.count_;
  while(iterator > 0){
    Link_Node < T > * new_node = new  Link_Node < T > (temp -> item_);
    save -> next_ = new_node;
    save = new_node;
    temp = temp -> next_;
    --iterator;
  }
}

// Postcondition: The memory from the linked list pointed to be start_node is
//  reclaimed/freed.
template < class T >
  void
Stack < T > ::delete_list(Link_Node < T > * start_node) {
  while (count_+1 != 0) {
    Link_Node < T > * pointer = start_node;
    start_node = pointer -> next_;
    delete pointer;
    count_--;
  }
}

// Assignment operator.
// Postcondition: The stack has been assigned the stack argument
//  passed in (i.e., same values, order, and number of elements).
template < class T >
  Stack < T > &
  Stack < T > ::operator = (const Stack < T > & rhs) {
    if (tail_ == rhs.tail_) {
      return *this;
    } else {
      Link_Node < T > * num = rhs.tail_;
      T save[rhs.count_ + 1];
      for (size_t i = 0; i < rhs.count_; i++) {
        save[i] = num -> item_;
        num = num -> next_;
      }
      for (int x = rhs.count_; x >= 0; x--) {
        this -> push(save[x]);
      }
      count_ = rhs.count_;
      return *this;
    }
  }

// Postcondition: Returns the current number of elements in the stack.
template < class T >
  size_t
Stack < T > ::size(void) const {
  return count_;
}

// Postcondition: Returns true if the
//   size()'s of the two stacks are equal and all the elements from 0
//   .. size()-1 are equal, else false.
template < class T >
  bool
Stack < T > ::operator == (const Stack < T > & rhs) const {
  if (count_ == rhs.count_) {
    Link_Node < T > * pointer = tail_;
    Link_Node < T > * num = rhs.tail_;
    for (size_t i = 0; i < this -> size(); i++) {
      if (pointer -> item_ != num -> item_) {
        return false;
      }
      pointer = pointer -> next_;
      num = num -> next_;
    }
    return true;
  } else {
    return false;
  }
}

// Postcondition: Returns false if the
//   size()'s of the two stacks are equal and all the elements from 0
//   .. size()-1 are equal, else true.
template < class T >
  bool
Stack < T > ::operator != (const Stack < T > & rhs) const {
  return (!( * this == rhs));
}

// Postcondition: A new copy of <new_item> is at the top of the stack.
template < class T >
  void
Stack < T > ::push(const T & new_item) {
  Link_Node < T > * save = new Link_Node < T > (new_item, tail_);
  tail_ = save;
  count_++;
}

// Precondition: size() > 0.
// Postcondition: The top item on the stack has been removed.  
//   Throws the <Underflow> exception if the stack is empty. 
template < class T >
  void
Stack < T > ::pop(void) {
  if (!is_empty()) {
    Link_Node < T > * save = tail_;
    tail_ = tail_ -> next_;
    delete save;
    count_--;
  } else {
    throw Underflow();
  }
}

// Precondition: size() > 0.
// Postcondition: Returns the top stack item.
//   Throws the <Underflow> exception if the stack is empty. 
template < class T >
  T
Stack < T > ::top(void) const {
  if (!is_empty()) {
    return tail_ -> item_;
  } else {
    throw Underflow();
  }
}

// Postcondition: Returns true if the stack is empty, false otherwise. 
template < class T >
  bool
Stack < T > ::is_empty(void) const {
  return (!(count_ > 0));
}

#endif /* STACK_T_TEMPLATE */