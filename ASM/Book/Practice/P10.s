/*
Program to check if a number is a palindrome
 */

/*
1001
0000 0000 0000 0000 0000 0000 0000 1001

1) check the length of the bit -> in this case 4 <-> get_bit_length

now we check the last bit
2a) 0000 0000 0000 0000 0000 0000 0000 0001 -> using and with 0x00000001 <-> get_last_bit
2b) compare this with 0x00000001 if equal, 1, if not 0

3) store the bit at a location

4) finally cross compare the bits to check if the bit is a palindrom
 */

/*
bool check_palindrome(int a)
{
    bool ans = true;
    int size = get_bit_length(a);

    int idx = 0;
    int store[size];
    while (idx < size)
    {
        store[idx] = that_bit;
    }

    idx = 0;
    while (idx < size)
    {
        if (store[idx] != store[size-idx-1])
        {
            ans = false;
        }
    }

    return ans;
}
 */