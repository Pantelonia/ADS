#include "edx-io.hpp"
#include <map>
#include <string>
using namespace std;

//���-������� 
long get_hash(long long value, long ht_size)
{
    return abs((value * 47) ^ (value * 31)) % ht_size;
}
//���������� true ���� ������� ��������, false - ���� ����� ������� ��� ��� ��������
bool insert_into_ht(long long*& ht, long long value, long ht_size)
{
    //��������� ���
    long hash = get_hash(value, ht_size);
    //���� �� �������� �� ��������� ������ ��� ������ � ���� �� ��������� ��������� ����� �� ���� ������
    while (ht[hash] != -1 && ht[hash] != value)
    {
        //����������� ������
        if (++hash == ht_size)
        {
            hash = 0;
        }
    }
    if (ht[hash] == value)
    {
        return false;
    }
    else
    {
        ht[hash] = value;
        return true;
    }
}

int main()
{
    long N;
    int A, Ac, Ad;
    long long X, B, Bc, Bd;

    io >> N >> X >> A >> B >> Ac >> Bc >> Ad >> Bd;
    long long* ht = new long long[N * 2];

    for (long i = 0; i < N * 2; i++)
    {
        ht[i] = -1;
    }

    for (long i = 0; i < N; i++)
    {
        if (insert_into_ht(ht, X, N * 2))
        {
            A = (A + Ad) % 1000;
            B = (B + Bd) % 1000000000000000;
        }
        else
        {
            A = (A + Ac) % 1000;
            B = (B + Bc) % 1000000000000000;
        }
        X = (X * A + B) % 1000000000000000;
    }

    io << X << " " << A << " " << B;

    return 0;
}