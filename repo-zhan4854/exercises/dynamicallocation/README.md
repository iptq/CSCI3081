NAMES:

Chena Lee (leex8119), Jessica Zhu (zhux0551), Axel Stenson (stens103), Michael Zhang (zhan4854)

## Dynamic Allocation and Class destructor

The ArrayPointerTest class has a collection of 4 arrays of Duck and Duck pointers.
main() calls a helper function in which it declares an instance of this class.
Then displaycontents is called, which simply makes every duck in every array
PerformQuack(). Upon exit of the helper, everything is destroyed (or is it!).

Note that there are print statements inside the destructors to better understand when things are called. To make things even more evident, you can print the name of the duck before you destroy it.

Here is your assignment:

- Copy to a git repo of someone in your group.
- Put the name of eveyone in your group at the top of this readme!
- Fill in the initialization of all duck arrays in the constructor.
- Make all the ducks quack in DisplayContents().
- Fix the delete's where appropriate in the destructor.
- Answer the following questions directly in the readme in your git repo:
  1. Decide which of these you think is correct and briefly justify:
  ```C++
  printf("Initializing ducks1\n");
  ducks1_[0].SetName("angel");
  ```
  ```C++
  printf("Initializing ducks1\n");
  ducks1_[0] = Duck("angel");
  ```
  If the duck has already been created, then it makes more sense to use the
  first scenario, ducks1[0].SetName() since it simply changes the name property
  of an existing duck rather than creating a new one like the second one.
  2. In the destructor, there are 2 lines with the comment "WILL NOT COMPILE". Explain why these will not compile.
  - For the first of the two "WILL NOT COMPILE" statements, there was never a new
    that was used to initialize the array, because it's a statically allocated
    array and it will automatically be deleted with the object is destroyed.
  - For the second of the two statements, each of the elements within the array
    had been initialized manually, so each of them must be deleted manually as
    well (must pair the 'delete's with the 'new's).
  3. For each delete statement that is insufficient, explain how you fixed it.
  - Since we don't need to 'delete' it, it's ok if we don't do anything.
  - I looped through the array and called delete on each of the elements within
    the array.

- Push to git.
