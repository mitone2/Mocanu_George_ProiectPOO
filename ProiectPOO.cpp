
//domeniuInitiale = imagine; 3 obiecte = aparat foto, drone de filmare, proiector imagine
//atribute normale, constante si statice
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

class ConcursFotografie {
public:
	virtual void afisareDescriere() = 0;
};

class AparatFoto : public ConcursFotografie {
private:
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
	void afisareDescriere() {
		cout << "Aparatul foto,modelul : " << this->getModel() << endl;
	}
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
		this->model = "////";
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
			<< ", Marca: " << marca;

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

	virtual char* getMarca() const {
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

	friend ofstream& operator<<(ofstream& fisier, const AparatFoto& aparat) {
		if (aparat.marca != NULL) {
			fisier << aparat.model << endl << aparat.marca << endl << aparat.autonomie << endl << aparat.zoom << endl << aparat.pret;
			fisier << endl;
		}
		return fisier;
	}
	friend ifstream& operator>>(ifstream& fisier, AparatFoto& aparat) {
		if (aparat.marca != NULL) {
			delete[]aparat.marca;
		}
		fisier >> aparat.model;
		char aux[30];
		fisier >> aux;
		aparat.marca = new char[strlen(aux) + 1];
		strcpy_s(aparat.marca, strlen(aux) + 1, aux);
		fisier >> aparat.autonomie;
		fisier >> aparat.zoom;
		fisier >> aparat.pret;
		return fisier;
	}
};

ostream& operator<<(ostream& masina, const AparatFoto& aparat) {
	if (aparat.marca != NULL) {
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
float AparatFoto::TVA = 0.19;

class AparatFotoDSLR : public AparatFoto {
private:
	int nrTipPoze;
	string* formatPoze;
public:
	string getModel() {
		return "Model: " + AparatFoto::getModel();
	}

	int getNrTipPoze() {
		return nrTipPoze;
	}
	void setNrAparat(int nrAparat) {
		this->nrTipPoze = nrAparat;
	}
	string* FormatPoze() {
		return formatPoze;
	}
	void setTipSenzor(string* formatPoze) {
		for (int i = 0; i < getNrTipPoze(); i++) {
			this->formatPoze[i] = formatPoze[i];
		}
	}
	AparatFotoDSLR() :AparatFoto("Suprem") {
		this->nrTipPoze = 0;
		this->formatPoze = NULL;
	}
	AparatFotoDSLR(int nrTipPoze, string* formatPoze) :AparatFoto("Salut", 2, "DSLR") {
		this->nrTipPoze = nrTipPoze;
		this->formatPoze = new string[nrTipPoze];
		for (int i = 0; i < nrTipPoze; i++) {
			this->formatPoze[i] = formatPoze[i];
		}
	}
	~AparatFotoDSLR() {
		if (this->nrTipPoze != NULL) {
			delete[]this->formatPoze;
		}
	}
	AparatFotoDSLR(const AparatFotoDSLR& a) :AparatFoto(a) {
		this->nrTipPoze = a.nrTipPoze;
		this->formatPoze = new string[a.nrTipPoze];
		for (int i = 0; i < nrTipPoze; i++) {
			this->formatPoze[i] = a.formatPoze[i];
		}
	}
	AparatFotoDSLR operator=(const AparatFotoDSLR& a) {
		if (this != &a) {
			AparatFoto::operator=(a);
			this->formatPoze = new string[a.nrTipPoze];
			for (int i = 0; i < nrTipPoze; i++) {
				this->formatPoze[i] = a.formatPoze[i];
			}
		}
		return *this;
	}
	void afisareDescriere() {
		cout << "Modelul de aparat: " << this->getModel() << ". " << "Nr tipului de poze: " << this->nrTipPoze << ". " << "Formate poze: ";
		for (int i = 0; i < nrTipPoze; i++) {
			cout << this->formatPoze[i] << ", ";
		}
		cout << endl;
	}
	friend ostream& operator<<(ostream& out, const AparatFotoDSLR& aparat) {
		out << "Numar de formate: " << aparat.nrTipPoze;
		out << "\nFormate fotografii: ";
		for (int i = 0; i < aparat.nrTipPoze; i++) {
			out << aparat.formatPoze[i] << ";";
		}
		out << (AparatFoto)aparat;
		return out;
	}
};

class Fotograf {
private:
	char* denumire;
	int nrEvenimente;
	ConcursFotografie** aparatFoto;
public:
	Fotograf() {
		this->denumire = new char[strlen("Meduza") + 1];
		strcpy_s(this->denumire, strlen("Meduza") + 1, "Meduza");
		this->aparatFoto = new ConcursFotografie * [10];
		for (int i = 0; i < 9; i++) {
			this->aparatFoto[i] = new AparatFoto();
		}
		this->aparatFoto[10] = new AparatFotoDSLR();
	}
	Fotograf(int evenimente, const char* denumire, const AparatFoto& aparat) :nrEvenimente(evenimente), aparatFoto(aparatFoto) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->aparatFoto = new ConcursFotografie * [10];
		for (int i = 0; i < 9; i++) {
			this->aparatFoto[i] = new AparatFoto();
		}
		this->aparatFoto[10] = new AparatFotoDSLR();

	};
	ConcursFotografie*& operator[](int index) {
		if (index >= 0 && index < 10) {
			return this->aparatFoto[index];
		}
	}
	~Fotograf() {
		if (this->denumire != NULL) {
			delete[]this->denumire;
		}
	}
	Fotograf(const Fotograf& c) {
		if (this != &c) {
			this->denumire = new char[strlen(c.denumire) + 1];
			strcpy_s(this->denumire, strlen(c.denumire) + 1, c.denumire);
			this->nrEvenimente = c.nrEvenimente;
			aparatFoto = c.aparatFoto;
			this->aparatFoto = new ConcursFotografie * [10];
			for (int i = 0; i < 10; i++) {
				this->aparatFoto[i] = (c.aparatFoto[i]);

			}
			//this->aparatFoto[10] = new AparatFotoDSLR();

		}

	}
	Fotograf operator= (const Fotograf& c) {
		if (this != &c) {
			this->denumire = new char[strlen(c.denumire) + 1];
			strcpy_s(this->denumire, strlen(c.denumire) + 1, c.denumire);
			aparatFoto = c.aparatFoto;
		}
		this->aparatFoto = new ConcursFotografie * [10];
		for (int i = 0; i < 10; i++) {
			this->aparatFoto[i] = (c.aparatFoto[i]);
		}
		//this->aparatFoto[10] = new AparatFotoDSLR();

		return *this;
	}

	char* getDenumire() {
		return denumire;
	}
	void setProducator(char* denumire) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	int getNrEvenimente() {
		return nrEvenimente;
	}
	void setMemorie(int nrEvenimente) {
		this->nrEvenimente = nrEvenimente;
	}

	/*void setAparatFoto(AparatFoto aparat) {
		aparatFoto = aparat;
	}*/
	AparatFoto getAparatFoto() {
		for (int i = 0; i < 3; i++) {
			cout << aparatFoto[i];
		}
	}

	friend ostream& operator<<(ostream& out, const Fotograf& foto) {
		out << "Nume fotograf: " << foto.denumire << "\nNr evenimente: " << foto.nrEvenimente;
		{
			out << "\nAparat detinut:\n" << foto.aparatFoto;
		}
		return out;
	}
	friend istream& operator>>(istream& in, Fotograf& foto) {
		cout << "Nume fotograf: ";
		in >> foto.denumire;
		//foto.denumire = new char[strlen(foto.denumire) + 1];
		//strcpy_s(foto.denumire, strlen(foto.denumire) + 1, foto.denumire);

		cout << "Nr evenimente: ";
		in >> foto.nrEvenimente;
		{
			cout << "Aparat detinut:";
		}
		return in;
	}
	/*char& operator[](int index) {
		return this->denumire[index];
		return this->denumire[0];
	}*/
	Fotograf operator++() {
		this->nrEvenimente++;
		return *this;
	}
	Fotograf operator++(int) {
		Fotograf aux = *this;
		this->nrEvenimente++;
		return aux;
	}
	friend ofstream& operator<<(ofstream& fisier, const Fotograf& fotograf) {
		fisier << fotograf.denumire << endl << fotograf.nrEvenimente << endl << fotograf.aparatFoto << endl;
		return fisier;
	}
	/*friend ifstream& operator>>(ifstream& fisier, Fotograf& fotograf) {
		if (fotograf.denumire != NULL) {
			delete[]fotograf.denumire;
		}
		char aux[30];
		fotograf.denumire = new char[strlen(aux) + 1];
		strcpy_s(fotograf.denumire, strlen(aux) + 1, aux);
		fisier >> fotograf.denumire;
		fisier >> fotograf.nrEvenimente;
		fisier >> fotograf.aparatFoto;

	}*/
};

class Armata { // folosirea in cotext politic a dronelor
public:
	virtual void afisareDescriere() = 0;
	virtual ~Armata() = default;

};
class Drona : public Armata {
private:
	Drona* drone;
	static int perioadaRetur;
	const int id;
	const float greutate;
	char* model;
	string rezolutieCamera;
	float autonomie;
	string conectivitate;
	float altitudineZbor;
public:
	virtual void afisareDescriere() {
		cout << "Id: " << this->id << "; ", cout << "greutate: " << this->greutate << "; " << "model: " << this->model << "; ";
	}
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
				this->rezolutieCamera = p.rezolutieCamera;
				this->autonomie = p.autonomie;
				this->conectivitate = p.conectivitate;
				this->altitudineZbor = p.altitudineZbor;
				this->model = new char[strlen(p.model) + 1];
				strcpy(this->model, p.model);
			}
			else this->model;
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
			masina << "\nModel:" << drona.getModel() << "\nRezolutie: "
				<< drona.getRezolutieCamera() << "\nAutonomie: " << drona.getAutonomie() << " h" << "\nConectivitate: " << drona.getConectivitate()
				<< "\nAltitudine zbor:" << drona.getAltitudineZbor();
		}
		return masina;
	}
	Armata& operator[](int index) {
		if (index >= 0 && index < 10) {
			return drone[index];
		}
	}
	friend ofstream& operator<<(ofstream& fisier, const Drona& drona) {
		fisier << drona.getModel() << drona.getRezolutieCamera() << endl
			<< drona.getAutonomie() << drona.getConectivitate() << drona.getAltitudineZbor();
	}

	friend ifstream& operator>>(ifstream& fisier, Drona& drona) {
		if (drona.model != NULL) {
			delete[]drona.model;
		}
		char aux[30];
		drona.model = new char[strlen(aux) + 1];
		strcpy_s(drona.model, strlen(aux) + 1, aux);
		fisier >> drona.model;
		fisier >> drona.rezolutieCamera;
		fisier >> drona.autonomie;
		fisier >> drona.altitudineZbor;
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
		masina >> drona.conectivitate;
		cout << "Altitudine zbor: ";
		masina >> drona.altitudineZbor;
	}
	return masina;

};
class DronaDeVanatoare : public Drona, Armata {
private:
	int nrMateriale;
	string* tipuriMateriale;
public:
	int getNrMateriale() {
		return this->nrMateriale;
	}
	void setNrMateriale(int nrMateriale) {
		this->nrMateriale = nrMateriale;
	}
	string* getTipuriMateriale() {
		return this->tipuriMateriale;
	}
	void setTipuriMateriale(string* tipuriMateriale) {
		for (int i = 0; i < getNrMateriale(); i++) {
			this->tipuriMateriale[i] = tipuriMateriale[i];
		}
	}
	DronaDeVanatoare() :Drona("Sus ca jordan") {
		this->nrMateriale = 0;
		this->tipuriMateriale = NULL;
	}
	DronaDeVanatoare(int nrMateriale, string* tipuriMateriale) :Drona("Salam", 2, 156.56, "720p") {
		this->nrMateriale = nrMateriale;
		this->tipuriMateriale = new string[nrMateriale];
		for (int i = 0; i < nrMateriale; i++) {
			this->tipuriMateriale[i] = tipuriMateriale[i];
		}
	}
	~DronaDeVanatoare() {
		if (this->nrMateriale != 0) {
			delete[]this->tipuriMateriale;
		}
	}
	DronaDeVanatoare(const DronaDeVanatoare& d) :Drona(d) {
		if (this != &d) {
			this->nrMateriale = d.nrMateriale;
			this->tipuriMateriale = new string[nrMateriale];
			for (int i = 0; i < nrMateriale; i++) {
				this->tipuriMateriale[i] = d.tipuriMateriale[i];
			}
		}
	}
	DronaDeVanatoare operator=(const DronaDeVanatoare& d) {
		if (this != &d) {
			Drona::operator=(d);
			this->nrMateriale = d.nrMateriale;
			this->tipuriMateriale = new string[nrMateriale];
			for (int i = 0; i < nrMateriale; i++) {
				this->tipuriMateriale[i] = d.tipuriMateriale[i];
			}
		}
		return *this;
	}
	void afisareDescriere() {
		cout << "Id: " << this->getId() << "; ", cout << "greutate: " << this->getGreutate() << "; " << "model: " << this->getModel() << "; "
			<< "Nr materiale: " << this->nrMateriale << "; " << "Tipuri materiale ptr panza: ";
		for (int i = 0; i < nrMateriale; i++) {
			cout << this->tipuriMateriale[i] << "; ";
		}
	}

	friend ostream& operator<<(ostream& out, const DronaDeVanatoare& drona) {
		out << "Numar materiale plasa: " << drona.nrMateriale << endl;
		out << "Materiale: ";
		for (int i = 0; i < drona.nrMateriale; i++) {
			out << drona.tipuriMateriale[i] << ";";
		}
		out << (Drona)drona;
		return out;
	}

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
	friend ofstream& operator<<(ofstream& fisier, const Proiector& proiector) {
		fisier << proiector.getModel() << proiector.getMarca() << proiector.getContrast() << proiector.getNrLumeni() << proiector.getPret();
	}
	friend ifstream& operator>>(ifstream& fisier, Proiector& proiector) {
		if (proiector.marca && proiector.model != NULL) {
			delete[]proiector.marca;
			delete[]proiector.model;
		}
		char aux[30];
		proiector.marca = new char[strlen(aux) + 1];
		strcpy_s(proiector.marca, strlen(aux) + 1, aux);
		proiector.model = new char[strlen(aux) + 1];
		strcpy_s(proiector.model, strlen(aux) + 1, aux);
		fisier >> proiector.marca;
		fisier >> proiector.model;
		fisier >> proiector.contrast;
		fisier >> proiector.nrLumeni;
		fisier >> proiector.pret;
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
	//AparatFoto* v_aparat = new AparatFoto[3];
	//AparatFoto* pointerAparat = new AparatFoto();
	//int dimVector = 3;
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

	cout << "APARAT" << endl;
	AparatFoto aparat1("Canon");
	cout << "\nId: " << aparat1.getId() << "\nTip: " << aparat1.getTipAparat() << "\nModelul: " << aparat1.getModel() << "\nMarca: "
		<< aparat1.getMarca() << "\nAutonomie: " << aparat1.getAutonomie() << " de cadre " << "\nZoom :" << aparat1.getZoom() << "\nUn pret de: " << aparat1.getPret()
		<< "\nTva calc: ";
	aparat1.setCalcTva(1500.50);
	cout << "\nModelul aparatului este? " << getModel1(aparat1);
	cout << "\n------------------------------------------------------------------------------------";;

	AparatFoto aparat2("Sony", 2, "DSLR");
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

	AparatFoto ap("mihai", 2, "Camera compacta", "Sony vegas 3", 2300, 12, 400.50);
	cout << "Operatori>> fisier text" << endl;
	//cin >> ap;
	ofstream f("aparat.txt", ios::app);
	f << ap;
	//f.close();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "Operatori<< fisier text" << endl;
	ifstream g("aparat.txt", ios::in);
	//g>> ap;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "AparatFotoDSLR" << endl;
	string* formatPoze = new string[2];
	formatPoze[0] = { "JPEG" };
	formatPoze[1] = { "RAW" };
	AparatFotoDSLR dslr1;
	cout << dslr1;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	AparatFotoDSLR dslr2(2, formatPoze);
	cout << dslr2;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	AparatFotoDSLR dslr3(dslr2);
	cout << dslr2;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	dslr1 = dslr3;
	cout << dslr2;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "FOTOGRAF" << endl;
	Fotograf fotograf1(3, "Florinel", aparat1);
	cout << "\nOperator <<\n";
	//cout << fotograf1.getAparatFoto();
	cout << "\n------------------------------------------------------------------------------------" << endl;
	cout << "\nOperator index";
	cout << "\nProducator: " << fotograf1.getDenumire();
	/*fotograf1[0] = 'X';*/
	cout << "\nProducator: " << fotograf1.getDenumire();
	cout << "\n------------------------------------------------------------------------------------" << endl;
	cout << "\nOperatori++" << endl;
	cout << "Nr Evenimente initial: " << fotograf1.getNrEvenimente() << endl;
	fotograf1++;
	cout << "\nnrEvenimente++: " << fotograf1.getNrEvenimente() << endl;
	++fotograf1;
	cout << "++nrEvenimente: " << fotograf1.getNrEvenimente() << endl;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Fotograf fotograf2(fotograf1);
	cout << "\nConstructor copiere" << endl;
	cout << fotograf2;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Fotograf fotograf3(4, "Octavian Popescu", aparat3);
	cout << "\nOperator =" << endl;
	fotograf2 = fotograf3;
	cout << fotograf2;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "Operatori>> fisier text" << endl;
	//cin >> fotograf3;
	fstream h("fotograf.txt", ios::app);
	h << fotograf3;
	h.close();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "Operatori<< fisier text" << endl;
	fstream i("fotograf.txt", ios::in);
	i << fotograf3;
	i.close();
	cout << fotograf3;
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
		<< drona1.getRezolutieCamera() << "\nAutonomie: " << drona1.getAutonomie() << "\nConectivitate: " << drona1.getConectivitate() << "\nAltitudine zbor: " << drona1.getAltitudineZbor() << endl;
	cout << "\n" << Drona::returnarePosibila(21) << " zile";
	cout << "\n------------------------------------------------------------------------------------";

	Drona drona2("FR 11", 2, 657.5, "4k");
	cout << "\nId: " << drona2.getId() << "\nGreutate: " << drona2.getGreutate() << "\nModel: " << drona2.getModel() << "\nRezolutie camera: "
		<< drona2.getRezolutieCamera() << "\nAutonomie: " << drona2.getAutonomie() << "\nConectivitate: " << drona2.getConectivitate() << "\nAltitudine zbor: " << drona2.getAltitudineZbor() << endl;
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
	//drona2[1] = 'W';
	/*cout << "\nOperator schimbare litera\n" << drona2;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	cout << "\nOperator >=\n";
	cout << (drona2 >= drona1);
	cout << "\n------------------------------------------------------------------------------------" << endl;*/

	Drona drona("SUS", 4, 1, "2k", 0.24);
	cout << "Operatori>> fisier binar" << endl;
	//cin >> drona;
	fstream j("drona.bin", ios::in | ios::binary);
	j.write((char*)&drona, sizeof(drona));
	j.close();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "Operatori<< fisier binar" << endl;
	fstream k("drona.bin", ios::out | ios::binary);
	k.read((char*)&drona, sizeof(Drona));
	cout << drona;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "DRONA DE VANATOARE" << endl;
	string* tipuriMateriale = new string[2];
	tipuriMateriale[0] = "Nylon";
	tipuriMateriale[1] = "Fibra de sticla";
	DronaDeVanatoare dvanatoare1;
	cout << dvanatoare1;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	DronaDeVanatoare dvanatoare2(2, tipuriMateriale);
	cout << dvanatoare2;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	DronaDeVanatoare dvanatoare3(dvanatoare1);
	cout << dvanatoare3;
	cout << "\n------------------------------------------------------------------------------------" << endl;
	dvanatoare3 = dvanatoare2;
	cout << dvanatoare3;
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

	cout << "Apel operator <" << endl;
	cout << (proiector4 <= proiector2) << endl;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Proiector proiector("Floricel", "Flori", 4, "full HD", 3000, 9000, 1235.4);
	cout << "Operatori>> fisier binar" << endl;
	//cin >> proiector;
	fstream l("proiector.bin", ios::in);
	l.write((char*)&proiector, sizeof(Proiector));
	l.close();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "Operatori<< fisier binar" << endl;
	fstream m("proiector.bin", ios::out | ios::binary);
	m.read((char*)&proiector, sizeof(Proiector));
	cout << proiector;

	cout << "Implementare clasa abstracta, ptr clasa mostenita" << endl;

	ConcursFotografie* r = NULL;
	r = new AparatFoto();

	Fotograf fotografie;
	fotografie[0] = r;
	fotografie[1] = new AparatFotoDSLR(2, formatPoze);
	fotografie[2] = new AparatFoto("mihai", 2, "DSLR", "C7", 1400, 7, 13.2);
	fotografie[3] = new AparatFotoDSLR(1, formatPoze);
	fotografie[4] = new AparatFoto("stefan", 3, "DSLR", "B4", 1400, 7, 13.2);
	fotografie[5] = new AparatFotoDSLR(2, formatPoze);
	fotografie[6] = new AparatFoto("sony cariciu");
	fotografie[7] = new AparatFotoDSLR(2, formatPoze);
	fotografie[8] = new AparatFoto("sony cariciu");
	fotografie[9] = new AparatFotoDSLR(2, formatPoze);
	for (int i = 0; i < 10; i++) {
		fotografie[i]->afisareDescriere();
		delete[]fotografie[i];
	}
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Drona* droneArmata[10];
	droneArmata[0] = new Drona();
	droneArmata[1] = new Drona("Samsung");
	droneArmata[2] = new DronaDeVanatoare();
	droneArmata[3] = new DronaDeVanatoare(2, tipuriMateriale);
	droneArmata[4] = new Drona("Campina");
	droneArmata[5] = new DronaDeVanatoare(1, tipuriMateriale);
	droneArmata[6] = new Drona("Cascaval", 4, 300.5, "2k");
	droneArmata[7] = new Drona("Nokia");
	droneArmata[8] = new DronaDeVanatoare(0, tipuriMateriale);
	droneArmata[9] = new Drona();

	for (int i = 0; i < 10; i++) {
		droneArmata[i]->afisareDescriere(); cout << endl;
		delete[]droneArmata[i];
	}
	cout << "------------------------------------------------------------------------------------" << endl;
}




