int func7(int *ad, int inp)
{
  if (!ad)
    return -1;
  int temp = &ad;
  int ans;
  if (temp - inp <= 0)
  {
    ans = 0;
    if (temp == inp)
      return ans;
    ad = *(ad + 0x10);
    ans = func7(ad, inp);
    ans = ans * 2 + 1;
    return ans;
  }
  else
  {
    ad = *(ad + 0x8);
    ans = func7(ad, inp) * 2;
    return ans;
  }
}