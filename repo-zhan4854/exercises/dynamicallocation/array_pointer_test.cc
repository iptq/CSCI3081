#include "array_pointer_test.h"

#include <string>

ArrayPointerTest::ArrayPointerTest(int size) {
    size_ = size;
    std::string names[3] = {"angel", "yang", "mia"};

    /*  USE THIS FOR INITIALIZING DUCKS
    Duck::Duck(std::string name) {
        SetName(name);
    }
    */

    // Initialize Duck ducks1[3];
    printf("Initializing ducks1\n");
    for (int i = 0; i < 3; i++) {
        ducks1_[i].SetName(names[i]);
    }

    // Initialize  Duck * ducks2; with "size" number of elements
    printf("Initializing ducks2\n");
    ducks2_ = new Duck[size_];
    for (int i = 0; i < size_; i++) {
        ducks2_[i].SetName(names[i % 3]);
    }

    // Initialize Duck * ducks3_[3];
    printf("Initializing ducks3_[3]\n");
    for (int i = 0; i < 3; i++) {
        ducks3_[i] = new Duck(names[i % 3]);
    }

    // Initialize Duck ** ducks4; with "size" number of elements
    printf("Initializing ducks2\n");
    ducks4_ = new Duck*[size_];
    for (int i = 0; i < size_; i++) {
        ducks4_[i] = new Duck(names[i % 3]);
    }
}

ArrayPointerTest::~ArrayPointerTest() {
    printf("In destructor\n");

    // delete Duck ducks1[3];
    printf("Deleting ducks1\n");
    // delete ducks1_;  //  WILL NOT COMPILE

    // delete Duck * ducks2;
    printf("Deleting ducks2\n");
    delete[] ducks2_;

    // delete  Duck * ducks3[3]
    printf("Deleting ducks3\n");
    for (int i = 0; i < 3; i++) {
        delete ducks3_[i];
    }
    // delete[] ducks3_;    // WILL NOT COMPILE

    // delete Duck ** ducks4;
    printf("Deleting ducks4\n");
    delete[] ducks4_;
}

void ArrayPointerTest::DisplayContents() {
    // PerformQuack() for all in Duck ducks1[3];
    printf("Quack ducks1[3]\n");
    for (int i = 0; i < 3; i++) {
        ducks1_[i].PerformQuack();
    }

    // PerformQuack() for all in Duck * ducks2;
    printf("Quack ducks2[size_]\n");
    for (int i = 0; i < size_; i++) {
        ducks2_[i].PerformQuack();
    }

    // PerformQuack() for all in Duck * ducks3[3]
    printf("Quack ducks3[3]\n");
    for (int i = 0; i < 3; i++) {
        ducks3_[i]->PerformQuack();
    }

    // PerformQuack() for all in Duck ** ducks4;
    printf("Quack ducks4[size_]\n");
    for (int i = 0; i < size_; i++) {
        ducks4_[i]->PerformQuack();
    }
}
