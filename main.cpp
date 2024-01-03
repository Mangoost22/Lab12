
#include <iostream>
#include "algorithm"
#include "vector"
#include "bitset"
#include "cstdint"
using namespace std;


void output_double_in_bin(union number);

union {
    long ValueL;
    double ValueD;
}TestLD;



int main (){
    setlocale(LC_ALL, "Rus");

    unsigned int choice;
    cout << "Ââåäèòå:\n"
         << "\n    1 - äàííûå òèïà Long è ïîëó÷åíèå èõ äâîè÷íîãî ïðåäñòàâëåíèÿ;"
         << "\n    2 - äàííûå òèïà Double  ïîëó÷åíèå èõ äâîè÷íîãî ïðåäñòàâëåíèÿ;"
         << "\n    3 - äàííûå òèïà Long è âûïîëííèå ïðåîáðàçîâàíèÿ;"
         << "\n    4 - äàííûå òèïà Double è âûïîëíèå ïðåîáðàçîâàíèÿ;"
         << "\n    0 - Exit.\n\n";
    cin >> choice;
    cin.ignore(4, '\n');
    switch (choice) {
        case 1:{
            cout << "\nÂâåäèòå äàííûå òèïà Long: ";
            cin >> TestLD.ValueL;
            cout << "\nÂàøè äàííûå òèïà Long â äâîè÷íîì ïðåäñòàâëåíèè: ";
            for (int i = 0; i < sizeof(TestLD.ValueL)*8; i++){                                      //öèêë ïðîãîíà ïî áèòàì (64)
                cout << (((TestLD.ValueL & (1<<(sizeof(long) * 8 - 1)))==0) ? 0 : 1 );              //îáðàùåíèå ê ñòàðøåìó áèòó è ïîâåðêà åãî íà 0\1, åñëè 0 - âûâîäèì 0, åñëè îòëè÷íî îò 0 (ëþáîå äðóãîå çíà÷åíèå) - âûâîäèì 1
                TestLD.ValueL <<= 1;                                                                //ñäâèã áèòà âëåâî
            }
            break;
        }

        case 2:{
            vector<bool> VectorDouble;
            cout << "\nÂâåäèòå äàííûå òèïà Double: ";
            cin >> TestLD.ValueD;
            cout << "\nÂàøè äàííûå òèïà Double â äâîè÷íîì ïðåäñòàâëåíèè: ";
            output_double_in_bin(union TestLD);
            break;
        }

        case 3: {
            vector<bool> VectorLong, temp;
            int direction, StRaz, Razs;
            cout << "Ââåäèòå äàííûå òèïà Long: ";
            cin >> TestLD.ValueL;
            cout << "Ââåäèòå ñòàðøèé ðàçðÿä(1-64): ";
            cin >> StRaz;
            cout << "Ââåäèòå êîëè÷åñòâî ðàçðÿäîâ â ãðóïïå";
            cin >> Razs;
            cout << "Íà ñêîëüêî ñäâèíóòü âïðàâî (çàäàéòå îòðèöàòåëüíîå ÷èñëî äëÿ ñäâèãà âëåâî)? ";
            cin >> direction;
            for (int i = 0; i < sizeof(TestLD.ValueL)*8; i++){                                      //öèêë ïðîãîíà ïî áèòàì (64)
                VectorLong.push_back(((TestLD.ValueL & (1<<0))==0) ? 0 : 1 );              //îáðàùåíèå ê ñòàðøåìó áèòó è ïîâåðêà åãî íà 0\1, åñëè 0 - âûâîäèì 0, åñëè îòëè÷íî îò 0 (ëþáîå äðóãîå çíà÷åíèå) - âûâîäèì 1
                TestLD.ValueL >>= 1;                                                                //ñäâèã áèòà âëåâî
            }
            for (auto i : VectorLong) {
                cout << i;
            }
            cout << "\n";

            if (direction>=0) {
                while (Razs>direction){
                    direction = direction - Razs;
                }
                rotate(VectorLong.begin() + (StRaz-Razs),
                       VectorLong.begin() + (StRaz-direction),
                       VectorLong.begin() + StRaz);
                reverse(VectorLong.begin(), VectorLong.end());
                for (auto i: VectorLong) {
                    cout << i;
                }
            }
            else {
                direction *=-1;
                while (Razs>direction){
                    direction = direction - Razs;
                }
                rotate(VectorLong.begin() + (StRaz - Razs),
                       VectorLong.begin() + (StRaz + direction),
                       VectorLong.begin() + StRaz);
                //reverse(VectorLong.begin(), VectorLong.end());
                for (auto i: VectorLong) {
                    cout << i;
                }
            }



            /*for (int i = 0; i< VectorLong.size();i++){
                if (i>x-x1-1){
                    if(i<=x-1)
                        temp.push_back(VectorLong[i]);
                }
            }
            for(auto i:temp){
                cout << i;
            }
            cout << "\n";
            rotate(temp.begin(), temp.begin()+direction, temp.end());
            for(auto i:temp){
                cout << i;
            }*/













            break;
        }

        case 4: {
            int direction, x;
            cout << "Ââåäèòå ñòàðøèé ðàçðÿä: ";
            cin >> x;
            cout << "Íà ñêîëüêî ñäâèíóòü âïðàâî (çàäàéòå îòðèöàòåëüíîå ÷èñëî äëÿ ñäâèãà âëåâî)? ";
            cin >> direction;
            static_assert(sizeof(TestLD.ValueD) != sizeof(TestLD.ValueL), "value0 does no equal to value1");
            TestLD.ValueL >>= direction;
            break;
        }


    }

    return 0;
}


void output_double_in_bin(number)
{
    uint8_t* bytePointer = (uint8_t*)&number.ValueD;
    for (size_t i = 0; i < sizeof(double); i++)
    {
        //output double
        uint8_t byte = bytePointer[i];
        for (int bit = 0; bit < 8; bit++)
        {
            VectorDouble.push_back(byte & 1);
            byte >>= 1;
        }
    }
    reverse(VectorDouble.begin(), VectorDouble.end());

    for (auto i : VectorDouble) {
        cout << i;
    }
}