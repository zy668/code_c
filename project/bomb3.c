void phase_3()
{
  int num1, num2;
  char ch, expected_char = 'k';
  if (scanf("%d %c %d", &num1, &ch, &num2) <= 2)
  {
    explode_bomb();
  }

  switch (num1)
  {
  case 0:
    if (num2 != 0x3db)
      explode_bomb();
    expected_char = 'q';
    break;
  case 1:
    if (num2 != 0x16b)
      explode_bomb();
    expected_char = 'v';
    break;
  case 2:
    if (num2 != 0x32c)
      explode_bomb();
    expected_char = 'n';
    break;
  case 3:
    if (num2 != 0x3dc)
      explode_bomb();
    expected_char = 'w';
    break;
  case 4:
    if (num2 != 0x3c7)
      explode_bomb();
    expected_char = 'm';
    break;
  case 5:
    if (num2 != 0x3c4)
      explode_bomb();
    expected_char = 'y';
    break;
  case 6:
    if (num2 != 0x388)
      explode_bomb();
    expected_char = 'b';
    break;
  case 7:
    if (num2 != 0x25b)
      explode_bomb();
    expected_char = 'b';
    break;
  default:
    explode_bomb();
    break;
  }

  if (expected_char != ch)
  {
    explode_bomb();
  }
}