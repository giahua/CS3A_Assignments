#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

//------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/list_sorted/list_sorted.h"

//------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------
//          COPY BASIC_TEST INTO THIS FILE.
//                    AND THEN,
//         DO NOT EDIT THIS FILE ANY FURTHER
//------------------------------------------------------------------------------

bool basic_test(bool debug = false)
{
  // Test 1: ascending, duplicate(not unique)
  cout << "ascending, duplicate(not unique)\n";
  bool ascending = true;
  bool unique = false;
  List<int> list_a_d(ascending, unique); 
  for (int i = 1; i < 6; i++)
  {
    list_a_d.insert(i);
    list_a_d.insert(i * 10);
  }
  cout << list_a_d;
  for (int i = 3; i < 13; i++)
  {
    list_a_d.insert(i);
  }
  cout << list_a_d << endl;

  // Test 2: descending, duplicate(not unique)
  cout << "descending, duplicate(not unique)\n";
  ascending = false;
  unique = false;
  List<int> list_d_d(ascending, unique); 
  for (int i = 1; i < 6; i++)
  {
    list_d_d.insert(i);
    list_d_d.insert(i * 10);
  }
  cout << list_d_d;
  for (int i = 3; i < 13; i++)
  {
    list_d_d.insert(i);
  }
  cout << list_d_d << endl;

  // Test 3: ascending, unique
  cout << "ascending, unique\n";
  ascending = true;
  unique = true;
  List<int> list_a_u(ascending, unique); 
  for (int i = 3; i < 7; i++)
  {
    list_a_u.insert(i);
    list_a_u.insert(i * 10);
  }
  cout << list_a_u;
  list_a_u.insert(1);
  list_a_u.insert(5);
  list_a_u.insert(30);
  cout << list_a_u << endl;

  // Test 4: descending, unique
  cout << "descending, unique\n";
  ascending = false;
  unique = true;
  List<int> list_d_u(ascending, unique); 
  for (int i = 3; i < 7; i++)
  {
    list_d_u.insert(i);
    list_d_u.insert(i * 10);
  }
  cout << list_d_u;
  list_d_u.insert(70);
  list_d_u.insert(5);
  list_d_u.insert(30);
  cout << list_d_u << endl;

  cout << "\n\n---------- D O N E ---------------\n\n";
  return true;
}


//Lord help me! 
bool debug = false;

TEST(BASIC_TEST, BasicTest)
{
  bool success = basic_test(debug);
  EXPECT_EQ(success, true);
}

int main(int argc, char **argv)
{
  if (argc>1){
    debug = argv[1][0]=='t';
  }
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


/*
build git:(master) ✗  😊 $> tree ../includes 
../includes
├── linked_list_functions
│   └── linked_list_functions.h
├── list_sorted
│   └── list_sorted.h
└── node
    └── node.h
3 directories, 3 files
build git:(master) ✗  😊 $> ./bin/basic_test
----------running testA.cpp---------
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.BasicTest
ascending, duplicate(not unique)
[1]->[2]->[3]->[4]->[5]->[10]->[20]->[30]->[40]->[50]->|||
[1]->[2]->[3]->[3]->[4]->[4]->[5]->[5]->[6]->[7]->[8]->[9]->[10]->[10]->[11]->[12]->[20]->[30]->[40]->[50]->|||

descending, duplicate(not unique)
[50]->[40]->[30]->[20]->[10]->[5]->[4]->[3]->[2]->[1]->|||
[50]->[40]->[30]->[20]->[12]->[11]->[10]->[10]->[9]->[8]->[7]->[6]->[5]->[5]->[4]->[4]->[3]->[3]->[2]->[1]->|||

ascending, unique
[3]->[4]->[5]->[6]->[30]->[40]->[50]->[60]->|||
[1]->[3]->[4]->[10]->[6]->[60]->[40]->[50]->[60]->|||

descending, unique
[60]->[50]->[40]->[30]->[6]->[5]->[4]->[3]->|||
[70]->[60]->[50]->[40]->[60]->[6]->[10]->[4]->[3]->|||


---------- D O N E ---------------

[       OK ] BASIC_TEST.BasicTest (0 ms)
[----------] 1 test from BASIC_TEST (0 ms total)
[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $> 
*/
