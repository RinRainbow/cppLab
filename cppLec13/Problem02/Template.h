#ifndef Template_h
#define Template_h

template <typename T>
T absoluteValue(T t1, T t2) {
    return (t1 > t2) ? (t1 - t2) : (t2 - t1);
}

template <>
char absoluteValue<char>(char c1, char c2) {
    int int_1 = c1 - 0x30, int_2 = c2 - 0x30;
    if(int_1 > int_2) return 0x30 + (int_1 - int_2);
    else return 0x30 + (int_2 - int_1);
}

#endif /* Template_h */
