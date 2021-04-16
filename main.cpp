#include <fstream>
#include"class.h"

using namespace std;

int main(int argc, char * argv[]){
	if(argc!=2){
		cout << "ОШИБКА" << endl;
		return 0;
	}
	cout << "Вы ввели файл " << argv[1] << endl;
	fstream f1(argv[1], ios::in);
	if(!f1){
		cout << "ОШИБКА" << endl;
		return 0;
	}
	int n;
	f1 >> n;
	
	int tmp1, tmp2;
	string str;
	bakery * array = new bakery[n];
	for(int i = 0; i < n; i++){
                f1 >> str;
                array[i].setName(str);
		f1 >> tmp1;
		array[i].setWeight(tmp1);
		f1 >> tmp2;
		array[i].setPrice(tmp2);
	}
	f1.close();

	cout << "Пекарня" << endl << "1.Посмотреть меню" << endl << "2.Добавить изделие" << endl << "3.Убрать изделие из меню" << endl << "4.Выбрать изделие по названию" << endl << "5.Выбрать изделие по массе" << endl << "6.Найти изделие по цене" << endl << "7.Редактировать изделие" << endl << "8.Выход" << endl;
	int c;
	cin >> c;

	Menu m;
	m.SetN(n);
	while(c != 8){
		switch(c){
		case 1:
			m.printAll(array);
			break;
		case 2:
                        array = m.push(array);
	        	break;
		case 3:
			m.del(array);
	        	break;
		case 4:
			m.find1(n, array);
	        	break;
		case 5:
			m.find2(n, array);
	        	break;
		case 6:
			m.find3(n, array);
	        	break;
		case 7:
			m.edit(array);
			break;
		}
		cout << "Пекарня" << endl << "1.Посмотреть меню" << endl << "2.Добавить изделие" << endl << "3.Убрать изделие из меню" << endl << "4.Выбрать изделие по названию" << endl << "5.Выбрать изделие по массе" << endl << "6.Найти изделие по цене" << endl << "7.Редактировать изделие" << endl << "8.Выход" << endl;
                cin >> c;
	}
        fstream f(argv[1], ios::out);
        f << m.GetN() << endl;
        for(int i = 0; i < m.GetN(); i++){
                f << array[i]._name() << endl;
                f << array[i]._weight() << endl;
                f << array[i]._price() << endl;
        }
        f.close();
	delete [] array;
	return 0;
}
