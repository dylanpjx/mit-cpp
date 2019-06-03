void reverseArray(int iarr[], int size) {
  int* beg = iarr;
  int* end = iarr + (size - 1);
  int buff;
  for (int i = 0; i <= size / 2; ++i) {
    buff = *beg;
    *beg = *end;
    *end = buff;
    ++beg;
    --end;
  }
}
