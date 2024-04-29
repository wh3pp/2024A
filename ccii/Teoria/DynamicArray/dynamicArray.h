#ifndef DYNARR_H
#define DYNARR_H

class DynamicArray{
    int size;
    int *data;
  public:
    DynamicArray();
    DynamicArray(int arr[], int size);
    DynamicArray(DynamicArray &o);
    ~DynamicArray();
    void push_back(int val);
    void insert(int pos, int val);
    void remove(int pos);
    void print() const;
};

#endif
