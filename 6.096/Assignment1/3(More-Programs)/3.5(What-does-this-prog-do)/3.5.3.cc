// N is a nonnegative integer
double acc = 0;
for (int i = 1; i <= N; ++i) {
  double term = (1.0 / i);
  acc += term * term;
  for (int j = 1; j < i; ++j) {
    acc *= -1;
  }
  cout << acc << "\n";
}
/*
 * https://www.khanacademy.org/computing/computer-science/cryptography/
 * modarithmetic/a/congruence-modulo
 *
 * There are 4 buckets, (0, 1, 2, 3) mod 4. And for diff values of n, for
 * those of the same sequence as (0, 1, 2, 3), they belong to the same bucket
 */
