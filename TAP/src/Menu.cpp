#include <iostream>
#include "graphviewer.h"
#include <cstdio>
#include <fstream>
#include <sstream>
#include "Agency.h"
#include "Client.h"
#include <limits.h>
#include "Date.h"

#define HIGH_S_M 1.40

GraphViewer *gv;
float multiplier = 1;

StringAlgorithms algorithm;

using namespace std;

void Agency::introMenu() {

	int opcao;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Bem vindo a nossa agencia de viagens!                    |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "| 1 - Gestao de Clientes                                   |\n";
	cout << "| 2 - Gestao de Viagens                                    |\n";
	cout << "| 3 - Abrir o Mapa                                         |\n";
	cout << "| 4 - Guardar Ficheiros                                    |\n";
	cout << "| 0 - Sair                                                 |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	cin >> opcao;

	cout << "\n";

	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
		cout << "Pressione Enter para voltar ao menu" << endl;
		cin.get();
	}

	switch (opcao) {

	case 0:
		return;
		break;

	case 1:
		menuCliente();
		cin.get();
		cin.get();
		break;

	case 2:
		menuTrip();
		cin.get();
		cin.get();
		break;

	case 3:
		map();
		cin.get();
		cin.get();
		break;

	case 4:
		menuSave();
		cin.get();
		cin.get();
		break;

	default:
		cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";

	}
}

void Agency::menuCliente() {

	int opcaocliente;
	while (true) {
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o que pretende fazer com os clientes             |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Adicionar Cliente                                    |\n";
		cout << "| 2 - Apagar Cliente					                    |\n";
		cout << "| 3 - Listagem Clientes					                |\n";
		cout << "| 4 - Menu Principal  					                    |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "\n";

		cin >> opcaocliente;

		cout << "\n";

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}
		switch (opcaocliente) {

		case 0:
			return;
			break;

		case 1:
			adicionaCliente();
			cin.get();
			cin.get();
			break;

		case 2:	
			removeCliente();
			cin.get();
			cin.get();
			break;

		case 3:
			listClients();
			cin.get();
			cin.get();
			break;

		case 4:
			introMenu();
			cin.get();
			cin.get();
			break;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";

		}
	}
}

void Agency::adicionaCliente() {

	string nomeCliente;
	int telemovel, ID;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o seu nome?                                       |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, nomeCliente);

	cout << "\n";

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o seu ID?                                         |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	cin >> ID;

	cout << "\n";

	for(unsigned int i = 0; i < clientes.size(); i++){

		if(getClientes()[i]->getID() == ID){
			cout << " Cliente ja existe!"<<endl;
			introMenu();
		}
	}

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual o seu numero de telemovel?                          |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	cin >> telemovel;

	cout << "\n";

	Client * novocliente = new Client(nomeCliente, ID, telemovel);
	addClients(novocliente);

	cout << "Cliente adicionado com sucesso! \n";
	menuCliente();

}

void Agency::removeCliente() {

	string clienteremover;
	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e o cliente a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, clienteremover);

	cout << "\n";

	for (unsigned int i = 0; i < getClientes().size(); i++)
	{
		if (getClientes()[i]->getName() == clienteremover)
			clientes.erase(clientes.begin() + i);

		else {
			cout << " Cliente nao existe!\n";

		}
	}
	cout << endl << "O cliente foi removido com sucesso" << endl;
	menuCliente();
}

void Agency::listClients(){

	cout << "CLIENTES:\n" <<endl;

	for(unsigned int i = 0; i < getClientes().size(); i++){

		cout << getClientes().at(i)->getName() << " - " << getClientes().at(i)->getID() << " - " << getClientes().at(i)->getPhoneNumber() <<endl;
	}

	cout << "Pressione ENTER para regressar" << endl;
	cin.get();
	return;
}

void Agency::menuTrip(){

	int opcaotrip;

	while (true) {
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha o que pretende fazer com a viagem                |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Criar Viagem                                         |\n";
		cout << "| 2 - Apagar Viagem					                    |\n";
		cout << "| 3 - Lista de Destinos					                |\n";
		cout << "| 4 - Escolher uma origem e um destino diretamente         |\n";
		cout << "| 5 - Escolher vários locais a visitar                     |\n";
		cout << "| 6 - Escolher conjunto de locais a visitar                |\n";
		cout << "|     a partir de onde me encontro                         |\n";
		cout << "| 7 - Menu Principal                                       |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "\n";

		cin >> opcaotrip;

		cout << "\n";

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}

		cin.ignore(INT_MAX, '\n');

		switch (opcaotrip) {

		case 0:
			return;
			break;

		case 1:
			adicionaTrip();
			cin.get();
			cin.get();
			break;

		case 2:
			removeTrip();
			cin.get();
			cin.get();
			break;

		case 3:
			destinationsList();
			cin.get();
			cin.get();
			break;

		case 4:
			menuViagem();
			cin.get();
			cin.get();
			break;


		case 5:
			menuViagem2();
			cin.get();
			cin.get();
			break;

		case 6:
			destinosCidade();
			cin.get();
			cin.get();
			break;

		case 7:
			introMenu();
			cin.get();
			cin.get();
			break;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";

		}
	}
}

void Agency::adicionaTrip() {

	string dataInicio;
	string dataFim;

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e a data de inicio da viagem?  (Formato: dd/mm/aa)  |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	cin >> dataInicio;
	cout << "\n";
	Date *dataInicial = new Date(dataInicio);

	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e a data de fim da viagem?  (Formato: dd/mm/aa)     |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	cin >> dataFim;
	cout << "\n";
	Date *dataFinal = new Date(dataFim);

	string temp;
	cout << "+----------------------------------------------------------+\n";
	cout << "| Indique os voos a adicionar (escreva FIM para terminar): |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	Trip * novaTrip = new Trip(*dataInicial, *dataFinal);
	addTrips(novaTrip);

	cout << "Viagem adicionada com sucesso!\n";
}

void Agency::removeTrip() {

	tripList();

	string tripremover;
	cout << "+----------------------------------------------------------+\n";
	cout << "| Qual e a viagem a remover?	                            |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	cin.ignore(INT_MAX, '\n');
	getline(cin, tripremover);

	cout << "\n";

	for (unsigned int i = 0; i < getTrips().size(); i++)
	{
		if (getTrips()[i]->getID() == stoi(tripremover))
			trips.erase(trips.begin() + i);
	}
	cout << endl << "A viagem foi removida com sucesso" << endl;
	cout << "Pressione Enter para regressar" << endl;
	cin.get();
	return;

}

void Agency::escolheGeral() {

	string temp;
	vector<string> destinos;
	vector<string> novosDestinos;

	cout << "\n";

	string data;
	cout << "+----------------------------------------------------------+\n";
	cout << "|	Indique a data da sua viagem:                           |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "Data formato : DD/MM/YY\n";
	cout << "\n";

	getline(cin, data);

	cout << "\n";

	Date dateInput(data);

	cout << "+-------------------------------------------------------------+\n";
	cout << "| Indique os destinos a adicionar (escreva FIM para terminar):|\n";
	cout << "+-------------------------------------------------------------+\n";
	cout << "\n";


	while (temp != "FIM")
	{
		getline(cin, temp);
		if(temp != "FIM")
			destinos.push_back(temp);
	}

	string response;

	cout << "\n\n";
	cout << "+-------------------------------------------------------------+\n";
	cout << "| Pretende visitar locais específicos? (Format : Y|N)         |\n";
	cout << "+-------------------------------------------------------------+\n";
	cout << "\n";

	getline(cin,response);

	cout << "\n";

	if(response == "Y"){

		vector<string> locais;
		string resultado;
		string tempcin;


		cout << "+--------------------------------------------------------------+\n";
		cout << "| Insira aqui a lista de locais a visitar : (FIM para terminar)|\n";
		cout << "+--------------------------------------------------------------+\n";
		cout << "\n";

		while(tempcin != "FIM"){

			getline(cin,tempcin);

			if(tempcin!= "FIM")
				locais.push_back(tempcin);

			else
				cout << "\nProcurando nos seus destinos pelos locais que inseriu.\n\n";
		}

		int opcaoPesquisa;

		cout << "+--------------------------------------------------------------+\n";
		cout << "| Escolha o tipo de pesquisa que prefere :                     |\n";
		cout << "+--------------------------------------------------------------+\n";
		cout << "| 1 - Pesquisa Exacta                                          |\n";
		cout << "| 2 - Pesquisa Aproximada                                      |\n";
		cout << "+--------------------------------------------------------------+\n";
		cout << "\n";

		cin >> opcaoPesquisa;

		cout << "\n";

		switch(opcaoPesquisa){

		case 1:
			if((resultado = searchInYourDestinations(destinos,locais)) != "EXISTE"){
			novosDestinos = searchInAllDestinations(destinos,resultado);
			calculateMultiplePaths(dateInput,novosDestinos);
			}
			break;
		case 2:
			if((resultado = aproxSearchInYourDestinations(destinos,locais)) != "EXISTE"){
			novosDestinos = aproxSearchInAllDestinations(destinos,resultado);
			calculateMultiplePaths(dateInput,novosDestinos);
			}
			cin.get();
			cin.get();
		    break;
		}
	}

	else
		calculateMultiplePaths(dateInput,destinos);
}

void Agency::calculateMultiplePaths(Date date, vector<string> locals){

	vector<string> destinations;
	float cost, mul;
	Vertex<City>* last;

	mul = setSeason(date);

	cout << "\nYour Route :\n";

	for(unsigned int i = 0; i < locals.size() -1; i++) {

		Vertex<City>* vertex1;
		Vertex<City>* vertex2;


		if((vertex1 = getGraph().findVertexName(locals[i])) == NULL){
			cout << " Destino não existe.\n";
			break;
		}

		if((vertex2 = getGraph().findVertexName(locals[i+1])) == NULL){
			cout << "Destino não existe!\n";
			break;
		}

		graph.dijkstraShortestPath(vertex1->getInfo());
		auto path = graph.getPath(vertex1->getInfo(), vertex2->getInfo());


		cout <<"\n" << i+1 << " - ";
		for(City city: path){
			cout << city.getName() << "; ";
			destinations.push_back(city.getName());

		}
	}

	for(unsigned int i = 0; i < destinations.size(); i++){

		if(destinations[i] == destinations[i+1]){
			destinations.erase(destinations.begin() + i);

		}
	}

	last = getGraph().findVertexName(destinations[destinations.size() -1]);

	cost = last->getInfo().getHotels()[0]->getPrice() * mul;

	for(unsigned int i = 0; i < vec.size(); i++){
		for(unsigned int j = 0; j < destinations.size(); j++){
			if(vec[i]->getName() == destinations[j]){
				for(unsigned int m = 0; m < vec.size(); m++){
					for(unsigned k = 0; k < 3; k++){
						if(destinations[j + 1] == vec[m]->getName()){
							if(vec[m]->getID() == vec[i]->getIDDestinies(k))
								cost += vec[m]->getPlaneTicket(k);
						}
					}
				}
			}
		}
	}

	cout << "\nCusto : " << cost <<  "€\n\n";
}

string Agency::searchInYourDestinations(vector<string> destinos, vector<string> locals){

	string local;

	for(unsigned int n = 0; n < vec.size(); n++){

		for(unsigned int m = 0; m < destinos.size(); m++){

			if(algorithm.ExactStringMatchingKMP(destinos[m], vec[n]->getName())){

				for(unsigned int v = 0; v < vec[n]->getTouristAttractions().size(); v++){

					for(unsigned int p = 0; p < locals.size(); p++){

						if(algorithm.ExactStringMatchingKMP(locals[p], vec[n]->getTouristAttractions()[v]))
						{
							cout << locals[p] << " encontra-se em " << vec[n]->getName() << ", que já está incluido na sua viagem.\n";
							local = "EXISTE";
						}

						else
							local = locals[p];
					}}}}}

	return local;
}

vector<string> Agency::searchInAllDestinations(vector<string> destinos, string local){

	for(unsigned int i = 0; i < vec.size(); i++){
		for(unsigned int j = 0; j < vec[i]->getTouristAttractions().size(); j++){
			if(algorithm.ExactStringMatchingKMP(local, vec[i]->getTouristAttractions()[j])){
				destinos.push_back(vec[i]->getName());
				cout << local << " encontra-se em " << vec[i]->getName() <<". Adicionámos esta paragem à sua viagem.\n";
			}
		}
	}

	return destinos;
}

string Agency::aproxSearchInYourDestinations(vector<string> destinos, vector<string> locals){

	string local;
	vector<string> possible ;

	cout << "\n\nSerá que quis dizer : \n";

	for(unsigned int n = 0; n < vec.size(); n++){

		for(unsigned int m = 0; m < destinos.size(); m++){

			if(algorithm.ExactStringMatchingKMP(destinos[m], vec[n]->getName())){

				for(unsigned int v = 0; v < vec[n]->getTouristAttractions().size(); v++){

					for(unsigned int p = 0; p < locals.size(); p++){

						if(algorithm.findApproxMatchingStrings(locals[p], vec[n]->getTouristAttractions()[v]) <= 10)
						{
							possible.push_back(vec[n]->getTouristAttractions()[v]);
							local = "EXISTE";
						}

						else
							local = locals[p];
					}}}}}

	for(unsigned int i = 0; i < possible.size(); i++){
		cout << possible[i] << "\n";
	}
	return local;
}

vector<string> Agency::aproxSearchInAllDestinations(vector<string> destinos, string local){

	vector<string> possible;

	for(unsigned int i = 0; i < vec.size(); i++){
			for(unsigned int j = 0; j < vec[i]->getTouristAttractions().size(); j++){
				if(algorithm.findApproxMatchingStrings(local, vec[i]->getTouristAttractions()[j]) < 5){
					possible.push_back(vec[i]->getTouristAttractions()[j]);
				}
			}
		}

	for(unsigned int i = 0; i < possible.size(); i++){

		cout << possible[i] << "\n";
	}
		return destinos;
}

void Agency::menuViagem(){

	int opcaotrip;

	while (true) {
		cout << "+----------------------------------------------------------+\n";
		cout << "| Qual a sua prioridade?                                   |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Tempo                                                |\n";
		cout << "| 2 - Custo         					                    |\n";
		cout << "| 3 - Andar p/ trás         					            |\n";
		cout << "| 4 - Menu Principal                                       |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "\n";

		cin >> opcaotrip;

		cout << "\n";

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}

		cin.ignore(INT_MAX, '\n');

		switch (opcaotrip) {

		case 0:
			return;
			break;

		case 1:
			calculatePathAcorddingToDistance();
			escolheDireto();
			cin.get();
			cin.get();
			break;

		case 2:
			calculatePathAcorddingToCost();
			escolheDireto();
			cin.get();
			cin.get();
			break;

		case 3:
			menuTrip();
			cin.get();
			cin.get();
			break;

		case 4:
			introMenu();
			cin.get();
			cin.get();
			break;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";

		}
	}
}

void Agency::menuViagem2(){

	int opcaotrip;

	while (true) {
		cout << "+----------------------------------------------------------+\n";
		cout << "| Qual a sua prioridade?                                   |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Tempo                                                |\n";
		cout << "| 2 - Custo         					                    |\n";
		cout << "| 3 - Andar p/ trás         					            |\n";
		cout << "| 4 - Menu Principal                                       |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "\n";

		cin >> opcaotrip;

		cout << "\n";

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}

		cin.ignore(INT_MAX, '\n');

		switch (opcaotrip) {

		case 0:
			return;
			break;

		case 1:
			calculatePathAcorddingToDistance();
			escolheGeral();
			cin.get();
			cin.get();
			break;

		case 2:
			calculatePathAcorddingToCost();
			escolheGeral();
			cin.get();
			cin.get();
			break;

		case 3:
			menuTrip();
			cin.get();
			cin.get();
			break;

		case 4:
			introMenu();
			cin.get();
			cin.get();
			break;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";

		}
	}
}

void Agency::destinosCidade(){

	string origem;

	cout << "+----------------------------------------------------------+\n";
	cout << "|	Indique onde se encontra                                |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	getline(cin, origem);

	cout << "\n";

	for(unsigned int i = 0; i < vec.size(); i++){

		if(origem == vec[i]->getName()){

			gv = new GraphViewer(1360,625, false);
			gv->setBackground("worldmap.jpg");
			gv->defineVertexColor("black");
			gv->defineEdgeColor("red");
			gv->defineEdgeCurved(true);
			gv->createWindow(750,450);

			for(unsigned int i = 0; i < vec.size(); i++){

				gv->addNode(vec.at(i)->getID(), vec[i]->getCoordinates().getX(), vec[i]->getCoordinates().getY());
				gv->setVertexLabel(vec[i]->getID(),vec[i]->getName());
				gv->setVertexColor(vec[i]->getID(), GRAY);
				gv->setVertexSize(vec[i]->getID(), 3);
			}

			gv->addEdge(0, vec[i]->getID(), vec[i]->getIDDestinies(0), EdgeType::DIRECTED);
			gv->addEdge(1, vec[i]->getID(), vec[i]->getIDDestinies(1), EdgeType::DIRECTED);
			gv->addEdge(2, vec[i]->getID(), vec[i]->getIDDestinies(2), EdgeType::DIRECTED);

		}
	}

	gv->rearrange();

}

void Agency::escolheDireto() {

	string origem;
	string destino;

	cout << "+----------------------------------------------------------+\n";
	cout << "|	Indique a origem da sua viagem:                         |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	getline(cin, origem);

	cout << "\n";

	Vertex<City>* originVertex;
	if ((originVertex = getGraph().findVertexName(origem)) == NULL){//VERIFICAR SE EXISTE
		cout << " Origem nao existe!\n";
		return;
	}


	cout << "+----------------------------------------------------------+\n";
	cout << "|	Indique o destino que quer visitar:                     |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "\n";

	getline(cin, destino);

	cout << "\n";

	string data;
	cout << "+----------------------------------------------------------+\n";
	cout << "|	Indique a data da sua viagem:                           |\n";
	cout << "+----------------------------------------------------------+\n";
	cout << "Data formato : DD/MM/YY\n";
	cout << "\n";

	getline(cin, data);

	cout << "\n";

	Date date(data);

	float mul = setSeason(date);

	Vertex<City>* destVertex;
	if ((destVertex = getGraph().findVertexName(destino)) == NULL)
	{//VERIFICAR SE EXISTE
		cout << " Destino nao existe!\n";
		return;
	}

	graph.dijkstraShortestPath(originVertex->getInfo());
	cout << "\nDistancia : " << destVertex->getDist() << "\n";
	auto path = graph.getPath(originVertex->getInfo(), destVertex->getInfo());

	int i = 1;

	cout << "\nO seu trajeto :\n";
	for(City city: path){
		cout << i << " - ";
		cout << city.getName() <<"\n";
		i++;
	}

	int cost = path[(path.size()-1)].getHotels()[0]->getPrice() * mul;

	for(unsigned int j = 0; j < path.size(); j++){
		for(int i = 0; i < 3; i++) {

			if (path[j+ 1].getID() == path[j].getIDDestinies(i))
				cost += path[j].getPlaneTicket(i);
		}
	}

	cout << "\nCusto : " << cost << "€\n\n";

	gv = new GraphViewer(1360,625, false);
	gv->setBackground("worldmap.jpg");
	gv->defineVertexColor("black");
	gv->defineEdgeColor("red");
	gv->defineEdgeCurved(true);
	gv->createWindow(750,450);

	for(unsigned int i = 0; i < vec.size(); i++){

		gv->addNode(vec.at(i)->getID(), vec[i]->getCoordinates().getX(), vec[i]->getCoordinates().getY());
		gv->setVertexLabel(vec[i]->getID(),vec[i]->getName());
		gv->setVertexColor(vec[i]->getID(), GRAY);
		gv->setVertexSize(vec[i]->getID(), 3);
	}

	int id = 0;

	for(unsigned int i = 0; i < path.size() - 1; i++){
		gv->addEdge(id, path[i].getID(), path[i+1].getID(), EdgeType::DIRECTED);
		id++;
	}

	gv->rearrange();
}

void Agency::destinationsList(){

	string assets = "./assets/CitiesNames";
	ifstream in;

	string temp;
	string fich = assets + ".txt";
	const char *nomeFich;
	nomeFich = fich.c_str();

	in.open(nomeFich);

	cout << "\nDESTINOS:\n"<<endl;

	while(!in.eof()){

		getline(in,temp);
		cout << " | "<< temp;
	}

	in.close();
}

void Agency::tripList(){

	cout << "\nVIAGENS:\n" << endl;

	for(unsigned int i = 0; i < getTrips().size(); i++){

		cout << trips[i]->getID() << " - " << trips[i]->getDepartureDate().getString() << " ; "  << trips[i]->getArrivalDate().getString() << " - " << trips[i]->getDepartureCity() << " - " << trips[i]->getArrivalCity() << " - " << trips[i]->getHotel() << " - " << trips[i]->getCost() << " ; " << trips[i]->getDistance() << endl;
	}
}

void Agency::menuSave(){

	int opcaotrip;

	while (true) {
		cout << "+----------------------------------------------------------+\n";
		cout << "| Escolha que ficheiros pretende guardar                   |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| Selecione a sua opcao (insira apenas o numero):          |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "| 1 - Guardar Cliente                                      |\n";
		cout << "| 2 - Guardar Viagens					                    |\n";
		cout << "| 3 - Menu Principal					                    |\n";
		cout << "| 0 - Sair                                                 |\n";
		cout << "+----------------------------------------------------------+\n";
		cout << "\n";

		cin >> opcaotrip;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Erro: Introduziu um input invalido. So pode usar numeros inteiros." << endl;
			cout << "Pressione Enter para voltar ao menu" << endl;
			cin.get();
		}

		switch (opcaotrip) {

		case 0:
			return;
			break;

		case 1:
			readToClientFile();
			cin.get();
			cin.get();
			break;

		case 2:
			readToTripsFile();
			cin.get();
			cin.get();
			break;

		case 3:
			readToTripsFile();
			cin.get();
			cin.get();
			break;

		default:
			cout << "Lamento, mas a opcao que inseriu nao e valida. Sera redirecionado/a para o inicio do menu. \n";

		}
	}
}

void Agency::map(){

	gv = new GraphViewer(1360,625, false);
	gv->setBackground("worldmap.jpg");
	gv->defineVertexColor(GRAY);
	gv->defineEdgeColor(GRAY);
	gv->defineEdgeCurved(true);
	gv->createWindow(750,450);

	for(unsigned int i = 0; i < vec.size(); i++){
		cout << i << "\n";
		gv->addNode(vec.at(i)->getID(), vec[i]->getCoordinates().getX(), vec[i]->getCoordinates().getY());
		gv->setVertexLabel(vec[i]->getID(),vec[i]->getName());
		gv->setVertexColor(vec[i]->getID(), GRAY);
		gv->setVertexSize(vec[i]->getID(), 3);
	}

	int id = 0;

	for(unsigned int i = 0; i < vec.size(); i++){

		if(vec[i]->getID() != 0){

			for(unsigned int j = 0; j < 3; j++){
				gv->addEdge(id, vec.at(i)->getID(), vec.at(i)->getIDDestinies(j), EdgeType::UNDIRECTED);
				id++;
			}
		}
	}

	gv->rearrange();

}

float Agency::setSeason(Date date) {

	if((date.getMonth() == 12 && date.getDay() > 3) ||
			(date.getMonth() == 1 && date.getDay() < 10) ){  //CHRISTMAS VACATIONS
		multiplier = HIGH_S_M;
		cout << "\nAVISO - Férias de Natal - Época Alta : Os preços dos hoteis estão mais altos.\n";
	}

	if(date.getMonth() == 4){                           //EASTER
		if(10 <= date.getDay() &&  date.getDay() <= 19)
			multiplier = HIGH_S_M;
		cout << "\nAVISO - Férias da Páscoa - Época Alta : Os preços dos hoteis estão mais altos.\n";
	}

	if(date.getMonth() == 7 || date.getMonth() == 8){   //SUMMER VACATIONS
		multiplier = HIGH_S_M;
		cout << "\nAVISO - Férias de Verão - Época Alta : Os preços dos hoteis estão mais altos.\n";

	}

	return multiplier;
}
