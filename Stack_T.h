// File: Stack_T.h
//
// Author: 
// Course:
// Assignment: 
//
// Purpose: Header file for templatized stack class.
// This class is being constructed to provide more flexibility
// (over an array) in the data structures we want.
// This file includes definitions for a Stack and Link_Node.
//
// Value Semantics: Assignment and copy constructor may be used with Stack.

#ifndef STACK_T_H
#define STACK_T_H

// This header defines "size_t"
#include <stdlib.h>

#include <stdexcept>

// Solve circular include problem via forward decls.
template <typename T>
class Link_Node;

/*****************************************************************************
 * class: Stack
 * desc: Defines a generic "last-in/first-out" (LIFO) Abstract Data Type (ADT)
 *        using a "circular list" with a dummy node.
 *****************************************************************************/
template <class T> 
class Stack
{
public:
  // Define a "trait"
  typedef T element_type;

  // = Exceptions thrown by methods in this class.
  class Underflow {};

  // = Initialization, assignment, and termination methods.
  // Constructor.
  // Postcondition: The stack has been initialized as an empty stack.
  Stack (void);

  // Copy constructor.
  // Postcondition: The stack has been initialized with the stack argument
  //  passed in (i.e., same values, order, and number of elements).
  Stack (const Stack<T> &rhs);

  // Assignment operator.
  // Postcondition: The stack has been assigned the stack argument
  //  passed in (i.e., same values, order, and number of elements).
  Stack<T> &operator = (const Stack<T> &rhs);

  // Perform actions needed when stack goes out of scope.
  // Postcondition: Any allocated memory has been reclaimed/freed.
  ~Stack (void);

  // = Classic Stack operations.
  // Postcondition: A new copy of <new_item> is at the top of the stack.
  void push (const T &new_item);

  // Precondition: size() > 0.
  // Postcondition: The top item on the stack has been removed.  
  //   Throws the <Underflow> exception if the stack is empty. 
  void pop (void);

  // Precondition: size() > 0.
  // Postcondition: Returns the top stack item.
  //   Throws the <Underflow> exception if the stack is empty. 
  T top (void) const;

  // = Check boundary conditions for Stack operations. 
  // Postcondition: Returns true if the stack is empty, false otherwise. 
  bool is_empty (void) const;

  // Postcondition: Returns the current number of elements in the stack.
  size_t size (void) const;

  // Postcondition: Returns true if the
  //   size()'s of the two stacks are equal and all the elements from 0
  //   .. size()-1 are equal, else false.
  bool operator== (const Stack<T> &rhs) const;

  // Postcondition: Returns false if the
  //   size()'s of the two stacks are equal and all the elements from 0
  //   .. size()-1 are equal, else true.
  bool operator!= (const Stack<T> &rhs) const;

protected:
  // Postcondition: The start_node will contain a copy of the linked list in
  //  the rhs argument.
  //  This can throw a std::bad_alloc exception.
  void copy_list (Link_Node<T> *&start_node,
                  const Stack<T> &rhs);

  // Postcondition: The memory from the linked list pointed to by start_node is
  //  reclaimed/freed.
  void delete_list (Link_Node<T> *start_node);

private:
  // We only need to keep a single pointer for the circular linked
  // list.  This points to the tail of the stack.  Since the list is
  // circular, the head of the stack is always this->tail_->next_;
  // HINT: Use a dummy node to make keeping track of whether or not
  // the linked list is empty easier.
  Link_Node<T> *tail_;

  // Number of items that are currently in the stack (for performance).
  size_t count_;
};


/*****************************************************************************
 * class: Link_Node
 * desc: Defines an element of the <Stack>
 *****************************************************************************/
template <class T>
class Link_Node
{
  friend class Stack<T>;
public:
  // = Initialization methods
  Link_Node (const T &item,
             Link_Node<T> *next = 0);

  // Default constructor that doesn't initialize <item_>.
  Link_Node (void);

private:
  // Item in this node.
  T item_;

  // Pointer to the next node.
  Link_Node<T> *next_;
};

#include "Stack_T.cpp"

#endif /* STACK_T_H */