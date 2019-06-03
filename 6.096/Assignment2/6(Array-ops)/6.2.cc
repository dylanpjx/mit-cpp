void reverseArray(int iarr[], int size) {
  int buff;
  for (int i = 0; i <= size / 2; ++i) {
    buff = iarr[i];
    iarr[i] = iarr[size - 1 - i];
    iarr[size - 1 - i] = buff;
  }
}
