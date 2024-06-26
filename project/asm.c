// void phase_5(char *user_input)
// {
//   int num, sum = 0, counter = 0, value_from_address;

//   if (sscanf(user_input, "%d", &num) != 1)
//   {
//     explode_bomb();
//   }

//   num = num & 0xf;

//   if (num == 15)
//   {
//     explode_bomb();
//   }

//   do
//   {
//     value_from_address = get_value_from_address(0x402800 + (num * 4));
//     sum += value_from_address;
//     counter++;
//   } while (value_from_address != 15 && counter < 15);

//   if (sum != 15)
//   {
//     explode_bomb();
//   }
// }

// int array_3602[] = {10, 2, 14, 7, 8, 12, 15, 11, 0, 4, 1, 13, 3, 9, 6, 5};

// int get_value_from_address(int address)
// {
//   int offset = (address - 0x402800) / 4; // 每个整数占4个字节
//   return array_3602[offset];
// }

void phase_5(char *user_input)
{
  int num, expected_sum, sum = 0, counter = 0, value_from_address;

  if (sscanf(user_input, "%d %d", &num, &expected_sum) != 2)
  {
    explode_bomb();
  }

  num = num & 0xf;

  if (num == 15)
  {
    explode_bomb();
  }

  do
  {
    value_from_address = get_value_from_address(0x402800 + (num * 4));
    sum += value_from_address;
    counter++;
    num = (num + 1) & 0xf; // 注意：要使num在[0, 15]之间循环
  } while (value_from_address != 15 && counter < 15);

  if (sum != expected_sum)
  {
    explode_bomb();
  }
}

int array_3602[] = {10, 2, 14, 7, 8, 12, 15, 11, 0, 4, 1, 13, 3, 9, 6, 5};

int get_value_from_address(int address)
{
  int offset = (address - 0x402800) / 4; // 每个整数占4个字节
  return array_3602[offset];
}

void explode_bomb()
{
  // 假设的函数
  printf("Bomb exploded!\n");
  exit(1);
}