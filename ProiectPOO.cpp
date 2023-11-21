//domeniuInitiale = imagine; 3 obiecte = aparat foto, drone de filmare, proiector imagine
//atribute normale, constante si statice
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class AparatFoto {
private:
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
public:
	static float getTVA() {
		return TVA;
	}
	static void setTVA(float TvaNou) {
		TVA = TvaNou;
	}

	static void setCalcTva(float pret) {
		cout << pret * TVA;
	}
	AparatFoto() :id(0), tipAparat("DSLR") {
		this->model = " ";
		this->autonomie = 0;
		this->zoom = 0;
		this->pret = 0;
		this->marca = new char[strlen(" ") + 1];
		strcpy(this->marca, " ");
	}
	AparatFoto(const char* marca) :id(1), tipAparat("DSLR") {
		this->model = "Canon 4000 D";
		this->autonomie = 1400;
		this->zoom = 50;
		this->pret = 1500.50;
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}

	AparatFoto(const char* marca, int idNou, string tipAparatNou) :id(idNou), tipAparat(tipAparatNou) {
		this->model = "Sony A7";
		this->autonomie = 2400;
		this->zoom = 200;
		this->pret = 7000;
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}



	AparatFoto(const char* marca, int idNou, string tipAparatNou, string modelNou, int autonomieNoua, int zoomNou, float pretNou)
		:id(idNou), tipAparat(tipAparatNou), model(modelNou), autonomie(autonomieNoua), zoom(zoomNou), pret(pretNou) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);

	}

	AparatFoto(const AparatFoto& p) : id(p.id), tipAparat(p.tipAparat) {
		this->model = p.model;
		this->autonomie = p.autonomie;
		this->zoom = p.zoom;
		this->pret = p.pret;
		this->marca = new char[strlen(p.marca) + 1];
		strcpy(this->marca, p.marca);

	}

	~AparatFoto() {
		if (marca != NULL) {
			delete[]this->marca;
		}
	}

	AparatFoto operator=(const AparatFoto& p) {
		if (this != &p) {
			if (this->marca != NULL) {
				delete[]this->marca;
				this->model = p.model;
				this->autonomie = p.autonomie;
				this->zoom = p.zoom;
				this->pret = p.pret;
				this->marca = new char[strlen(p.marca) + 1];
				strcpy(this->marca, p.marca);
			}
			else this->marca = NULL;
		}
		return*this;
	}

	void afisare() {

		cout << " Tip: " << tipAparat << "Autonomie(cadre): "
			<< this->autonomie << ", Zoom optic pana la: " << this->zoom << "x " << ", Pretul: " << pret << " lei"
			<< ", Mufa incarcare: " << portIncarcare << ", Marca: " << marca;

	}

	const int getId() const {
		return id;
	}

	const string getTipAparat() const {
		return tipAparat;
	}

	void setModel(string model) {
		this->model = model;
	}
	string getModel() const {
		return model;
	}

	void setMarca(char* marca) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}

	char* getMarca() const {
		return marca;
	}

	int getAutonomie() const {
		return autonomie;
	}

	void setAutonomie(int autonomie) {
		this->autonomie = autonomie;
	}
	int getZoom() const {
		return zoom;
	}

	void setZoom(int zoom) {
		this->zoom = zoom;
	}
	void setPret(float p) {
		this->pret = pret;
	}

	float getPret() const {
		return pret;
	}

	friend float getPret1(AparatFoto a);
	friend string getModel1(AparatFoto b);
	friend ostream& operator<<(ostream& masina, const AparatFoto& aparat);
	friend istream& operator>>(istream& masina, AparatFoto& aparat) {
		if (aparat.marca != NULL) {

			cout << "Model: ";
			masina >> aparat.model;
			cout << "Marca: ";
			masina >> aparat.marca;
			cout << "Autonomie: ";
			masina >> aparat.autonomie;
			cout << "Zoom: ";
			masina >> aparat.zoom;
			cout << "Pret: ";
			masina >> aparat.pret;
		}
		return masina;
	}

	void operator+=(float addPret) {
		this->pret += addPret;
		return;
	}

	bool operator != (const AparatFoto& p) {
		if (this->model != p.model) {
			return true;
		}
		if (*marca != *p.marca) {
			return true;
		}
		if (this->autonomie != p.autonomie) {
			return true;
		}
		if (this->zoom != p.zoom) {
			return true;
		}
		if (this->pret != p.pret) {
			return true;
		}
		return false;
	}

	string operator >(const AparatFoto& p) {
		if (this->pret > p.pret) {
			string S = "Aparatul e mai scump decat altul";
			return S;
		}
		else {
			string S = "Aparatul e mai ieftin decat altul";
			return S;
		}

	}
};



ostream& operator<<(ostream& masina, const AparatFoto& aparat) {
	if (aparat.marca != NULL) {
		masina << "\nId: " << aparat.getId() << "\n" << aparat.getTipAparat();
			
		masina << "\nModel: " << aparat.getModel() << "\nMarca: "
			<< aparat.getMarca() << "\nAutonomie: " << aparat.getAutonomie() << "\nZoom: " << aparat.getZoom() << "\nPret: " << aparat.pret;
	}
	return masina;
}

float getPret1(AparatFoto a) {
	if (a.pret < 2000) {
		cout << " Aparatul este in bugetul clientului ,";
	}
	return a.pret;
}
string getModel1(AparatFoto b) {
	if (b.model == "Canon 4000 D") {
		return b.model;
	}
	//return b.model;
}
string AparatFoto::portIncarcare = "Type C";
float AparatFoto::TVA = 0.19;

class CardMemorie {
private:
	char* producator;
	int memorie;
	AparatFoto aparatFoto;
public:
	CardMemorie(int memorie, const char* producator, const AparatFoto& aparat) :memorie(memorie), aparatFoto(aparat) {
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	};
	~CardMemorie() {
		if (this->producator != NULL) {
			delete[]this->producator;
		}
	}
	CardMemorie(const CardMemorie& c)  {
		this->producator = new char[strlen(c.producator) + 1];
		strcpy_s(this->producator, strlen(c.producator) + 1, c.producator);
		this->memorie = c.memorie;
		aparatFoto = c.aparatFoto;
	}
	CardMemorie operator= (const CardMemorie& c) {
		this->producator = new char[strlen(c.producator) + 1];
		strcpy_s(this->producator, strlen(c.producator) + 1, c.producator);
		aparatFoto = c.aparatFoto;
		return *this;
	}
	char* getProducator() {
		return producator;
	}
	void setProducator(char* producator) {
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	}
	int getMemorie() {
		return memorie;
	}
	void setMemorie(int memorie) {
		this->memorie = memorie;
	}

	void setAparatFoto(AparatFoto aparat) {
		aparatFoto = aparat;
	}
	AparatFoto getAparatFoto() {
		return aparatFoto;
	}

	friend ostream& operator<<(ostream& out, const CardMemorie& card) {
		out << "Capacitate card: " << card.memorie << " GB\nTip card: " << card.producator;
		 {
			out << "\nAparat asociat:\n" << (card.aparatFoto);
		}
		return out;
	}
	char& operator[](int index) {
		return this->producator[index];
		return this->producator[0];
	}
	CardMemorie operator++() {
		this->memorie++;
		return *this;
	}
	CardMemorie operator++(int) {
		CardMemorie aux = *this;
		this->memorie++;
		return aux;
	}
};

class Drona {
private:
	static int perioadaRetur;
	const int id;
	const float greutate;
	char* model;
	string rezolutieCamera;
	float autonomie;
	string conectivitate;
	float altitudineZbor;
	

public:
	static int getPerioadaRetur() {
		return perioadaRetur;
	}
	void setPerioadaRetur(int perioadaRetur) {
		this->perioadaRetur = perioadaRetur;
	}
	static int returnarePosibila(int posesieClient) {
		if (posesieClient < perioadaRetur)
			cout << "Se poate face returul, clientul are produsul de: ";
		else
			cout << "Nu se mai poate face returul,clientul are produsul deja de: ";
		return posesieClient;
	}
	const int getId() const {
		return id;
	}
	const float getGreutate() const {
		return greutate;
	}
	void setModel(char* model) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
	}
	char* getModel() const {
		return model;
	}
	string getRezolutieCamera() const {
		return rezolutieCamera;
	}
	void setRezolutieCamera(string rezluitaCamera) {
		this->rezolutieCamera = rezolutieCamera;
	}

	float getAutonomie() const {
		return autonomie;
	}
	void setAutonomie() {
		this->autonomie = autonomie;
	}
	string getConectivitate() const {
		return conectivitate;
	}
	void setAltitudineZbor(float altitudineZbor) {
		this->altitudineZbor = altitudineZbor;
	}
	float getAltitudineZbor() const {
		return altitudineZbor;
	}
	Drona() :id(0), greutate(500.60) {
		this->model = new char[strlen(" ") + 1];
		strcpy(this->model, " ");
		rezolutieCamera = " ";
		autonomie = 0;
		conectivitate = " ";
		altitudineZbor = 0;
	}

	Drona(const char* model) :id(1), greutate(650.8) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		rezolutieCamera = "4k";
		autonomie = 1.3;
		conectivitate = "Wi-Fi 5G ";
		altitudineZbor = 825.5;
	}

	Drona(const char* model, int idNou, float greutateNoua, string rezolutieCameraNoua) :
		id(idNou), greutate(greutateNoua), rezolutieCamera(rezolutieCameraNoua) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		autonomie = 0.3;
		conectivitate = "Wi-Fi 4 ";
		altitudineZbor = 600;
	}

	Drona(const char* model, int idNou, float greutateNoua, string rezolutieCameraNoua, float autonomieNoua) : id(idNou),
		greutate(greutateNoua), rezolutieCamera(rezolutieCameraNoua), autonomie(autonomieNoua) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		conectivitate = "Wi-Fi 4 ";
		altitudineZbor = 450;
	}
	Drona(const Drona& p) :id(p.id), greutate(p.greutate) {
		this->model = new char[strlen(p.model) + 1];
		strcpy(this->model, p.model);
		this->rezolutieCamera = p.rezolutieCamera;
		this->autonomie = p.autonomie;
		this->conectivitate = p.autonomie;
		this->altitudineZbor = p.altitudineZbor;
	}
	Drona operator=(const Drona& p) {
		if (this != &p) {
			if (this->model != NULL) {
				delete[]this->model;
				//ce fac cu atributele constante
				this->rezolutieCamera = p.rezolutieCamera;
				this->autonomie = p.autonomie;
				this->conectivitate = p.conectivitate;
				this->altitudineZbor = p.altitudineZbor;
				this->model = new char[strlen(p.model) + 1];
				strcpy(this->model, p.model);
			}
			else this->model = NULL;
		}
		return *this;

	}
	bool operator ==(const Drona& d) {
		if (*model != *d.model) {
			return false;
		}
		else return true;
	}
	bool operator >=(const Drona& d) {
		if (this->altitudineZbor >= d.altitudineZbor) {
			return true;
		}
		else {
			return false;
		}
	}

	~Drona() {
		if (altitudineZbor != NULL) {
			delete[]this->model;

		}
	}

	void afisare() {
		cout << " Modelul: " << model << ", Are rezolutia: " << rezolutieCamera << ", O autonomie de: "
			<< autonomie << " de h" << ", Conectivitate: " << conectivitate << ", Altitudine maxima zbor: "
			<< altitudineZbor << ", O greutate de: " << greutate << endl;
	}
	friend istream& operator>>(istream& masina, Drona& drona);
	friend ostream& operator<<(ostream& masina, const Drona& drona) {
		if (drona.model != NULL) {
			masina << "\nId: " << drona.getId() << "\nGreutate: " << drona.getGreutate() << "\nModel:" << drona.getModel() << "\nRezolutie: "
				<< drona.getRezolutieCamera() << "\nAutonomie: " << drona.getAutonomie() << " h" << "\nConectivitate: " << drona.getConectivitate()
				<< "\nAltitudine zbor:" << drona.getAltitudineZbor();
		}
		return masina;
	}
	char& operator[](int index) {
		return this->model[index];
		return this->model[0];
	}

};
int Drona::perioadaRetur = 30;

istream& operator>>(istream& masina, Drona& drona) {
	if (drona.model != NULL) {
		cout << "Model: ";
		masina >> drona.model;
		cout << "Rezolutie: ";
		masina >> drona.rezolutieCamera;
		cout << "Autonomie: ";
		masina >> drona.autonomie;
		cout << "Conectivitatea: ";
		masina >> drona.altitudineZbor;
	}
	return masina;


};


class Proiector {
private:
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
public:
	static string getMufaConectare() {
		return mufaConectare;
	}
	void setMufaConectare(string mufaConectare) {
		this->mufaConectare = mufaConectare;
	}
	string getSePoateConecta(string mufaClient) {
		if (mufaClient == mufaConectare)
			cout << "Se poate conecta la proiecor: ";
		else
			cout << "Are nevoie de adaptor: ";
		return mufaConectare;
	}

	const int getId() const {
		return id;
	}
	const string getRezolutie() const {
		return rezolutie;
	}
	void setModel(char* model) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
	}
	char* getModel() const {
		return model;
	}
	void setMarca(char* marca) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}
	char* getMarca() const {
		return marca;
	}
	int getContrast() const {
		return contrast;
	}
	void setContrast(int contrast) {
		this->contrast = contrast;
	}
	int getNrLumeni() const {
		return nrLumeni;
	}
	void SetNrLumeni(int nrLumeni) {
		this->nrLumeni = nrLumeni;
	}
	float getPret() const {
		return pret;
	}
	void setPret(float pret) {
		this->pret = pret;
	}
	Proiector() :id(0), rezolutie("") {
		this->model = new char[strlen(" ") + 1];
		strcpy(this->model, " ");
		this->marca = new char[strlen(" ") + 1];
		strcpy(this->marca, " ");
		this->contrast = 0;
		this->nrLumeni = 0;
		this->pret = 0;
	}

	Proiector(const char* model, const char* marca) :id(1), rezolutie("4K") {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		contrast = 1000;
		nrLumeni = 13000;
		pret = 1888.9;
	}

	Proiector(const char* model, const char* marca, int idNou, string rezolutieNoua, float pretNou)
		: id(idNou), rezolutie(rezolutieNoua), pret(pretNou)
	{
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		contrast = 4000;
		nrLumeni = 8000;
	}

	Proiector(const char* model, const char* marca, int idNou, string rezolutieNoua, int contrastNou, int nrLumeniNou, float pretNou) :id(idNou),
		rezolutie(rezolutieNoua), contrast(contrastNou), nrLumeni(nrLumeniNou), pret(pretNou) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}
	Proiector(const Proiector& p) :id(p.id), rezolutie(p.rezolutie) {
		this->model = new char[strlen(p.model) + 1];
		strcpy(this->model, p.model);
		this->marca = new char[strlen(p.marca) + 1];
		strcpy(this->marca, p.marca);
		this->contrast = p.contrast;
		this->nrLumeni = p.nrLumeni;
		this->pret = p.pret;

	}
	Proiector operator=(const Proiector& p) {
		if (this != &p) {
			if (this->model != NULL) {
				delete[]this->model;
				delete[]this->marca;
				this->model = new char[strlen(p.model) + 1];
				strcpy(this->model, p.model);
				this->marca = new char[strlen(p.marca) + 1];
				strcpy(this->marca, p.marca);
				this->contrast = p.contrast;
				this->nrLumeni = p.nrLumeni;
				this->pret = p.pret;
			}
			else this->model = NULL;
		}
		return *this;
	}


	~Proiector() {
		if (contrast != NULL) {
			delete[]this->marca;
		}
	}

	void afisare() {
		cout << " Model: " << model << ", Marca: " << marca << " ,Contrast: " << contrast << " la 1" << ", Rezolutie: "
			<< rezolutie << " , Nr Lumeni: " << nrLumeni << ", Pret: " << pret << endl;
	}
	friend float discount(Proiector a);
	friend float TVA(Proiector b);
	friend string incadreareBuget(Proiector b, int salariu);
	friend ostream& operator<<(ostream& masina, const Proiector& proiector);
	friend istream& operator>>(istream& masina, Proiector& proiector)
	{
		if (proiector.model != NULL && proiector.marca != NULL) {
			cout << "Marca: ";
			masina >> proiector.model;
			cout << "Model: ";
			masina >> proiector.marca;
			cout << "Contrast: ";
			masina >> proiector.contrast;
			cout << "Nr Lumeni: ";
			masina >> proiector.nrLumeni;
			cout << "Pret: ";
			masina >> proiector.pret;
		}
		else {
			cout << "Nu exista marca si modelul proiectorului";
			proiector.model = NULL;
			proiector.marca = NULL;
		}
		return masina;
	}
	/*Proiector operator+(const Proiector& p) {
		Proiector aux ;
		*aux.model = *model + *p.model;
		*aux.marca = *marca + *p.marca;
		aux.contrast = this->contrast + p.contrast;
		aux.nrLumeni = this->nrLumeni + p.nrLumeni;
		aux.pret = this->pret + p.pret;
		return aux;
	}*/
	void operator++()
	{
		++this->nrLumeni;
		return;
	}
	bool operator <= (const Proiector& p) {
		if (this->nrLumeni <= p.nrLumeni) {
			return true;
		}
		else return false;
	}
};

ostream& operator<<(ostream& masina, const Proiector& proiector)
{
	masina << "\nId: " << proiector.getId() << "\nRezolutie: " << proiector.getRezolutie();
	if (proiector.model != NULL && proiector.marca != NULL) {
		masina << "\nModel: " << proiector.getModel() << "\nMarca: " << proiector.getMarca() << "\nContrast: "
			<< proiector.getContrast() << "\nNr lumeni: " << proiector.getNrLumeni() << "\nPret: " << proiector.getPret();
	}
	else {
		masina << "-";
	}
	masina << "\n------------------------------------------------------------------------------------" << endl;
	return masina;
}

float discount(Proiector a) {
	float valoareFinala = 0;
	valoareFinala = 0.8 * a.getPret();
	return valoareFinala;
}

float TVA(Proiector b) {
	float valoareFinala = 0;
	valoareFinala = 0.19 * b.getPret();
	return valoareFinala;
}

string incadrareBuget(Proiector b, int salariu) {
	string decizie;
	if (salariu >= 4 * b.getPret()) {
		decizie = "Si-l permite.";
	}
	else {
		decizie = "Nu si-l permite";
	}
	return decizie;
}

string Proiector::mufaConectare = "HDMI";

void main() {

	//clasa 1 Aparat Foto
	AparatFoto aparat1("Canon");
	AparatFoto* v_aparat = new AparatFoto[3];
	AparatFoto* pointerAparat = new AparatFoto();
	int dimVector = 3;
	//vector
	//for (int i = 0; i < dimVector; i++) {
	//	cin >> v_aparat[i];
	//	cout << "\n-----------"<<endl;
	//}
	//for (int i = 0; i < dimVector; i++) {
	//	cout<< v_aparat[i];
	//	cout << "\n-----------" << endl;
	//}
	//delete[]v_aparat;
	////matrice
	//int linii = 2;
	//int coloane = 2;

	//AparatFoto** matrice = new AparatFoto*[linii];
	//for (int i = 0; i < linii; i++) {
	//	matrice[i] = new AparatFoto[coloane];
	//}
	//for (int i = 0; i < linii; i++) {
	//	for (int j = 0; j < coloane; j++) {
	//		cout << "Valoare matrice [" << i << "]["<< j <<"]"<<endl;
	//		cin >> matrice[i][j];
	//	}
	//}
	//for (int i = 0; i < linii; i++) {
	//	for (int j = 0; j < coloane; j++) {
	//		cout<<matrice[i][j];
	//	}
	//}
	//for (int i = 0; i < linii; i++) {
	//	delete[] matrice[i];
	//}
	//delete[]matrice;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	cout << "\nCARD MEMORIE" << endl;
	CardMemorie card(3, "samsung",aparat1);
	cout << "\nOperator <<\n";
	cout << card;
	cout << "\n------------------------------------------------------------------------------------"<<endl;
	cout << "\nOperator index";
	cout << "\nProducator: " << card.getProducator();
	card[0] = 'X';
	cout << "\nProducator: "<<card.getProducator();
	cout << "\n------------------------------------------------------------------------------------" << endl;
	cout << "\nOperatori++"<<endl;
	cout << "Memorie initiala: "<<card.getMemorie() << endl;
	card++;
	cout << "card++: "<<card.getMemorie() << endl;
	++card;
	cout << "++card: "<<card.getMemorie() << endl;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	CardMemorie card1(card);
	cout << "\nConstructor copiere"<<endl;
	cout << card1;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	AparatFoto aparat2("Sony", 2, "DSLR");
	CardMemorie card2(4, "Humus", aparat2);
	cout << "\nOperator =" << endl;
	card1 = card2;
	cout << card1;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "APARAT" << endl;
	cout << "\nId: " << aparat1.getId() << "\nTip: " << aparat1.getTipAparat() << "\nModelul: " << aparat1.getModel() << "\nMarca: "
		<< aparat1.getMarca() << "\nAutonomie: " << aparat1.getAutonomie() << " de cadre " << "\nZoom :" << aparat1.getZoom() << "\nUn pret de: " << aparat1.getPret()
		<< "\nTva calc: ";
	aparat1.setCalcTva(1500.50);
	cout << "\nModelul aparatului este? " << getModel1(aparat1);
	cout << "\n------------------------------------------------------------------------------------";;

	cout << endl << getPret1(aparat2);
	cout << "\nId: " << aparat2.getId() << "\nTip: " << aparat2.getTipAparat() << "\nModelul: " << aparat2.getModel() << "\nMarca: "
		<< aparat2.getMarca() << "\nAutonomie: " << aparat2.getAutonomie() << " de cadre " << "\nZoom :" << aparat2.getZoom() << "\nUn pret de: " << aparat2.getPret();
	cout << "\n------------------------------------------------------------------------------------";

	AparatFoto aparat3("Nikon", 3, "DSLR", "Nikon 12A", 4000, 175, 7000);
	cout << "\nId: " << aparat3.getId() << "\nTip: " << aparat3.getTipAparat() << "\nModelul: " << aparat3.getModel() << "\nMarca: "
		<< aparat3.getMarca() << "\nAutonomie: " << aparat3.getAutonomie() << " de cadre " << "\nZoom :" << aparat3.getZoom() << "\nUn pret de: " << aparat3.getPret();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	AparatFoto aparat4(aparat1);
	cout << "Apel constructor copiere\n";
	cout << "\nId: " << aparat4.getId() << "\nTip : " << aparat4.getTipAparat() << "\nModelul : " << aparat4.getModel() << "\nMarca : "
		<< aparat4.getMarca() << "\nAutonomie: " << aparat4.getAutonomie() << " de cadre " << "\nZoom :" << aparat4.getZoom() << "\nUn pret de: " << aparat4.getPret();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "Apel operator =\n";
	aparat2 = aparat1;
	cout << "\nModelul: " << aparat2.getModel() << "\nMarca: "
		<< aparat2.getMarca() << "\nAutonomie: " << aparat2.getAutonomie() << " de cadre " << "\nZoom :" << aparat2.getZoom() << "\nUn pret de: " << aparat2.getPret();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "Operator +=\n";
	aparat4 += 700;
	cout << aparat4;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	cout << "Operator !=\n\n";
	cout << (aparat2 != aparat3);
	cout << "\n------------------------------------------------------------------------------------" << endl;
	cout << "Operator >\n\n";
	cout << (aparat3 > aparat2);
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "DRONA" << endl;

	/*Drona* v_drona = new Drona[3];
	for (int i = 0; i < dimVector; i++) {
		cin >> v_drona[i];
		cout << "\n-----------" << endl;
	}
	for (int i = 0; i < dimVector; i++) {
		cout << v_drona[i];
		cout << "\n-----------" << endl;
	}
	delete[]v_drona;*/

	Drona drona1("SG906 PRO Max");
	drona1.setPerioadaRetur(29);
	cout << "\nId: " << drona1.getId() << "\nGreutate: " << drona1.getGreutate() << "\nModel: " << drona1.getModel() << "\nRezolutie camera: "
		<< drona1.getRezolutieCamera() << "\nAutonomie: " << drona1.getAutonomie() << "\nConectivitate: " << drona1.getConectivitate() << "\nAltitudine zbor: " << drona1.getAltitudineZbor();
	cout << "\n" << Drona::returnarePosibila(21) << " zile";
	cout << "\n------------------------------------------------------------------------------------";

	Drona drona2("FR 11", 2, 657.5, "4k");
	cout << "\nId: " << drona2.getId() << "\nGreutate: " << drona2.getGreutate() << "\nModel: " << drona2.getModel() << "\nRezolutie camera: "
		<< drona2.getRezolutieCamera() << "\nAutonomie: " << drona2.getAutonomie() << "\nConectivitate: " << drona2.getConectivitate() << "\nAltitudine zbor: " << drona2.getAltitudineZbor();
	cout << "\n" << Drona::returnarePosibila(21) << " zile";
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Drona drona3("HouDeOS", 3, 500.3, "2k", 0.24);
	cout << "Id: " << drona3.getId() << "\nGreutate: " << drona3.getGreutate() << "\nModel: " << drona3.getModel() << "\nRezolutie camera: "
		<< drona3.getRezolutieCamera() << "\nAutonomie: " << drona3.getAutonomie() << "\nConectivitate: " << drona3.getConectivitate() << "\nAltitudine zbor: " << drona3.getAltitudineZbor();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Drona drona4(drona1);
	cout << "Apel constructor copiere\n";
	cout << "\nId: " << drona4.getId() << "\nGreutate: " << drona4.getGreutate() << "\nModel: " << drona4.getModel() << "\nRezolutie camera: "
		<< drona4.getRezolutieCamera() << "\nAutonomie: " << drona4.getAutonomie() << "\nConectivitate: " << drona4.getConectivitate() << "\nAltitudine zbor: " << drona4.getAltitudineZbor();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "Apel operator=\n";
	drona3 = drona1;
	cout << "\nModel: " << drona3.getModel() << "\nRezolutie camera: "
		<< drona3.getRezolutieCamera() << "\nAutonomie: " << drona3.getAutonomie() << "\nConectivitate: " << drona3.getConectivitate() << "\nAltitudine zbor: " << drona3.getAltitudineZbor();

	cout << "\n------------------------------------------------------------------------------------";
	cout << "\nOperator ==\n\n";
	cout << (drona2 == drona1);
	cout << "\n------------------------------------------------------------------------------------" << endl;
	drona2[1] = 'W';
	cout << "\nOperator schimbare litera\n" << drona2;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	cout << "\nOperator >=\n";
	cout << (drona2 >= drona1);
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "\nPROIECTOR\n" << endl;

	Proiector* v_proiector = new Proiector[3];
	/*for (int i = 0; i < dimVector; i++) {
		cin >> v_proiector[i];
		cout << "\n-----------" << endl;
	}
	for (int i = 0; i < dimVector; i++) {
		cout << v_proiector[i];
		cout << "\n-----------" << endl;
	}*/
	//delete[]v_proiector;

	Proiector proiector1("SW 10", "SUREWHELL");
	proiector1.setMufaConectare("VGA");
	cout << "\n" << proiector1.getSePoateConecta("HDMI");
	cout << "\nPret aplicare discount: " << discount(proiector1);
	cout << "\nId: " << proiector1.getId() << "\nRezolutie: " << proiector1.getRezolutie() << "\nModel: " << proiector1.getModel() << "\nMarca: " << proiector1.getMarca() << "\nContrast:"
		<< proiector1.getContrast() << "\nNr Lumeni: " << proiector1.getNrLumeni() << "\nPret: " << proiector1.getPret();;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Proiector proiector2("YG430 WiFi", "Loosafe", 2, "Full-HD", 800.5);
	int salariu = 5000;
	string itiPermiti = incadrareBuget(proiector2, salariu);
	cout << "TVA Produs: " << TVA(proiector2);
	cout << "\nId: " << proiector2.getId() << "\nRezolutie: " << proiector2.getRezolutie() << "\nModel: " << proiector2.getModel() << "\nMarca: " << proiector2.getMarca() << "\nContrast:"
		<< proiector2.getContrast() << "\nNr Lumeni: " << proiector2.getNrLumeni() << "\nPret: " << proiector2.getPret();
	cout << "\nSe incadreaza in buget? " << itiPermiti;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Proiector proiector3("WowStep M", "Wowstep", 3, "HD", 2000, 7000, 995.7);
	cout << "Id: " << proiector3.getId() << "\nRezolutie: " << proiector3.getRezolutie() << "\nModel: " << proiector3.getModel() << "\nMarca: " << proiector3.getMarca() << "\nContrast:"
		<< proiector3.getContrast() << "\nNr Lumeni: " << proiector3.getNrLumeni() << "\nPret: " << proiector3.getPret();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Proiector proiector4(proiector1);
	cout << "Apel constructor copiere\n";
	cout << "\nModel: " << proiector4.getModel() << "\nMarca: " << proiector4.getMarca() << "\nContrast:"
		<< proiector4.getContrast() << "\nNr Lumeni: " << proiector4.getNrLumeni() << "\nPret: " << proiector4.getPret();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "Apel operator = \n";
	proiector2 = proiector1;
	cout << "\nModel: " << proiector2.getModel() << "\nMarca: " << proiector2.getMarca() << "\nContrast:"
		<< proiector2.getContrast() << "\nNr Lumeni: " << proiector2.getNrLumeni() << "\nPret: " << proiector2.getPret();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "Apel operator<<\n" << proiector2;
	++proiector4;
	cout << "Operator ++\n" << proiector4;

	cout << "Apel operator <\n";
	cout << (proiector4 <= proiector2);

	//Proiector proiector5("WowStep M", "Wowstep", 3, "HD", 2000, 7000, 995.7);
	//proiector5 = proiector1 + proiector3;
	//cout << "\nOperator +";
	//cout<<"\nContrast:"<< proiector5.getContrast() << "\nNr Lumeni: " << proiector5.getNrLumeni() << "\nPret: " << proiector5.getPret();

}
