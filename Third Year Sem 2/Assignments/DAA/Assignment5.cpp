#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;
using std::vector;

vector<vector<int>> inTxt(string path, int cityNb) {

	ifstream infile(path);

	string line;
	vector<vector<int>> distance(cityNb, vector<int>(cityNb));

	int lineCount = 0;
	int tempDis = 0;


	while (getline(infile, line)) {

		int nb = 0;

		istringstream iss(line);
		while (iss >> tempDis && nb < cityNb) {

			distance[lineCount][nb] = tempDis;
			nb = nb + 1;

		}

		lineCount = lineCount + 1;

	}

	return distance;
}

vector<vector<int>> initPath(int route, int nb) {

	vector<vector<int>> population(route, vector<int>(nb));

	default_random_engine generator(std::random_device{}());

	int city;
	for (int i = 0; i < route; i++) {

		vector<int> place;
		for (int k = 0; k < nb; k++) {
			place.push_back(k);
		}

		int s = nb;
		for (int j = 0; j < nb; j++) {


			uniform_int_distribution<int> distribution(0, s - 1);

			city = distribution(generator);
			population[i][j] = place[city];
			
			int temp = place[s - 1];
			place[city] = temp;
			place.pop_back();
			s = s - 1;
			
		}
	}
	
	return population;
}

int fitness(vector<int> sroute, vector<vector<int>> length) {

	int s = sroute.size();

	int routeLength = 0;
	for (int i = 1; i < s; i++) {
		routeLength += length[sroute[i - 1]][sroute[i]];
	}
	routeLength += length[sroute[s - 1]][sroute[0]];

	return routeLength;
}

vector<double> choseRange(vector<int> fitness, int ep) {

	vector<int>::const_iterator fitIter = fitness.cbegin();
	int minFit = *fitIter;
	for (; fitIter != fitness.cend(); fitIter++) {
		if (*fitIter < minFit) {
			minFit = *fitIter;
		}
	}

	//cout << "Minimun distance: " << minFit << endl;

	vector<double> trueFitness;
	double total = 0;
	for (fitIter = fitness.cbegin(); fitIter != fitness.cend(); fitIter++) {
		double ratio = double(*fitIter) / double(minFit);
		double exponent = -pow(ratio, ep);
		total += exp(exponent);
		trueFitness.push_back(total);
	}

	vector<double> range(fitness.size());
	for (int i = 0; i < (int)fitness.size(); i++) {
		range[i] = trueFitness[i] / total;
	}

	return range;
}

vector<int> inheritance(vector<int> father, vector<int> mother) {

	if (father.size() != mother.size()) {
		cout << "Ops! Length is different." << endl;
	}

	int s = father.size();
	default_random_engine generator(std::random_device{}());
	uniform_int_distribution<int> distribution(0, s - 1);

	int p1, p2;
	p1 = distribution(generator);
	p2 = distribution(generator);

	while (p1 == p2) {
		p2 = distribution(generator);
	}

	if (p1 > p2) {
		int temp = p1;
		p1 = p2;
		p2 = temp;
	}

	vector<int> child(s);

	for (int i = p1; i <= p2; i++) {
		for (int j = 0; j < (int)mother.size(); j++) {
			if (mother[j] == father[i]) {
				mother.erase(mother.begin() + j);
				break;
			}
		}
	}

	vector<int>::const_iterator mIter = mother.cbegin();
	for (int i = 0; i < s; i++) {
		if (i >= p1 && i <= p2) {
			child[i] = father[i];
		}
		else {
			child[i] = *mIter;
			if (mIter != mother.cend()) {
				mIter++;
			}
		}

	}

	//cout << "p1: " << p1 << endl;
	//cout << "p2: " << p2 << endl;

	return child;
}

vector<vector<int>> mutate(vector<vector<int>> population, vector<double> range, vector<int> fitness) {

	int routeNb = population.size();

	default_random_engine generator(std::random_device{}());

	vector<vector<int>> childGen;
	uniform_real_distribution<double> distribution(0, 1);
	for (int i = 0; i < routeNb; i++) {
		double randNb;
		randNb = distribution(generator);

		int parFather;
		for (int j = 1; j < range.size(); j++){
			if (randNb <= range[0]) {
				parFather = 0;
				break;
			}
			else if (randNb > range[j - 1] && randNb <= range[j]){
				parFather = j;
				break;
			}
		}

		randNb = distribution(generator);

		int parMother;
		for (int j = 1; j < range.size(); j++){
			if (randNb <= range[0]) {
				parMother = 0;
				break;
			}
			else if (randNb > range[j - 1] && randNb <= range[j]){
				parMother = j;
				break;
			}
		}


		while (parFather == parMother){
			randNb = distribution(generator);
			for (int j = 1; j < range.size(); j++){
				if (randNb <= range[0]) {
					parMother = 0;
					break;
				}
				else if (randNb > range[j - 1] && randNb <= range[j]){
					parMother = j;
					break;
				}
			}
		}

		vector<int> child = inheritance(population[parFather], population[parMother]);
		childGen.push_back(child);

	}

	vector<int>::const_iterator fitIter = fitness.cbegin();
	int minFit = *fitIter;
	int index = 0;
	for (; fitIter != fitness.cend(); fitIter++) {
		if (*fitIter < minFit) {
			minFit = *fitIter;
			index = fitIter - fitness.cbegin();
		}
	}
	childGen.push_back(population[index]);

	return childGen;
}

vector<vector<int>> change(vector<vector<int>> population, double changeRate, int cityNb) {

	default_random_engine generator(std::random_device{}());
	uniform_real_distribution<double> dis(0, 1);
	uniform_int_distribution<int> disInt(0, cityNb - 1);

	for (int i = 0; i < population.size(); i++) {
		double r = dis(generator);
		if (r >= changeRate) {
			int first, second;
			first = disInt(generator);
			second = disInt(generator);

			while (first == second) {
				second = disInt(generator);
			}

			int temp = population[i][first];
			population[i][first] = population[i][second];
			population[i][second] = temp;
		}
	}

	return population;
}

vector<int> saveMin(vector<vector<int>> population, vector<int> fitness) {

	vector<int>::const_iterator fitIter = fitness.cbegin();
	int minFit = *fitIter;
	int index = 0;
	for (; fitIter != fitness.cend(); fitIter++) {
		if (*fitIter < minFit) {
			minFit = *fitIter;
			index = fitIter - fitness.cbegin();
		}
	}

	return population[index];
}


int main(int argc, char * argv[]) {

	int cityNb = 5;
	int route = 5;
	int ep = 5;
	int iteration = 200;

	string dataPath = "./data.txt";

	vector<vector<int>> distance = inTxt(dataPath, cityNb);

	vector<vector<int>> population = initPath(route, cityNb);

	vector<vector<int>>::const_iterator pRow;
	vector<int>::const_iterator pCol;

	ofstream outputP("./population.txt");
	for (pRow = population.cbegin(); pRow != population.cend(); pRow++) {
		for (pCol = (*pRow).cbegin(); pCol != (*pRow).cend(); pCol++) {
			outputP << *pCol << " ";
		}
		outputP << endl;
	}

	vector<int> routeLength;
	for (int i = 0; i < route; i++) {
		routeLength.push_back(fitness(population[i], distance));
	}

	vector<double> range = choseRange(routeLength, ep);
	outputP << endl;
	outputP << "range:" << endl;
	vector<double>::const_iterator rIter = range.cbegin();
	for (; rIter != range.cend(); rIter++) {
		outputP << *rIter << " ";
	}
	
	vector<vector<int>> mini(iteration, vector<int>(cityNb));

	for (int j = 0; j < iteration; j++) {

		population = mutate(population, range, routeLength);
		population = change(population, 0.06, cityNb);

		vector<int> routeLength;
		for (int i = 0; i < population.size(); i++) {
			routeLength.push_back(fitness(population[i], distance));
		}

		mini[j] = saveMin(population, routeLength);

		vector<double> range = choseRange(routeLength, ep);

		vector<vector<int>>::const_iterator spRow;
		vector<int>::const_iterator spCol;
		ofstream outputGen("./generation.txt");
		for (spRow = population.cbegin(); spRow != population.cend(); spRow++) {
			for (spCol = (*spRow).cbegin(); spCol != (*spRow).cend(); spCol++) {
				outputGen << *spCol << " ";
			}
			outputGen << endl;
		}
	}

	vector<int> finalLength;
	for (int i = 0; i < iteration; i++) {
		finalLength.push_back(fitness(mini[i], distance));
	}

	vector<int>::const_iterator fitIter = finalLength.cbegin();
	int minFit = *fitIter;
	int index = 0;
	for (; fitIter != finalLength.cend(); fitIter++) {
		if (*fitIter < minFit) {
			minFit = *fitIter;
			index = fitIter - finalLength.cbegin();
		}
	}
	cout << "Minimum length: " << minFit << endl;
	cout << "Index: " << index << endl;

	return 0;
}