#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

class StaticArray {
    int size;
    int *data;
  public:
    StaticArray(int size);
    StaticArray(StaticArray &a);
    ~StaticArray();
    int get(int index) const;
    void set (int index, int value);
    int getsize() const;
    void print() const;
};

#endif
