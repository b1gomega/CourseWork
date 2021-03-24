#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
struct date{
	unsigned int DateDay;
	unsigned int DateMonth;
	unsigned int DateYear;	
};
struct position{
	char NameDemandant[15];
	char NameAccuser[15];
};
struct phone{
	char PhoneNumberDemandant[15];
	char PhoneNumberAccuser[15];
	
};
struct law{
	date date;
	char InfoAboutAffair[15];
	position position;
	phone phone;	
};
law ved;
void DeleteInformation(){
	system("cls");
	ofstream fout("Kursova.dat", ios::binary);
	if(!fout.is_open()){
		cout << "Ошибка открытия файла!" << endl;
	}
	else{
		fout.open("Kursova.dat", ios::binary | ios::out);
		cout << "База данных удалена!!!! \nОсталось 0 елементов \n";
	}
	fout.close();
	system("pause");
}
void AmountElement(law ved){
	system("cls");
	unsigned short int Amount = 0;
	ifstream fin("Kursova.dat", ios::binary);
	if(!fin.is_open()){
		cout << "Ошибка открытия файла!" << endl;
	}
	else{
		while(fin.read((char*)&ved, sizeof(struct law))){
			Amount++;
		}
		if(Amount == 0 || Amount >=5){
			cout << "Сейчас в базе данных имеется " << Amount << " елементов." << endl;
		}
		if(Amount == 1){
			cout << "Сейчас в базе данных имеется " << Amount << " елемент." << endl;
		}
		if(Amount >= 2 && Amount <=4){
			cout << "Сейчас в базе данных имеется " << Amount << " елемента." << endl;
		}		
	}
	fin.close();
	system("pause");
}
void BeginOutPut(){
	system("cls");
	cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" <<  setw(7) << "Номер" << "|" << setw(6) << "День" << "|" << setw(7) << "Месяц" << " | " << setw(7) << "Год" << "|" << setw(13) << "Предмет" << "|" << setw(20) << "Телефон позивача" 
	<< "|" << setw(18) << "Название фирмы" << "|" << setw(20) << "Телефон обвинителя" << "|" << setw(18) << "Название фирмы" << "|" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void OutPutInfo(law ved, int lich){
	cout << "|" << setw(7) << lich << "|" << setw(6) << ved.date.DateDay << "|" << setw(8) << ved.date.DateMonth << "|" << setw(8) << ved.date.DateYear << "|" << setw(13) <<  ved.InfoAboutAffair << "|" << setw(20) << ved.phone.PhoneNumberDemandant 
	<< "|" << setw(18) << ved.position.NameDemandant << "|" << setw(20) << ved.phone.PhoneNumberAccuser << "|" << setw(18) << ved.position.NameAccuser << "|" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void ShowInfo(){
	system("cls");
	ifstream fin("Kursova.dat", ios::binary);
	unsigned int lich = 1;
	if(!fin.is_open()){
		cout << "Ошибка открытия файла!" << endl;	
	}
	else{
		BeginOutPut();
		while(fin.read((char*)&ved, sizeof(struct law))){
			OutPutInfo(ved, lich);
			lich++;
		}	
	}
	fin.close();
	system("pause");
}
void ShowInfoAccordingVariant(){
	system("cls");
	ifstream fin("Kursova.dat", ios::binary);
	if(!fin.is_open()){
		cout << "Ошибка открытия файла!" << endl;	
	}
	else{
		int LichVariant = 0;
		string AccuserName;
		cout << "Введите название фирмы по которой хотите получить информацию было ли возбуждено на эту фирму уголовное дело: ";
			cin >> AccuserName;
		while(fin.read((char*)&ved, sizeof(struct law))){
			if(ved.position.NameAccuser == AccuserName){
				LichVariant++;
			}
		}	
		if(LichVariant == 0){
			cout << "С фирмой " << AccuserName << " не возбуждалось уголовное дело.Возбуждено " << LichVariant << " уголовных дел." << endl;
		}
		if(LichVariant == 1){
			cout << "С фирмой " << AccuserName << " возбуждалось уголовное дело.Возбуждено " << LichVariant << " уголовное дело." << endl;	
		}
		if(LichVariant > 1){
			cout << "С фирмой " << AccuserName << " возбуждалось уголовное дело.Возбуждено " << LichVariant << " уголовных дела." << endl;
		}
	}
	fin.close();
	system("pause");
}
void AddInfo(){
	system("cls");
	ofstream fout("Kursova.dat", ios::binary | ios::app);
	if(!fout.is_open()){
		cout << "Ошибка открытия файла!" << endl;
	}
	else{
		short int AmountAffair;
		do{
			cout << "Введите количество судебных дел которые хотите добавить.Будьте внимательные нужно вводить число и адекватные значения, ввод:";
			cin.clear();
			cin.ignore();
			cin >> AmountAffair;
		}while(!cin.good() || AmountAffair < 1);
		system("cls");
		for(int i = 0; i < AmountAffair; i++){
			do{
				cout << "Введите день подачи заявления.Будьте внимательные нужно вводить число и адекватные значения, ввод:";
				cin.clear();
				cin.ignore();
				cin >> ved.date.DateDay;
			}while(!cin.good() || ved.date.DateDay <=0 || ved.date.DateDay > 31);
				cout << "Введите месяц подачи заявления:" << endl;
			do{
				cout << "Будьте внимательные нужно вводить число и адекватные значения, ввод:";
					cin.clear();
					cin.ignore();
					cin >> ved.date.DateMonth;
			}while(!cin.good() || ved.date.DateMonth <=0 || ved.date.DateMonth > 12);
				cout << "Введите год подачи заявления:" << endl;	
			do{
				cout << "Будьте внимательные нужно вводить число и адекватные значения, ввод:";
					cin.clear();
					cin.ignore();
					cin >> ved.date.DateYear;
			}while(!cin.good() || ved.date.DateYear < 2000 || ved.date.DateYear > 2020);
				cout << "Введите предмет подачи заявления:";
					cin.ignore();
					cin.getline(ved.InfoAboutAffair, 15);
				cout << "Введите название фирмы позивача:";
					cin.getline(ved.position.NameDemandant, 15);
				cout << "Введите телефон фирмы позивача:"; 
					cin.getline(ved.phone.PhoneNumberDemandant, 15);
				cout << "Введите название фирмы обвинителя:";
					cin.getline(ved.position.NameAccuser, 15);
				cout << "Введите телефон фирмы обвинителя:";
					cin.getline(ved.phone.PhoneNumberAccuser, 15);
			fout.write((char*)&ved, sizeof(struct law));
		}	
	}
	fout.close();
	system("pause");
}
int main(){
	setlocale(LC_ALL, "Russian");
	int UserChoise;
	while(1){
		system("cls");
		cout << "Выберите пункт" << endl;
		cout << "1)Добавить информацию в базу данных" << endl;
		cout << "2)Посмотреть информацию, которая есть в базе данных" << endl;
		cout << "3)Посмотреть список фирм, на которых было заведено больше 2-ох дел" << endl;
		cout << "4)Удалить всю базу данных" << endl;
		cout << "5)Узнать сколько елемент находится в базе данных" << endl;
		cout << "6)Завершить программу" << endl;
		do{
			cout << "Введите число от 1 до 6(число - это пункт который хотите выполнить).Будьте внимательные нужно вводить число и адекватные значения, ввод:";
			cin.clear();
			cin.ignore();
			cin >> UserChoise;
		}while(!cin.good() || UserChoise > 6 || UserChoise < 1);
		switch(UserChoise){
			case 1:
				AddInfo();
				break;
			case 2:
				ShowInfo();
				break;
			case 3:
				ShowInfoAccordingVariant();
				break;
			case 4:
				DeleteInformation();
				break;
			case 5:
				AmountElement(ved);
				break;
			case 6:
				cout << "Вы уверены, что хотите завершить програму(1 - да, 0 - нет)" << endl;
				int FinishProgram;
				do{
					cout << "Будьте внимательные нужно вводить число и адекватные значения, ввод:";
					cin.clear();
					cin.ignore();
					cin >> FinishProgram;
			}while(!cin.good() || ( FinishProgram !=0 && FinishProgram !=1));
				if(FinishProgram){
					system("pause");
					return 0;
				}
				else{
					break;
				}
		}
	}	
	system("pause");
	return 0;
}

