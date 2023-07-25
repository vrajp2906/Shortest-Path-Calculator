#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <fstream>
using namespace std;

class Coordinate
{
private:
	int i, j;
public:
	Coordinate(); //Initialize the member variables to 0
	Coordinate(const int&, const int&);
	int getRowIndex() const;
	int getColIndex() const;
	void setRowIndex(const int&);
	void setColIndex(const int&);
	bool operator == (const Coordinate&) const;
	friend ostream& operator << (ostream&, const Coordinate&);
};

Coordinate::Coordinate()
{
	i=0;
	j=0;
}
Coordinate::Coordinate(const int &a, const int &b)
{
	i = a;
	j = b;
}
int Coordinate::getRowIndex() const
{
	return i;
}
int Coordinate::getColIndex() const
{
	return j;
}
void Coordinate::setRowIndex(const int &a)
{
	i = a;
}
void Coordinate::setColIndex(const int &b)
{
	j = b;
}
bool Coordinate::operator == (const Coordinate &C) const 
{
	if (this->i == C.i && this->j == C.j)
		return true;
	return false;
}


ostream& operator << (ostream& out, const Coordinate& c)
{
	out << "(" << c.i << ", " << c.j << ")";
	return out;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SmarterArray
{
private:
	T *A;
	int size;
public:
	SmarterArray();//Initialize the pointer to nullptr and the size to 0
	SmarterArray(const SmarterArray<T>&);
	SmarterArray<T>& operator = (const SmarterArray<T>&);
	~SmarterArray();
	int getSize() const;
	T& operator[](const int&) const;
	bool isFound(const T&) const;
	void append(const T&);
	bool remove(const int&);
	bool operator == (const SmarterArray<T>&) const;

	template <class T>
	friend ostream& operator << (ostream&, const SmarterArray<T>&);


};

template <class T>
SmarterArray<T>::SmarterArray()
{
	this->A = nullptr;
	this->size = 0;
}

template <class T>
SmarterArray<T>::SmarterArray(const SmarterArray<T> &L)
{
	this->size = L.getSize();
	if (this->getSize() > 0)
	{
		this->A = new T[this->getSize()];
		for (int i = 0; i < this->getSize(); i++)
			this->A[i] = L[i];
	}
}

template <class T>
SmarterArray<T>& SmarterArray<T> :: operator = (const SmarterArray<T> &L)
{
	//if (this == &L)
	//	return *this;
	this->~SmarterArray();
	this->size= L.getSize();
	if (this->getSize() > 0)
	{
		this->A = new T[this->getSize()];

		for (int i = 0; i < this->getSize(); i++)
			this->A[i] = L[i];
	}
	return *this;
}

template <class T>
SmarterArray<T>::~SmarterArray()
{
	if (this->getSize() > 0)
	{
		delete[] this->A;
		this->size = 0;
	}
}

template <class T>
int SmarterArray<T>::getSize() const
{
	return this->size;
}

template <class T>
T& SmarterArray<T>::operator[](const int &index) const
{
	assert(index >= 0 && index < this->getSize());
	return this->A[index];
}


template <class T>
bool SmarterArray<T>::isFound(const T &e) const ////
{
	for (int i = 0 ; i < this->getSize(); i++)
	{
		if (this->A[i] == e)
			return true;
	}
	return false;
}

template <class T>
void SmarterArray<T>::append(const T &e)
{
	T *temp = new T[this->getSize() + 1];
	for (int i = 0; i<this->getSize(); i++)
		temp[i] = this->A[i];
	temp[this->getSize()] = e;
	if (this->getSize() > 0)
		delete[] this->A;
	this->A = temp;
	this->size += 1;
}

template <class T>
bool SmarterArray<T>::remove(const int &index)
{
	if (index < 0 && index >= this->getSize())
		return false;
	else;
	{
		T *temp = new T[this->getSize() - 1];
		for (int i = 0; i < index; i++)
			temp[i] = this->A[i];
		for(int i = index+1; i<this->getSize(); i++)
			temp[i-1] = this->A[i];
		if (this->getSize() > 0)
			delete[] this->A;

		this->A = temp;
		this->size -= 1;
		return true;
	}
}

template <class T>/////
bool SmarterArray<T>::operator == (const SmarterArray<T> &L) const
{
	if (this->getSize() != L.getSize())
		return false;
	else
	{
		for(int i = 0; i<this->getSize(); i++)
		{
			if (this->A[i] != L.A[i])
			{
				return false;
			}
		}
	}
	return true;
}

template <class T>
ostream& operator << (ostream& out, const SmarterArray<T>& L)
{
	if (L.getSize() == 0)
		out << "[Empty Container]";
	else
	{
		cout << L[0];
		for (int i = 1; i < L.getSize(); i++)
			out << " --> " << L[i];
	}
	return out;
}

/////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class City
{
private:
	string name;
	int cost_right; //Although double data type would be more appropriate,
	int cost_left; //let us use int data type for easy printing purposes
	int cost_up; //This is not too important
	int cost_down; //So let's just use int data type
public:
	//Constructors
	City(); //Set city to "" and all cost to -1 to mean no connection to its neighbours
	City(const string&, const int&, const int&, const int&, const int&);
	//This constructor must take the name, right, left, up, down arguments in that order

	//Getters
	string getCityName() const;
	int getCostRight() const;
	int getCostLeft() const;
	int getCostUp() const;
	int getCostDown() const;

	//Setters
	void setCityName(const string&);
	void setCostRight(const int&);
	void setCostLeft(const int&);
	void setCostUp(const int&);
	void setCostDown(const int&);
	//Friend functions
	//friend ostream& operator << (ostream&, const City&); WE Do NOT WANT THIS FUNCTION!!!
};

City::City()//Set city to "" and all cost to -1 to mean no connection to its neighbours
{
	name = "";
	cost_right = -1;
	cost_left = -1;
	cost_up = -1;
	cost_down = -1;
}

City::City(const string &n, const int &r, const int &l, const int &u, const int &d)
{
	name = n;
	cost_right = r;
	cost_left = l;
	cost_up = u;
	cost_down = d;
}

string City::getCityName() const
{
	return name;
}
int City::getCostRight() const
{
	return cost_right;
}
int City::getCostLeft() const
{
	return cost_left;
}
int City::getCostUp() const
{
	return cost_up;
}
int City::getCostDown() const
{
	return cost_down;
}

void City::setCityName(const string &n)
{
	name = n;
}
void City::setCostRight(const int &r)
{
	cost_right = r;
}
void City::setCostLeft(const int &l)
{
	cost_left = l;
}
void City::setCostUp(const int &u)
{
	cost_up = u;
}
void City::setCostDown(const int &d)
{
	cost_down = d;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator << (ostream& out, const SmarterArray<SmarterArray<City>>& region)
{
	assert(region.getSize() > 0);
	int R = region.getSize();
	int C = region[0].getSize();
	out.setf(ios::fixed | ios::left); //Left aligned fixed decimal places
	const int width = 17;
	for (int i = 0; i < R; i++)
	{
		out << endl;
		//Print the costs to move up only if i = 0
		if (i == 0)
		{
			out << setw(width) << "";
			for (int j = 0; j < C; j++)
				out << setw(width) << region[i][j].getCostUp() << setw(width) << "";
			out << endl << endl;
		}
		//Print the costs to move left, the city names, and the costs to move right
		for (int j = 0; j < C; j++)
		{
			//Print cost to move left only if j = 0
			if (j == 0)
				out << setw(width) << region[i][j].getCostLeft();
			out << setw(width) << region[i][j].getCityName();
			out << setw(width) << region[i][j].getCostRight();
		}
		out << endl << endl;
		//Print costs to move down
		out << setw(width) << "";
		for (int j = 0; j < C; j++)
			out << setw(width) << region[i][j].getCostDown() << setw(width) << "";
		out << endl;
	}
	out.unsetf(ios::fixed | ios::left); //Removing formatting
	out.precision(0); //Resetting the decimal places
	return out;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////

void computeAllPossiblePaths(const SmarterArray<SmarterArray<City>>& region_map, const Coordinate& departure, const Coordinate& destination, SmarterArray<SmarterArray<Coordinate>>& all_paths, SmarterArray<Coordinate>& path = SmarterArray<Coordinate>())
{
	assert(region_map.getSize() > 0);

	int i1 = departure.getRowIndex();
	int j1 = departure.getColIndex();
	int i2 = destination.getRowIndex();
	int j2 = destination.getColIndex();

	assert(i1 >= 0 && i1 < region_map.getSize() && j1 >= 0 || j1 < region_map[0].getSize());
	
	//cout << "Visiting... " << departure << endl;
	path.append(departure);
	//cout << "The path so far is: " << path << endl;system("Pause");
	
	if (i1 == i2 && j1 == j2) //The departure and destination coordinates are equal.
	{
		cout << endl << "Path found: " << path << endl << endl;
		all_paths.append(path);
		return;
	}
	else
	{
		if (region_map[i1][j1].getCostUp() != -1)
		{
			if (!path.isFound(Coordinate(i1-1, j1)))
				{
					computeAllPossiblePaths(region_map, Coordinate(i1-1, j1), destination, all_paths, path);
					//cout << "Erasing " << path[path.getSize()-1] << endl;
					path.remove(path.getSize()-1);
					//cout << "The path so far is: " << path << endl;system("Pause");
				}					
		}
		if (region_map[i1][j1].getCostRight() != -1)
		{
			if (!path.isFound(Coordinate(i1, j1+1)))
				{
				computeAllPossiblePaths(region_map, Coordinate(i1, j1+1), destination, all_paths, path);
				//cout << "Erasing " << path[path.getSize()-1] << endl;
				path.remove(path.getSize()-1);
				//cout << "The path so far is: " << path << endl;system("Pause");
				}
		}
		if (region_map[i1][j1].getCostDown() != -1)
		{
			if (!path.isFound(Coordinate(i1+1, j1)))
			{
				computeAllPossiblePaths(region_map, Coordinate(i1+1, j1), destination, all_paths, path);
				//cout << "Erasing " << path[path.getSize()-1] << endl;
				path.remove(path.getSize()-1);
				//cout << "The path so far is: " << path << endl;system("Pause");
			}
		}
		if (region_map[i1][j1].getCostLeft() != -1)
		{
			if (!path.isFound(Coordinate(i1, j1-1)))
			{
				computeAllPossiblePaths(region_map, Coordinate(i1, j1-1), destination, all_paths, path);
				//cout << "Erasing " << path[path.getSize()-1] << endl;
				path.remove(path.getSize()-1);
				//cout << "The path so far is: " << path << endl;system("Pause");
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
int computePathCost(const SmarterArray<SmarterArray<City>>& region_map, const SmarterArray<Coordinate>& min_path)
{
	int path_cost = 0; 
	int i1,i2,j1,j2;
	for (int i = 0 ; i < min_path.getSize() - 1; i++)
	{
		i1 = min_path[i].getRowIndex();
		j1 = min_path[i].getColIndex();
		i2 = min_path[i+1].getRowIndex();
		j2 = min_path[i+1].getColIndex();
		
		if (i2 == i1 - 1)
			path_cost += region_map[i1][j1].getCostUp();
		else if (i2 == i1 + 1)
			path_cost += region_map[i1][j1].getCostDown();
		else if (j2 == j1 + 1)
			path_cost += region_map[i1][j1].getCostRight();
		else
			path_cost += region_map[i1][j1].getCostLeft();
	}
	return path_cost;
}


SmarterArray<Coordinate> computeMinimumCostPath(const SmarterArray<SmarterArray<City>>& region_map, const  SmarterArray<SmarterArray<Coordinate>>& all_paths)
{
	
	SmarterArray<Coordinate> minimum_path;
	if (all_paths.getSize() == 0 )
		return minimum_path;

	minimum_path = all_paths[0];
	int minimum_cost = computePathCost(region_map, minimum_path);
	for (int i = 1; i < all_paths.getSize(); i++)
	{
		int pathCost = computePathCost(region_map, all_paths[i]);
		if (pathCost < minimum_cost)
		{
			minimum_path = all_paths[i];
			minimum_cost = pathCost;
		}
	}
	return minimum_path;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	int R;
	int C;
	string name;

	SmarterArray<City> row_map;
	SmarterArray<SmarterArray<City>> region_map;
	ifstream fin("Region_Map.txt");

	if (fin.fail())
	{
		cout << "Input File Stream Failed" << endl;
		return 0;
	}
	else
	{
		cout << "Reading from Region_Map.txt input file..." <<endl;
		
	}

	fin>>R;
	fin >> C;

	for (int j = 0 ; j < R ; j++)
	{	
		for (int i = 0; i<C; i++)
		{
			fin >> name;
			row_map.append(City(name,-1,-1,-1,-1));
		}
		region_map.append(row_map);
		row_map.~SmarterArray();
	}
	fin.close();
	cout << "Done!" << endl << endl;
	//////////////////////////////////////////////////////////////////////

	
	ifstream fin2("Connectivity_Map.txt");

	if (fin2.fail())
	{
		cout << "Input File Stream Failed" << endl;
		return 0;
	}
	else
	{
		cout << "Reading from Connectivity_Map.txt input file..." <<endl;
		
	}

	
	string city1;
	string city2;
	int cost;
	
	//CHANGING DISTANCE ACCORDINGLY
	
	while(fin2.eof() == false)
	{
		fin2 >> city1 >> city2 >> cost;
		int x1,y1,x2,y2;
		for (int i = 0; i<R; i++)
		{
			for (int j = 0; j<C; j++)
			{
				if (region_map[i][j].getCityName() == city1)
					x1 = i, y1 = j;
				if (region_map[i][j].getCityName() == city2)
					x2 = i, y2 = j;
			}
		}
		if (x2 == x1-1)
		{
			region_map[x1][y1].setCostUp(cost);
			region_map[x2][y2].setCostDown(cost);
		}
		else if (x2 == x1+1)
		{
			region_map[x1][y1].setCostDown(cost);
			region_map[x2][y2].setCostUp(cost);
		}
		else if (y2 == y1+1)
		{
			region_map[x1][y1].setCostRight(cost);
			region_map[x2][y2].setCostLeft(cost);
		}
		else
		{
			region_map[x1][y1].setCostLeft(cost);
			region_map[x2][y2].setCostRight(cost);
		}
	}
		
	fin2.close();
	cout << "Done!" << endl << endl;

	////PRINTING THE MAP WITH UPDATED DISTANCE
	cout << "The region map is..." << endl << region_map << endl << endl;


	//ASKING USER TO GIVE INPUT
	string start, end;

	cout << "Enter a departure city: ";
	cin >> start;
	cout << "Enter a destination city: ";
	cin >> end;
	cout << endl;
	

	//Getting Coordinates
	int i1, j1, i2, j2;
	int count1 = 0; 
	int count2 = 0;
	for (int i = 0 ; i < R ; i++)
	{
		for (int j = 0; j<C; j++) 
		{
			//region_map[i].getSize()
			if (start == region_map[i][j].getCityName())
			{
				i1 = i;
				j1 = j;
				count1++;
			}
			if (end == region_map[i][j].getCityName())
			{
				i2 = i;
				j2 = j;
				count2++;
			}
		}
	}
	if (count1 + count2 == 0)
	{
		cout << "Your Departure input and Destination Input does not exist within the map " << endl;
		system("pause");
		return 0;
	}

	else if (count1 == 0)
	{

		cout << "Your Departure input does not exist within the map " << endl;
		system("pause");
		return 0;
	}
	
	else if (count2 == 0)
	{
		cout << "Your Destination input does not exist within the map" << endl;
		system("pause");
		return 0;
	}

	

	Coordinate departure(i1, j1);
	cout << "Departing from " << departure << endl << endl;
	
	Coordinate destination(i2, j2);
	cout << "Destined to " << destination << endl << endl << endl;
	
	

	SmarterArray<SmarterArray<Coordinate>> all_paths;
	computeAllPossiblePaths(region_map, departure, destination, all_paths);

	
	//SmarterArray<City> city_path;
	cout << endl;
	cout << "All the paths computed are..." << endl;
	
	
	//PRINTING THE PATH OF THE CITIES
	//for (int i = 0 ; i < all_paths.getSize(); i++)
	//	cout << all_paths[i] << endl;
	
	
	SmarterArray<string> H;

	if (all_paths.getSize() > 0)
	{
		for (int i = 0; i < all_paths.getSize(); i++)
		{
			int a,b;
			for (int j = 0 ; j < all_paths[i].getSize(); j++)
			{
				a = all_paths[i][j].getRowIndex();
				b = all_paths[i][j].getColIndex();
				string name = region_map[a][b].getCityName();		
				H.append(name);
			
			}
			cout << H << endl;
			H.~SmarterArray();
		}
	}
	else
		cout <<  " NO PATHS FOUND FOR THE ROUTE" << endl;

	//	for (int i = 0 ; i < all_paths.getSize(); i++)
		//	cout << all_paths[i] << endl;

	cout << endl;
	//////////////////

	SmarterArray<Coordinate> minCostPath = computeMinimumCostPath(region_map, all_paths);

	//cout << endl << "The minimum cost path is " << endl << minCostPath << endl << endl;
	
	SmarterArray<string> Z;

	for (int i = 0 ; i < minCostPath.getSize(); i++)
	{
		int a = minCostPath[i].getRowIndex();
		int b = minCostPath[i].getColIndex();
		string name = region_map[a][b].getCityName();
		Z.append(name);
	}
	
	cout << endl << "The minimum cost path is " << endl << Z << endl << endl;
	Z.~SmarterArray();


	//////////////

	cout << "It's cost = " << computePathCost(region_map, minCostPath) << endl << endl;
	

	
	system("pause");
	return 0;
}
