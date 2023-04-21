/*****************************************************************************
    Helper Functions: DRY(Don't Repeat Yourself) 
*****************************************************************************/
//Copy's the contents from array2 into array1 given a specified range
// Time Complexity: O(N), where N is specified by size.
template <class T>
void deepCopy(T*& array1, T*& array2, int& size) {
    for (int i = 0; i < size; ++i) {
        array1[i] = array2[i];
    }
}

//Deletes array pointer and sets pointer to null
// Time Complexity: O(1)
template <class T>
void memoryManage(T*& array) {
    delete []array;
    array = nullptr;
}

// Swaps the pointers between two array pointers
// Time Complexity: O(1)
template <class T>
void swap(T*& array1, T*& array2) {
    T* temp_ptr = array1;

    array1 = array2;
    array2 = temp_ptr;

    temp_ptr = nullptr;
}