int sum(const int size, const int iarr[]) {
  int sum;
  for (int i = 0; i < size; ++i) {
    sum += iarr[i];
  }
  return sum;
}
