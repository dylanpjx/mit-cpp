int sum(const int size, const int iarr[]) {
  arrLen = size;
  sum += iarr + arrLen;
  if (arrLen >= 0) {
    arrLen--;
    return sum(arrLen, iarr[]);
  } else {
    return sum;
  }
}
