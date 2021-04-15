#include "class.h"

bakery::bakery(){
	name = " ";
	weight = 0;
	price = 0;
}

bakery::~bakery(){
 cout << "Вызван дестрктор для " << name << endl;
}

string bakery::_name(){
	return name;
}

int bakery:: _weight(){
	return weight;
}
int bakery:: _price(){
	return price;
}

void bakery::setName(string n){
	if(n != ""){
		name = n;
	}
	else{
		cout << "Ошибка. Пустое имя" << endl;
	}
}
void bakery::setWeight(int w){
	if(w > 0){
		weight = w;
	}
	else{
		cout << "Неверное значение" << endl;
	}
}
void bakery::setPrice(int p){
	if(p > 0){
        	price = p;
        }
        else{
         	cout << "Неверное значение" << endl;
        }
}

void Menu::printAll(bakery* array){
        for(int i = 0; i < n; i++){
                cout << "Изделие: " << array[i]._name() << endl;
                cout << "Масса: " << array[i]._weight() << endl;
                cout << "Цена: " << array[i]._price() << endl;
        }
}
bakery* Menu::push(bakery* array){
	bakery* new_array = new bakery[n + 1];
	for(int j = 0; j < n; j++){
                new_array[j] = array[j];
	}
	cout << "Введите название изделия" << endl;
	string z;
	cin >> z;
	new_array[n].setName(z);
	cout << "Введите массу изделия в граммах" << endl;
	int m;
	cin >> m;
	new_array[n].setWeight(m);
	cout << "Введите цену изделия в рублях" << endl;
	int t;
	cin >> t;
	new_array[n].setPrice(t);
	n = n + 1;

        delete [] array;
        return  new_array;

}
void Menu::del(bakery* array){
	cout << "Введите номер изделия, которое нужно удалить" << endl;
	int index;
	cin >> index;
	for(int i = index-1; i < n - 1; i++){
		array[i] = array[i+1];
	}
	n = n - 1;
}
void Menu::find1(int a, bakery* array){
	string z;
	cout << "Введите название для поиска" << endl;
	cin >> z;
	for(int j = 0; j < a; j++){
		if(z == array[j]._name()){
			cout << "Изделие: " << array[j]._name() << endl << "Масса: " << array[j]._weight() << endl << "Цена: " << array[j]._price() << endl;
			break;
		}
	}
}
void Menu::find2(int a, bakery* array){
	int m;
        cout << "Введите массу для поиска" << endl;
        cin >> m;
        for(int j = 0; j < a; j++){
                if(m == array[j]._weight()){
                        cout << "Изделие: " << array[j]._name() << endl << "Масса: " << array[j]._weight() << endl << "Цена: " << array[j]._price() << endl;
                }
        }
}
void Menu::find3(int a, bakery* array){
	int t;
        cout << "Введите цену для поиска" << endl;
        cin >> t;
        for(int j = 0; j < a; j++){
                if(t == array[j]._price()){
                        cout << "Изделие: " << array[j]._name() << endl << "Масса: " << array[j]._weight() << endl << "Цена: " << array[j]._price() << endl;
                }
        }
}

void Menu::SetN(int a){
	n = a;
}
int Menu::GetN(){
	return n;
}



