#include <iostream>
#include <cstring>
using namespace std;

class Transport
{
	string type;
	string color;
	int speed;
	int fuelcons;
	int passenger;
public:
	Transport()
	{
		type = nullptr;
		color = "";
		speed = fuelcons = passenger = 0;
	}
	Transport(string t, string c, int s, int f, int p)
	{
		type = t;
		color = c;
		speed = s;
		fuelcons = f;
		passenger = p;
	}
	virtual void Show()
	{
		cout << "MaIIIina: " << type << endl;
		cout << "IIvet: " << color << endl;
		cout << "Skorost: " << speed << " km\\h\n";
		cout << "Rasxod topliva: " << fuelcons << " L\\100 km\n";
		cout << "Passajury " << passenger << endl;
	}
	virtual void Init()
	{
		cout << "MaIIIina: ";
		cin >> type;
		cout << "IIvet: ";
		cin >> color;
		cout << "Skorost: ";
		cin >> speed;
		cout << "Rasxod topliva: ";
		cin >> fuelcons;
		cout << "Passajury: ";
		cin >> passenger;
	}
	virtual int GetFuel()
	{
		return fuelcons;
	}

};
class Plane :public Transport
{
	string company;
public:
	Plane()
	{
		company = nullptr;
	}
	Plane(string t, string c, int s, int f, int p, string co) :Transport(t, c, s, f, p)
	{
		company = co;
	}
	void Show()
	{
		Transport::Show();
		cout << "Firma: " << company << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "Firma:";
		cin >> company;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
};

class Cycle :public Transport
{
	double tire_size;
public:
	Cycle()
	{
		tire_size = 0;
	}
	Cycle(string t, string c, int s, int f, int p, double ti) :Transport(t, c, s, 0, p)
	{
		tire_size = ti;
	}
	void Show()
	{
		Transport::Show();
		cout << "Diameter koles: " << tire_size << " sm\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "Razmer kolesa: ";
		cin >> tire_size;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
};

class Jeep :public Transport
{
	bool offroad;
public:
	Jeep()
	{
		offroad = false;
	}
	Jeep(string t, string c, int s, int f, int p, bool off) :Transport(t, c, s, f, p)
	{
		offroad = off;
	}
	void Show()
	{
		Transport::Show();
		if (offroad)
			cout << "Yedet po bezdorojiy\n";
		else
			cout << " Ne yedet po bezdorojiy\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "Dlya bezdorojia ?\t1.Da\t0.Net\n";
		cin >> offroad;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
};

class Ship :public Transport
{
	double carr_cap;
public:
	Ship()
	{
		carr_cap = 0;
	}
	Ship(string t, string c, int s, int f, int p, double cc) :Transport(t, c, s, f, p)
	{
		carr_cap = cc;
	}
	void Show()
	{
		Transport::Show();
		cout << "Gryzopodemnost: " << carr_cap << " toni\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "Gryzopodemnost: ";
		cin >> carr_cap;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
};

class Truck :public Transport
{
	int HP;
public:
	Truck()
	{
		HP = 0;
	}
	Truck(string t, string c, int s, int f, int p, int hp) :Transport(t, c, s, f, p)
	{
		HP = hp;
	}
	void Show()
	{
		Transport::Show();
		cout << "LoIIIadinaya sila : " << HP << "\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "LoIIIadinaya sila :";
		cin >> HP;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
};

int menu1()
{
	int choose;
	cout << "1.Samolet\n2.Velik\n3.Jeep\n4.Korabl\n5.Fura\n";
	cin >> choose;
	return choose;
}

int menu2()
{
	int choose;
	cout << "1.Pokazat \n2.Pokazat rashod na 100km\n";
	cin >> choose;
	return choose;
}

int main()
{
	int choose_1 = menu1();
	Transport* Tptr = nullptr;
	switch (choose_1)
	{
	case 1:
		Tptr = new Plane();
		Tptr->Init();
		break;
	case 2:
		Tptr = new Cycle();
		Tptr->Init();
		break;
	case 3:
		Tptr = new Jeep();
		Tptr->Init();
		break;
	case 4:
		Tptr = new Ship();
		Tptr->Init();
		break;
	case 5:
		Tptr = new Truck();
		Tptr->Init();
		break;
	default:
		break;
	}
	system("cls");
	int choose_2 = menu2();
	switch (choose_2)
	{
	case 1:
		Tptr->Show();
		break;
	case 2:
		cout << Tptr->GetFuel();
		break;
	default:
		break;
	}
	delete Tptr;
}