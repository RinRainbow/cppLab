#ifndef Template_h
#define Template_h

template <typename T>
auto absoluteValue(T t1, T t2) {
    return (t1 > t2) ? (t1 - t2) : (t2 - t1);
}

#endif /* Template_h */
