//domeniuInitiale = imagine; 3 obiecte = aparat foto, drone de filmare, proiector imagine
//atribute normale, constante si statice
#include <iostream>
using namespace std;

class AparatFoto{
public:
	static string portIncarcare;
	static float TVA;
	static float calcTVA(float a) {
		return a * TVA;
	}

	const int id;
	const string tipAparat;
	string model;
	char* marca;
	int autonomie;
	int zoom;
	float pret;

	AparatFoto() :id(1), tipAparat("DSLR") {
		this->model = "Canon 4000 D";
		this->marca = new char[strlen("Canon") + 1];
		strcpy_s(marca, strlen("Canon")+ 1, "Canon");
		this->autonomie = 1400;
		this->zoom = 50;
		this->pret = 1500.50;
	}

	AparatFoto(int idNou,string tipAparatNou) :id(idNou), tipAparat(tipAparatNou){
		this->model = "Sony A7";
		this->marca = new char[strlen("Sony") + 1];
		strcpy_s(marca, strlen("Sony") + 1, "Sony");
		this->autonomie = 2400;
		this->zoom = 200;
		this->pret = 7000;
	}

	AparatFoto(int idNou, string tipAparatNou, string modelNou, int autonomieNoua,int zoomNou, float pretNou) 
		:id(idNou), tipAparat(tipAparatNou), model(modelNou),autonomie(autonomieNoua), zoom(zoomNou), pret(pretNou) {
		this->marca = new char[strlen("Nikon") + 1];
		strcpy_s(marca, strlen("Nikon") + 1, "Nikon");
	}

	~AparatFoto() {
		if (id != NULL) {
			delete[]this->marca;
		}
	}

	void afisare() {
		
		cout << ", Tip: " << tipAparat << ", Model: " << this->model << ", Marca: " << this->marca << ", Autonomie(cadre): " 
			<<this->autonomie << ", Zoom optic pana la: " << this->zoom << "x " << ", Pretul: " << pret << " lei" 
			<< ", Mufa incarcare: " << portIncarcare << endl;
	}
};

string AparatFoto::portIncarcare = "Type C";
float AparatFoto::TVA = 0.19;



class Drona {
	public:
	static int perioadaRetur;
	static int returnarePosibila(int posesieClient) {
		if (posesieClient < perioadaRetur) 
			cout << "Se poate face returul, clientul are produsul de: ";
		else
			cout << "Nu se mai poate face returul,clientul are produsul deja de: ";
		return posesieClient;
	}

	const int id;
	const float greutate;
	char* model;
	string rezolutieCamera;
	float autonomie;
	string conectivitate;
	float altitudineZbor;

	Drona() :id(1), greutate(650.8) {
		model = new char[strlen("SG906 PRO Max") + 1];
		strcpy_s(model, strlen("SG906 PRO Max") + 1, ("SG906 PRO Max"));
		rezolutieCamera = "4k";
		autonomie = 1.3;
		conectivitate = "Wi-Fi 5G ";
		altitudineZbor = 825.5;
	}

	Drona(int idNou,float greutateNoua,string rezolutieCameraNoua):
		id(idNou), greutate(greutateNoua), rezolutieCamera(rezolutieCameraNoua){
		model = new char[strlen("F11 RC") + 1];
		strcpy_s(model, strlen("F11 RC") + 1, ("F11 RC"));
		autonomie =  0.3 ;
		conectivitate = "Wi-Fi 4 ";
		altitudineZbor = 600;
	}

	Drona(int idNou, float greutateNoua, string rezolutieCameraNoua,float autonomieNoua) : id(idNou),
		greutate(greutateNoua), rezolutieCamera(rezolutieCameraNoua), autonomie(autonomieNoua) {
		model = new char[strlen("DJI mini 3") + 1];
		strcpy_s(model, strlen("DJI mini 3") + 1, ("DJI mini 3"));
		conectivitate = "Wi-Fi 4 ";
		altitudineZbor = 450;
	}

	~Drona() {
		if (altitudineZbor != NULL) {
			delete[]this->model;
		
		}
	}

	void afisare() {
		cout << " Modelul: " << model << ", Are rezolutia: " << rezolutieCamera << ", O autonomie de: " 
			<< autonomie << " de h" << ", Conectivitate: "<< conectivitate << ", Altitudine maxima zbor: " 
			<< altitudineZbor << ", O greutate de: "<< greutate<<endl;
	}
};

int Drona::perioadaRetur = 30;



class Proiector {
public:
	static string mufaConectare;
	static string sePoateConecta(string mufaClient) {
		if (mufaClient == mufaConectare) 
			cout << " Se poate conecta la proiecor: ";
		else 
		    cout << " Are nevoie de adaptor: ";
		return mufaConectare;
		
	};
	const int id;
	const string rezolutie;
	char* model;
	char* marca;
	int contrast;
	int nrLumeni;
	float pret;

	Proiector() :id(1),rezolutie("4K") {
		model = new char[strlen("SW 10") + 1];
		strcpy_s(model, strlen("SW 10") + 1, ("SW 10"));
		marca = new char[strlen("SUREWHELL") + 1];
		strcpy_s(marca, strlen("SUREWHELL") + 1, ("SUREWHELL"));
		contrast = 1000;
		nrLumeni = 13000;
		pret = 1888.9;
	}

	Proiector(int idNou, string rezolutieNoua, float pretNou) 
		: id(idNou), rezolutie(rezolutieNoua), pret(pretNou) {
		this->model = new char[strlen("YG430 WiFi") + 1];
		strcpy_s(model, strlen("YG430 WiFi") + 1, ("YG430 WiFi"));
		this->marca = new char[strlen("Loosafe") + 1];
		strcpy_s(marca, strlen("Loosafe") + 1, ("Loosafe"));
		contrast = 4000;
		nrLumeni = 8000;
	}

	Proiector(int idNou, string rezolutieNoua, int contrastNou, int nrLumeniNou, float pretNou) :id(idNou),
		rezolutie(rezolutieNoua), contrast(contrastNou), nrLumeni(nrLumeniNou), pret(pretNou){
		this->model = new char[strlen("WowStep M") + 1];
		strcpy_s(model, strlen("WowStep M") + 1, ("WowStep M"));
		this->marca = new char[strlen("WowStep") + 1];
		strcpy_s(marca, strlen("WowStep") + 1, ("Wowstep"));
	}

	~Proiector() {
		if (contrast != NULL) {
			delete[]this->model;
			delete[]this->marca;
		}
	}

	void afisare() {
		cout << " Model: " << model << ", Marca: " << marca << " ,Contrast: " << contrast << " la 1" << ", Rezolutie: " 
			<< rezolutie << " , Nr Lumeni: " << nrLumeni << ", Pret: " << pret<<endl;
	}

};

string Proiector::mufaConectare = "HDMI";

void main() {
	//clasa 1 Aparat Foto
	AparatFoto aparat1;
	cout <<"TVA-ul primului produs: " <<AparatFoto::calcTVA(1500.50);
	aparat1.afisare();
	AparatFoto aparat2(2, "DSLR");
	aparat2.afisare();
	AparatFoto aparat3(3, "DSLR","Nikon D7500",4000,175,7000);
	aparat3.afisare();
	//clasa 2 Drone de Filmat
	Drona drona1;
	drona1.afisare();
	cout <<Drona::returnarePosibila(31)<<" zile";
	Drona drona2(2 ,657.5,"4k");
	drona2.afisare();
	Drona drona3(3, 500.3, "2k", 0.24);
	drona3.afisare();
	//clasa 3 videoproiectoare
	Proiector proiector1;
	proiector1.afisare();
	cout << Proiector::sePoateConecta("VGA");
	Proiector proiector2(2,"Full-HD",800.5);
	proiector2.afisare();
	Proiector proiector3(2,"HD",2000,7000,995.7);
	proiector3.afisare();
}