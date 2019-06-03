void printArray(int iarr[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << iarr[i];
    if (i < (size - 1)) {
      cout << ", ";
    }
  }
  cout << endl;
}
