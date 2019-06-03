// bob and dole are integers
int accumulator = 0;
while (true) {
  if (dole == 0)
    break;
  accumulator += ((dole % 2 == 1) ? bob : 0);
  dole /= 2;
  bob *= 2;
}
cout << accumulator << "\n";

/*
 * terminate if dole = 0
 * accumulator = 0, if dole is odd
 * accumulator = bob, if dole is even
 * dole = dole/2
 * bob = bob*2
 * cout accumulator
 * accumulator returns bob * dole
 */
