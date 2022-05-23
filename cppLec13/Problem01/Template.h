#ifndef Template_h
#define Template_h

#include <iostream>

template <typename T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
    found = false;
    while(first != last) {
        location = (first + last) / 2;
        if(key < a[location]) last = location;
        else if(key > a[location]) first = ++location;
        else if(key == a[location]) {
            found = true;
            return;
        }
    }
    if(!found && a[first] == key) found = true;
    return;
}

template <typename T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
    found = false;
    location = (first + last) / 2;
    if(key == a[location]) {
        found = true;
        return;
    }
    if(first == last) return;
    if(key < a[location]) return RecBinarySearch(a, first, location, key, found, location);
    if(key > a[location]) return RecBinarySearch(a, location+1, last, key, found, location);

}


#endif /* Template_h */
