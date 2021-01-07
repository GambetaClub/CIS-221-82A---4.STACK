// File: Stack_T-Test.cpp
//
// Author: 
// Course: 
// Assignment: 
//
// Purpose: Testing file for templatized stack class.

// Standard headers
#include <iostream>

#include <assert.h>

#include "Stack_T.h"

typedef Stack < int > STACK;
const size_t items_size = 10;
const size_t half_size = items_size / 2;
int items[items_size] = {
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10
};

const size_t MANY_TESTS = 15;
const int POINTS[MANY_TESTS + 1] = {
  150, // Total points for all tests.
  10, // Test 1 points
  10, // Test 2 points
  10, // Test 3 points
  10, // Test 4 points
  10, // Test 5 points
  10, // Test 6 points
  10, // Test 7 points
  10, // Test 8 points
  10, // Test 9 points
  10, // Test 10 points
  10, // Test 11 points
  10, // Test 12 points
  10, // Test 13 points
  10, // Test 14 points
  10 // Test 14 points
};

const char DESCRIPTION[MANY_TESTS + 1][256] = {
  "test for stack implementation with a linked list.",
  "Test pushing and popping 5 elements.",
  "Test calling top with an empty stack.",
  "Test stacks with a different number of elements aren't equal.",
  "Test two stacks with different values but same count aren't equal.",
  "Test two stacks with the same elements are equal.",
  "Test the copy constructor with a stack of at least 3 elements",
  "Testing the assignment operator and comparing both stacks elements.",
  "Test popping all elements off a stack until an Underflow exception is thrown.",
  "Testing empty function.",
  "Test inequality operator.",
  "Testing stack functions for other value type.",
  "Testing size funciton.",
  "Testing top function.",
  "Testing constructor function and the size of it data member.",
  "Testing copy constructor with no elements."
};

int run_a_test(int number,
  const char message[], int test_function(), int max) {
  int result;

  std::cout << std::endl << "---------------~  " << number;
  std::cout << "  ~---------------" << std::endl << std::endl;
  std::cout << message << " (" << max << " percent)." << std::endl;
  result = test_function();
  if (result > 0) {
    std::cout << "Test " << number << " got " << result << " percent";
    std::cout << " out of a possible " << max << "." << std::endl;
  } else {
    std::cout << "Test " << number << " failed." << std::endl;
    std::cout << "END OF TEST " << number << "." << std::endl << std::endl;
  }
  std::cout << "Total Points: ";
  return result;
}

int test1() {

  // Test pushing and popping of at least 5 elements to make sure the
  // elements are the right values in the right order.

  STACK stack_1;

  stack_1.push(items[0]);
  stack_1.push(items[1]);
  stack_1.push(items[2]);
  stack_1.push(items[3]);
  stack_1.push(items[4]);
  if (stack_1.top() != items[4]) {
    std::cout << "There was an error with the order of the elements." << std::endl << std::endl;
    return 0;
  }
  stack_1.pop();
  if (stack_1.top() != items[3]) {
    std::cout << "There was an error with the order of the elements." << std::endl << std::endl;
    return 0;
  }
  stack_1.pop();
  if (stack_1.top() != items[2]) {
    std::cout << "There was an error with the order of the elements." << std::endl << std::endl;
    return 0;
  }
  stack_1.pop();
  if (stack_1.top() != items[1]) {
    std::cout << "There was an error with the order of the elements." << std::endl << std::endl;
    return 0;
  }
  stack_1.pop();
  if (stack_1.top() != items[0]) {
    std::cout << "There was an error with the order of the elements." << std::endl << std::endl;
    return 0;
  }
  stack_1.pop();
  std::cout << "The first test passed succesfully." << std::endl << std::endl;
  return POINTS[1];
}

int test2() {

  // Test calling top with an empty stack.

  STACK stack_2;

  try {
    stack_2.top();
    std::cout << "The program didn't detect an Underflow error, which it was expected." << std::endl;
    std::cout << "Test failed" << std::endl << std::endl;
    return 0;
  } catch (STACK::Underflow) {
    std::cout << "The program detected an Underflow error, which it was expected." << std::endl;
    std::cout << "Test passed succesfully." << std::endl << std::endl;
    return POINTS[2];
  }
}

int test3() {

  // Test calling the == operator with stacks that have at least 5 elements
  // testing that:

  STACK stack_2;
  STACK stack_3;

  for (size_t i = 0; i < 5; i++) {
    stack_2.push(items[i]);
    stack_3.push(items[i]);
  }

  stack_2.push(6);

  // Two stacks with a different number of elements aren't equal.
  std::cout << "Testing the equal operator with two stacks of different size" << std::endl;
  if (!(stack_2 == stack_3)) {
    std::cout << "Third test passed succesfully." << std::endl << std::endl;
    return POINTS[3];
  } else {
    std::cout << "The program detected an error with the equal operator." << std::endl;
    std::cout << "Third test failed." << std::endl << std::endl;
    return 0;
  }
}

int test4() {

  // Two stacks with different values but same count aren't equal.

  STACK stack_2;
  STACK stack_3;

  for (size_t i = 0; i < half_size; i++) {
    stack_2.push(items[i]);
    stack_3.push(items[i]);
  }

  stack_2.push(6);
  stack_3.push(1);

  std::cout << "Testing two stacks with same size but different values." << std::endl;
  if (!(stack_2 == stack_3)) {
    std::cout << "Fourth test passed succesfully." << std::endl << std::endl;
    return POINTS[4];
  } else {
    std::cout << "The program detected an error with the equal operator." << std::endl;
    std::cout << "Fourth test failed comparing two stacks with same size but with different values." << std::endl;
    return 0;
  }
}

int test5() {

  // Test calling the == operator with stacks that have at least 5 elements

  STACK stack_2;
  STACK stack_3;

  for (size_t i = 0; i < half_size; i++) {
    stack_2.push(items[i]);
    stack_3.push(items[i]);
  }

  if (stack_2 == stack_3) {
    std::cout << "Fifth test passed succesfully." << std::endl << std::endl;
    return POINTS[5];
  } else {
    std::cout << "The program detected a error with the equal operator." << std::endl;
    std::cout << "Fifth test failed." << std::endl << std::endl;
    return 0;
  }
}

int test6() {

  // Test the copy constructor with a stack of at least 3 elements
  // (comparing the elements popped off to make sure they are the same).

  STACK stack_1;

  for (size_t i = 0; i < half_size; i++) {
    stack_1.push(items[i]);
  }

  STACK stack_4(stack_1);

  if (stack_4.top() != stack_1.top()) {
    std::cout << "The program detected an error with the copy constructor." << std::endl;
    return 0;
  }
  stack_4.pop();
  stack_1.pop();
  if (stack_4.top() != stack_1.top()) {
    std::cout << "The program detected an error with the copy constructor." << std::endl;
    return 0;
  }
  stack_4.pop();
  stack_1.pop();
  if (stack_4.top() != stack_1.top()) {
    std::cout << "The program detected an error with the copy constructor." << std::endl;
    return 0;
  }
  stack_4.pop();
  stack_1.pop();
  if (stack_4.top() != stack_1.top()) {
    std::cout << "The program detected an error with the copy constructor." << std::endl;
    return 0;
  }
  stack_4.pop();
  stack_1.pop();
  if (stack_4.top() != stack_1.top()) {
    std::cout << "The program detected an error with the copy constructor." << std::endl;
    return 0;
  }
  if (stack_4.top() != stack_1.top()) {
    std::cout << "The program detected an error with the copy constructor." << std::endl;
    return 0;
  }
  std::cout << "Seventh test passed succesfully." << std::endl;
  return POINTS[6];

}

int test7() {

  // Test the assignment operator with a stack of at least 4 elements
  // (comparing the elements popped off to make sure they are the same).

  STACK stack_1;
  STACK stack_2;

  for (size_t i = 0; i < half_size; i++) {
    stack_1.push(items[i]);
  }

  stack_2 = stack_1;
  if (stack_2.top() == stack_1.top()) {
    stack_2.pop();
    stack_1.pop();
    if (stack_2.top() == stack_1.top()) {
      stack_2.pop();
      stack_1.pop();
      if (stack_2.top() == stack_1.top()) {
        std::cout << "Seventh test passed succesfully." << std::endl << std::endl;
        return POINTS[8];
      } else {
        std::cout << "The program detected an error with the copy constructor." << std::endl;
        std::cout << "Seventh test failed." << std::endl << std::endl;
        return 0;
      }
    } else {
      std::cout << "The program detected an error with the copy constructor." << std::endl;
      std::cout << "Seventh test failed." << std::endl << std::endl;
      return 0;
    }
  } else {
    std::cout << "The program detected an error with the copy constructor." << std::endl;
    std::cout << "Seventh test failed." << std::endl << std::endl;
    return 0;
  }
}

int test8() {

  // Test popping all elements off a stack (with at least 4 elements)
  // until an Underflow exception is thrown.

  STACK stack_3;

  for (size_t i = 0; i < half_size; i++) {
    stack_3.push(items[i]);
  }

  std::cout << "Now the program will pop elements from an stack until it throws an exception." << std::endl;
  size_t size = stack_3.size();
  for (size_t i = 0; i < size; i++) {
    std::cout << "Elements in the stack: " << stack_3.size() << std::endl;
    stack_3.pop();
  }

  try {
    stack_3.pop();
    std::cout << "The program didn't detect an Underflow error, which it was expected." << std::endl;
    std::cout << "Eigth test failed." << std::endl << std::endl;
    return 0;
  } catch (STACK::Underflow) {
    std::cout << "The program detected an Underflow error, which it was expected." << std::endl;
    std::cout << "Eigth test passed succesfully." << std::endl << std::endl;
    return POINTS[8];
  }
}

int test9() {

  // Test stacks for being empty.

  STACK stack_3;

  std::cout << "Testing empty function." << std::endl;
  std::cout << "The stack should have 0 elements now. It has: " << stack_3.size() << " elements." << std::endl;
  if (!stack_3.is_empty()) {
    std::cout << "Ninth test detected an error. The stack just manipulated is supposed to be empty, which is not." << std::endl << std::endl;
    std::cout << "Ninth test failed." << std::endl << std::endl;
    return 0;
  } else {
    std::cout << "The program detected that manipulated stack is empty, which should be right." << std::endl;
    std::cout << "Ninth test passed succesfully." << std::endl << std::endl;
    return POINTS[9];
  }
}

int test10() {

  // Test inequality operator.

  STACK stack_3;
  STACK stack_2;

  for (size_t i = 0; i < half_size; i++) {
    stack_3.push(items[i]);
  }

  if (stack_3 != stack_2) {
    std::cout << "The program detected that two different stacks are in fact different." << std::endl;
    std::cout << "Tenth test passed succesfully." << std::endl << std::endl;
    return POINTS[10];
  } else {
    std::cout << "The program compared to different stacks and returned that both are equal" << std::endl << std::endl;
    std::cout << "Tenth test failed." << std::endl << std::endl;
    return 0;
  }
}

int test11() {

  // Testing stack functions for other value type

  typedef Stack < char > CSTACK;
  CSTACK stack;
  char letter = 'A';
  stack.push(letter);
  std::cout << stack.top() << std::endl;
  std::cout << "Testing stack functions for other value type." << std::endl;
  std::cout << "The stack should return " << letter << " as top." << std::endl;
  if (stack.top() == letter) {
    std::cout << "The program returned " << letter << " succesfully" << std::endl;
    std::cout << "Eleventh test passed succesfully." << std::endl << std::endl;
    return POINTS[11];
  } else {
    std::cout << "The top function returned " << stack.top() << std::endl << std::endl;
    std::cout << "Eleventh test failed." << std::endl << std::endl;
    return 0;
  }
}

int test12() {

  // Testing size funciton.

  std::cout << "Testing size function." << std::endl;
  STACK stack_5;
  size_t size_1 = 100;
  for (size_t i = 0; size_1 > i; i++) {
    stack_5.push(i);
  }

  if (stack_5.size() == size_1) {
    std::cout << "The program returned the right size succesfully." << std::endl;
    std::cout << "Twelfth test passed succesfully." << std::endl << std::endl;
    return POINTS[12];
  } else {
    std::cout << "The program did not returned the right size." << std::endl;
    std::cout << "The size fo the stack had to be " << size_1 << " and it was ";
    std::cout << stack_5.size() << "." << std::endl;
    std::cout << "Twelfth test failed." << std::endl << std::endl;
    return 0;
  }
}

int test13() {

  // Testing top function

  STACK stack_5;

  std::cout << "Testing top function." << std::endl;
  stack_5.push(items[half_size]);
  if (stack_5.top() == items[half_size]) {
    std::cout << "The top function returns the correct value." << std::endl;
    std::cout << "Thirteenth test passed succesfully." << std::endl << std::endl;
    return POINTS[13];
  } else {
    std::cout << "Thirteenth test failed." << std::endl << std::endl;
    return 0;
  }
}

int test14() {

  //  Testing constructor function and the size of it data member." 

  STACK stack_6;
  if (stack_6.size() == 0) {
    std::cout << "The program returned size 0 since it is a bran new stack." << std::endl;
    std::cout << "Fourteenth test passed succesfully." << std::endl << std::endl;
    return POINTS[14];
  } else {
    std::cout << "The program returned " << stack_6.size() << " and it had to be 0" << std::endl;
    return 0;
  }
}

int test15() {

  // Testing copy constructor with no elements.

  STACK stack_1;
  STACK stack_2(stack_1);

  if (stack_2.is_empty()) {
    std::cout << "Fifteenth test passed succesfully." << std::endl << std::endl;
    return POINTS[15];
  } else {
    std::cout << "Fifteenth test failed." << std::endl << std::endl;
    return 0;
  }
}

int main() {
  int sum = 0;

  std::cout << "Running " << DESCRIPTION[0] << std::endl;

  sum += run_a_test(1, DESCRIPTION[1], test1, POINTS[1]);
  std::cout << sum << std::endl;
  sum += run_a_test(2, DESCRIPTION[2], test2, POINTS[2]);
  std::cout << sum << std::endl;
  sum += run_a_test(3, DESCRIPTION[3], test3, POINTS[3]);
  std::cout << sum << std::endl;
  sum += run_a_test(4, DESCRIPTION[4], test4, POINTS[4]);
  std::cout << sum << std::endl;
  sum += run_a_test(5, DESCRIPTION[5], test5, POINTS[5]);
  std::cout << sum << std::endl;
  sum += run_a_test(6, DESCRIPTION[6], test6, POINTS[6]);
  std::cout << sum << std::endl;
  sum += run_a_test(7, DESCRIPTION[7], test7, POINTS[7]);
  std::cout << sum << std::endl;
  sum += run_a_test(8, DESCRIPTION[8], test8, POINTS[8]);
  std::cout << sum << std::endl;
  sum += run_a_test(9, DESCRIPTION[9], test9, POINTS[9]);
  std::cout << sum << std::endl;
  sum += run_a_test(10, DESCRIPTION[10], test10, POINTS[10]);
  std::cout << sum << std::endl;
  sum += run_a_test(11, DESCRIPTION[11], test11, POINTS[11]);
  std::cout << sum << std::endl;
  sum += run_a_test(12, DESCRIPTION[12], test12, POINTS[12]);
  std::cout << sum << std::endl;
  sum += run_a_test(13, DESCRIPTION[13], test13, POINTS[13]);
  std::cout << sum << std::endl;
  sum += run_a_test(14, DESCRIPTION[14], test14, POINTS[14]);
  std::cout << sum << std::endl;
  sum += run_a_test(15, DESCRIPTION[15], test15, POINTS[15]);
  std::cout << sum << std::endl;

  std::cout << "If you submit this sequence now, you will have\n";
  std::cout << sum << " percent out of the " << POINTS[0];
  std::cout << " percent from this test program.\n";

  return EXIT_SUCCESS;
}