#include <iostream>
#include "algorithm"
#include "vector"
#include "bitset"
#include "cstdint"
using namespace std;


//void output_double_in_bin(union number);

union {
    long ValueL;
    double ValueD;
}TestLD;



int main (){
    setlocale(LC_ALL, "Rus");

    unsigned int choice;
    cout << "�������:\n"
         << "\n    1 - ������ ���� Long � ��������� �� ��������� �������������;"
         << "\n    2 - ������ ���� Double  ��������� �� ��������� �������������;"
         << "\n    3 - ������ ���� Long � ��������� ��������������;"
         << "\n    4 - ������ ���� Double � �������� ��������������;"
         << "\n    0 - Exit.\n\n";
    cin >> choice;
    cin.ignore(4, '\n');
    switch (choice) {
        case 1:{
            cout << "\n������� ������ ���� Long: ";
            cin >> TestLD.ValueL;
            cout << "\n���� ������ ���� Long � �������� �������������: ";
            for (int i = 0; i < sizeof(TestLD.ValueL)*8; i++){                                      //���� ������� �� ����� (64)
                cout << (((TestLD.ValueL & (1<<(sizeof(long) * 8 - 1)))==0) ? 0 : 1 );              //��������� � �������� ���� � ������� ��� �� 0\1, ���� 0 - ������� 0, ���� ������� �� 0 (����� ������ ��������) - ������� 1
                TestLD.ValueL <<= 1;                                                                //����� ���� �����
            }
            break;
        }

        case 2:{
            vector<bool> VectorDouble;
            cout << "\n������� ������ ���� Double: ";
            cin >> TestLD.ValueD;
            cout << "\n���� ������ ���� Double � �������� �������������: ";
            uint8_t *bytePointer = (uint8_t *)&TestLD.ValueD;
            for(size_t i = 0; i < sizeof(double); i++)
            {
                uint8_t byte = bytePointer[i];
                for(int bit = 0; bit < 8; bit++)
                {
                    VectorDouble.push_back(byte&1);
                    byte >>= 1;
                }
            }
            reverse(VectorDouble.begin(), VectorDouble.end());
            for (auto i : VectorDouble){
                cout << i;
            }
            break;
        }

        case 3: {
            vector<bool> VectorLong, temp;
            int direction, StRaz, Sdvig;
            cout << "������� ������ ���� Long: ";
            cin >> TestLD.ValueL;
            cout << "������� ������� ������(1-64): ";
            cin >> StRaz;
            cout << "������� ���������� �������� � ������";
            cin >> Sdvig;
            cout << "�� ������� �������� ������ (������� ������������� ����� ��� ������ �����)? ";
            cin >> direction;
            for (int i = 0; i < sizeof(TestLD.ValueL)*8; i++){                                      //���� ������� �� ����� (64)
                VectorLong.push_back(((TestLD.ValueL & (1<<0))==0) ? 0 : 1 );              //��������� � �������� ���� � ������� ��� �� 0\1, ���� 0 - ������� 0, ���� ������� �� 0 (����� ������ ��������) - ������� 1
                if (i<StRaz){
                    if(i>=StRaz-Sdvig) temp.push_back(VectorLong[i]);                  //����� � ������ ����� �� ��������� ������
                }
                TestLD.ValueL >>= 1;                                                                //����� ���� �����
            }
            for (auto i : VectorLong) {
                cout << i;
            }
            cout << "\n";
            for (auto i : temp) {
                cout << i;
            }
            cout << "\n";


// �������� ��� �����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!













            break;
        }

        case 4: {
            int direction, x;
            cout << "������� ������� ������: ";
            cin >> x;
            cout << "�� ������� �������� ������ (������� ������������� ����� ��� ������ �����)? ";
            cin >> direction;
            static_assert(sizeof(TestLD.ValueD) != sizeof(TestLD.ValueL), "value0 does no equal to value1");
            TestLD.ValueL >>= direction;
            break;
        }


    }

    return 0;
}


/*
void FUNC (long perem){
    for (int i = 0; i < sizeof(perem)*8; i++){                                      //���� ������� �� ����� (64)
        cout << (((perem & (1<<(sizeof(long) * 8 - 1)))==0) ? 0 : 1 );              //��������� � �������� ���� � ������� ��� �� 0\1, ���� 0 - ������� 0, ���� ������� �� 0 (����� ������ ��������) - ������� 1
        perem <<= 1;                                                                //����� ���� �����
    }
}*/


/*
static_assert(sizeof(TestLD.ValueD) != sizeof(TestLD.ValueL), "ValueD does no equal to ValueL"); //���� ������� ����� ������ �� ���������, �� ���������� ������ ���������� � ����� ���������������� ���������
FUNC(TestLD.ValueL);*/


/*
std::vector<int> output_double(myDouble count) {
    std::vector<int> arr;
    arr.resize(64);
    int k = 0;
    for (int i = 0; i < 8; i++) {
        auto tmp = output_unsigned_char(count.arr[7 - i]);
        for (int j = 0; j < tmp.size(); ++j) {
            arr[k] = tmp[j];
            ++k;
        }
    }
    return arr;
}

vec_long_double = output_double(two);
reverse(vec_long_double.begin(), vec_long_double.end());*/


